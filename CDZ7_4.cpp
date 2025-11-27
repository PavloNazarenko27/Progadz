#include<iostream>
using namespace std;
void readArr(int*a){
    for(int i=0;i<5;i++)
        cin>>a[i];
}
int maxArr(int*a){
    int m=a[0];
    for(int i=1;i<5;i++)
        if(a[i]>m)
            m=a[i];
    return m;
}
int main(){
    int a[5];
    readArr(a);
    cout<<maxArr(a);
    return 0;
}
