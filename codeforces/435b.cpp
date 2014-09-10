#include <iostream>
#include <string>

using namespace std;

int main(){
    string inp;
    int t;
    cin >> inp >> t;
    int maxm=-1;
    int pos=0;
    for(int i=0;i<inp.length()-1&&t>0;i++){
        for(int j=i;j<=i+t&&j<inp.length();j++){
            if(inp[j]-'0'>maxm){
                maxm = inp[j]-'0';
                pos = j;
            }
        }
        //cout << pos << maxm << " " << inp << " " << t <<endl;
        for(int k=pos;k>i;k--){
            swap(inp[k],inp[k-1]);
            t--;
        }
        maxm=-1;
        pos=0;
    }

    cout << inp << endl;
}
