#include <iostream>
#include <iomanip>
using namespace std;
int main(){
int a1=1,a2=2,a3=3,a4=2,a5=1;
double b1=1.1,b2=2.8,b3=5.0,b4=4.4,b5=2.1;
cout<<"x | "<<a1<<" | "<<a2<<" | "<<a3<<" | "<<a4<<" | "<<a5<<" |\n";
cout<<"- | -- | -- | -- | -- | -- |\n";
cout<<"y | "<<fixed<<setprecision(1)<<b1<<" | "<<b2<<" | "<<b3<<" | "<<b4<<" | "<<b5<<" |";
return 0;
}