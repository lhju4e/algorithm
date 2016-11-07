#include <iostream>
#include <time.h>
using namespace std;

void TimeSearch();

int fib(int n)
{
	if(n<=1)
		return n;
	else
		return fib(n-1) + fib(n-2);
}

int main()
{
	TimeSearch(); //TimeSearch 함수 실행
	return 0;
}

void TimeSearch() {
  int n[20];
   const long r[20] = {10000000, 300000, 200000, 20000, 10000, 10000,
  8000, 5000, 5000, 3000, 2000, 2000, 1000, 1000, 800, 750, 700,
  600, 500, 500}; 
  
  for (int j = 0; j < 10; j++)  {// n의 값
  		 n[j] = 5 * j ; //0~9까지는 10씩
	   	n[j+10] = 50 * (j+1);// 10~ 19까지는 300씩 건너뛰었다.
  }
  
  cout <<  "   n   totalTime   runTime" << endl;
  
  for(int j = 0; j < 20; j++)  { // 계산 시간을 구함 
    float start, stop ;
    start = clock();
	for (long b = 1; b <= r[j]; b++)//짧은 사건에 대한 시간을 재기 위해서는 그 사건을 여러 번
     fib(n[j]); 
    stop = clock();
	float totalTime = stop - start ;//실행 시간
    float runTime = (float) (totalTime)/(float)(r[j]) ; // 반복하고, 전체 시간을 반복 횟수로 나눈다.
    cout << "   " << n[j] << "   " << totalTime << "   " << runTime << endl;
  }
  cout << "Times are in hundredths of a second." << endl;
}

