#pragma once
#ifndef __UTILS__
#define __UTILS__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <utility>
#include <algorithm>
#include <random>
#include <chrono>
#include <type_traits>

#include "point.h"

using millis = std::chrono::milliseconds;
using micros = std::chrono::microseconds;
using nanos = std::chrono::nanoseconds;
using steady_clock = std::chrono::steady_clock;


template <class T>
struct is_duration : std::false_type{};

template <class R, class P>
struct is_duration<std::chrono::duration<R, P>> : std::true_type{};

template <typename T>
struct measure
{
    static_assert(is_duration<T>::value, "time must be std::chrono::duration");
      
    template<typename P>
    using ElapsedTimeWithIterations = std::pair<P, int>;

    template <class F, class... Args>
    static ElapsedTimeWithIterations<T> measure_time(F &&func, Args &&... args)
    {
        const auto start = steady_clock::now();
        const auto result = std::forward<F>(func)(std::forward<Args>(args)...);
        const int iteration = 0; // default value for iteration
        return std::make_pair(std::chrono::duration_cast<T>(steady_clock::now() - start), iteration);
    }
};


namespace Utils
{
    std::vector<Observation> readCsv(std::string path);

    void writeCsv(const std::vector<Observation>& p, const std::string path);

    // std::vector<Point> initCentroids(const std::vector<Point> &dataset, const long clusters);
}


#endif // __UTILS__
