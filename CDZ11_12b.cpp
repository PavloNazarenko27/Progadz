#include <bits/stdc++.h>
using namespace std;
struct toy
{
char name[30];
double price;
int a;
int b;
};
int main()
{
string f;
string g;
cin>>f>>g;
ifstream fin(f,ios::binary);
ofstream fout(g,ios::binary);
int n;
int m;
cin>>n>>m;
toy t;
vector<string>out;
while(fin.read((char*)&t,sizeof(t)))
if(t.a<=n && t.b>=m) out.push_back(string(t.name));
fin.close();
for(int i=0;i<out.size();i++) cout<<out[i]<<(i+1<out.size()?" ":"");
cout<<"\n";
for(int i=0;i<out.size();i++) fout.write(out[i].c_str(),30);
fout.close();
}
