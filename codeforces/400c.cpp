#include <iostream>
#include <vector>
//not solved vector resizing??
using namespace std;
typedef long long ll;

int main(){
    ll n,m,x,y,z,p;
    cin >> n >> m >> x >> y >> z >> p;
    vector< vector<bool> > inp(n+1,vector<bool>(m+1,false));
    ll i=0;

    while(i<p){
        ll t1,t2;
        cin >> t1 >> t2;
        inp[t1][t2]=true;
        i++;
    }
    x=x%4;

    for(int m=0;m<x;m++){
        ll temp=m;
        m=n;
        n=temp;
        vector< vector<bool> > t(n+1,vector<bool>(m+1,false));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                t[i][j]=inp[i][n-j+1];
            }
        }
        vector< vector<bool> > inp(n+1,vector<bool>(m+1,false));
        inp=t;
    }
    y=y%2;
    for(int m=0;)
}
