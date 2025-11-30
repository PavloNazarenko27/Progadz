#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct Town{ string name; int population; int elevation; int weather; };
int main(){
    ifstream fin("Towns.txt");
    vector<Town> v; Town t;
    while(fin >> t.name >> t.population >> t.elevation >> t.weather) v.push_back(t);
    fin.close();
    transform(v.begin(), v.end(), v.begin(), [](Town a){ a.population=int(a.population*1.10); return a; });
    ofstream fout("Towns.txt");
    for(const auto &x:v) fout<<x.name<<" "<<x.population<<" "<<x.elevation<<" "<<x.weather<<"\n";
    fout.close();
}
