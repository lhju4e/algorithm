#include <iostream>
#include <string.h>
using namespace std;

void m_coloring(int i);
bool promising(int i);

int n; 
int **w;
int m;
int *vcolor;
bool error = true;
int count=0;

int main()
{
	cout<<"그래프의 크기를 입력하세요(n값)\n";
	cin>>n;
	w = new int*[n+1];
	for(int i=0;i<n+1;i++)
		w[i] = new int[n+1];
	vcolor = new int[n+1];

	for(int i=0;i<n+1;i++)
		for(int j=0;j<n+1;j++)
		w[i][j] = 0;

	cout<<"그래프를 색칠할 최대 갯수를 입력하세요(m값)\n";
	cin>>m;
	cout<<"그래프를 입력하세요\n";
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>w[i][j];

	cout<<endl<<"==========출력==="<<endl;
	m_coloring(0);
	if(error == true)
		cout<<"입력 에러(m값이 너무 작거나 그래프 오류)";
	else
		cout<<"해답은"<<count<<"가지입니다."<<endl;
	for(int i=0;i<n+1;i++)
		delete [] w[i];
	
	delete [] w;
	delete [] vcolor;	
	return 0;
}

void m_coloring(int i)
{
	int color;
	if(promising(i))
		if(i == n){
			for(int k=1;k<=n;k++)
				cout<<vcolor[k]<<" ";
			cout<<endl;
			error = false;
			count++;
		}
		else
			for(color=1;color<=m;color++){
				vcolor[i+1] = color;
				m_coloring(i+1);
			}
}

bool promising(int i)
{
	int j;
	bool s;

	s = true;
	j = 1;
	while(j<i && s){
		if(w[i][j] && (vcolor[i] == vcolor[j]))
			s = false;
		j++;
	}
	return s;
}

