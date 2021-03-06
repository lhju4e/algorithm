#include <iostream>
#include <time.h>
using namespace std;
void selectionSort(int *, const int);
void TimeSearch();

int main()
{
	TimeSearch(); //TimeSearch 함수 실행
	return 0;
}

void TimeSearch() {
  int a[3001], n[20];
   const long r[20] = {10000000, 300000, 200000, 200000, 100000, 100000,
  80000, 50000, 50000, 30000, 20000, 20000, 10000, 10000, 8000, 7500, 7000,
  6000, 5000, 5000}; 
  
  for (int j = 1 ; j <= 3000; j++) // a 초기화
    a[j] = 3001 - j ;// selectionsort의 최악의 경우는 역순일 경우이다.
  
  for (int j = 0; j < 10; j++)  {// n의 값
  		 n[j] = 10 * j ; //0~9까지는 10씩
	   	n[j+10] = 300 * (j+1);// 10~ 19까지는 300씩 건너뛰었다.
  }
  
  cout <<  "   n   totalTime   runTime" << endl;
  
  for(int j = 0; j < 20; j++)  { // 계산 시간을 구함 
    float start, stop ;
    start = clock();
	for (long b = 1; b <= r[j]; b++)//짧은 사건에 대한 시간을 재기 위해서는 그 사건을 여러 번
      selectionSort(a, n[j]);  
    stop = clock();
	float totalTime = stop - start ;//실행 시간
    float runTime = (float) (totalTime)/(float)(r[j]) ; // 반복하고, 전체 시간을 반복 횟수로 나눈다.
    cout << "   " << n[j] << "   " << totalTime << "   " << runTime << endl;
  }
  cout << "Times are in hundredths of a second." << endl;
}

void selectionSort(int*a, const int n) // 책의 코드 참조
{
	for(int i=0; i<n; i++)
	{
		int j = i;
		for(int k=i+1; k<n; k++)
			if(a[k] < a[j]) j = k;
		swap(a[i], a[j]);
	}
}

