#include <iostream>
using namespace std;
int main(){
int m,k=0;
cin>>m;
while(pow(4,k+1)<=m)k++;
cout<<k;
}
