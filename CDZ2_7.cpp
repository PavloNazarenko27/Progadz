#include <iostream>
using namespace std;
int main(){
int n;double x,s=1,t=1;
cin>>x>>n;
for(int i=1;i<=n;i++){t*=x/i;s+=t;}
cout<<s;
}