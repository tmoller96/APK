namespace detail
{
template <class T> struct value_category
{
  static constexpr char const *value = "prvalue";
};
template <class T> struct value_category<T &>
{
  static constexpr char const *value = "lvalue";
};
template <class T> struct value_category<T &&>
{
  static constexpr char const *value = "xvalue";
};
} // namespace detail

#define PRINT_VALUE_CAT(expr)                                                  \
  std::cout << #expr << " is a "                                               \
            << ::detail::value_category<decltype((expr))>::value << '\n'