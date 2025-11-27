#include <iostream>
#include <string>
using namespace std;
int main(){
string s;
getline(cin,s);
int n=s.size();
string w="";
for(int i=0;i<n;i++){
    if(s[i]!=' '){
        w+=s[i];
    } else{
        if(w.size()>0) w.pop_back();
        cout<<w<<" ";
        w="";
    }
}
if(w.size()>0) w.pop_back();
cout<<w;
}
