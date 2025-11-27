#include <iostream>
using namespace std;
double factorial(int n){
    if(n==0 || n==1) return 1;
    return n*factorial(n-1);}
double product(int n){
    if(n==1) return 1+1.0/factorial(1);
    return product(n-1)*(1+1.0/factorial(n));
}
int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    cout<<"P_"<<n<<" = "<<product(n)<<endl;
    return 0;
}
