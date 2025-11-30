#include <iostream>
#include <vector>
using namespace std;

int main(){
int n,d;
cin>>n>>d;
vector<vector<int>> v(n,vector<int>(d));
for(int i=0;i<n;i++)
for(int j=0;j<d;j++)
cin>>v[i][j];
for(int i=0;i<n;i++){
int s=0;
for(int j=0;j<d;j++)
s+=v[i][j];
cout<<s<<"\n";
}
return 0;
}
