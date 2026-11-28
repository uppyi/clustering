#pragma once

#include <utility>
struct Point {
    float first;
    float second;

    Point();
    Point(float first, float second);
    Point(const std::pair<float, float>& coordinates);
    
    Point& operator=(const Point& other);
    Point& operator+=(const Point& other);
    Point& operator/=(int x);
};

#ifdef POINT_IMP

Point::Point() : first(0.0), second(0.0) {}
Point::Point(float first, float second) : first(first), second(second) {}
Point::Point(const std::pair<float, float>& coordinates) : first(coordinates.first), second(coordinates.second) {}

Point& Point::operator=(const Point& other) {
    if (this == &other) return *this;
    this->first = other.first;
    this->second = other.second;
    return *this;
}

Point& Point::operator+=(const Point& other) {
    this->first += other.first;
    this->second += other.second;
    return *this;
}

Point& Point::operator/=(int x) {
    this->first /= x;
    this->second /= x;
    return *this;
}

#include <ostream>
std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << p.first << ' ' << p.second;
    return out;
}

bool operator==(const Point& p1, const Point& p2) {
    return  p1.first == p2.first && p1.second == p2.second;
}

#endif
