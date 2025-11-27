#include<iostream>
#include<vector>
using namespace std;
void transpose(vector<vector<int>>&A,int n){
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            int t=A[i][j];
            A[i][j]=A[j][i];
            A[j][i]=t;
        }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>A(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>A[i][j];
    transpose(A,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j];
            if(j<n-1) cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
