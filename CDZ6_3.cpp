#include <iostream>
#include <bitset>
using namespace std;
int main(){
unsigned long long m;
cin>>m;
for(int j=63;j>=0;j--)cout<<((m>>j)&1);
cout<<endl;
}
