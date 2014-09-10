#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool func(int i,int j){
    return (i>j);
}
int main(){
    int n,k;
    cin >> n >> k;
    int i=0;
    vector<int> inp(n,0);
    while(i<n){
        cin >> inp[i];
        i++;
    }
    sort(inp.begin(),inp.end(),func);
    cout << inp[k-1];
}
