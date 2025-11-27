#include <iostream>
using namespace std;
unsigned short mul(unsigned char x,unsigned char y){
return (unsigned short)x*y;
}
int main(){
unsigned char a,b;
cin>>a>>b;
cout<<mul(a,b);
}
