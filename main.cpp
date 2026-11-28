#define MANH_DISTANCE
#define POINT_IMP
#define CLUSTER_IMP
#define CLUSTERISATION_IMP
#include "point.h"
#include "cluster.h"
#include "extras.h"
#include "clusterisation.h"

const std::string filename = "input.txt";

#include <iostream>
void print_dist_matrix(const std::vector<std::vector<float>>& dist_matrix) {
  for (const auto& line : dist_matrix) {
    for (auto el : line) {
      std::cout << el << ' ';
    }
    std::cout << '\n';
  }
}

#include <fstream>
void save_matrix(const std::vector<std::vector<float>>& matrix, const std::string& filename) {
  std::ofstream writer(filename);
  if (!writer.is_open()) {
    std::cerr << "Ошибка открытия файла " << filename << ".\n";
    return;
  }
  for (const auto& line : matrix) {
    for (float el : line) {
      writer << std::setw(3) << el << std::setw(1) << '|';
    }
    writer << '\n';
  }
  writer.close();
  std::cout << "Матрица записана в файл " << filename << ".\n";
}

#include <algorithm>
void find_4_centers(const std::vector<std::vector<float>>& dist_m) {
  size_t len = dist_m.size();
  float max_min = -1.0;
  int centers_ids[4];
  for (int a = 0; a < len; a++) {
    for (int b = 0; b < len; b++) {
      for (int c = 0; c < len; c++) {
	for (int d = 0; d < len; d++) {
	  float min_dist = std::min({
				    dist_m[a][b], dist_m[a][c], dist_m[a][d],
				    dist_m[b][c], dist_m[b][d], dist_m[c][d]
	    });
	  if (min_dist > max_min) {
	    max_min = min_dist;
	    centers_ids[0] = a+1;
	    centers_ids[1] = b+1;
	    centers_ids[2] = c+1;
	    centers_ids[3] = d+1;
	  }
	}
      }
    }
  }
  std::cout << "Найденные центры - это объекты < "
	    << centers_ids[0] << ' '
	    << centers_ids[1] << ' '
	    << centers_ids[2] << ' '
	    << centers_ids[3] << " >.\n"; // 3 24 43 49
}

#define INPUTFILE  "input.txt"
#define MATRIXFILE "dm.txt"

int main() {
  Clusterisation cl{INPUTFILE};
  auto dm_34 = cl.get_dist_matrix(3, 4);
  find_4_centers(dm_34);
  
  return 0;
}
