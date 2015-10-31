#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
#define S(x) cout<<x;
#define D(x) cout<<endl<<x<<endl;
using namespace std;


int main(){
//freopen("cord.in","r",stdin);
//freopen("cord.out","w",stdout);
string s;
int c,n,q,i,j,man,l;
cin>> n>> q;
int ar[n][q*2];
int a[n],k[q*2];
for (i=0; i<n; i++)
    cin>>a[i];
for (i=0; i<n; i++)
    for (j=0; j<=q*2; j++){
        ar[i][j]=(j)%(i+1);
}
for (i=0; i<q*2; i++)
    k[i]=0;
for (i=0; i<q*2; i++){
    c=0;
    for (j=0; j<n; j++)
            if (ar[i][j]==a[i])
            c++;
    if (c==n)
        k[i]=i;
}
man=q*3;
for (i=0; i<q*2; i++)
    S(k[i]);
    if (fabs(q-k[i])<man){
        man=fabs(q-k[i]);
        l=i;
    }
cout<<k[l];
}