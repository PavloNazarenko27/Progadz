#include <iostream>
#include <bitset>
using namespace std;
int main(){
unsigned char n;
cin>>n;
int maxlen=0,current=0,pos=0;
for(int i=7;i>=0;i--){
if((n>>i)&1){current++;if(current>maxlen){maxlen=current;pos=i;}}
else current=0;
}
cout<<maxlen<<' '<<(8-pos-maxlen)<<endl;
}
