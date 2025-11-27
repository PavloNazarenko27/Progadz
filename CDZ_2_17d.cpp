#include <iostream>
#include <cmath>
using namespace std;
double gauss(double x){
return exp(-x*x);
}
double gaussder(double x){
return -2*x*exp(-x*x);
}
int main(){
double x;
cin>>x;
cout<<gauss(x)<<endl;
cout<<gaussder(x);
}
