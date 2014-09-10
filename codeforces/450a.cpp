#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int i=0;
    int j=0;
    vector<int> inp(n);
    while(j<n){
        cin >> inp[j];
        j++;
    }
    int cnt=0;
    int ind=0;
    while(true){
        if(inp[i]==0){
            i++;
            if(i==n){
                i=0;
            }
            continue;
        }
        if(inp[i]>m){
            inp[i]-=m;
            i++;
            if(i==n){
                i=0;
            }
        }
        else{
            inp[i]=0;
            cnt++;
            if(cnt==n){
                ind=i;
                break;
            }
            i++;
            if(i==n){
                i=0;
            }
        }
    }
    cout << ind+1 << endl;
}
