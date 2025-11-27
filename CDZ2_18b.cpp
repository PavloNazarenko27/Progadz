#include <iostream>
using namespace std;
double fact(int n){
if(n<=1)return 1;
return n*fact(n-1);
}
double term(double x,int k){
return pow(x,2*k)/fact(2*k);
}
int main(){
double x;int n;
cin>>x>>n;
for(int k=0;k<n;k++)cout<<term(x,k)<<"\n";
}

