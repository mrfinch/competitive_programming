#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    /*
    int t;
    cin >> t;
    while(t){
        int n,k;
        cin >> n >> k;
        if(k==0){
            cout << 1 << endl;
            continue;
        }
        if(k==n){
            cout << 1 << endl;
            continue;
        }
        vector< vector<ll> > inp(n,vector<ll>(k,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<min(i,k);j++){
                if(j==0 || j==i){
                    inp[i][j]=1;
                }
                else{
                    inp[i][j]=inp[i-1][j-1]+inp[i-1][j];
                }
            }
        }
        cout << inp[n-1][k-1] << endl;
        t--;
    }
    */
    int t;
    cin >> t;
    while(t){
        int n,k;
        cin >> n >> k;
        if(k==0 || k==n){
            cout << 1 << endl;
            t--;
            continue;
        }
        n--;k--;
        ll res=1;
        int x=(n-k<k)?(n-k):k;
        int j=n-x+1;

        for(int i=1;i<=x;i++){
            res=(res*j)/i;
            j++;
        }
        cout << res << endl;
        t--;
    }
}
