#include <iostream>
#include <time.h>
using namespace std;

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

int main(){
	int a[5]={1,2,3,4,5};
	int b[6]={1,2,3,4,5,6};
	int c[7]={1,2,3,4,5,6,7};
	int d[10]={1,2,3,4,5,6,7,8,9,10};
	int ans;
	binsearch(5,a,3,ans);
	cout<<ans<<endl;
	binsearch(6,b,3,ans);
	cout<<ans<<endl;
	binsearch(7,c,3,ans);
	cout<<ans<<endl;
	binsearch(10, d, 3, ans);
	cout<<ans<<endl;
	return 0;
}


