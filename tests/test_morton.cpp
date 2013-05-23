#include <iostream>
#include <climits>
#include <bitset>
#include <chrono>
#include <functional>
#include <random>
using namespace std;

#include "morton.hpp"

template<typename T>
void show_binrep(const T& a)
{
    const char* beg = reinterpret_cast<const char*>(&a);
    const char* end = beg + sizeof(a);
    while(beg != end)
        std::cout << std::bitset<CHAR_BIT>(*beg++) << ' ';
    std::cout << '\n';
}

template<typename F>
void benchmark(F task, string name){
	auto start=chrono::high_resolution_clock::now();
	task();
	auto end=chrono::high_resolution_clock::now();
	cout<<name<<" took nanoseconds:"<<endl;	
	cout<<chrono::duration_cast<chrono::nanoseconds>(end-start).count()<<endl;
}

template<typename fun, typename rng_t>
void repeat_morton(fun f,rng_t rng){
	for(int i=0;i<1000000;i++){
		f(rng(),rng());
	}
}

int main(){
	auto start=chrono::high_resolution_clock::now();
	unsigned int x=11;
	unsigned int y=22;
	//cin>>x>>y;
	unsigned int z=morton_magic(x, y);
	benchmark(bind(morton_magic,x,y), "magic");
	show_binrep(x);
	show_binrep(y);
	show_binrep(z);
	auto end=chrono::high_resolution_clock::now();
	cout<<chrono::duration_cast<chrono::nanoseconds>(end-start).count()<<endl;
	default_random_engine gen;
	uniform_int_distribution<int> dist(0,256);
	auto rng=bind(dist,gen);
	repeat_morton(morton_basic,rng);
	benchmark([rng](){repeat_morton(morton_basic, rng);},"basic");
	benchmark([rng](){repeat_morton(morton_magic, rng);},"magic");
	return 0;
}