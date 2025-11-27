#include<iostream>
using namespace std;
int main(){
    double A[3][3]={{1.0,2,3},{4,5,6},{7,8,9}};
    int i,j;
    double a;
    cin>>i>>j>>a;
    if(i>=1 && i<=3 && j>=1 && j<=3)
        A[i-1][j-1]=a;
    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
            cout<<A[r][c];
            if(c<2) cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
