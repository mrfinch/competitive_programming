#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    int sum=0;
    while(t){
        int n;
        cin >> n;
        if(n>0){
            sum+=n;
        }
        t--;
    }
    cout << sum << endl;
}
