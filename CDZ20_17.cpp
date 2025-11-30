#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main(){
vector<string> v;
int n;
cin>>n;
v.resize(n);
for(int i=0;i<n;i++) cin>>v[i];
multimap<char,string> m;
for(const auto& w:v) m.insert({w.size()>=2?w[1]:w[0],w});
for(const auto& p:m) cout<<p.first<<" "<<p.second<<"\n";
}
