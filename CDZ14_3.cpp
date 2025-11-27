#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
bool letter(char c){
    return isalpha((unsigned char)c);
}
int main(){
    ifstream f("in.txt");
    ofstream g("out.txt");
    string w = "";
    char c;
    while(f.get(c)){
        if(letter(c)) w += c;
        else{
            reverse(w.begin(), w.end());
            g << w << c;
            w = "";
        }
    }
    reverse(w.begin(), w.end());
    g << w;
}
