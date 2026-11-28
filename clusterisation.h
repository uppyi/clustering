#pragma once

#include "point.h"
#include "cluster.h"
#include <vector>
struct Clusterisation {
    std::vector<std::vector<float>> objects;
    int f1, f2;
    
    Clusterisation(std::string filename);
    void set_f(int f1, f2);
    
    std::vector<Cluster> clusterise();
    std::vector<std::vector<float>> get_dist_matrix();
    void visualise(const std::vector<std::vector<float>>& extra_objects);
};

#ifdef CLUSTERISATION_IMP

#include <fstream>
#include <iostream>
#include <sstream>
Clusterisation::Clusterisation(std::string filename) {
    std::cout << "Чтение объектов из файла...\n"; 
    std::ifstream reader(filename);
    if (!reader.is_open()) {
	std::cerr << "Ошибка открытия файла " << filename << '\n';
	return;
    }
    std::string line;
    std::string token;
    while (std::getline(reader, line)) { 
	std::istringstream iss(line);
	std::vector<float> object;
	while (std::getline(iss, token, ',')) {
	    object.push_back(std::stoi(token));
	}
	objects.push_back(object);
    }
    reader.close();
    std::cout << "Объекты успешно прочитаны. Прочитано " << objects.size() << " объектов.\n";
}

void Clusterisation::set_f(int f1, f2) {
    this->f1 = f1;
    this->f2 = f2;
}

#include "extras.h"
std::vector<std::vector<float>> Clusterisation::get_dist_matrix(int f1, int f2) {
    std::vector<std::vector<float>> dist_matrix;
    size_t len = objects.size();
    std::vector<float> line;
    for (int i = 0; i < len; i++) {
	line.clear();
	for (int j = 0; j < len; j++) {
	    if (i == j) {
		line.push_back(0.0);
		continue;
	    }
	    Point p1{objects[i][f1-1], objects[i][f2-1]}, p2{objects[j][f1-1], objects[j][f2-1]};
	    line.push_back(manh_distance(p1, p2));
	}
	dist_matrix.push_back(line);
    }
    std::cout << "Матрица расстояний составлена.\n";
    return dist_matrix;
}

void visualise(const std::vector<int>& extra_objects_ids) {
    using ebi = extra_objects_ids;
    
}

#endif
