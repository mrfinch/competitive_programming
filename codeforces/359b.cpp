#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> inp(2*n+1);

    for(int i=1;i<2*n+1;i++){
        inp[i]=i;
    }
    for(int i=1;i<k+1;i++){
        int t = inp[2*i];
        inp[2*i]=inp[2*i-1];
        inp[2*i-1]=t;
    }
    for(int i=1;i<2*n+1;i++){
        cout << inp[i] << " ";
    }
}
