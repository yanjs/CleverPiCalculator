//Settings:
//Use macro functions?
#define USE_MACRO_FUNCTIONS
#define SHOW_ARCCOS_V2_
#define POWER 16

//Main:
#include <iostream>
#include <iomanip>
#include <cmath>
#define LD long double
#define M1 1
#define M2 pow(10,POWER)
#ifdef USE_MACRO_FUNCTIONS
	#define GetV1(X,Y) (T11*(X)+T12*(Y))
	#define GetV2(X,Y) (T21*(Y)+T22*(X))
#else
	LD T11, T12, T21, T22;
	LD GetV1(LD &, LD &);
	LD GetV2(LD &, LD &);
	inline LD GetV1(LD &v1, LD &v2){
		return T11*v1+T12*v2;
	}
	inline LD GetV2(LD &v1, LD &v2){
		return T21*v2+T22*v1;
	}
#endif
using namespace std;
int main(){
	LD v11 = 0, v21 = -1;
	LD v12 = 0;//, v22 = 0;
#ifdef USE_MACRO_FUNCTIONS
	LD T11, T12, T21, T22;
#endif
	register long long count = 0;
	{
		LD sum = M1 + M2;
		LD min1 = M1 - M2;
		LD min2 = M2 - M1;
		LD M1M1 = 2 * M1;
		LD M2M2 = 2 * M2;
		T11 = min1 / sum;
		T12 = M2M2 / sum;
		T21 = min2 / sum;
		T22 = M1M1 / sum;
	}
	while(v11>v21){
		count++;
		v12 = GetV1(v11, v21);
#ifdef SHOW_ARCCOS_V2
		cout<<acos(v21)<<endl;
#endif
		if(v12>=0)break;
		v21 = GetV2(v11, v21);
		count++;
		v11 = -v12;
	}
	cout<<setbase(10)<<count<<" times\n";
	return 0;
}