#include <vector>
#include <random>
#include "common.hpp"

#include "../matrix.hpp"

vector<vector<double>> data;

template<typename map_t>
void do_trans(){
	matrix<map_t> m=data;
	// print_mat(m);
	m=transpose(m);
	// print_mat(m);
}

int main(){
	default_random_engine gen;
	uniform_int_distribution<int> dist(0,256);
	auto rng=bind(dist,gen);
	int d_size=1000;
	for(int i=0;i<d_size;i++){
		vector<double> temp;
		for(int j=0;j<d_size;j++){
			temp.push_back(rng());
		}
		data.push_back(temp);
	}
	benchmark(do_trans<basic_map>, "basic_map");
	benchmark(do_trans<z_map>, "z_map");
	return 0;
}