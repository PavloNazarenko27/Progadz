#include<iostream>
#include<vector>
using namespace std;
void readRows(vector<vector<int>>&A,int m,int n){
    for(int i=0;i<m;i++){
        cout<<"row "<<i+1<<":";
        for(int j=0;j<n;j++)
            cin>>A[i][j];
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    if(m>24) m=24;
    if(n>24) n=24;
    vector<vector<int>>A(m,vector<int>(n));
    readRows(A,m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j];
            if(j<n-1) cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
