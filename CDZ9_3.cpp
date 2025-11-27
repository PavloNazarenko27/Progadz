#include<iostream>
using namespace std;
double* createVector(int n){
    double* v=new double[n];
    for(int i=0;i<n;i++)
        cin>>v[i];
    return v;
}
void deleteVector(double*v){
    delete[]v;
}
int main(){
    int n;
    cin>>n;
    double*a=createVector(n);
    int m;
    cin>>m;
    double*b=createVector(m);
    if(n==m){
        double*c=new double[n];
        for(int i=0;i<n;i++)
            c[i]=a[i]-b[i];
        for(int i=0;i<n;i++){
            cout<<c[i];
            if(i<n-1) cout<<" ";
        }
        delete[]c;
    }
    deleteVector(a);
    deleteVector(b);
    return 0;
}
