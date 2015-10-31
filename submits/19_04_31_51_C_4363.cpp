#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct point{
int x;
int y;
};
double lenght(point a, point b){
int dy, dx;
dy=(a.y-b.y);
dx=(a.x-b.x);
return sqrt(dy*dy+dx*dx);
}
double sq(point a, point b, point c){
double a1,b1,c1,p;
a1=sqrt((a.y-b.y)*(a.y-b.y)+(a.x-b.x)*(a.x-b.x));
b1=sqrt((a.y-c.y)*(a.y-c.y)+(a.x-c.x)*(a.x-c.x));
c1=sqrt((b.y-c.y)*(b.y-c.y)+(b.x-c.x)*(b.x-c.x));
p=(a1+b1+c1)/2;
return sqrt(p*(p-a1)*(p-b1)*(p-c1));
}
int main()
{
    freopen("cord.in","r",stdin);
    freopen("cord.out","w",stdout);
    point cur, pr[2],tr[3],lab,kar;
    int r;
    kar.x=0;
    kar.y=0;
    lab.x=1000;
    lab.y=1000;
    scanf("%d%d%d",&cur.x, &cur.y,&r);
    scanf("%d%d%d%d", &pr[0].x , &pr[0].y , &pr[1].x , &pr[1].y);
    scanf("%d%d%d%d%d%d", &tr[0].x , &tr[0].y , &tr[1].x , &tr[1].y , &tr[2].x , &tr[2].y);
    int freq=0;
    if(lenght(kar,cur)<(double)r)
        freq++;
    if(pr[0].x < kar.x && kar.x< pr[1].x && pr[0].y < kar.y && kar.x< pr[1].y)
        freq++;
   double s1,s2,s3,s0;
   s1=sq(tr[0],tr[1],kar);
   s2=sq(tr[0],tr[2],kar);
   s3=sq(tr[2],tr[1],kar);
   s0=sq(tr[0],tr[1],tr[2]);
   if(abs(s0-s1-s2-s3)<0.0001)
    freq++;
   cout << freq;
   return 0;
}
