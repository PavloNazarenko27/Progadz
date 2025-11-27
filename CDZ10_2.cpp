#include<iostream>
using namespace std;
struct Square{char f;int r;};
void in(Square&s){cin>>s.f>>s.r;}
bool move(Square a,Square b){
    if(a.f==b.f||a.r==b.r)return 1;
    if(abs(a.f-b.f)==abs(a.r-b.r))return 1;
    return 0;
}
int main(){
    Square a,b;
    in(a);
    in(b);
    cout<<move(a,b);
    return 0;
}
