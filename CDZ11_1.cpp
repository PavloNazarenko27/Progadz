#include <bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
vector<double>a(n);
for(int i=0;i<n;i++)
cin>>a[i];
string fn;
cin>>fn;
ofstream f(fn);
for(int i=0;i<n;i++)
{
if(i)
f<<" ";
f<<a[i];
}
f.close();
ifstream r(fn);
double x;
bool first=true;
while(r>>x)
{
if(!first)
cout<<",";
cout<<x;
first=false;
}
cout<<"\n";
r.close();
}
