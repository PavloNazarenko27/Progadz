#include <iostream>
using namespace std;

int main(){
    long long a,f1=0,f2=1,next;
    cout<<"enter a: ";
    cin>>a;
    int i=1;
    while(f2<=a){
        next=f1+f2;
        f1=f2;
        f2=next;
        i++;
    }
    cout<<"biggest fib that is ≤a: "<<i-1<<endl;
    return 0;
}
