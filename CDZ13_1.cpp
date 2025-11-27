#include <iostream>
#include <string>
using namespace std;
int main(){
string s;
getline(cin,s);
int n=s.size();
for(int i=0;i<n;i++){
    if(s[i]==':'){
        int j=i+1;
        while(j<n && s[j]!=',') j++;
        for(int k=i+1;k<j;k++) cout<<s[k];
        i=j;
    } else cout<<s[i];
}
}
