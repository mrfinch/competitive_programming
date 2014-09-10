#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    string ans="";
    ans+=s[0];
    if(s.size()>1)
        ans+=s[1];
    for(int i=2;i<s.size();i++){
        if(s[i]==ans[ans.size()-1] && s[i]==ans[ans.size()-2]){
            //cout << "h" << endl;
        }
        else if(s[i]==ans[ans.size()-1] && i>2 && ans.size()>=3 &&ans[ans.size()-2]==ans[ans.size()-3]){
            //cout << "t" << endl;
        }
        else{
            ans+=s[i];
            //cout << "a" << ans <<endl;
        }
    }
    cout << ans << endl;
}
