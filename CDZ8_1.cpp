#include<iostream>
using namespace std;
int main(){
    int A[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int N,M;
    cin>>N>>M;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(A[i][j]==M)
                A[i][j]=N;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<A[i][j];
            if(j<2) cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
