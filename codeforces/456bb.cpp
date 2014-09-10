#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

int divide(string a,int d){
    int tmp=a[0]-'0';
    //cout << tmp << endl;
    for(int i=0;i<a.size();i++){
        if(tmp>=d){
            int y=tmp/d;
            tmp=tmp%d;
        }
        else{
            if(i==0){
                continue;
            }
            if(tmp==0){
                tmp=a[i]-'0';
            }
            else{
                tmp=tmp*10+((a[i]-'0'));
                tmp=tmp%d;
            }
        }
        //cout << tmp << endl;
    }
    if(tmp>=d){
        return tmp%d;
    }
    return tmp;
}
int main(){
    string n;
    cin >> n;
    //int x=divide(n,4);
    //cout << x ;
    int x;
    if(n.size()>=2){
        int t=10*(n[n.size()-2]-'0')+(n[n.size()-1]-'0');
        if(t%4==0){
            x=0;
        }
        else{
            x=1;
        }
    }
    else{
        if(n.size()==1){
            int t=n[n.size()-1]-'0';
            if(t%4==0){
                x=0;
            }
            else{
                x=1;
            }
        }
    }
    if(x%4==0){
        cout << 4 << endl;
    }
    else{
        cout << 0 << endl;
    }
}
