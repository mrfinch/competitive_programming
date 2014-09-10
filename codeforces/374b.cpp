#include <iostream>
#include <string>

using namespace std;

int main(){
    string inp;
    cin >> inp;
    long long cnt=1;
    int i=0;
    bool x=false;
    int j=0;
    int s;
    while(i<inp.size()-1){
        if(inp[i]-'0'+inp[i+1]-'0'==9){
            s=2;
            j=i+1;
            while(j<inp.size()-1){
                if(inp[j]-'0'+inp[j+1]-'0'==9){
                    s++;
                    x=true;
                    i=j+2;
                }
                else{
                    break;
                }
                j++;
                //cout << "t " << j << endl;
            }
            if(s%2==1){
                cnt*=((s/2)+1);
            }
        }
        if(!x){
            i++;
        }
        x=false;
        //cout << i << " " << x << endl;
    }
    cout << cnt << endl;
}
