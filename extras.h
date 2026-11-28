#pragma once

#ifdef MEDIAN_IMP

// 3 4 5 6 7 8  --> len == 6
// 0 1 2 3 4 5  --> len / 2 == 3

float median(const std::vector<float>& values) {
    size_t len = values.size();
    if (len % 2 == 1) return values[len / 2];
    return (values[len / 2 - 1] + values[len / 2]) / 2.0;
}

#endif

#ifdef MEAN_IMP

float mean(const std::vector<float>& values) {
    size_t len = values.size();
    int sum = 0;
    for (size_t i = 0; i < len; i++) {
	sum += values[i];
    }
    return sum / len;
}

#endif

#ifdef EUCL_DISTANCE

#include <cmath>
float eucl_distance(const Point& p1, const Point& p2) {
    float dx1 = p1.first - p2.first;
    float dx2 = p1.second - p2.second;
    return std::sqrt(dx1 * dx1 + dx2 * dx2);
}

#endif

#ifdef MANH_DISTANCE

float manh_distance(const Point& p1, const Point& p2) {
    float dx1 = std::abs(p1.first - p2.first);
    float dx2 = std::abs(p1.second - p2.second);
    return dx1 + dx2;
}

#endif
