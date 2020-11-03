#include <iostream>
template<typename T> T sum(T last) {
    return last;
}
template <typename T, typename... Args> T sum(T first, Args... rest) {
    return first + sum(rest...);
}

int main() {
    std::cout << sum(1,20,103,30,472) << std::endl;
}
