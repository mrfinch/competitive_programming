#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<long long> inp(n,0);
    long long sum=0;
    int i=0;
    while(i<n){
        cin >> inp[i];
        i++;
    }
    sort(inp.begin(),inp.end());
    for(int i=0;i<n;i++){
        if(x<1){
            x=1;
        }
        sum+=(inp[i]*x);
        x-=1;
    }
    cout << sum << endl;
}
