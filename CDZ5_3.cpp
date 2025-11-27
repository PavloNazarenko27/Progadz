#include <iostream>
using namespace std;

int steps(int n){
    int s=0;
    while(n!=1){
        if(n%2==0) n/=2;
        else n=3*n+1;
        s++;
    }
    return s;
}

int main(){
    int maxs=0,best=0;
    for(int i=1;i<1000;i++){
        int s=steps(i);
        if(s>maxs){
            maxs=s;
            best=i;
        }
    }
    cout<<"max steps needed for n="<<best<<" ("<<maxs<<" steps)"<<endl;
    return 0;
}
