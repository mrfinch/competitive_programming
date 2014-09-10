#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m,p;
    cin >> n >> m >> p;
    vector< vector<int> > inp(n+1,vector<int>(m+1));
    int i=1;
    while(i<n+1){
    	int j=1;
        while(j<m+1){
            inp[i][j]=j;
            j++;
        }
        i++;
    }
    i=0;
    vector< vector<int> > q(n+1,vector<int>());
    vector< vector<int> > inc(n+1,vector<int>());
    while(i<p){
        int x,y;
        cin >> x >> y;
        if(find(q[x].begin(),q[x].end(),y)==q[x].end())
            q[x].push_back(y);
        inc[x].push_back(y);
        if(y>1){
            if(find(q[x].begin(),q[x].end(),y-1)==q[x].end())
                q[x].push_back(y-1);
        }
        if(y<m){
            if(find(q[x].begin(),q[x].end(),y+1)==q[x].end())
                q[x].push_back(y+1);
        }
        i++;
    }
    for(int i=1;i<n+1;i++){
        if(q[i].size()==0){
            cout << m-1 << endl;
            continue;
        }
        for(int j=0;j<inc[i].size();j++){
            inp[i][inc[i][j]]++;
        }
        bool flag=false;
        int ans=m-1;
        sort(q[i].begin(),q[i].end());
        for(int k=0;k<q[i].size();k++){
            if(q[i][k]+1 <= m && inp[i][q[i][k]+1]<inp[i][q[i][k]]){
                flag=true;
                break;
            }
            else{
                if(q[i][k]+1<=m){
                    ans+=(inp[i][q[i][k]+1]-inp[i][q[i][k]])-1;
                }
            }
        }
        if(flag){
            cout << -1 << endl;
        }
        else{
            cout << ans << endl;
        }
    }
}
