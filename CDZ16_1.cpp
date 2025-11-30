#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class person{
protected:
string name;
unsigned byear;
public:
person():name(""),byear(0){}
virtual void input(){cout<<"name: ";cin>>name;cout<<"year: ";cin>>byear;}
virtual void show()const{cout<<name<<" "<<byear;}
friend ostream& operator<<(ostream& os,const person& p){os<<p.name<<" "<<p.byear;return os;}
friend istream& operator>>(istream& is,person& p){is>>p.name>>p.byear;return is;}
string getname()const{return name;}
};
class friendp:public person{
string phone;
public:
friendp():phone(""){}
void input()override{person::input();cout<<"phone: ";cin>>phone;}
void show()const override{person::show();cout<<" "<<phone;}
friend ostream& operator<<(ostream& os,const friendp& f){os<<f.name<<" "<<f.byear<<" "<<f.phone;return os;}
friend istream& operator>>(istream& is,friendp& f){is>>f.name>>f.byear>>f.phone;return is;}
string getphone()const{return phone;}
void setphone(const string& p){phone=p;}
};
class phonebook{
friendp a[100];
int c;
string file;
public:
phonebook(const string& f):c(0),file(f){load();}
void load(){ifstream in(file);if(!in)return;while(in>>a[c]&&c<100)c++;in.close();}
void save(){ofstream out(file);for(int i=0;i<c;i++)out<<a[i]<<'\n';out.close();}
void add(){if(c>=100)return;a[c].input();c++;save();}
string find(const string& n){for(int i=0;i<c;i++)if(a[i].getname()==n)return a[i].getphone();return "not found";}
void change(const string& n,const string& ph){for(int i=0;i<c;i++)if(a[i].getname()==n){a[i].setphone(ph);save();return;}}
void showall(){for(int i=0;i<c;i++){a[i].show();cout<<"\n";}}
};
int main(){
phonebook pb("data.txt");
pb.add();
cout<<pb.find("ivan")<<"\n";
pb.change("ivan","111222333");
pb.showall();
return 0;
}
