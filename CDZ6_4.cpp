#include <iostream>
#include <bitset>
using namespace std;
int main(){
unsigned int n;
cin>>n;
bitset<32> b(n);
for(int i=31;i>=0;i--)cout<<b[i];
cout<<endl;
}
