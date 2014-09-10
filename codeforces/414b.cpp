#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector< vector<int> > out(n+1,vector<int>(n+1,0));
    for(int i=1;i<n+1;i++){
        out[1][i]=1;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<n+1;j++){
            for(int k=1;k<=n;k++){
                if(j%k==0){
                    out[i][j]=(out[i][j]+out[i-1][k])%1000000007;
                }
            }
        }
    }
    /*
    for(int i=1;i<=k;i++){
        for(int j=1;j<n+1;j++){
            cout << i << " " << j << " " << out[i][j] << endl;
        }
    }
    */
    long long sum=0;
    for(int i=1;i<n+1;i++){
        sum=(sum+out[k][i])%1000000007;
    }
    cout << sum%1000000007 << endl;
}
