#include<iostream>
#include<string>
using namespace std;
struct peak{string n;int h;};
void in(peak&p){cin>>p.n>>p.h;}
void out(peak p){cout<<p.n<<" "<<p.h<<"\n";}
int main(){
    int N;
    cin>>N;
    peak a[100];
    for(int i=0;i<N;i++)in(a[i]);
    int mx=0;
    for(int i=1;i<N;i++)if(a[i].h>a[mx].h)mx=i;
    cout<<a[mx].n<<"\n";
    string s;
    cin>>s;
    bool f=0;
    for(int i=0;i<N;i++)
        if(a[i].n==s){cout<<a[i].h;f=1;}
    if(!f)cout<<"not found";
    return 0;
}
