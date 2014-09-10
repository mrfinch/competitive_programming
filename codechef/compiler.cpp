#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t>0){
        string inp;
        cin >> inp;
        int cnt=0;
        int temp=0;
        for(int i=0;i<inp.size();i++){
            if(inp[i]=='<'){
                temp++;
            }
            else{
                temp--;
                if(temp==0){
                    cnt=max(temp,i+1);
                }
                if(temp<0){
                    break;
                }
            }
        }
        cout << cnt << endl;
        t--;
    }
}
