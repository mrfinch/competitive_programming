#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector< vector<int> > inp(n+1, vector<int>(m+1,0));
    vector< vector<int> > out(n+1, vector<int>(m+1,0));
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=m){
            cin >> inp[i][j];
            j++;
        }
        i++;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            out[i][j] = inp[i][j] + max(out[i-1][j],out[i][j-1]);
        }
    }
    for(int i=1;i<n+1;i++){
        cout << out[i][m] << " ";
    }
    cout << endl;
}
