#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
ifstream f("points.txt");
if(!f) return 0;
vector<pair<int,int>> a;
char c;
int x,y;
while(f>>c>>x>>c>>y>>c)
a.push_back({x,y});
vector<tuple<double,int,int,int,int>> d;
int n=a.size();
for(int i=0;i<n;i++)
for(int j=i+1;j<n;j++)
{
double l=sqrt((a[i].first-a[j].first)*(a[i].first-a[j].first)+(a[i].second-a[j].second)*(a[i].second-a[j].second));
d.push_back({l,a[i].first,a[i].second,a[j].first,a[j].second});
}
sort(d.begin(),d.end());
ofstream g("segments.txt");
for(auto &t:d)
g<<"("<<get<1>(t)<<","<<get<2>(t)<<")-("<<get<3>(t)<<","<<get<4>(t)<<") "<<get<0>(t)<<"\n";
return 0;
}
