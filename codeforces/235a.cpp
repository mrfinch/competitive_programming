#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n==1){
        cout << 1 <<  endl;
    }
    else if(n==2){
        cout << 2 << endl;
    }
    else if(n==3){
        cout << 6 << endl;
    }
    else if(n%2==1){
        long long x=n*(n-1)*(n-2);
        cout << x << endl;
    }
    else{
        long long x=((n-1)*(n-2)*(n-3));
        cout << x << endl;
    }
}
