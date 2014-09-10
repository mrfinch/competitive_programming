#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> inp(n+1,0);
    int i=1;
    while(i<n+1){
        cin >> inp[i];
        i++;
    }
    vector<int> out(k+1,0);
    for(int i=1;i<k+1;i++){
        for(int j=i;j<n+1;j+=k){
            out[i]+=inp[j];
        }
    }
    int minm=9999999999;
    int val=1;
    for(int i=1;i<k+1;i++){
        if(out[i]<minm){
            minm=out[i];
            val=i;
        }
    }
    cout << val << endl;
}
