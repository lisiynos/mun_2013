#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    long long n,m;
    //freopen("erd.in","r",stdin);
    //freopen("erd.out","w",stdout);
    cin>>n>>m;
    long long z[n];
    for(long long i=0;i<n;i++){
        cin>>z[i];
    }
    long long p[n];
    for (long long i=0;i<n;i++){
        p[i]=m%(i+1);
    }
    long long flag;
    long long h;
    for (long long i=0;i<100000000000;i++){
    flag=0;
    for (long long j=0; j<n;j++){
        h=i%(j+1);
        if (z[j]==((p[j]-h)%(j+1))){
            flag+=1;
        }else{
            break;}
    }
    if (flag==n){
        if ((m-i)>0){
            cout<<(m-i)<<endl;
            exit(0);}
            }
    flag=0;
    for (long long j=0;j<n;j++){
        h=i%(j+1);
        if (z[j]==(p[j]+h)%(j+1)){
            flag+=1;}
        else{
            break;  }
    }
    if (flag==n){
        cout<<(m+i)<<endl;
        exit(0);
    }

}
}
