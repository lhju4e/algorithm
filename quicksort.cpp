#include <iostream>
#include <time.h>
using namespace std;

int s[10] = {30, 40, 15, 22, 13, 27, 12, 10, 20, 25};
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

int main(){
	quicksort(0, 9);
	for(int i=0;i<10;i++)
		cout<<s[i]<<" ";

	return 0;
}


