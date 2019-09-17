#include "shared_workspace.h"

#include <string>
#include <unordered_map>
#include <vector>

struct Complex
{
    Complex () = default;
    double real, imag;
};

struct Lib
{
    std::unordered_map<std::string, std::vector<double>> idToDouble;
    std::unordered_map<std::string, std::vector<Complex>> idToComplex;

    std::vector<double> output;
};

void* create()
{
    auto lib =  new Lib;
    lib->idToDouble.insert({"empty", {}});
    lib->idToDouble.insert({"double", {1, 2, 3}});

    lib->idToComplex.insert({"complex", { {1, 2}, {3, 4}, {5, 6} } });
    return lib;
}

void release(void *lib)
{
    delete static_cast<Lib*>(lib);
}

double* get(void* libptr, const char* id, int* size, DataType *type)
{
    auto lib = static_cast<Lib*>(libptr);

    lib->output = [id, lib, type]() -> std::vector<double>
    {
        if (lib->idToDouble.find(id) != lib->idToDouble.end())
        {
            *type = DataType::DOUBLE;
            return lib->idToDouble.at(id);
        }
        else if (lib->idToComplex.find(id) != lib->idToComplex.end())
        {
            *type = DataType::COMPLEX;
            auto &data = lib->idToComplex.at(id);
            std::vector<double> output{};
            for(size_t i = 0; i < data.size(); i++)
            {
                output.push_back(data.at(i).real);
            }
            for(size_t i = 0; i < data.size(); i++)
            {
                output.push_back(data.at(i).imag);
            }
            return output;
        }
        else
        {
            return {};
        }
    }();

    *size = lib->output.size();
    return lib->output.data();

}
