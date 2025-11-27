#include <iostream>
using namespace std;
int main(){
int n;
cin>>n;
int ones=n%10;
int tens=(n/10)%10;
int hundreds=n/100;
cout<<ones<<" "<<tens<<" "<<hundreds<<endl;
cout<<ones+tens+hundreds<<endl;
cout<<ones*100+tens*10+hundreds;
}
