#include <iostream>
#include <cmath>
using namespace std;
int main(){
int n;double x,s=0;
cin>>n>>x;
for(int i=1;i<=n;i++)s+=i*pow(x,i);
cout<<s;
}
