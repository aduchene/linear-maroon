#include <climits>
#include <algorithm>

unsigned int next_power2(unsigned int n){
	n--;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	return n+1;
}

struct z_map{
	unsigned int side_size; //z map is square

	z_map(unsigned int row_size, unsigned int col_size){
		side_size=next_power2(std::max(row_size,col_size));
	}


	//Morton z-order curve from Anderson
	unsigned int operator()(unsigned int x, unsigned int y){
	unsigned int z=0; //z curve value
		for(int i=0;i<sizeof(x)*CHAR_BIT/2;i++){
			z |= (x & 1U << i) << i | (y & 1U << i) << (i + 1);
		}
		return z;
	}

	unsigned int max_index(){
		return side_size*side_size;
	}
};

struct basic_map{
	unsigned int row_size, col_size;

	basic_map(unsigned int row_size, unsigned int col_size): row_size(row_size) {}

	unsigned int operator()(unsigned int x, unsigned int y){
		return y*row_size+x;
	}

	unsigned int max_index(){
		return row_size*col_size;
	}
};