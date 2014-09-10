#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
//not complete don't know how to store path of graph
struct node{
    node(int x,int y,int z){
        cur=x;prev=y;step=z;
    }
    int cur;
    int prev;
    int step;
};

int main(){
    vector<int> wt;
    string st;
    cin >> st;
    for(int i=0;i<st.size();i++){
        if(st[i]=='1'){
            wt.push_back(i+1);
        }
    }
    int m;
    cin >> m;
    stack<node> s;
    s.push(node(0,0,0));
    int moves=0;
    vector<node> steps;
    int p=0;
    while(s.empty()==false){
        node x=s.top();
        if(x.step>p){
            steps.push_back(x);
            p=x.step;
        }

        //cout << x.cur << " " << x.prev << " " << x.step << endl;
        s.pop();
        moves=max(moves,x.step);
        if(x.cur>10){
            steps.clear();
            p=0;
            //steps.push_back(node(0,0,0));
            continue;
        }
        if(x.step==m){
            break;
        }
        for(int i=0;i<wt.size();i++){
            if(wt[i]!=x.prev){
                if(x.step%2==0){
                    if(x.cur+wt[i]<10 && x.cur+wt[i]>0){
                        s.push(node(x.cur+wt[i],wt[i],x.step+1));
                    }
                }
                else{
                    if(x.cur-wt[i]<0 && abs(x.cur-wt[i])<10){
                        s.push(node(x.cur-wt[i],wt[i],x.step+1));
                    }
                }
            }
        }
    }
    if(moves==m){
        cout << "YES" <<endl;
        for(int i=0;i<m;i++){
            cout << steps[i].prev << " ";
        }
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
