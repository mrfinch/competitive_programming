#include <cmath>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <bitset>
#include <memory.h>
#include <functional>
#include <queue>
#include <fstream>
#include <ctime>
#include <deque>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <cctype>
#include <numeric>
#include <iomanip>
#include <assert.h>
#include <climits>

using namespace std;

typedef long long ll;
vector<int> a(100005);
vector< pair<int,bool> > tree(1000000,make_pair(0,false));


int find3mul(int pos,int st,int ed,int qi,int qj){
    //cout << st << " " << ed << " " << pos << " " << tree[pos].first << endl;
    if(qi>ed || qj<st){
        return -1;
    }
    if(st>=qi && ed<=qj){
        //cout << "h " << tree[pos].first << endl;
        //cout << st << " " << ed << " " << pos << " " << tree[pos].first << endl;
        if(st==ed){
            return (tree[pos].first%3==0?1:0);
        }
        return tree[pos].first;
    }
    int mid=(st+ed)/2;
    int p1=find3mul(2*pos,st,mid,qi,qj);
    int p2=find3mul(2*pos+1,mid+1,ed,qi,qj);
    if(p1==-1 && p2==-1){
        return 0;
    }
    if(p1==-1){
        return p2;
    }
    if(p2==-1){
        return p1;
    }
    return p1+p2;
}

void update(int pos,int st,int ed,int ui,int uj){
    //cout << st << " " << ed << " " << pos << " " << tree[pos].first << endl;
    if(ui>ed || uj<st){
        return;
    }

    if(st==ed && st>=ui && ed<=uj){
		//cout << st << " " << ed << " " << pos << " " << tree[pos].first << endl;
        tree[pos].first++;
    }
    else{
        int mid=(st+ed)/2;
        update(2*pos,st,mid,ui,uj);
        update(2*pos+1,mid+1,ed,ui,uj);
        tree[pos].first=0;

        if(tree[2*pos].second==true && tree[2*pos].first%3==0){
            tree[pos].first+=1;
        }
        else if(tree[2*pos].second==true && tree[2*pos].first%3!=0){
            tree[pos].first+=0;
        }
        if(tree[2*pos+1].second==true && tree[2*pos+1].first%3==0){
            tree[pos].first+=1;
        }
        else if(tree[2*pos+1].second==true && tree[2*pos+1].first%3!=0){
            tree[pos].first+=0;
        }
        if(tree[2*pos].second==false){
            tree[pos].first+=tree[2*pos].first;
        }
        if(tree[2*pos+1].second==false){
            tree[pos].first+=tree[2*pos+1].first;
        }
        //cout << st << " " << ed << " " << pos << " " << tree[pos].first << endl;

    }
}

void constructST(int pos,int st,int ed){
    if(st==ed){
        tree[pos].first=0;
        tree[pos].second=true;
    }
    else{
        int mid=(st+ed)/2;
        constructST(2*pos,st,mid);
        constructST(2*pos+1,mid+1,ed);
        if(tree[2*pos].second==true && tree[2*pos].first%3==0){
            tree[pos].first++;
        }
        if(tree[2*pos+1].second==true && tree[2*pos+1].first%3==0){
            tree[pos].first++;
        }
        if(tree[2*pos].second==false){
            tree[pos].first+=tree[2*pos].first;
        }
        if(tree[2*pos+1].second==false){
            tree[pos].first+=tree[2*pos+1].first;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int n,q;
    cin >> n >> q;
    constructST(1,1,n);
    while(q){
        int a,b,c;
        cin >> a >> b >> c;
        if(a==0){
            update(1,1,n,b+1,c+1);
        }
        else{
            cout << find3mul(1,1,n,b+1,c+1) << endl;
        }
        q--;
    }
    /*for(int i=1;i<20;i++){
        cout << tree[i].first << endl;
    }*/
      //n in included in tree
}
