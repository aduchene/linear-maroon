#include <chrono>
#include <iostream>
using namespace std;

template<typename F>
void benchmark(F task, string name){
	auto start=chrono::high_resolution_clock::now();
	task();
	auto end=chrono::high_resolution_clock::now();
	cout<<name<<" took nanoseconds:"<<endl;	
	cout<<chrono::duration_cast<chrono::nanoseconds>(end-start).count()<<endl;
}

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