#include <iostream>
using namespace std;
void printBytes(unsigned int x){
    unsigned char *b=(unsigned char*)&x;
    cout<<"Little-endian: ";
    for(int i=0;i<sizeof(x);i++) cout<<int(b[i])<<" ";
    cout<<endl;
    cout<<"Big-endian: ";
    for(int i=sizeof(x)-1;i>=0;i--) cout<<int(b[i])<<" ";
    cout<<endl;
    cout<<"Middle-endian: ";
    if(sizeof(x)==4) cout<<int(b[1])<<" "<<int(b[0])<<" "<<int(b[3])<<" "<<int(b[2]);
    cout<<endl;
}
int main(){
    unsigned int num;
    cin>>num;
    printBytes(num);
}
