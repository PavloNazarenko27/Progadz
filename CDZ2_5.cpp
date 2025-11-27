#include <iostream>
using namespace std;
long long f(int n){
long long r=1;
for(int i=n;i>1;i-=2)r*=i;
return r;
}
int main(){
int n;cin>>n;
cout<<f(n);
}
