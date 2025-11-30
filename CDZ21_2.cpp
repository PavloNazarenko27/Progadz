#include <iostream>
#include <vector>
using namespace std;
int main(){
int n;
cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++)
cin>>a[i];
int x;
cin>>x;
int k;
k=0;
for(int i=0;i<n;i++){
if(a[i]!=x){
int t;
t=a[k];
a[k]=a[i];
a[i]=t;
k++;
}
}
for(int i=0;i<n;i++)
cout<<a[i]<<(i+1<n?" ":"");
cout<<"\n";
return 0;
}
