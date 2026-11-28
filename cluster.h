#pragma once

#include "point.h"
#include <vector>

struct Cluster {
    std::vector<Point> points;
    Point center;

    bool median_update_center();
    bool mean_update_center();
};

#ifdef CLUSTER_IMP

#define MEDIAN_IMP
#define MEAN_IMP
#include "extras.h"

bool Cluster::median_update_center() {
    std::vector<float> firsts{}, seconds{};
    for (const auto& p : points) {
	firsts.push_back(p.first);
	seconds.push_back(p.second);
    }
    float new_first = median(firsts), new_second = median(seconds);
    Point new_center{new_first, new_second};
    if (new_center == center) return false;
    center = new_center;
    return true;
}

bool Cluster::mean_update_center() {
    std::vector<float> firsts{}, seconds{};
    for (const auto& p : points) {
	firsts.push_back(p.first);
	seconds.push_back(p.second);	
    }
    float new_first = mean(firsts), new_second = mean(seconds);
    Point new_center{new_first, new_second};
    if (new_center == center) return false;
    center = new_center;
    return true;
}

#endif
