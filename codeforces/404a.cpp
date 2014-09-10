#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> inp(n);
    int i=0;
    while(i<n){
        cin >> inp[i];
        i++;
    }
    bool no=false;
    for(int i=0;i<inp.size();i++){
        if(inp[i].at(i)!=inp[i].at(inp.size()-i-1) || inp[i].at(inp.size()-i-1)!=inp[0].at(0)){
            no=true;
            break;
        }
    }
    if(no){
        cout << "NO" << endl;
        return 0;
    }
    char x= inp[0].at(1);
    no=false;
    if(x==inp[0].at(0)){
        cout << "NO" << endl;
        return 0;
    }
    for(int i=0;i<inp.size();i++){
        for(int j=0;j<inp[i].size();j++){
            if(j==i || j==(inp.size()-i-1)){
                continue;
            }
            if(x!=inp[i].at(j)){
                no=true;
                break;
            }
        }
    }
    if(no){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}
