#include <iostream>
#include <fstream>
using namespace std;
class vector{
int n;
int* a;
public:
vector(int size=0){n=size;if(n>0)a=new int[n];else a=nullptr;}
~vector(){delete[] a;}
void input(){for(int i=0;i<n;i++)cin>>a[i];}
void output(){for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";}
void save(const string& f){ofstream g(f);for(int i=0;i<n;i++)g<<a[i]<<" ";g.close();}
void load(const string& f){ifstream g(f);for(int i=0;i<n;i++)g>>a[i];g.close();}
};
int main(){
int n;
cin>>n;
vector v(n);
v.input();
v.output();
v.save("v.txt");
vector w(n);
w.load("v.txt");
w.output();
return 0;
}
