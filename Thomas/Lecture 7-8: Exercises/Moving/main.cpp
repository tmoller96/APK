#include "file.hpp"

int main(int argc, char const *argv[])
{
    File file1("test1.txt");
    File file2(std::move(file1));
    File file3("test2.txt");
    file3 = std::move(file2);
    // File file4(file3); <-- This will not work when calling destructor

    return 0;
}
