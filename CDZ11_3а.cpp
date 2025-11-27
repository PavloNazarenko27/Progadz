#include <bits/stdc++.h>
using namespace std;
int main()
{
string f,g;
cin>>f>>g;
ofstream ff(f);
int x;
while(cin>>x)
{
if(x==0)
break;
ff<<x<<" ";
}
ff.close();
ifstream fin(f);
ofstream fg(g);
bool first=true;
while(fin>>x)
{
if(x%2==0)
{
if(!first)
fg<<" ";
fg<<x;
first=false;
}
}
fin.close();
fg.close();
}
