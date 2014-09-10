#include <iostream>
#include <vector>

using namespace std;

int main(){
    string x[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    vector<string> a(x,x+sizeof(x)/sizeof(string));
    int n;
    cin >> n;
    vector<string> req;
    for(int i=0;i<a.size();i++){
        if(a[i].size()==n){
            req.push_back(a[i]);
        }
    }
    string s;
    cin >> s;

    for(int i=0;i<req.size();i++){
        bool q = true;
        for(int j=0;j<s.size();j++){
            if(s[j]=='.'){
                continue;
            }
            else{
                if(s[j]!=req[i][j]){
                    q=false;
                    break;
                }
            }
        }
        if(q){
            cout << req[i] << endl;
            break;
        }
    }
}
