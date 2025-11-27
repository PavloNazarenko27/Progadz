#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
double x;
cin>>x;
double y=pow(x,8);
cout<<setw(24)<<fixed<<setprecision(4)<<y;
return 0;
}