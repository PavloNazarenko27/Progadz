#include <iostream>
#include <iomanip>
using namespace std;
int main(){
double a,b;
cin>>a>>b;
double ar=(a+b)/2;
double har=2.0/(1.0/a+1.0/b);
cout<<scientific<<setprecision(6)<<ar<<"\n";
cout<<fixed<<setprecision(2)<<ar<<"\n";
cout<<scientific<<setprecision(6)<<har<<"\n";
cout<<fixed<<setprecision(2)<<har;
return 0;
}