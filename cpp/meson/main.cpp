#include <iostream>
#include <boost/filesystem.hpp>

// Run with:
// meson build
// cd build
// ninja
// ./hello_meson

int main()
{
    std::cout << boost::filesystem::current_path() << std::endl;
}
