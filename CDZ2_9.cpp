#include <iostream>
#include <cmath>
using namespace std;
int main(){
int n,r=0;
cin>>n;
while(pow(2,r)<=n)r++;
cout<<int(pow(2,r));
}
