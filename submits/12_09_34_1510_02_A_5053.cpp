#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  //freopen("abt.in", "r", stdin);

  //freopen("abt.out", "w", stdout);


  int n,l=0,k;
  cin >> n;

    l=floor(sqrt(n));
    k=l+1;
  if(k*l==n){cout<<l<<" "<<k<<endl; return 0;}
    /*{l=n/i;
    if (l*i==n)
  {
  if(l==i+1){cout<<i<<" "<<l<<endl; return 0;}}}
 */
 cout <<-1<<" "<<-1<<endl;
  return 0;
}