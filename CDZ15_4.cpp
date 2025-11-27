#include <iostream>
using namespace std;

class tochka
{
public:
int x;int y;
void input()
{
cin>>x>>y;
}
void output()
{
cout<<x<<" "<<y<<"\n";
}
};
class vidrizok
{
public:
tochka a;tochka b;
void input()
{
a.input();b.input();
}
void output()
{
a.output();b.output();
}
};
class trngl
{
public:
vidrizok r1;vidrizok r2;tochka t;
void input()
{
r1.input();r2.input();t.input();
}
void output()
{
r1.output();r2.output();t.output();
}
};
int main()
{
trngl tr;tr.input();tr.output();
}
