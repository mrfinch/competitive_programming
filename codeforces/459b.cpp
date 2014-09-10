#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<long long> a(n);
    int m=0;
    while(m<n){
        cin >> a[m];
        m++;
    }
    sort(a.begin(),a.end());
    int mx=a[a.size()-1]-a[0];
    if(mx==0){
        long long c=0;
        for(int i=1;i<n;i++){
            c+=i;
        }
        cout << 0 << " " << c << endl;
        return 0;
    }
    long long x=1;
    long long b=a[a.size()-1];
    int h=a.size()-2;
    while(h>=0 && a[h]==b){
        x++;
        h--;
    }
    b=a[0];
    h=1;
    long long y=1;
    while(h<a.size() && a[h]==b){
        y++;
        h++;
    }
    long long c=x*y;
    cout << mx << " " << c << endl;
}
