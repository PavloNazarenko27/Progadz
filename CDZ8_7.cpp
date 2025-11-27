#include<iostream>
#include<vector>
using namespace std;
double det(vector<vector<double>>A){
    int n=A.size();
    double D=1;
    for(int i=0;i<n;i++){
        int p=i;
        for(int j=i+1;j<n;j++)
            if(fabs(A[j][i])>fabs(A[p][i]))
                p=j;
        if(fabs(A[p][i])<1e-12)
            return 0;
        if(p!=i){
            swap(A[p],A[i]);
            D=-D;
        }
        D*=A[i][i];
        for(int j=i+1;j<n;j++){
            double f=A[j][i]/A[i][i];
            for(int k=i;k<n;k++)
                A[j][k]-=f*A[i][k];
        }
    }
    return D;
}
int main(){
    int n;
    cin>>n;
    vector<vector<double>>A(n,vector<double>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>A[i][j];
    cout<<det(A);
    return 0;
}
