#include <iostream>
#include <cmath>
using namespace std;
int main(){
double eps;cin>>eps;
double pi=0.0;
for(int k=0;;k++){
double term=pow(-1,k)/pow(3,k)/(2*k+1);
if(abs(term)<eps)break;
pi+=term;
}
pi*=2*sqrt(3);
cout<<pi;
}
