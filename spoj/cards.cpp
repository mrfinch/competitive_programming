#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        long long res=0;
        res=(3*n+1);
        res=(res*n);
        res=(res/2);
        cout << res%1000007 << endl;
        t--;
    }
}
