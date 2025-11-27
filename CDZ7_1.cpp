#include<iostream>
using namespace std;
int main(){
    int a[5]={7,2,9,4,1};
    int x;
    cin>>x;
    int c=0;
    for(int i=0;i<5;i++)
        if(a[i]<x)
            c++;
    cout<<c;
    return 0;
}
