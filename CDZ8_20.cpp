#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>A(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>A[i][j];
    if(m>0) k%=m;
    vector<int>row(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            row[(j+k)%m]=A[i][j];
        for(int j=0;j<m;j++){
            cout<<row[j];
            if(j<m-1) cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
