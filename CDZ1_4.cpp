#include <iostream>
using namespace std;
int main(){
    double m1, m2, r;
    cout<<"give me m1,m2,r: ";
    cin>>m1>>m2>>r;
    double G = 6.673e-11;
    double F = G*m1*m2/(r*r);
    cout<<"F="<<F;
    return 0;
}