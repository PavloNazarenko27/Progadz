#include <iostream>
using namespace std;
class dot
{
public:
int x;
int y;
dot(int a,int b){x=a;y=b;}
bool counter()
{
if(x>0 && y>0) return true;
else return false;
}
};

int main()
{
int a,b;
cin>>a>>b;
dot t(a,b);
cout<<t.counter()<<"\n";
cout<<t.x<<" "<<t.y<<"\n";
}
