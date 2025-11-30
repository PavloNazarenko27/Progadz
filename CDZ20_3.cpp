#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main(){
ifstream fin("input.txt");
set<pair<int,int>> s;
int x,y;
char c;
while(fin>>c){
if(c=='('){
fin>>x>>c>>y>>c;
s.insert({x,y});
}
}
for(auto p:s)
cout<<"("<<p.first<<","<<p.second<<")\n";
return 0;
}
