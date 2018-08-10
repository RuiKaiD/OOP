#include "std_lib_facilities.h"
class vec{
	int sz;
	double* elem;

public:
	vec(int s): sz{s}, elem{new double [s]} {/*.  */}
	~vec(){delete[] elem;}
	//double get(int i){return elem[i];}
	//void set(int i, double d){elem[i]=d;}

	double& operator[](int n) { return elem[n]; }



	vec(const vec&arg):sz{arg.sz},elem{new double[arg.sz]}
{
	copy(arg.elem,arg.elem+arg.sz,elem);
}



	vec& operator=(const vec& a)//make a vector copy of a
{
	double* p =new double[a.sz];
	copy(a.elem, a.elem+a.sz,p);
	delete[] elem;
	elem=p;
	sz=a.sz;
	return *this; //return self-ref
}





};




void f(int n)
{ 
	vec v(n);
	//v.set(2,2.2);//
	v[2]=2.2;
	vec v2=v;
	//v.set(1,9.9);//
	v[1]=9.999;
	//v2.set(0,8.8);//
	v2[0]=8.8;
	cout << v[0] <<' '<< v2[1]<<' ';
}



int main(){
	int i;
	i=0;
	while(i <10000){
	f(10);
	i++;
	}
}