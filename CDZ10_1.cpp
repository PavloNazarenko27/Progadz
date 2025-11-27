#include<iostream>
using namespace std;
struct Date{int d,m,y;};
void in(Date&a){cin>>a.d>>a.m>>a.y;}
void out(Date a){cout<<a.d<<" "<<a.m<<" "<<a.y;}
struct Square{char f;int r;};
void in(Square&s){cin>>s.f>>s.r;}
void out(Square s){cout<<s.f<<s.r;}
struct Point{double x,y;};
void in(Point&p){cin>>p.x>>p.y;}
void out(Point p){cout<<p.x<<" "<<p.y;}
struct Rect{Point a,b;};
void in(Rect&r){in(r.a);in(r.b);}
void out(Rect r){out(r.a);cout<<" ";out(r.b);}
struct Poly{int n;double c[100];};
void in(Poly&p){cin>>p.n;for(int i=0;i<=p.n;i++)cin>>p.c[i];}
void out(Poly p){for(int i=0;i<=p.n;i++)cout<<p.c[i]<<" ";}
int main(){return 0;}
