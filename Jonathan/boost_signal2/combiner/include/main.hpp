#include <iostream>
#include <vector>
#include <boost/signals2.hpp>
#include <math.h>
#include <set>

struct comp
{
    inline bool operator()(const double& left, const double& right){
        return left > right;
    }
};

template<typename T>
struct findMedian
{
    typedef T result_type;
    
    template<typename InputIterator>
    result_type operator()( InputIterator first, InputIterator last ) const
    {
        if(first == last){
            throw std::runtime_error("Empty");
        }

        std::set<double,comp> set;
        set.insert(*first++);
        while (first != last)
        {
            //std::cout << *first << ", ";
            set.insert(*first);
            ++first;
        }
        auto n = set.size();
        std::vector<double> v;
        std::copy(set.begin(),set.end(),std::back_inserter(v));
        if (n % 2 != 0) 
            return (result_type)v[n / 2];
               
        return (result_type)(v[(n - 1) / 2] + v[n / 2]) / 2.0;
    }
};