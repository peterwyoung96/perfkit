// // HEADERS //////////////////////////////////////////////////////////////////

#include <vector>
#include <cstdint>
#include <chrono>
#include <cmath>
#include <iostream>

#include <perfkit/math/fast_math.h>

// // HELPER & TEST FUNCTIONS //////////////////////////////////////////////////

/// NOTE: Modern C++ is way too optimized which is great, but a pain in the
/// but for tests like this. If we don't give a place to store the variable
/// and use it, then it will just be ignored by the compilers. This would
/// cause us to not actually do the calculations.
volatile int64_t sink = 0;

std::vector<int64_t> makeData(size_t n)
{
    std::vector<int64_t> data;
    data.reserve(n);

    for (size_t i = 0; i < n; ++i)
    {
        // Make a mix of positive and negative values
        data.push_back(
            (i % 2 == 0) ? 
            i : 
            -static_cast<int64_t>(i)
        );
    }
    return data;
} // end-makeData


template <typename Func>
void benchmark(const char* name, const std::vector<int64_t> data, Func f)
{
    auto start = std::chrono::high_resolution_clock::now();
    int64_t local_sink = 0;

    for (auto v : data)
        local_sink += f(v);

    sink = local_sink;
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> us = end - start;
    std::cout << name << ": " << us.count() << " us\n";
}

// // MAIN LOOP ////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    constexpr size_t N = 10'000'000;
    auto data = makeData(N);

    benchmark("std::abs", data, [](int64_t x) {
        return std::abs(x);
    });

    benchmark("fast_abs", data, [](int64_t x) {
        return perfkit::math::fast_abs(x);
    });

    std::cout << "sink: " << sink << "\n";

    return 0;
}

// // EOF //////////////////////////////////////////////////////////////////////