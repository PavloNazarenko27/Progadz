#include <iostream>
#include <cmath>
using namespace std;
int main(){
double x;
cin>>x;
int c=(int)x;
double d=x-c;
cout<<"whole part:"<<c<<"\n";
cout<<"frac part:"<<d<<"\n";
cout<<"floor:"<<floor(x)<<"\n";
cout<<"ceil:"<<ceil(x)<<"\n";
cout<<"round:"<<round(x);
return 0;
}
