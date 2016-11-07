#include <iostream>
#include <time.h>
using namespace std;
void TimeSearch();

  int s[1001];

void partition(int low, int high, int& pivotpoint)
{
	int i, j, tmp;
	int pivotitem;

	pivotitem = s[low];
	j = low;
	for(i=low+1;i<=high;i++)
		if(s[i]<pivotitem){
			j++;
			tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
		}
	pivotpoint = j;
	tmp = s[low];
	s[low] = s[pivotpoint];
	s[pivotpoint] = tmp;
}

void quicksort(int low, int high)
{
	int pivotpoint;
	if(high>low){
		partition(low, high, pivotpoint);
		quicksort(low, pivotpoint - 1);
		quicksort(pivotpoint+1, high);
	}
}


int main()
{
	TimeSearch(); //TimeSearch 함수 실행
	return 0;
}

void TimeSearch() {
  int n[20];
   const long r[20] = {10000000, 300000, 200000, 200000, 100000, 100000,
  8000, 5000, 5000, 3000, 2000, 2000, 1000, 1000, 800, 750, 700,
  600, 500, 500}; 
  
  for (int j = 1 ; j <= 1000; j++) // a 초기화
    s[j] = j ;// selectionsort의 최악의 경우는 역순일 경우이다.
  
  for (int j = 0; j < 10; j++)  {// n의 값
  		 n[j] = 10 * j ; //0~9까지는 10씩
	   	n[j+10] = 300 * (j+1);// 10~ 19까지는 300씩 건너뛰었다.
  }
  
  cout <<  "   n   totalTime   runTime" << endl;
  
  for(int j = 0; j < 20; j++)  { // 계산 시간을 구함 
    float start, stop ;
    start = clock();
	for (long b = 1; b <= r[j]; b++)//짧은 사건에 대한 시간을 재기 위해서는 그 사건을 여러 번
      quicksort(0,n[j]);  
    stop = clock();
	float totalTime = stop - start ;//실행 시간
    float runTime = (float) (totalTime)/(float)(r[j]) ; // 반복하고, 전체 시간을 반복 횟수로 나눈다.
    cout << "   " << n[j] << "   " << totalTime << "   " << runTime << endl;
  }
  cout << "Times are in hundredths of a second." << endl;
}

