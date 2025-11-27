#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    double a1=0, a2=1, b1=1, b2=0, ak, bk, S=0;
    if(n>=1) S+=pow(2,1)/(a1+b1);
    if(n>=2) S+=pow(2,2)/(a2+b2);
    for(int k=3;k<=n;k++){
        bk=b2+a2;
        ak=a2/k+a1*bk;
        S+=pow(2,k)/(ak+bk);
        a1=a2;
        a2=ak;
        b1=b2;
        b2=bk;
    }
    cout<<"the sum is "<<S<<endl;
    return 0;
}
