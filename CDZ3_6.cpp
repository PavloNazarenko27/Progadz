#include <iostream>
#include <cmath>
using namespace std;
int main(){
double a,b,c;
cin>>a>>b>>c;
double maxv=a,minv=a;
if(fabs(b)>fabs(maxv))maxv=b;
if(fabs(c)>fabs(maxv))maxv=c;
if(fabs(b)<fabs(minv))minv=b;
if(fabs(c)<fabs(minv))minv=c;
cout<<"max="<<maxv<<" min="<<minv;
}
