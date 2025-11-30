#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main(){
ifstream fin("input.txt");
map<string,int> m;
string s;
while(fin>>s)
m[s]++;
for(auto p:m)
cout<<p.first<<" "<<p.second<<"\n";
return 0;
}
