#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool art(string s){
    return s=="die" || s=="der" || s=="das";
}
int main(){
    ifstream f("input.txt");
    ofstream g("output.txt");
    string a,b;
    while(f >> a){
        g << a << " ";
        if(art(a) && f >> b){
            b[0] = toupper(b[0]);
            g << b << " ";
        }
    }
}
