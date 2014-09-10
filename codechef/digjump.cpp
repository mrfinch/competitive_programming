#include <iostream>
#include <string>

using namespace std;

int main(){
    string inp;
    cin >> inp;
    int i=0;
    int cnt=0;
    while(i<inp.size()-1){
        size_t  t;
        if((t=inp.find(inp[i],i))!=string::npos){
            i=t;
            cnt++;
        }
        else{
            cnt++;
            i++;
        }
    }
    cout << cnt << endl;
}

