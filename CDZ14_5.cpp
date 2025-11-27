#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
double avg(string s){
    stringstream ss(s);
    string t;
    double x, sum = 0;
    int c = 0;
    while(getline(ss, t, ',')){
        sum += stod(t);
        c++;
    }
    return sum / c;
}
int main(){
    ifstream f("stud.txt");
    string pr, k, gr, marks, bad = "";
    double worst = 1e9, a;
    while(f >> pr >> k >> gr){
        getline(f, marks);
        a = avg(marks);
        if(a < worst){
            worst = a;
            bad = pr;
        }
    }
    cout << bad;
}
