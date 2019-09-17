#include "mean.hpp"

#include <numeric>

double mean(const std::vector<int>& samples)
{
    const double sum = std::accumulate(samples.begin(), samples.end(), 0); // TODO : Should this be 0.0?
    return sum / samples.size();
}
