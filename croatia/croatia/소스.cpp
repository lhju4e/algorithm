#include <iostream>
#include <string>
using namespace std;
int main() {
	string a;
	cin >> a;
	int count = 0;
	for(int i=0;i<a.length(); i++)
	{
		if (a[i] == '=')
			continue;
		else if (a[i] == '-')
			continue;
		else if ((a[i] == 'z') && (i != 0)) {
			if (a[i - 1] == 'd')
				continue;
		}
		else if ((a[i] == 'j') && (i != 0))
			if ((a[i - 1] == 'l') || a[i - 1] == 'n')
				continue;
		count++;
	}
	std::cout << count;
	return 0;
}