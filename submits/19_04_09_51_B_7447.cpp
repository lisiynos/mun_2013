#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
 string s,b;
int main()
{
    freopen("berg.in","r",stdin);
    freopen("berg.out","w",stdout);
   cin >> s;
   for(int i=0;i<s.length();i++){
    if(i%2==1&&s[i]!='a'){
        cout << "Suspicious!";
        return 0;
    }
    if(i%2==0)
    b+=s[i];
   }
   cout << b;
    return 0;
}
