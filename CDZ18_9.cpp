#include <iostream>
#include <string>
using namespace std;

template<typename T>
T sum(T* x, size_t n){
T s=T();
for(size_t i=0;i<n;i++)
s+=x[i];
return s;
}

template<>
string sum<char>(char* x, size_t n){
string s="";
for(size_t i=0;i<n;i++)
s+=x[i];
return s;
}

template<typename T>
T* sum(T** x, size_t n){
size_t total=0;
for(size_t i=0;i<n;i++)
total+=sizeof(x[i])/sizeof(T);
T* s=new T[total];
size_t idx=0;
for(size_t i=0;i<n;i++){
size_t len=sizeof(x[i])/sizeof(T);
for(size_t j=0;j<len;j++)
s[idx++]=x[i][j];
}
return s;
}

int main(){
int v1[]={1,2,3};
cout<<sum(v1,3)<<"\n";
double v2[]={1,2,3};
cout<<sum(v2,3)<<"\n";
string v3[]={"a","bc","def"};
cout<<sum(v3,3)<<"\n";
char v4[]={'a','b','c'};
cout<<sum(v4,3)<<"\n";
return 0;
}
