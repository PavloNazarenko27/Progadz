#include<iostream>
using namespace std;
void countEO(int*a,int n,int&ev,int&od){
    ev=0;
    od=0;
    for(int i=0;i<n;i++)
        if(a[i]%2==0)
            ev++;
        else
            od++;
}
int main(){
    int a[50];
    int x;
    int n=0;
    while(n<50 && cin>>x){
        if(x==0)
            break;
        a[n]=x;
        n++;
    }
    int ev,od;
    countEO(a,n,ev,od);
    cout<<ev<<" "<<od;
    return 0;
}
