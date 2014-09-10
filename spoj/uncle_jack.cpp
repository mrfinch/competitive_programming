#include <iostream>
#include <cmath>
using namespace std;
int main(){
    while(true){
        int n,d;
        cin>>n>>d;
        if(n==0&&d==0)break;
        long long x=pow(n,d);
        cout << x << endl;
    }
}
