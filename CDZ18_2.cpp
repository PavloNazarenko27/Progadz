#include <iostream>
#include <stack>
using namespace std;
template<typename t>
class stk{
stack<t> s;
public:
void push(t x){s.push(x);}
t pop(){t x=s.top();s.pop();return x;}
bool empty(){return s.empty();}
};
int main(){
int n;
cin>>n;
stk<int> s;
for(int i=0;i<n;i++){
int x;
cin>>x;
s.push(x);
}
while(!s.empty()){
cout<<s.pop()<<" ";
}
cout<<"\n";
return 0;
}
