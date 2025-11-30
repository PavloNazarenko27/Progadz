#include <iostream>
using namespace std;
template<typename t>
class masiv{
t* a;
int n;
public:
masiv(int size){n=size;a=new t[n];}
~masiv(){delete[] a;}
t& operator[](int i){return a[i];}
void read(){
for(int i=0;i<n;i++)
cin>>a[i];
}
void print(){
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<"\n";
}
void sort_select(){
for(int i=0;i<n-1;i++){
int min_idx=i;
for(int j=i+1;j<n;j++)
if(a[j]<a[min_idx]) min_idx=j;
if(min_idx!=i){
t tmp=a[i];
a[i]=a[min_idx];
a[min_idx]=tmp;
}
}
}
};
int main(){
int n;
cin>>n;
masiv<int> m(n);
m.read();
m.sort_select();
m.print();
return 0;
}
