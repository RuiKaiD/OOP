#include "std_lib_facilities.h"
class vec{
	int sz;
	double* elem;

public:
	vec(int s): sz{s}, elem{new double [s]} {/*.  */}
	~vec(){delete[] elem;}
	double get(int i){return elem[i];}
	void set(int i, double d){elem[i]=d;}


};


void f(int n)
{ 
	vec v(n);
	v.set(2,2.2);//v[2]=2.2;
	vec v2=v;
	v.set(1,9.9);//v[1]=9.9;
	v2.set(0,8.8);//v2[0]=8.8;
	cout << v.get(0) <<' '<< v2.get(1);
}

int main(){
	while(true){
	f(10);
	}
}


/* the destructor called more than once, that produce error */