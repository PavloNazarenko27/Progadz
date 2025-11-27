#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
int n;
cin>>n;

cout<<"+++++++++++++++++++++++++++++++++++\n";
for(int i=1;i<=n;i++) cout<<i<<" ";
cout<<"\n+++++++++++++++++++++++++++++++++++\n";

for(int i=1;i<=n;i++)
{
double r=sqrt(i);
if(floor(r)==r) cout<<(int)r<<" ";
else cout<<fixed<<setprecision(2)<<r<<" ";
}
cout<<"\n+++++++++++++++++++++++++++++++++++\n";
return 0;
}

