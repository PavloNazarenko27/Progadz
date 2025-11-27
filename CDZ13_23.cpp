#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
string s;
getline(cin,s);
vector<string> words;
string w="";
for(int i=0;i<s.size();i++){
    if(s[i]!=' ') w+=s[i];
    else{ if(w!="") words.push_back(w); w=""; }
}
if(w!="") words.push_back(w);
for(int i=0;i<words.size();i++){
    if(i+1<words.size() && words[i].size()>2 && words[i].substr(words[i].size()-2)=="'s"){
        cout<<words[i+1]<<" of "<<words[i].substr(0,words[i].size()-2)<<" ";
        i++;
    } else cout<<words[i]<<" ";
}
}
