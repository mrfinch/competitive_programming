#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector< vector<char> > a(n+1,vector<char>(n+1,'*'));
    for(int i=1;i<=ceil(n/2.0);i++){
        int cnt=1;
        int t=ceil(n/2.0);
        int t1=t-1;
        int t2=t+1;
        a[i][t]='D';
        while(cnt<i){
            a[i][t1]='D';
            a[i][t2]='D';
            t1--;t2++;cnt++;
        }
    }

    for(int i=n;i>ceil(n/2.0);i--){
        int cnt=n;
        int t=ceil(n/2.0);
        int t1=t-1;
        int t2=t+1;
        a[i][t]='D';
        while(cnt>i){
            a[i][t1]='D';
            a[i][t2]='D';
            t1--;t2++;cnt--;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j];
        }
        cout << endl;
    }
}
