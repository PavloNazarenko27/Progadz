#include <iostream>
using namespace std;
int main(){
int n;
cin>>n;
int ones=n%10;
int tens=(n/10)%10;
int hundreds=n/100;
if(ones!=tens&&tens!=hundreds&&ones!=hundreds){
cout<<hundreds<<tens<<ones<<endl;
cout<<hundreds<<ones<<tens<<endl;
cout<<tens<<hundreds<<ones<<endl;
cout<<tens<<ones<<hundreds<<endl;
cout<<ones<<hundreds<<tens<<endl;
cout<<ones<<tens<<hundreds;
}
}
