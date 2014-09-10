#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int t=10;
    while(t){
        string n,m;
        cin >> n;
        cin >> m;
        int x=max(n.size(),m.size());
        vector<int> a1(n.size(),0);
        vector<int> a2(m.size(),0);
        vector<int> sum(x,0);
        vector<int> diff(x,0);
        for(int i=0;i<n.size();i++){
            a1[i]=n[i]-'0';
        }
        for(int i=0;i<m.size();i++){
            a2[i]=m[i]-'0';
        }
        int i=n.size()-1;
        int j=m.size()-1;
        int in=x-1;
        int carry=0;
        while(i>=0 && j>=0){
            if(i==0 && j==0){
                sum[in]=(a1[i]+a2[j]+carry);
            }
            else{
                sum[in]=(a1[i]+a2[j]+carry)%10;
            }

            carry=(a1[i]+a2[j]+carry)/10;
            i--;j--;in--;
        }
        while(i>=0){
            if(i==0){
                sum[in]=(a1[i]+carry);
            }
            else{
                sum[in]=(a1[i]+carry)%10;
            }
            carry=(a1[i]+carry)/10;
            i--;in--;
        }
        while(j>=0){
            if(j==0){
                sum[in]=(a2[j]+carry);
            }
            else{
                sum[in]=(a2[j]+carry)%10;
            }
            carry=(a2[j]+carry)/10;
            j--;in--;
        }
        /*for(int i=0;i<sum.size();i++){
            cout << sum[i] << endl;
        }*/

        i=n.size()-1;
        j=m.size()-1;
        in=x-1;
        int borrow=0;
        while(i>=0 && j>=0){
            if(a1[i]>=a2[j]){
                diff[in]=a1[i]-a2[j];
                //cout << diff[in] << " g" << i << j <<endl;
                i--;j--;in--;
            }
            else{
                int ind=i-1;
                while(a1[ind]==0){
                    ind--;
                }
                //cout << ind << " " << a1[ind] << endl;
                a1[ind]--;
                int q=i-ind;
                int d=11-q;
                for(int k=ind+1;k<=i;k++){
                    if(k==i){
                        a1[k]=10+a1[k];
                    }
                    else
                        a1[k]=9;
                    //d++;
                }
                diff[in]=a1[i]-a2[j];
                i--;j--;in--;
            }
        }
        while(i>=0){
                diff[in]=a1[i];
                i--;in--;
        }
        /*for(int i=0;i<diff.size();i++){
            cout << diff[i] << endl;
        }*/

        vector<int> d_sum(sum.size(),0);
        vector<int> d_diff(diff.size(),0);
        int rem=0;
        for(int i=0;i<d_sum.size();i++){
            d_sum[i]=(sum[i]+rem*10)/2;
            rem=(sum[i]+rem*10)%2;
        }
        bool zero=true;
        for(int i=0;i<d_sum.size();i++){
            if(zero==true){
                if(d_sum[i]!=0){
                    cout << d_sum[i];
                    zero=false;
                }
            }
            else{
                cout << d_sum[i];
            }
        }
        cout << endl;
        rem=0;
        for(int i=0;i<d_diff.size();i++){
            d_diff[i]=(diff[i]+rem*10)/2;
            rem=(diff[i]+rem*10)%2;
        }
        zero=true;
        for(int i=0;i<d_diff.size();i++){
            if(zero==true){
                if(d_diff[i]!=0){
                    cout << d_diff[i];
                    zero=false;
                }
            }
            else{
                cout << d_diff[i];
            }
        }
        cout << endl;
        t--;
    }
}
