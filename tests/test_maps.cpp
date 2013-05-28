#include <iostream>
#include "../coordinate_maps.hpp"

using namespace std;

int main(){
	const int dim=4;
	z_map zm;
	basic_map bm(dim);
	for(int x=0;x<dim;x++){
		for(int y=0;y<dim;y++){
			cout<<"z "<<zm(x,y)<<endl;
			cout<<"b "<<bm(x,y)<<endl;
		}
	}
}
