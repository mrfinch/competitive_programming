#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> inp(n);
    int m=0;
    while(m<n){
        cin >> inp[m];
        m++;
    }
    int start=-1;
    for(int i=0;i<inp.size()-1;i++){
        if(inp[i]>inp[i+1]){
            start=i;
            break;
        }
    }
    if(start==-1){
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
    }
    else{
        int end=start;
        while(end<inp.size()-1 && inp[end]>inp[end+1]){
            end++;
        }
        int e=start+1;
        int f=end+1;
        while(start<end){
            int t=inp[start];
            inp[start]=inp[end];
            inp[end]=t;
            start++;
            end--;
        }
        bool done=true;
        for(int i=0;i<inp.size()-1;i++){
            if(inp[i]>inp[i+1]){
                done=false;
                break;
            }
        }
        if(done){
            cout << "yes" << endl;
            cout << e << " " << f << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
}
