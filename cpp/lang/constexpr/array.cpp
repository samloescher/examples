#include <iostream>
#include <array>
#include <algorithm>

template <typename T>
constexpr T my_transform(size_t index)
{
    return index * index;
}

template <typename T, int N>
constexpr std::array<T, N> squares()
{
    std::array<T, N> array{};
    size_t index = 0;
    std::transform(array.begin(),
                   array.end(),
                   array.begin(),
                   [&index](T){ return my_transform<T>(index++); });
    return array;
}


int main()
{
    constexpr auto my_constant_array = squares<double, 10>();

    for (size_t i = 0; i < my_constant_array.size(); i++)
    {
        std::cout << my_constant_array[i] << ", ";
    }
    std::cout << std::endl;

    static_assert(my_constant_array[0] == 0);

    return 0;
}
