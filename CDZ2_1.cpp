#include <iostream>
#include <cmath>
using namespace std;
double f(double x,int n){
for(int i=0;i<n;i++)x=sin(x);
return x;
}
int main(){
double x;int n;
cin>>x>>n;
cout<<f(x,n);
}
