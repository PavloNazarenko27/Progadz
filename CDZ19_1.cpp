#include <iostream>
#include <vector>
using namespace std;

int main(){
int n;
cin>>n;
vector<int> t(n);
vector<int> c(n);
for(int i=0;i<n;i++)
cin>>t[i]>>c[i];
int max_val=t[0];
int idx=0;
for(int i=1;i<n;i++)
if(t[i]>max_val){
max_val=t[i];
idx=i;
}
cout<<idx+1<<"\n";
return 0;
}
