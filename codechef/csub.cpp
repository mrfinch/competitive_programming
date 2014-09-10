#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        string s;
        cin >> s;
        long long c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')
                continue;
            for(int j=n-1;j>=i;j--){
                if(s[j]=='1')
                    c++;
            }
        }
        cout << c << endl;
        t--;
    }
}

