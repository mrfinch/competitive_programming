#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    map< string,vector<string> > inp;
    int i=0;
    while(i<n){
        string s;
        cin >> s;
        if(inp[s].size()==0){
            inp[s].push_back(s);
            cout << "OK" << endl;
        }
        else{
            int x = inp[s].size();
            string m;
            m=x;
            string t=s+m;
            inp[s].push_back(t);
            cout << t << endl;
        }
        i++;
        //cout << inp[s].size();
    }
}
