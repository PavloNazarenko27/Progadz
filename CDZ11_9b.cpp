#include <bits/stdc++.h>
using namespace std;
int main()
{
string f;
string g;
cin>>f>>g;
ifstream fin(f);
vector<int>p;
vector<int>n;
int x;
while(fin>>x) x>0?p.push_back(x):x<0?n.push_back(x):void();
fin.close();
ofstream fout(g);
for(int i=0;i<p.size();i++) fout<<(i?" ":"")<<p[i];
for(int i=0;i<n.size();i++) fout<<(p.size()||i?" ":"")<<n[i];
fout.close();
}
