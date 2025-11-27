#include <iostream>
#include <cmath>
using namespace std;
double f(double x,int n){
double s=0;
for(int i=0;i<=n;i++)s+=pow(x,i);
return s;
}
int main(){
cout<<f(2,3);
}
