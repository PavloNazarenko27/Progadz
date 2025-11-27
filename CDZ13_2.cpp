#include <iostream>
#include <string>
using namespace std;
int main(){
string s;
getline(cin,s);
int n=s.size();
int first=-1,last=-1;
for(int i=0;i<n;i++){
    if(s[i]=='.' && first==-1) first=i;
    if(s[i]=='.') last=i;
}
for(int i=0;i<n;i++){
    if(i>first && i<last) cout<<s[i];
    else cout<<s[i];
}
}
