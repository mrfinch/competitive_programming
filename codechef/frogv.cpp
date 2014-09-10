#include <iostream>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;


int main(){
    int n,k,p;
    cin >> n >> k >> p;
    vector< pair<int,int> > inp(n,make_pair(0,0));
    int m=0;
    while(m<n){
        int t;
        cin >> t;
        inp[m].first=t;  //val
        inp[m].second=m; //pos
        m++;
    }
    sort(inp.begin(),inp.end());
    m=0;
    while(m<p){
        int a,b;
        cin >> a >> b;
        int pos=0;
        for(int i=0;i<inp.size();i++){
            if(inp[i].second==(a-1)){
                pos=i;
                break;
            }
        }
        bool poss=true;
        for(int i=pos+1;i<inp.size();i++){
            if(inp[i].second==(b-1) && inp[i].first-inp[i-1].first<=k){
                break;
            }
            if(inp[i].first-inp[i-1].first>k){
                poss=false;
                break;
            }
        }
        if(poss)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        m++;
    }
}
