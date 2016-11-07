#include <iostream>
#include <time.h>
using namespace std;

int fib(int n)
{
	int i;
	int f[n];
	
	f[0] = 0;
	if(n>0) {
		f[1] = 1;
		for (i=2;i<=n;i++)
			f[i] = f[i-1] + f[i-2];
	}
	return f[n];
}

int main(){
	cout<<fib(2)<<endl;
	return 0;
}
