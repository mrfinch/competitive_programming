#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int x,k;
    cin >> x >> k;
    int i=0;
    vector<int> inp(x,0);
    while(i<k){
        int temp;
        cin >> temp;
        if(temp==1){
            int j=0;
            while(j<2){
                cin >> temp;
                j++;
                inp[temp]=1;
            }
        }
        else{
            cin >> temp;
            inp[temp]=1;
        }
        i++;
    }
    /*
    for(int i=0;i<inp.size();i++){
        cout << i << " " << inp[i] << endl;
    }
    */
    int maxm = count(inp.begin(),inp.end(),0)-1;
    int minm = 0;
    for(int i=1;i<inp.size()-1;i++){
        if(inp[i]==inp[i+1] && inp[i]==0){
            minm += 1;
            inp[i]=1;
            inp[i+1]=1;
        }
        else if(inp[i]==0){
            minm += 1;
            inp[i]=1;
        }
    }
    if(inp[inp.size()-1]==0 && inp.size()-1!=0){
        minm+=1;
        inp[inp.size()-1]=1;
    }
    cout << minm << " " << maxm << endl;
}
