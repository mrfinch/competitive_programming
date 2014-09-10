#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        vector< pair<int,int> > inp(n+1,make_pair(0,0));
        int m=1;
        while(m<n+1){
            int x;
            cin >> x;
            inp[m].first=x; //score
            inp[m].second=m;
            m++;
        }
        int q;
        cin >> q;
        while(q){
            int x;
            cin >> x;
            if(x==0){
                int n1,n2;
                cin >> n1 >> n2;
                bool move=true;
                if(inp[n1].second==inp[n2].second){
                    cout << "Invalid query!" << endl;
                    move=false;
                }
                if(move){
                    int c1=inp[n1].second;
                    int c2=inp[n2].second;
                    int i1=0,m1=0;
                    int i2=0,m2=0;
                    vector<int> cd1;
                    vector<int> cd2;
                    for(int i=1;i<inp.size();i++){
                        if(inp[i].second==c1){
                            if(inp[i].first>m1){
                                m1=inp[i].first;
                                i1=i;

                            }
                            cd1.push_back(i);
                        }
                        else if(inp[i].second==c2){
                            if(inp[i].first>m2){
                                m2=inp[i].first;
                                i2=i;

                            }
                            cd2.push_back(i);
                        }
                    }
                    if(inp[i1].first>inp[i2].first){
                        for(int i=0;i<cd2.size();i++){
                            inp[cd2[i]].second=inp[i1].second;
                        }
                        //inp[i2].second=inp[i1].second;
                    }
                    else{
                        for(int i=0;i<cd1.size();i++){
                            inp[cd1[i]].second=inp[i2].second;
                        }
                        //inp[i1].second=inp[i2].second;
                    }
                }
            }
            else{
                int n1;
                cin >> n1;
                cout << inp[n1].second << endl;
            }
            q--;
        }
        t--;
    }
}
