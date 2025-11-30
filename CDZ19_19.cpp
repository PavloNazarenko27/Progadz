#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
ifstream fin("input.txt");
vector<int> a;
int x;
while(fin>>x)
a.push_back(x);
for(int i=0;i+1<a.size();i+=2)
swap(a[i],a[i+1]);
for(int i=0;i<a.size();i++)
cout<<a[i]<<" ";
cout<<"\n";
return 0;
}
