#include <iostream>
#include <fstream>
using namespace std;

class vector_class
{
public:
int n;
double* a;
vector_class(int size){n=size;a=new double[n];}
void input()
{
for(int i=0;i<n;i++) cin>>a[i];
}
void input_file(const char* filename)
{
ifstream f(filename);
for(int i=0;i<n;i++) f>>a[i];
f.close();
}
void output()
{
for(int i=0;i<n;i++) cout<<a[i]<<" ";
cout<<"\n";
}
vector_class* clone()
{
vector_class* b=new vector_class(n);
for(int i=0;i<n;i++) b->a[i]=a[i];
return b;
}
~vector_class(){delete[] a;}
};

int main()
{
int n;
cin>>n;
vector_class v(n);
v.input();
v.output();
vector_class* v2=v.clone();
v2->output();
delete v2;
}
