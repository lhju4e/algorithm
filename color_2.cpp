#include <iostream>
#include <string.h>
using namespace std;

void m_coloring(int i);
bool promising(int i);

int n = 25; 
int w[26][26]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0, 0,1,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
{0, 1,0,1,1,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
{0, 1,1,0,1,1, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
{0, 0,1,1,0,1, 0,1,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
{0, 0,0,1,1,0, 0,0,1,0,0, 0,1,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
{0, 0,0,0,0,0, 0,1,0,1,0, 0,0,0,1,0, 0,0,0,0,0, 0,0,0,0,0},
{0, 0,0,0,1,0, 1,0,1,1,1, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
{0, 0,0,0,1,1, 0,1,0,0,0, 1,1,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
{0, 0,0,0,0,0, 1,1,0,0,1, 0,0,0,1,0, 0,0,0,0,0, 0,0,0,0,0},
{0, 0,0,0,0,0, 0,1,0,1,0, 1,0,0,1,1, 0,0,0,0,0, 0,0,0,0,0},
{0, 0,0,0,0,0, 0,0,1,0,1, 0,1,0,0,1, 1,0,0,0,0, 0,0,0,0,0},
{0, 0,0,0,0,1, 0,0,1,0,0, 1,0,1,0,0, 1,1,0,0,0, 0,0,0,0,0},
{0, 0,0,0,0,0, 0,0,0,0,0, 0,1,0,0,0, 0,1,0,0,0, 0,0,0,0,0},
{0, 0,0,0,0,0, 1,0,0,1,1, 0,0,0,0,1, 0,0,1,0,1, 0,0,0,0,0},
{0, 0,0,0,0,0, 0,0,0,0,1, 1,0,0,1,0, 1,0,0,0,1, 1,1,0,0,0},
{0, 0,0,0,0,0, 0,0,0,0,0, 1,1,0,0,1, 0,1,0,0,0, 0,1,0,0,0},
{0, 0,0,0,0,0, 0,0,0,0,0, 0,1,1,0,0, 1,0,0,0,0, 0,0,0,0,0},
{0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,1,0, 0,0,0,1,1, 0,0,0,0,0},
{0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,1,0,1, 0,0,1,0,0},
{0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,1,1, 0,0,1,1,0, 1,0,1,0,0},
{0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1, 0,0,0,0,1, 0,1,0,0,1},
{0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1, 1,0,0,0,0, 1,0,0,0,1},
{0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,1,1, 0,0,0,1,1},
{0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,1,0,1},
{0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 1,1,1,1,0}};

int m = 3;
int vcolor[26];
bool error = true;
int count=0;

int main()
{

	cout<<endl<<"==========출력==="<<endl;
	m_coloring(0);
	if(error == true)
		cout<<"입력 에러(m값이 너무 작거나 그래프 오류)";
	else
		cout<<"해답은"<<count<<"가지입니다."<<endl;
	return 0;
}

void m_coloring(int i)
{
	int color;
	if(promising(i))
		if(i == n){
//			for(int k=1;k<=n;k++)
//				cout<<vcolor[k]<<" ";
//			cout<<endl;
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

