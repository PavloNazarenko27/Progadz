#include <iostream>
#include <cmath>
using namespace std;
double f(int n){
double r=0;
for(int i=0;i<n;i++)r=sqrt(2+r);
return r;
}
int main(){
int n;cin>>n;
cout<<f(n);
}
