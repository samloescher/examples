#include <iostream>

template <typename T, template<typename> class crtpType>
struct crtp
{
    T& underlying() { return static_cast<T&>(*this); }
    T const& underlying() const { return static_cast<T const&>(*this); }

private:
    crtp(){}
    friend crtpType<T>;
};

template <typename T>
struct Amount : crtp<T, Amount>
{
    double value() const
    {
        return this->underlying().getValue();
    }
};

template <typename T>
struct Addition : crtp<T, Addition>
{
    void add(double o)
    {
        return this->underlying().setValue(this->underlying().getValue() + o);
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
