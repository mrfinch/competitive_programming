#include <iostream>
#include <vector>
using namespace std;

int numofdig(int x){
    int c=0;
    while(x){
        x/=10;
        c++;
    }
    return c;
}
int main(){
    long long w,m,k;
    cin >> w >> m >> k;
    long long dig=0;
    long long cost = 0;
    for(long long i=m;i<=100000000*100000000;i++){
        cost=cost+numofdig(i)*k;
        if(cost>w){
            break;
        }
        dig++;
    }
    cout << dig << endl;
}
