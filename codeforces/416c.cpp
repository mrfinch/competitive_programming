#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct visitor{
    visitor(int i,int j,int k,int l){
        c=i;
        p=j;
        pos=k;
        tnum=l;
    }
    int c;
    int p;
    int pos;
    int tnum;
};

struct table{
    table(int i,int j,bool k){
        val=i;
        pos=j;
        used=k;
    }
    int val;
    int pos;
    bool used;
};

bool visfunc(visitor a,visitor b){
    return a.p>b.p;
}

bool tabfunc(table a,table b){
    return a.val<b.val;
}

int main(){
    int n;
    cin >> n;
    vector<visitor> inp(n+1,visitor(0,0,0,-1));
    int m=1;
    while(m<n+1){
        int t1,t2;
        cin >> t1 >> t2;
        inp[m].c = t1;
        inp[m].p = t2;
        inp[m].pos = m;
        m++;
    }
    int k;
    cin >> k;
    vector<table> t(k+1,table(0,0,false));
    m=1;
    while(m<k+1){
        int t1;
        cin >> t1;
        t[m].val=t1;
        t[m].pos=m;
        m++;
    }
    sort(inp.begin()+1,inp.end(),visfunc);
    sort(t.begin()+1,t.end(),tabfunc);
    int taken=0;
    int cnt=0;
    for(int i=1;i<inp.size();i++){
        for(int j=1;j<t.size();j++){
            if(inp[i].c<=t[j].val && t[j].used==false){
                t[j].used=true;
                taken++;
                cnt+=inp[i].p;
                inp[i].tnum=t[j].pos;
                break;
            }
        }
    }
    cout << taken << " " << cnt << endl;
    for(int i=1;i<inp.size();i++){
        if(inp[i].tnum!=-1){
            cout << inp[i].pos << " " << inp[i].tnum << endl;
        }
    }
}
