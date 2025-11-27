#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    float f1=1e-4,f2=24.33E5,f3=M_PI,f4=M_E,f5=sqrt(5),f6=log(100);
    double d1=1e-4,d2=24.33E5,d3=M_PI,d4=M_E,d5=sqrt(5),d6=log(100);
    long double ld1=1e-4,ld2=24.33E5,ld3=M_PI,ld4=M_E,ld5=sqrt(5),ld6=log(100);
    cout<<fixed<<setprecision(2);
    cout<<"float: "<<f1<<" "<<f2<<" "<<f3<<" "<<f4<<" "<<f5<<" "<<f6<<endl;
    cout<<"double: "<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<" "<<d5<<" "<<d6<<endl;
    cout<<"long double: "<<ld1<<" "<<ld2<<" "<<ld3<<" "<<ld4<<" "<<ld5<<" "<<ld6;
    return 0;
}
