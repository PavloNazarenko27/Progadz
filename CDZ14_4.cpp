#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ifstream f("input.txt");
    string s;
    int k = 0;
    while(f >> s){
        if(s.find("<td>") != string::npos) k++;
        if(s.find("</td>") != string::npos) k--;
    }
    cout << (k == 0 ? "correct" : "incorrect");
}
