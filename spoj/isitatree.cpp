#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool dfs(vector<int>* inp,vector<bool>& vis,int k){
    stack<int> s;
    s.push(k);
    bool no=false;
    while(s.empty()==false){
        int x=s.top();
        if(vis[x]){
            no=true;
            return no;
        }
        s.pop();
        vis[x]=true;
        for(int i=0;i<inp[x].size();i++){
            s.push(inp[x][i]);
        }
    }
    return false;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> inp[n];
    int i=0;
    int k;
    while(i<m){
    	int t1,t2;
        cin >> t1 >> t2;
        inp[t1-1].push_back(t2-1);
        k=t1-1;
        i++;
    }
    vector<bool> vis(n,false);
    bool no=false;
    for(int i=0;i<vis.size();i++){
        if(vis[i]==false){
            no = dfs(inp,vis,i);
            if(no){
                break;
            }
        }
    }
    if(no){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }

}
