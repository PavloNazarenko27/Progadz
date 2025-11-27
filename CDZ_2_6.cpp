#include <iostream>
#include <cmath>
using namespace std;
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
double area(double a,double b,double c){
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main(){
    double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;
    double a=dist(x1,y1,x2,y2);
    double b=dist(x2,y2,x3,y3);
    double c=dist(x3,y3,x1,y1);
    cout<<area(a,b,c);
}
