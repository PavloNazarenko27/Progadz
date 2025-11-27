#include <iostream>
using namespace std;
double Rosenbrock2d(double x,double y){
    return 100*(x*x-y)*(x*x-y)+(x-1)*(x-1);
}
int main(){
    cout<<Rosenbrock2d(1.0,1.0)<<endl;
    cout<<Rosenbrock2d(0.0,0.0)<<endl;
    cout<<Rosenbrock2d(2.0,3.0)<<endl;
}
