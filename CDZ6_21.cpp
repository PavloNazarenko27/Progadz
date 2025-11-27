#include <iostream>
using namespace std;
unsigned int firstandlast(unsigned int n){
    n|=1;          
    n|=(1u<<31);        
    return n;
}
int main(){
    unsigned int n;
    cin>>n;
    cout<<firstandlast(n)<<endl;
}
