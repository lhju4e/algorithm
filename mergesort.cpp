#include <iostream>
#include <time.h>
using namespace std;

void mergesort(int, int*);
void merge(int, int, const int [], const int[], int []);

void mergesort(int n, int s[])
{
	int m=0;

	if(n>1)
	{
		const int h = n/2;
		m = n - h;
		int u[h], v[m];
		for(int i=0;i<h;i++)
			u[i] = s[i];
		for(int j=0;j<m;j++)
			v[j] = s[h+j];
		mergesort(h, u);
		mergesort(m, v);
		merge(h, m, u, v, s);
	}
}

void merge(int h, int m, const int u[], const int v[], int s[])
{
	int i, j, k;

	i = 0; j = 0; k = 0;
	while(i<h && j<m){
		if(u[i] < v[j]){
			s[k] = u[i];
			i++;
		}
		else{
			s[k] = v[j];
			j++;
		}
		k++;
	}
	if(i >= h)
		for(int a=k;j<m;j++){
			s[a] = v[j];
			a++;}
	else
		for(int a=k;i<h;i++){
			s[a] = u[i];a++;}
}

int main(){
	int a[5] = {3,2,4,5,1};
	mergesort(5, a);
	for(int i=0;i<5;i++)
		cout<<a[i]<<" ";
	return 0;
}

