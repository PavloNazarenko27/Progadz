#include <iostream>
#include <cmath>
using namespace std;
double eReLu(double a,double x){
return (x<0)?a*(exp(x)-1):0;
}
int main(){
double a,x;cin>>a>>x;
cout<<eReLu(a,x);
}
