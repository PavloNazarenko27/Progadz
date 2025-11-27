#include <iostream>
#include <cmath>
using namespace std;
int main(){
double a,b,c;
cin>>a>>b>>c;
double d=b*b-4*a*c;
if(d<0)cout<<"no roots";
else if(d==0){
double x2=-b/(2*a);
if(x2<0)cout<<"no roots";
else if(x2==0)cout<<0;
else cout<<sqrt(x2)<<" "<<-sqrt(x2);
}
else{
double x21=(-b+sqrt(d))/(2*a);
double x22=(-b-sqrt(d))/(2*a);
if(x21>=0){
cout<<sqrt(x21)<<" "<<-sqrt(x21)<<" ";
}
if(x22>=0){
cout<<sqrt(x22)<<" "<<-sqrt(x22);
}
}
}
