#include<iostream>
using namespace std;
struct rat{int n;unsigned d;};
int gcd(int a,int b){if(a<0)a=-a;while(b){int t=a%b;a=b;b=t;}return a;}
rat norm(rat x){int g=gcd(x.n,(int)x.d);if(g==0)return x;x.n/=g;x.d/=g;if((int)x.d<0){x.n=-x.n;x.d=-x.d;}return x;}
rat add(rat a,rat b){rat r;r.n=a.n*b.d+b.n*a.d;r.d=a.d*b.d;return norm(r);}
rat mul(rat a,rat b){rat r;r.n=a.n*b.n;r.d=a.d*b.d;return norm(r);}
int cmp(rat a,rat b){int l=a.n*b.d,r=b.n*a.d;if(l==r)return 0;return l>r?1:-1;}
void in(rat&r){cin>>r.n>>r.d;}
void out(rat r){cout<<r.n<<"/"<<r.d;}
int main(){
    rat a,b;
    in(a);
    in(b);
    out(add(a,b));cout<<"\n";
    out(mul(a,b));cout<<"\n";
    cout<<cmp(a,b);
    return 0;
}
