#include <iostream>
using namespace std;

int main(){
    double a,sum=0;
    int n=0;
    cout<<"enter a: ";
    cin>>a;
    while(sum<=a){
        n++;
        sum+=1.0/n;
    }
    cout<<"first bigger than a: "<<sum<<endl;
    return 0;
}
