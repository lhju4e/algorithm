#include <iostream>
#include <time.h>
using namespace std;
int seqsearch(int*, const int, const int);

void Timesearch(){
	int a[1001], n[20];
	const long r[20] = {10000000, 3000000, 2000000, 2000000, 1000000, 1000000, 1000000, 800000, 800000, 800000, 
						800000, 700000, 700000, 700000, 600000, 600000, 500000, 400000, 300000, 300000};
	for(int j=1;j<=1000;j++)
		a[j] = j;

	for(int j=0;j<10;j++){
		n[j] = 10*j;
		n[j+10]=100*(j+1);
	}
	
	cout << "	n	totalTime	runTime" <<endl;
	for(int j=0;j<20;j++)
	{
		float start, stop;
		start = clock();
		for(long b = 1;b<=r[j];b++)
		int k = seqsearch(a, n[j], 0);
			stop = clock();
		long totalTime = stop - start;
		float runTime = (float)(totalTime)/(float)(r[j]);
		cout<<"      "<<n[j] << "         " << totalTime << "        " << runTime << endl;
	}
	cout << "Times are in hundreths of a second." << endl;
}

int seqsearch(int *a, const int n, const int x)
{
	int i;
	for(i=0;i<n && a[i]!=x;i++);
	if(i==n) return -1;
	else return i;
}

int main()
{
	Timesearch();
	return 0;
}
