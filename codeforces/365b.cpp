#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> inp(n);
    int i=0;
    while(i<n){
        cin >> inp[i];
        i++;
    }
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    if(n==2){
        cout << 2 << endl;
        return 0;
    }
    vector<bool> out(n,false);
    out[0]=true;
    out[1]=true;
    int max=2;
    int ii=2;
    for(int i=2;i<n;i++){
        if(inp[i]==(inp[i-1]+inp[i-2])){
            out[i]=true;
        }
    }
    for(int i=2;i<n;i++){
        if(out[i]){
            ii++;
        }
        else{
            if(ii>max){
                max=ii;
            }
            ii=2;
        }
    }
    if(ii>max){
        max=ii;
    }
    if(max<2 && n>=2){
        max=2;
    }
    else if(max<2 && n==1){
        max=1;
    }
    cout << max << endl;

}
