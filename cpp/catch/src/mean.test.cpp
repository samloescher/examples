#include <catch2/catch.hpp>

#include "mean.hpp"

TEST_CASE("Mean filter", "[filter]")
{
    GIVEN("Small set of small numbers")
    {
        const auto expectedMean = 100;
        std::vector<int>samples{};
        for (auto i = 0; i < 10; i++)
        {
            samples.push_back(expectedMean);
        }
        WHEN("The mean is calculated")
        {
            const auto actualMean = mean(samples);
            THEN("The expected mean is correct")
            {
                REQUIRE(expectedMean == Approx(actualMean));
            }
        }
    }

    GIVEN("Large set of large numbers")
    {
        const int expectedMean = 1000000000;
        std::vector<int>samples{};
        for (auto i = 0; i < 1e3; i++)
        {
            samples.push_back(expectedMean);
        }
        WHEN("The mean is calculated")
        {
            const auto actualMean = mean(samples);
            THEN("The expected mean is correct")
            {
                REQUIRE(expectedMean == Approx(actualMean));
            }
        }
    }

    // ...
}
