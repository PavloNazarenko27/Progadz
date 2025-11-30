#include <iostream>
using namespace std;
template<typename t>
t max2(t a,t b){return a>b?a:b;}
int main(){
int x,y;
cin>>x>>y;
cout<<max2(x,y)<<"\n";
return 0;
}
