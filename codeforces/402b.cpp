#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
struct tree{
    tree(string a,int x,int y){
        pos=x;
        sz=y;
        sign = a;
    }
    string sign;
    int pos;
    int sz;
};
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> inp(n,0);
    vector<tree> out;
    int i=0;
    while(i<n){
        cin >> inp[i];
        i++;
    }
    int minute=0;
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(inp[i+1]-inp[i]!=k){
            if(inp[i+1]-inp[i]<k){
                minute = k-(inp[i+1]-inp[i]);
                //cout << "+" << " " << i+2 << " " << minute << " " << inp[i+1] << " " << inp[i] << endl;
                inp[i+1] += minute;
                out.push_back(tree("+",i+2,minute));
            }
            else{
                minute = (inp[i+1]-inp[i])-k;
                //cout << "-" << " " << i+2 << " " << minute << " " << inp[i+1] << " " << inp[i] << endl;
                inp[i+1] -= minute;
                out.push_back(tree("-",i+2,minute));
            }
            cnt++;
        }
    }
    cout << cnt << endl;
    for(int i=0;i<out.size();i++){
        cout << out[i].sign << " " << out[i].pos << " " << out[i].sz << endl;
    }
}
*/
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> inp(n,0);
    int m=0;
    while(m<n){
        cin >> inp[m];
        m++;
    }
    int minm=1001;int init=1;int t_min=0;
    vector<int> temp(n,0);
    for(int i=1;i<=1000;i++){
        for(int j=0;j<n;j++){
            temp[j] = i+(j*k);
        }
        for(int j=0;j<n;j++){
            if(inp[j]!=temp[j]){
                t_min++;
            }
        }
        if(t_min<minm){
            minm=t_min;
            init = i;
        }
        t_min = 0;
    }
    cout << minm << endl;
    for(int i=0;i<n;i++){
        temp[i] = init+(i*k);
        if(inp[i]!=temp[i]){
            if(inp[i]>temp[i]){
                cout << "-" << " " << i+1 << " " << inp[i]-temp[i] << endl;
            }
            else{
                cout << "+" << " " << i+1 << " " << temp[i]-inp[i] << endl;
            }
        }
    }
}
