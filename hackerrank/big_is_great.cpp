#include <cmath>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <bitset>
#include <memory.h>
#include <functional>
#include <queue>
#include <fstream>
#include <ctime>
#include <deque>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <cctype>
#include <numeric>
#include <iomanip>
#include <assert.h>
#include <climits>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int t;
    cin >> t;
    while(t){
        string s;
        cin >> s;
        int flag=false;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]<s[i+1]){
                flag=true;
                break;
            }
        }
        bool c=false;
        if(flag==false){
            cout << "no answer" << endl;
        }
        else{
            pair<string,bool> temp=make_pair(s,false);
            for(int i=s.size()-1;i>0;i--){
                string a=s;
                for(int j=i-1;j>=0;j--){
                    if(a[i]>a[j]){
                        char t=a[i];
                        a[i]=a[j];
                        a[j]=t;
                        if(temp.second==false){
                            temp.first=a;
                            temp.second=true;
                            if(i-j==1){
                                c=true;
                            }
                            //cout << temp.first << " " << "dh" << endl;
                            //break;
                        }
                        else{
                            if(lexicographical_compare(temp.first.begin(),temp.first.end(),a.begin(),a.end())){
                                //cout << temp.first.compare(a) << endl;
                                temp.first=a;
                                //cout << temp.first << endl;
                            }

                            if(i-j==1)
                                c=true;
                            //break;
                        }
                        //a=s;

                    }
                }
                if(c==true)
                    break;
            }
            cout << temp.first << endl;
        }
        t--;
    }
}
