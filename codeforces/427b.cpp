#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n,t,c;
    cin >> n >> t >> c;
    vector<int> inp(n+1,0);
    int i=1;
    while(i<n+1){
        cin >> inp[i];
        i++;
    }
    long long cnt=0;
    /*for(int i=1;i<inp.size()-(c-1);i++){
        long long x=i+c;
        bool v=true;
        for(int j=i;j<x;j++){
            if(inp[j]>t){
                v=false;
                break;
            }
        }
        if(v)
            cnt++;
    }*/
    long long l=0;
    cout << inp.size() << endl;
    for(int i=1;i<inp.size();i++){
        if(inp[i]<=t){
            l++;
        }
        else{
            cnt+=(l-c+1);
            l=0;
        }

    }
    if((l-c+1)>0){
        cnt+=l-c+1;
    }
    cout << cnt << endl;
}
