#include <algorithm>
#include <variant>
#include <string>
#include <vector>
#include <iostream>

using VariantType = std::variant<int, double, std::string>;

struct PrinterVisiter
{
    template <class T>
    void operator() (T&& t)
    {
        std::cout << t << std::endl;
    }
};

auto lambdaPrintVisitor = [](auto&& t){std::cout << t << std::endl;};
auto doublePrinterVisitor = [](auto&& t){std::cout << t + t << std::endl;};


int main()
{
    std::vector<VariantType> v;
    v.push_back(1);
    v.push_back(2.0);
    v.push_back(std::string{"some_string"});

    std::for_each(v.begin(), v.end(),
            [](VariantType item)
            {std::visit(PrinterVisiter{}, item);});

    std::cout << std::endl;

    std::for_each(v.begin(), v.end(),
                  [](VariantType item)
                  {std::visit(lambdaPrintVisitor, item);});

    std::cout << std::endl;

    std::for_each(v.begin(), v.end(),
                  [](VariantType item)
                  {std::visit(doublePrinterVisitor, item);});

    std::cout << std::endl;

}
