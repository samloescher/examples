#include <iostream>

template <typename T>
struct Amount
{
    double value() const
    {
        T const& underlying = static_cast<T const&>(*this);
        return underlying.getValue();
    }
};

template <typename T>
struct Addition
{
    void add(double o)
    {
        T& underlying = static_cast<T&>(*this);
        underlying.setValue(underlying.getValue() + o);
    }
};

class Value : public Addition<Value>, public Amount<Value>
{
public:
    Value() = default;
    double getValue() const
    {
        return v;
    }
    void setValue(double v)
    {
        this->v = v;
    }

private:
    double v;
};

template <typename T>
void print(Amount<T> const& p)
{
    std::cout << p.value() << std::endl;
}

int main()
{
    Value v{};
    v.setValue(1);
    std::cout << v.getValue() << std::endl;
    v.add(2);
    std::cout << v.getValue() << std::endl;
    v.add(2);

    print(v);
}
