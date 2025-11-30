#include <iostream>
#include <string>
using namespace std;
class human{
public:
string pib,sex;
int age;
virtual void input(){cin>>pib>>sex>>age;}
virtual void output(){cout<<pib<<" "<<sex<<" "<<age;}
virtual string get_vuz(){return "";}
};
class student:public human{
public:
string kurs,gr,vuz;
void input()override{cin>>pib>>sex>>age>>kurs>>gr>>vuz;}
void output()override{cout<<pib<<" "<<sex<<" "<<age<<" "<<kurs<<" "<<gr<<" "<<vuz;}
string get_vuz()override{return vuz;}
};
class teacher:public human{
public:
string vuz,pos;
double zp;
void input()override{cin>>pib>>sex>>age>>vuz>>pos>>zp;}
void output()override{cout<<pib<<" "<<sex<<" "<<age<<" "<<vuz<<" "<<pos<<" "<<zp;}
string get_vuz()override{return vuz;}
};
class aspirant:public student,public teacher{
public:
void input()override{cin>>pib>>sex>>age>>teacher::vuz;}
void output()override{cout<<pib<<" "<<sex<<" "<<age<<" "<<teacher::vuz;}
string get_vuz()override{return teacher::vuz;}
};
int main(){
int n;
cin>>n;
human* a[n];
for(int i=0;i<n;i++){
int t;
cin>>t;
if(t==1)a[i]=new student();
else if(t==2)a[i]=new teacher();
else a[i]=new aspirant();
a[i]->input();
}
for(int i=0;i<n;i++){
cout<<a[i]->get_vuz()<<"\n";
}
return 0;
}

