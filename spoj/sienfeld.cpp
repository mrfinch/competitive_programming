#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int m=1;
    while(true){
        string s;
        cin >> s;
        if(s[0]=='-'){
            break;
        }
        int c=0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{'){
                st.push(s[i]);
            }
            else if(s[i]=='}'){
                if(st.empty()==true){
                    c++;
                    st.push('{');
                }
                else{
                    st.pop();
                }
            }
        }
        c+=(st.size()/2);
        cout << m << "." << " " << c << endl;
        m++;
    }
}
