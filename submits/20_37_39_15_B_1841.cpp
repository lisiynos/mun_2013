#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{
	freopen("berg.in", "r", stdin);
	freopen("berg.out", "w", stdout);
	string s;
	cin >> s;
	if (s.size() % 2 == 0) 
		cout << "Suspicious!";  	              
	else
	{	
		for (int i = 1; i < s.size(); i += 2)
			if (s[i] != 'a')
			{
				cout << "Suspicious!";
				return 0;
			}
		for (int i = 0; i < s.size(); i += 2)
			cout << s[i];
	}
	return 0;
}