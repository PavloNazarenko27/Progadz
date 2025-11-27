#include <iostream>
using namespace std;

int main(){
    int x1=-99, x2=-99, x3=-99, x4;
    int n=3, min_pos_value=0, min_pos_index=0;
    while(true){
        n++;
        x4=x3+x1+100;
        if(x4>0){
            min_pos_value=x4;
            min_pos_index=n;
            break;
        }
        x1=x2;
        x2=x3;
        x3=x4;
    }
    cout<<"min positive number: "<<min_pos_value<<endl;
    cout<<"index: "<<min_pos_index<<endl;
    return 0;
}
