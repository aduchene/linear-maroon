#include "../matrix.hpp"

#include <iostream>
using namespace std;

template<typename T>
void print_mat(T mat){
	cout<<"Dimensions "<<mat.x_size<<", "<<mat.y_size<<endl;
	cout<<"Size "<<mat.size()<<endl;
	cout<<"Contents:"<<endl;
	for(int y=0;y<mat.y_size;y++){
		for(int x=0;x<mat.x_size;x++){
			cout<<mat(x,y)<<" ";
		}
		cout<<endl;
	}
	cout<<"Raw data:"<<endl;
	for(auto elem:mat.data){
		cout<<elem<<" ";
	}
	cout<<endl;
}

int main(){
	matrix<basic_map> bm={{{1,2},{3,4}}};
	matrix<basic_map> bm2={{{6,2},{3,8}}};
	bm=bm2+bm2;
	print_mat(bm);
	return 0;
}