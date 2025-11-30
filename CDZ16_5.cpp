#include <iostream>
#include <string>
using namespace std;
class slovo{
protected:
string pr1,pr2,kor,suf,endd;
public:
slovo(string k):pr1(""),pr2(""),kor(k),suf(""),endd(""){}
string get_pr1()const{return pr1;}
string get_pr2()const{return pr2;}
string get_kor()const{return kor;}
string get_suf()const{return suf;}
string get_end()const{return endd;}
void set_pr1(const string& s){pr1=s;}
void set_pr2(const string& s){pr2=s;}
void set_kor(const string& s){kor=s;}
void set_suf(const string& s){suf=s;}
void set_end(const string& s){endd=s;}
virtual void number()=0;
virtual void gender()=0;
virtual void face()=0;
virtual void casef()=0;
virtual string str()const{return pr1+pr2+kor+suf+endd;}
};
class imen:public slovo{
public:
imen(string k):slovo(k){}
void number()override{endd="s";}
void gender()override{}
void face()override{}
void casef()override{}
};
class adj:public slovo{
public:
adj(string k):slovo(k){}
void number()override{endd="";}
void gender()override{}
void face()override{}
void casef()override{}
};
class verb:public slovo{
bool thirdf=false;
bool pluralf=false;
public:
verb(string k):slovo(k){}
void number()override{pluralf=true;thirdf=false;endd="";}
void face()override{thirdf=true;if(!pluralf)endd="es";else endd="";}
void gender()override{}
void casef()override{}
};
int main(){
imen n("house");
n.number();
cout<<n.str()<<"\n";
verb v("go");
v.face();
cout<<v.str()<<"\n";
v.number();
v.face();
cout<<v.str()<<"\n";
adj a("big");
a.number();
cout<<a.str()<<"\n";
return 0;
}
