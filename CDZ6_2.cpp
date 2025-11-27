#include <iostream>
#include <bitset>
using namespace std;
int main(){
unsigned char n,k;
cin>>n>>k;
cout<<bitset<8>(k)<<endl;
for(int i=0;i<8;i++)if((n>>i)&1)cout<<(i+1)<<' ';
}
