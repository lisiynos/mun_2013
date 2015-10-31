#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    freopen("abt.in","r",stdin);
    freopen("abt.out","w",stdout);
    int n,a,b;
    cin >> n;
    a=ceil(sqrt(n))-1;
    b=ceil(sqrt(n));
    if(a!=b&&a>0&&b>0&&a*b==n)
    cout << a << " "<<b;
    else
    cout << "-1 -1";

    return 0;
}
