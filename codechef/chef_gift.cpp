#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        int n,k;
        cin >> n >> k;
        int m=0;
        vector<int> a(n);
        int num=0;
        int max_k=0;
        while(m<n){
            cin >> a[m];
            if(a[m]%2==0){
                num++;
            }
            m++;
        }
        if(num==n && k==0){
            cout << "NO" << endl;
        }
        else if(num>=k){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        t--;
    }
}
