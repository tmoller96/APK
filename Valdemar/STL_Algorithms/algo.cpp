/*****************************************/
/* Copyright: DevelEdu 2013              */
/* Author: sha                           */
/*****************************************/

#include <fstream>
#include <iostream>
#include <iterator>

#include <algorithm>
#include <assert.h>
#include <functional>
#include <numeric>
#include <string>
#include <vector>

#define PRODUCT_DB_FILE "product.db"

class Product
{
public:
  Product(const std::string &name, float price, unsigned int sold = 0)
      : name_(name), price_(price), sold_(sold)
  {
  }
  Product() : name_(""), price_(0), sold_(0) {}

  const std::string &name() const { return name_; }

  float price() const { return price_; }

  void setPrice(float newPrice) { price_ = newPrice; }

  unsigned int sold() const { return sold_; }

  friend std::istream &operator>>(std::istream &i, Product &p);
  friend std::ostream &operator<<(std::ostream &o, const Product &p);

private:
  std::string name_;
  float       price_;
  int         sold_;
};
typedef std::vector<Product> ProductList;

std::ostream &operator<<(std::ostream &o, const Product &p)
{
  return o << p.name_ << " " << p.price_ << " " << p.sold_;
}

std::istream &operator>>(std::istream &i, Product &p)
{
  return i >> p.name_ >> p.price_ >> p.sold_;
}
// possible implementation of back_insert
// template <class Container> class back_insert_iterator
// {

// private:
//   Container *container;

// public:
//   explicit back_insert_iterator(Container &x) : container(&x){};

//   back_insert_iterator &operator=(typename Container::const_reference value)
//   {
//     container->push_back(value);
//     return *this;
//   }
//   back_insert_iterator &operator*() { return *this; }
//   back_insert_iterator &operator++() { return *this; }
//   back_insert_iterator &operator++(int) { return *this; }
// };

// template <class Container>
// inline back_insert_iterator<Container> back_inserter(Container &x)
// {
//   return back_insert_iterator<Container>(x);
// }

// template <class InputIterator, class OutputIterator>
// OutputIterator copy(InputIterator first, InputIterator last, OutputIterator
// result) {
//   for(;first != last; ++first, ++result) {
//     *result = *first;
//   }
//   return result;
// }

/**
 * Read products from file
 */
void productDBRead(ProductList &pl, const std::string &fileName)
{
  pl.clear();
  std::ifstream pFile(fileName.c_str());

  std::istream_iterator<Product> it1(pFile);
  std::istream_iterator<Product> it2;

  std::copy(it1, it2, std::back_inserter(pl));
}

/**
 * Printout all products
 */
void printAll(const ProductList &pl)
{
  std::cout << "##################################################"
            << std::endl;
  std::cout << "Printing out all products..." << std::endl;
  std::cout << "----------------------------" << std::endl;

  std::ostream_iterator<Product> it1(std::cout, "\n");
  copy(pl.begin(), pl.end(), it1);

  // for (ProductList::const_iterator iter = pl.begin(); iter != pl.end();
  // ++iter)
  // {
  //   std::cout << *iter << std::endl;
  // }
  std::cout << "##################################################"
            << std::endl;
}

/**
   Add item
*/
void addItem(ProductList &pl)
{
  std::istream_iterator<Product> input(std::cin);
  pl.push_back(*input);
}

/**
   Write data to db file
*/
void productDBWrite(const ProductList &pl, const std::string &fileName)
{
  std::ofstream pFile(fileName.c_str());

  std::ostream_iterator<Product> it1(pFile, "\n");

  std::copy(pl.begin(), pl.end(), it1);
}
bool isNotPorlySelling(const Product &product) { return product.sold() > 10; }
/**
 * Print poorly selling products
 */
void printPoorlySellingProducts(const ProductList &pl)
{
  std::ostream_iterator<Product> output(std::cout, "\n");
  std::remove_copy_if(pl.begin(), pl.end(), output, isNotPorlySelling);
}

/**
 * Set a discount on all products - Using for_each()
 */

class addDiscount
{
private:
  double discount;

public:
  addDiscount(float disc) : discount(disc) {}
  void operator()(Product &p)
  {
    p.setPrice(p.price() * (1.0 - (discount / 100)));
  }
};

void addDiscountUsingForEach(ProductList &pl)
{
  float discount = 10;
  // std::for_each(pl.begin(), pl.end(), addDiscount(0.10)); //Using Functor
  std::for_each(pl.begin(), pl.end(), [discount](auto &p) -> void {
    p.setPrice(p.price() * (1.0 - (discount / 100)));
  }); // Using lambda
}

/**
 * Set a discount on all products - Using transform()
 */
template <class T, class Compare>
constexpr const T &clamp(const T &v, const T &lo, const T &hi, Compare comp)
{
  return assert(!comp(hi, lo)), comp(v, lo) ? lo : comp(hi, v) ? hi : v;
}

template <class T>
constexpr const T &clamp(const T &v, const T &lo, const T &hi)
{
  return ::clamp(v, lo, hi, std::less<>());
}
void addDiscountUsingTransform(ProductList &pl)
{
  float discount;
  std::cin >> discount;
  auto disc = [](float discount) {
    return [discount](Product p) {
      p.setPrice(p.price() * (1 - (discount / 100)));
      return p;
    };
  };
  std::ostream_iterator<Product> output(std::cout, "\n");
  std::transform(pl.begin(), pl.end(), output, disc(discount));
}

/**
 * Calculate the total amount of sold products
 */
void calcTotalSoldProducts(ProductList &pl) {
  unsigned int totalProductsSold = 0;
  std::cout << "Total products sold: " << std::accumulate(pl.begin(), pl.end(), totalProductsSold, [](unsigned int tempTotal, Product p) {
    return tempTotal += p.sold();
  }) << std::endl;
}

/**
 * Setting discount using bind2nd - OPTIONAL
 */

int main()
{
  bool        running = true;
  ProductList pl;

  while (running)
  {
    char choice;

    std::cout << "********************" << std::endl;
    std::cout << "Help menu: " << std::endl;
    std::cout << "'1' Read product database" << std::endl;
    std::cout << "'2' Print all items" << std::endl;
    std::cout << "'3' Add item" << std::endl;
    std::cout << "'4' Write product database" << std::endl;
    std::cout << "'5' Print poorly selling products" << std::endl;
    std::cout << "'6' Set a discount on all products (using for_each() )"
              << std::endl;
    std::cout << "'7' Set a discount on all products (using transform() )"
              << std::endl;
    std::cout << "'8' Calculate the total amount of sold products" << std::endl;

    std::cout << "'q' Quit" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case '1':
      productDBRead(pl, PRODUCT_DB_FILE);
      break;

    case '2':
      printAll(pl);
      break;

    case '3':
      addItem(pl);
      break;

    case '4':
      productDBWrite(pl, PRODUCT_DB_FILE);
      break;

    case '5':
      printPoorlySellingProducts(pl);
      break;

    case '6':
      addDiscountUsingForEach(pl);
      break;

    case '7':
      addDiscountUsingTransform(pl);
      break;

    case '8':
      calcTotalSoldProducts(pl);
      break;

    case 'q':
    case 'Q':
      running = false;
    }
  }
}
