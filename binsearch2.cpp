#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

void TimeSearch();

int binsearch(int n, const int s[], int x, int& location)
{
	int low, high, mid;

	low = 1; high = n;
	location = 0;
	while(low<=high && location == 0){
		mid = (low + high) / 2;
	if(x==s[mid])
		location = mid;
	else if(x<s[mid])
		high = mid - 1;
	else
		low = mid + 1;
	}
}


int main()
{
	TimeSearch(); //TimeSearch 함수 실행
	return 0;
}

void TimeSearch() {
  int a[1001], n[20];
   const long r[20] = {10000000, 30000000, 20000000, 20000000, 100000000, 10000000,
  8000000, 5000000, 5000000, 3000000, 2000000, 2000000, 1000000, 1000000, 800000, 750000, 700000,
  600000, 400000, 300000}; 
  
  for (int j = 1 ; j <= 1000; j++) // a 초기화
    a[j] =  j ;
  
  for (int j = 0; j < 10; j++)  {// n의 값
  		 n[j] = 10 * j ; //0~9까지는 10씩
	   	n[j+10] = 100 * (j+1);// 10~ 19까지는 300씩 건너뛰었다.
  }
  
  cout <<  "   n   totalTime   runTime" << endl;
 int ans=0; 
  for(int j = 0; j < 20; j++)  { // 계산 시간을 구함 
    float start, stop ;
    start = clock();
	for (long b = 1; b <= r[j]; b++)//짧은 사건에 대한 시간을 재기 위해서는 그 사건을 여러 번
    	binsearch(n[j], a, 0, ans);
	stop = clock();
	long totalTime = stop - start ;//실행 시간
    float runTime = (float) (totalTime)/(float)(r[j]) ; // 반복하고, 전체 시간을 반복 횟수로 나눈다.
    cout << "   " << n[j] << "   " << totalTime << "   ";
  	printf("%e\n", runTime);
  }
  cout << "Times are in hundredths of a second." << endl;
}

