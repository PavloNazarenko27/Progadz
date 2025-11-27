#include<iostream>
using namespace std;
struct Product{
    int hrn;
    int kpk;
};
double price(Product p){
    return p.hrn+p.kpk/100.0;
}
Product cheapest(Product a[],int n){
    Product m=a[0];
    for(int i=1;i<n;i++)
        if(price(a[i])<price(m))
            m=a[i];
    return m;
}
Product mostexpensive(Product a[],int n){
    Product m=a[0];
    for(int i=1;i<n;i++)
        if(price(a[i])>price(m))
            m=a[i];
    return m;
}
void nearaverage(Product a[],int n){
    double s=0;
    for(int i=0;i<n;i++)
        s+=price(a[i]);
    double avg=s/n;
    for(int i=0;i<n;i++)
        if(abs(price(a[i])-avg)<=10)
            cout<<a[i].hrn<<" "<<a[i].kpk<<endl;
}
int main(){
    int n;
    cin>>n;
    Product a[100];
    for(int i=0;i<n;i++)
        cin>>a[i].hrn>>a[i].kpk;
    Product c=cheapest(a,n);
    cout<<"cheapest: "<<c.hrn<<" "<<c.kpk<<endl;
    Product e=mostexpensive(a,n);
    cout<<"most expensive: "<<e.hrn<<" "<<e.kpk<<endl;
    cout<<"near average:"<<endl;
    nearaverage(a,n);
    return 0;
}

