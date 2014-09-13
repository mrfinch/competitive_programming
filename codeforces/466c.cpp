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
    int n;
    cin >> n;
    vector<int> a(n);
    int m=0;
    while(m<n){
        cin >> a[m];
        m++;
    }
    if(n<=2){
        cout << 0 << endl;
        return 0;
    }
    vector<ll> l(n);
    vector<ll> r(n);
    l[0]=a[0];
    for(int i=1;i<n;i++){
        l[i]=l[i-1]+a[i];

    }
    r[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        r[i]=r[i+1]+a[i];
        //cout << r[i] << endl;
    }
    ll c=0;
    ll fs,ss,ts;
    /*for(int i=0;i<n;i++){
        for(int j=n-1;j>i+1;j--){
            fs=l[i];ss=r[j];
            ts=l[j-1]-l[i];
            //cout << fs << " " << ss << " " << ts << " " << i << " " << j << endl;
            if(fs==ss && ss==ts){
                c++;
            }
        }
    }*/
    /*int i=0,j=n-1;
    while((j-i)>1){
        //cout << i << " " << j << " " << l[i] << " " << r[j] << endl;
        if(l[i]==r[j]){
            ss=l[j-1]-l[i];
            if(ss==l[i]){
                //cout << i << " " << j << " " << ss <<endl;
                c++;
                int q=i+1;
                int x1=i,x2=j;
                while((j-i)>1 && l[q]==l[i]){
                    c++;

                    q++;
                    i=q;
                }
                q=j-1;
                while(j-i>1 && r[q]==r[j]){
                    c++;
                    q--;
                    j=q;
                }
                if(i==x1 && j==x2){
                    if(l[i+1]<=r[j]){
                        i++;
                    }
                    else{
                        j--;
                    }
                }
            }
            else{
                if(l[i+1]<=r[j]){
                    i++;
                }
                else{
                    j--;
                }
            }
        }
        else{
            if(l[i+1]<=r[j]){
                i++;
            }
            else{
                j--;
            }
        }
    }*/
    for(int i=1;i<n-1;i++){
        fs=l[i-1];ts=r[i+1];
        if(fs==ts && fs==a[i]){
            c++;
            int w=i+1;
            while(w<n-1 && a[w]==0){
                c++;
                w++;
            }
            w=i-1;
            while(w>0 && a[w]==0){
                c++;
                w--;
            }
        }
    }
    cout << c << endl;
}
