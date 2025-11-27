#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    vector<vector<int>>A(N,vector<int>(M));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>A[i][j];
    int row;
    cin>>row;
    if(row>=1 && row<=N){
        for(int j=0;j<M;j++){
            cout<<A[row-1][j];
            if(j<M-1) cout<<" ";
        }
    }
    return 0;
}
