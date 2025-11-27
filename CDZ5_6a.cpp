#include <iostream>
using namespace std;

double chainFraction(double b, int n){
    if(n==1) return b;
    return b + 1.0/chainFraction(b, n-1);
}

int main(){
    double b;
    int n;
    cout<<"enter b,n: ";
    cin>>b>>n;
    cout<<"chain frac: "<<chainFraction(b,n)<<endl;
    return 0;
}
