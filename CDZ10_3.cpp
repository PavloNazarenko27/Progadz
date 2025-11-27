#include<iostream>
using namespace std;
struct Date{int d,m,y;};
void in(Date&a){cin>>a.d>>a.m>>a.y;}
bool leap(int y){return(y%4==0&&y%100!=0)||y%400==0;}
int mdays(int m,int y){int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};if(m==2&&leap(y))return 29;return a[m];}
Date next(Date a){a.d++;if(a.d>mdays(a.m,a.y)){a.d=1;a.m++;if(a.m>12){a.m=1;a.y++;}}return a;}
int dow(Date d){int y=d.y,m=d.m,q=d.d;if(m<=2){m+=12;y--;}int K=y%100,J=y/100,h=(q+13*(m+1)/5+K+K/4+J/4+5*J)%7;return(h+6)%7;}
int main(){
    Date a;
    in(a);
    Date b=next(a);
    cout<<b.d<<" "<<b.m<<" "<<b.y<<"\n"<<dow(a);
    return 0;
}
