#include <iostream>
#include <cmath>
using namespace std;
int main(){
double x,eps;
cin>>x>>eps;
double term=1.0;
double sum=0.0;
int k=0;
int cnt=0;
while(fabs(term)>=eps){
sum+=term;
cnt++;
k++;
term*=x*x/((2*k-1)*(2*k));
}
cout<<sum<<endl<<cnt;
}
