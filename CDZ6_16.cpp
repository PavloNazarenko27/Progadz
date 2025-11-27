#include <iostream>
using namespace std;
int main(){
    unsigned int n;
    cin>>n;
    for(int i=31;i>=0;i--){
        unsigned int bit=(n>>i)&1;
        if(bit) cout<<"X";
        else cout<<"Y";
    }
    cout<<endl;
}
