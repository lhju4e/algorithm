#include <iostream>
#include <cmath>
using namespace std;

void travel(int n, const int w[5][5]);
int min(int a, int b);

int main()
{
	int w[5][5] = {
					{100,100,100,100,100},
					{100},
					{100},
					{100},
					{100}
	}; 		//100은 경로가 없다는 뜻, 그래프배열w. 4*4행렬이지만 1부터 4까지 쓰기 위해 5*5로 선언
			//쓰지 않는 배열도 100값을 주었음
	cout<<"경로가 없는 곳은 100을 입력하시오."<<endl;
	for(int i=1;i<5;i++)
		for(int j=1;j<5;j++)
		cin>>w[i][j];
	travel(4, w);
	
	return 0;
}

void travel(int n, const int w[5][5])//n=4, 안타깝지만 크기가 4인 그래프밖에 못함.ㅠㅠ
{
	int minleng, p[5][16];
	int i = 0, j = 0, k = 0, a = 0;
	int d[n+1][16]; //배열은 항상 +1
	int dd[n+1][16]; //배열은 항상 +1
	int v = 15, p1, p2, p3;

	for(int t=0;t<5;t++){
		for(i=0;i<16;i++){
			d[t][i] = 100;
			dd[t][i]=100;}
	} //배열 초기화..

	for(i=2;i<=n;i++)
		d[i][0] = w[i][1];	

	for(a=2;a<=12;a+=2)
	{
		for(j=2;j<=n;j++)
		{
			for(i=2;i<=n;i++)
			{
				if(i!=j)
				{
					dd[i][a] = w[i][j] + d[j][a-(int)pow(2,j-1)]; //d[i][a]에 최솟값을 넣기 위한 저장배열 dd
					d[i][a] = min(d[i][a],dd[i][a]);
				}
				if(d[i][a] == w[i][j] + d[j][a-(int)pow(2,j-1)])
					p[i][a] = j; // 최소일 때(d[i][a]에 들어갈 때)의 j값
			}
		}
	}

	for(j=2;j<=n;j++)
	{
		dd[1][v-1] = w[1][j]+d[j][v-1-(int)pow(2,j-1)];
		d[1][v-1] = min(dd[1][v-1], d[1][v-1]);
		if(d[1][v-1] == w[1][j]+d[j][v-1-(int)pow(2,j-1)])
			p[1][v-1] = j;
	}

	minleng = d[1][v-1];
	cout<<"minlength : " << minleng<<endl;
	p1 = p[1][14];
	p2 = p[p1][14-(int)pow(2,p1-1)];
	p3 = p[p2][14-(int)pow(2,p1-1)-(int)pow(2,p2-1)];
	cout<<"path: 1 "<<p1<<" "<<p2<<" "<<p3<<" 1"<<endl;
	

}

int min(int a, int b)
{
	if(a>b)
		return b;
	else
		return a;
}
