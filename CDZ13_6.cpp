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
    if(s[i]!=' '){
        w+=s[i];
    } else{
        if(w!="") words.push_back(w);
        w="";
    }
}
if(w!="") words.push_back(w);
if(words.size()>0) cout<<words[0]<<"\n";
if(words.size()>0) cout<<words[words.size()-1]<<"\n";
for(int i=0;i<words.size();i++) cout<<words[i]<<" ";
}
