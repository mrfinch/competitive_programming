#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector< vector<int> > inp(n,vector<int>(n,0));
    int i=0;
    while(i<k){
        int t1,t2,t3;
        cin >> t1 >> t2 >> t3;
        inp[t1][t2]=t3;
        i++;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(j==i){
                continue;
            }
            for(int k=1;k<n;k++){
                if(j==k){
                    continue;
                }
                if(inp[j][k]<=inp[i][j] && inp[j][k]>0 && inp[i][j]>0){
                    inp[j][k]--;
                    inp[i][j]--;
                    inp[i][k]++;
                }
            }
        }
    }
    long long debt=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(i==j){
                continue;
            }
            debt+=inp[i][j];
        }
    }
    cout << debt << endl;
    return 0;
}
