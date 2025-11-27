#include <bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
string t;
while((int)t.size()<10*n)
{
string s;
if(!(cin>>s))break;
t+=s;
}
vector<unsigned long long>a(n);
for(int i=0;i<n;i++) a[i]=stoull(t.substr(i*10,10));
unsigned long long sum=0;
for(int i=0;i<n;i++) sum+=a[i];
cout<<sum<<"\n";
}
