#include <iostream>
#include <vector>
using namespace std;
class polinom
{
public:
vector<int> coef;
polinom(int n)
{
coef.resize(n);
for(int i=0;i<n;i++) cin>>coef[i];
}
int counter()
{
int sum=0;
for(int i=0;i<coef.size();i++) sum+=coef[i];
return sum;
}
};
int main()
{
int n;
cin>>n;
polinom p(n);
cout<<p.counter()<<"\n";
for(int i=0;i<n;i++) cout<<p.coef[i]<<" ";
cout<<"\n";
}
