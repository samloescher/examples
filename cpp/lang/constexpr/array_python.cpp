#include <iostream>
#include <array>

int main()
{
    constexpr auto my_constant_array = std::array<double, @array_size@>{@array_data@};

    for (size_t i = 0; i < my_constant_array.size(); i++)
    {
        std::cout << my_constant_array[i] << ", ";
    }
    std::cout << std::endl;

    static_assert(my_constant_array.size() == 3, "");

    return 0;
}
