#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int mi=min(n,m);
    int ma=max(n,m);
    int mov=mi;
    if(mov%2==0){
        int x=ma-mi;
        if(x%2==1){
            cout << "Akshat" << endl;
        }
        else{
            cout << "Malvika" << endl;
        }
    }
    else{
        int x=ma-mi;
        if(x%2!=1){
            cout << "Akshat" << endl;
        }
        else{
            cout << "Malvika" << endl;
        }
    }
}
