#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream f("input.txt");
    char c;
    double x;
    double res;
    f >> res;
    while(f >> c >> x){
        if(c == '+') res += x;
        else res -= x;
    }
    cout << res;
}
