#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
double a,b,c;cin>>a>>b>>c;
const double eps=1e-12;
vector<pair<double,double>> sol;
bool inf=false;
double ss[2]={1.0,-1.0};
for(int i=0;i<2;i++){
double s=ss[i];
if(fabs(a-b)>eps){
double x=(-c - b*s)/(a-b);
double y=s-x;
bool d=false;
for(auto&p:sol)if(fabs(p.first-x)<1e-9 && fabs(p.second-y)<1e-9)d=true;
if(!d)sol.emplace_back(x,y);
}else{
if(fabs(b)>eps){
if(fabs(b*s + c)<eps){inf=true;break;}
}else{
if(fabs(c)<eps){inf=true;break;}
}
}
}
if(inf){cout<<"INF";}
else if(sol.empty()){cout<<"0";}
else{
cout<<sol.size()<<"\n";
for(auto&p:sol)cout<<p.first<<" "<<p.second<<"\n";
}
}
