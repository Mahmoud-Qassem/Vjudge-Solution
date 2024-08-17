#include<iostream>
#include<iomanip>
using namespace std;

 int main() {
    int N=12;
    double sum=0;
    for(int i=0;i<N;++i){
        double x;
        cin>>x;
        sum+=x;
    }
    cout<<fixed<<setprecision(2)<<"$"<<(sum/12.0)<<endl;



}
