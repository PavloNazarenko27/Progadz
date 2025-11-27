#include<iostream>
using namespace std;
double sumGreaterE(double*a,int n){
    double s=0;
    const double e=2.718281828459045;
    for(int i=0;i<n;i++)
        if(a[i]>e)
            s+=a[i];
    return s;
}
int main(){
    double a[10];
    for(int i=0;i<10;i++)
        cin>>a[i];
    cout<<sumGreaterE(a,10);
    return 0;
}
