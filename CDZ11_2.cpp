#include <bits/stdc++.h>
using namespace std;
int main()
{
string f,g;
double a,x;
cin>>f>>g>>a;
ifstream fin(f);
vector<double>s;
vector<double>r;
while(fin>>x)
{
if(fabs(x)<a)
s.push_back(x);
else
r.push_back(x);
}
fin.close();
ofstream fg(g);
for(int i=0;i<s.size();i++)
{
if(i)
fg<<" ";
fg<<s[i];
}
fg.close();
ofstream ff(f);
for(int i=0;i<r.size();i++)
{
if(i)
ff<<" ";
ff<<r[i];
}
ff.close();
}
