#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    vector<double>P(n+1);
    for(int i=0;i<=n;i++)
        cin>>P[i];
    cin>>m;
    vector<double>Q(m+1);
    for(int i=0;i<=m;i++)
        cin>>Q[i];
    vector<double>R(1,0);
    for(int i=0;i<=n;i++){
        vector<double>term(1,1);
        for(int j=0;j<i;j++){
            vector<double>tmp(term.size()+Q.size()-1);
            for(size_t k=0;k<term.size();k++)
                for(size_t t=0;t<Q.size();t++)
                    tmp[k+t]+=term[k]*Q[t];
            term=tmp;
        }
        for(double &x:term) x*=P[i];
        if(term.size()>R.size()) R.resize(term.size());
        for(size_t k=0;k<term.size();k++)
            R[k]+=term[k];
    }
    for(size_t i=0;i<R.size();i++)
        cout<<R[i]<<" ";
    return 0;
}
