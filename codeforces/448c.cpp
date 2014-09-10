#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> inp(n);
    int m=0;
    while(m<n){
        cin>>inp[m];
        m++;
    }
    ll cnt=0;
    int c=0;
    while(true){
        ll h_sum=0;
        int h_s=0;
        int h_e=0;
        ll m_h_sum=0;
        int m_s=0;
        int m_e=0;

        for(int i=0;i<inp.size();i++){
            if(inp[i]<=0){
                h_sum=0;
                h_s=i;
                h_e=i;
            }
            else{
                //cout << "n " << h_sum << endl;
                h_sum+=inp[i];
                h_e=i;
                if(h_sum>m_h_sum){
                    m_h_sum=h_sum;
                    m_s=h_s;
                    m_e=h_e;
                }
            }
            //cout << inp[i] << " " << h_sum << endl;

        }
        ll v_sum=0;
        int v_i=0;
        for(int i=0;i<inp.size();i++){
            if(inp[i]>v_sum){
                v_sum=inp[i];
                v_i=i;
            }
        }
        if(m_h_sum==0 && v_sum==0){
            break;
        }
        if(v_sum>=m_h_sum){
            inp[v_i]=0;
            cnt++;
        }
        else{
            for(int i=m_s;i<=m_e;i++){
                if(inp[i]>0){
                    inp[i]--;
                }
            }
            cnt++;
        }
        c++;
        if(c>inp.size()){
            cnt=inp.size();
            break;
        }
        //cout << m_h_sum << " " << v_sum << " "<< m_e << " " << m_s << endl;
    }
    cout << cnt << endl;
}
