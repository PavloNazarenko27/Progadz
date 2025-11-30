#include <iostream>
#include <fstream>
using namespace std;
class rat{
int a,b;
public:
rat(int x=0,int y=1){a=x;b=y;}
friend istream& operator>>(istream& in,rat& r){in>>r.a>>r.b;if(r.b==0)r.b=1;return in;}
friend ostream& operator<<(ostream& out,const rat& r){out<<r.a<<"/"<<r.b;return out;}
rat operator-(const rat& r)const{return rat(a*r.b-b*r.a,b*r.b);}
rat operator/(const rat& r)const{return rat(a*r.b,b*r.a);}
friend void write(const rat& r,const string& f){ofstream g(f);g<<r.a<<" "<<r.b;g.close();}
};
int main(){
rat r1,r2(3,4),r3;
cin>>r1;
r3=r1-r2;
cout<<r3<<"\n";
write(r3,"out.txt");
return 0;
}
