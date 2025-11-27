#include<iostream>
#include<vector>
using namespace std;
void readMatrix(vector<vector<double>>&A,int m,int n){
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            cout<<"a["<<i+1<<"]["<<j+1<<"]:";
            cin>>A[i][j];
        }
}
int main(){
    int m,n;
    cin>>m>>n;
    if(m>19) m=19;
    if(n>19) n=19;
    vector<vector<double>>A(m,vector<double>(n));
    readMatrix(A,m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j];
            if(j<n-1) cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
