#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool myfunc(int a,int b){
    return a>b;
}

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<int> v(26);
    int m=0;
    while(m<26){
        cin >> v[m];
        m++;
    }
    int sum=0;
    int i;
    for(i=0;i<s.size();i++){
        sum+=((i+1)*v[(s[i]-'a')]);
    }
    sort(v.begin(),v.end(),myfunc);

    //i--;
    for(int j=0;j<k;j++){
        sum+=((i+1)*v[0]);
        i++;
    }
    cout << sum << endl;
}
