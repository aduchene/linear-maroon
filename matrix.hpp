#include "coordinate_maps.hpp"

#include <vector>
#include <algorithm>
#include <cstddef>
using std::size_t;
using std::vector;
using std::copy;

template<typename coord_map, typename val_t=double>
struct matrix{
	unsigned int x_size, y_size;
	coord_map cmap;
	vector<val_t> data;

	matrix(unsigned int x, unsigned int y): x_size(x), y_size(y), cmap(x,y){
		data.resize(cmap.max_index());
	}

	//template<typename ot>
	matrix(vector<vector<val_t>> contents): x_size(contents[0].size()), y_size(contents.size()), cmap(x_size,y_size){
		data.resize(cmap.max_index());
		for(int y=0;y<y_size;y++){
			for(int x=0;x<x_size;x++){
				data[cmap(x,y)]=contents[y][x];
			}
		}
	}

	val_t& operator()(size_t x, size_t y){
		unsigned int i=cmap(x,y);
		return data[i];
	}

	size_t size(){
		return data.size();
	}

	size_t get_x_size(){
		return x_size;
	}

	size_t get_y_size(){
		return y_size;
	}

	template<typename other_t>
	//should this be pass by reference for rhs?
	matrix& operator=(other_t rhs){
		data.resize(rhs.size());
		x_size=rhs.get_x_size();
		y_size=rhs.get_y_size();
		for(int x=0;x<x_size;x++){
			for(int y=0;y<y_size;y++){
				(*this)(x,y)=rhs(x,y);
			}
		}
		return *this;
	}
};

template<typename left_t, typename right_t>
struct mat_add{
	left_t lhs;
	right_t rhs;
	mat_add(left_t lhs, right_t rhs): lhs(lhs), rhs(rhs) {}

	double operator()(size_t x, size_t y){
		return lhs(x,y)+rhs(x,y);
	}

	size_t size(){
		return lhs.size();
	}

	size_t get_x_size(){
		return lhs.get_x_size();
	}

	size_t get_y_size(){
		return lhs.get_y_size();
	}
};


template<typename lhs_t, typename rhs_t>
mat_add<lhs_t, rhs_t> operator+(lhs_t l, rhs_t r){
	return mat_add<lhs_t, rhs_t>(l, r);
}

template<typename mat_t>
struct mat_transpose{
	mat_t mat;
	mat_transpose(mat_t m): mat(m) {}

	double operator()(size_t x, size_t y){
		return mat(y,x);
	}

	size_t size(){
		return mat.size();
	}

	size_t get_x_size(){
		return mat.get_x_size();
	}

	size_t get_y_size(){
		return mat.get_y_size();
	}
};

template<typename mat_t>
mat_transpose<mat_t> transpose(mat_t m){
	return mat_transpose<mat_t>(m);
}