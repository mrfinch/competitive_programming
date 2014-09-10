#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main(){
        string s;
        cin >> s;
        vector< pair<int,int> > inp(s.size());
        vector<int> ngb[10];
        for(int i=0;i<inp.size();i++){
            inp[i].first=s[i]-'0';
            inp[i].second=i;
            ngb[s[i]-'0'].push_back(i);
        }
        vector<int> d(inp.size(),9999);
        vector<int> vis(inp.size(),false);
        d[0]=0;
        queue< pair<int,int> > q;
        q.push(inp[0]);
        vis[0]=true;
        while(!q.empty()){
            pair<int,int> x = q.front();
            q.pop();
            //cout << x.second << " " << d[1] << " " << d[2] << " " << d[3] << endl;
            for(int i=0;i<ngb[x.first].size();i++){
                if(x.second==ngb[x.first][i]){
                    continue;
                }
                d[ngb[x.first][i]]=min(d[ngb[x.first][i]],d[x.second]+1);
                if(vis[ngb[x.first][i]]==false){
                    q.push(inp[ngb[x.first][i]]);
                    vis[ngb[x.first][i]]=true;
                }
            }
            ngb[x.first].clear();
            if(x.second-1>=0){
                d[x.second-1]=min(d[x.second-1],d[x.second]+1);
                if(vis[x.second-1]==false){
                    vis[x.second-1]=true;
                    q.push(inp[x.second-1]);
                }
            }
            if(x.second+1<inp.size()){
                d[x.second+1]=min(d[x.second+1],d[x.second]+1);
                if(vis[x.second+1]==false){
                    vis[x.second+1]=true;
                    q.push(inp[x.second+1]);
                }
            }
        }
        cout << d[inp.size()-1] << endl;
        return 0;
}
