#include<iostream>
using namespace std;
int main(){
    int N,M,k;
    cin>>N>>M>>k;
    double A[100][100];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>A[i][j];
    double s=0;
    bool f=false;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(i-j==k){
                s+=A[i][j];
                f=true;
            }
    if(f) cout<<s;
    else cout<<0;
    return 0;
}
