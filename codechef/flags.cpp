#include <iostream>

using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t>0){
        ll n;
        cin >> n;
        ll ans=(2*n*(n-1)*(n-1))+(n*(n-1)*(n-2))+(2*n*(n-1)*(n-2)*(n-2));
        cout << ans << endl;
        t--;
    }
}
