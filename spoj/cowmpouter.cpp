#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;
    string s;
    if(n==0){
        cout << 0 << endl;
        return 0;
    }
    while(n!=0){
        long long r=n%(-2);
        if(r<0){
            r=r+2;
            n=n/(-2);
            n=n+1;

            s+=(r+'0');
        }
        else{
            s+=(r+'0');
            n=n/(-2);
        }
    }
    reverse(s.begin(),s.end());
    cout << s << endl;
}
