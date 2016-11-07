#include <iostream>
#include <time.h>
using namespace std;

void TimeSearch();
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

int main()
{
	TimeSearch(); //TimeSearch 함수 실행
	return 0;
}

void TimeSearch() {
  int a[1001], n[20];
   const long r[20] = {10000000, 300000, 200000, 200000, 100000, 100000,
  80000, 50000, 50000, 30000, 20000, 20000, 10000, 10000, 8000, 7500, 7000,
  6000, 5000, 5000}; 
  
  for (int j = 1 ; j <= 1000; j++) // a 초기화
    a[j] = j ;// selectionsort의 최악의 경우는 역순일 경우이다.
  
  for (int j = 0; j < 10; j++)  {// n의 값
  		 n[j] = 10 * j ; //0~9까지는 10씩
	   	n[j+10] = 100 * (j+1);// 10~ 19까지는 300씩 건너뛰었다.
  }
  
  cout <<  "   n   totalTime   runTime" << endl;
  
  for(int j = 0; j < 20; j++)  { // 계산 시간을 구함 
    float start, stop ;
    start = clock();
	for (long b = 1; b <= r[j]; b++)//짧은 사건에 대한 시간을 재기 위해서는 그 사건을 여러 번
      mergesort(n[j], a);  
    stop = clock();
	float totalTime = stop - start ;//실행 시간
    float runTime = (float) (totalTime)/(float)(r[j]) ; // 반복하고, 전체 시간을 반복 횟수로 나눈다.
    cout << "   " << n[j] << "   " << totalTime << "   " << runTime << endl;
  }
  cout << "Times are in hundredths of a second." << endl;
}

