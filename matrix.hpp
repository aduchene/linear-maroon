#include "coordinate_maps.hpp"

#include <vector>
#include <cstddef>
using std::size_t;
using std::vector;

template<typename coord_map, typename val_t=double>
struct matrix{
	unsigned int x_size, y_size;
	coord_map cmap;
	vector<val_t> data;

	matrix(unsigned int x, unsigned int y): x_size(x), y_size(y), cmap(x,y){
		data.resize(cmap.max_index());
	}

	val_t operator()(size_t x, size_t y){
		unsigned int i=cmap(x,y);
		return data[i];
	}

	template<typename other_t>
	//should this be pass by reference?
	matrix& operator=(other_t rhs){
		
	}
};