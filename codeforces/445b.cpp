#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> inp[n+1];
    vector<bool> used(n+1,false);
    int a=0;
    int t1,t2;
    while(a<m){

        cin >> t1 >> t2;
        inp[t1].push_back(t2);
        inp[t2].push_back(t1);
        a++;
    }
    if(m==0){
        cout << 1 << endl;
        return 0;
    }
    stack<int> s;
    s.push(t1);
    bool allused=false;
    int comp=1;
    while(!allused){
        int x=s.top();
        s.pop();
        used[x]=true;
        //cout << x << " " << inp[x].size() << endl;
        for(int i=0;i<inp[x].size();i++){
            if(used[inp[x][i]]==false){
                s.push(inp[x][i]);
            }
        }
        //cout << "c " << comp << endl;
        if(s.empty()){
            allused=true;
            for(int i=1;i<used.size();i++){
                if(used[i]==false){
                    s.push(i);
                    comp++;
                    allused=false;
                    break;
                }
            }
        }
    }

    //cout << (n-comp) << endl;
    long long out=1<<(n-comp);
    cout << out << endl;
}
