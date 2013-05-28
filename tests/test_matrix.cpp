#include "../matrix.hpp"

#include <iostream>
using namespace std;

template<typename T>
void print_mat(T mat){
	cout<<"Dimensions "<<mat.get_x_size()<<", "<<mat.get_y_size()<<endl;
	cout<<"Size "<<mat.size()<<endl;
	cout<<"Contents:"<<endl;
	for(int y=0;y<mat.get_y_size();y++){
		for(int x=0;x<mat.get_x_size();x++){
			cout<<mat(x,y)<<" ";
		}
		cout<<endl;
	}
	// cout<<"Raw data:"<<endl;
	// for(auto elem:mat.data){
	// 	cout<<elem<<" ";
	// }
	cout<<endl;
}

int main(){
	matrix<basic_map> bm={{{1,2},{3,4}}};
	matrix<basic_map> bm2={{{6,2},{3,8}}};
	bm=bm2+bm2;
	print_mat(bm);
	print_mat(transpose(bm));
	return 0;
}