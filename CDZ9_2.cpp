#include<iostream>
#include<cmath>
using namespace std;
int readArr(int*a){
    int x,n=0;
    while(n<100 && cin>>x && x!=0)
        a[n++]=x;
    return n;
}
bool isSquare(int x){
    int r=sqrt(x);
    return r*r==x;
}
bool isCube(int x){
    int r=round(cbrt(x));
    return r*r*r==x;
}
int main(){
    int a[100];
    int n=readArr(a);
    int sq=0,cb=0;
    for(int i=0;i<n;i++){
        if(isSquare(a[i])) sq++;
        if(isCube(a[i])) cb++;
    }
    cout<<sq<<" "<<cb;
    return 0;
}
