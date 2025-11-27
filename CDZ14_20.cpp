#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main()
{
int n1;
int n2;
string finame;
string foutname;
cin>>n1>>n2>>finame>>foutname;
ifstream fin(finame);
if(!fin){cout<<"не виконується\n";ofstream fout(foutname);fout<<"не виконується\n";return 0;}
vector<string>lines;
string t;
while(getline(fin,t)) lines.push_back(t);
fin.close();
int n=lines.size();
if(n1<1||n2<1||n1>n||n2>n||abs(n1-n2)<=1){cout<<"не виконується\n";ofstream fout(foutname);fout<<"операцію неможливо виконати\n";return 0;}
int lo=min(n1,n2);
int hi=max(n1,n2);
vector<string>out;
for(int i=0;i<n;i++) if(i+1<=lo||i+1>=hi) out.push_back(lines[i]);
ofstream fout(foutname);
for(int i=0;i<out.size();i++) fout<<out[i]<<"\n";
fout.close();
return 0;
}
