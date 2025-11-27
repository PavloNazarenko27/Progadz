#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
int n;
cin>>n;
int* m=new int[n];
for(int i=0;i<n;i++) cin>>m[i];

ifstream f("input.txt");
if(!f) { cout<<"file error"; return 0; }

double* x=new double[n];
for(int i=0;i<n;i++) if(!(f>>x[i])) { cout<<"data error"; return 0; }

ofstream g("output.txt");
for(int i=0;i<n;i++) g<<pow(x[i],m[i])<<"\n";

delete[] m;
delete[] x;
return 0;
}
