#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        string q;
        cin >> q;
        string h;
        cin >> h;
        int i=0;
        int x;
        vector<int> ind;
        while((x=(h.find(q,i)))!=string::npos){
            ind.push_back(x);
            i=x+1;
        }
        for(int i=0;i<ind.size();i++){
            cout << ind[i] << endl;
        }
        cout << endl;
    }
}
