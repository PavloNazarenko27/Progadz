#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    double a[100];
    for(int i=0;i<n;i++)
        cin>>a[i];
    double m=a[1];
    for(int i=3;i<n;i+=2)
        if(a[i]>m)
            m=a[i];
    cout<<m;
    return 0;
}
