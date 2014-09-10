#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
   ll n;
   cin >> n;
   vector<ll> one;
   vector<ll> two;
   int i=0;
   ll m=0;
   while(i<n){
        ll w,c;
        cin >> w >> c;
        if(w==1)
            one.push_back(c);
        else
            two.push_back(c);
        m+=w;
        i++;
   }
   sort(one.begin(),one.end());
   sort(two.begin(),two.end());
   vector<ll> out(m,0);

   if(one.size()>=1){
        out[0]=one[one.size()-1];
        //out.pop_back();
   }
   ll cost1=0;
   if(one.size()>=2){
        cost1+=one[one.size()-1];
        cost1+=one[one.size()-2];
   }
   ll cost2=0;
   if(two.size()>=1){
        cost2+=two[two.size()-1];
   }
   if(cost1>cost2){
        out[1]=cost1;
        //one.pop_back();
        //one.pop_back();
   }else{
        out[1]=cost2;
        //two.pop_back();
   }

   for(int i=2;i<m;i++){
        cost1=0;cost2=0;
        ll cost3=0;
        if(two.size()>=1){
            cost2=out[i-2]+two[two.size()-1];
        }
        if(one.size()>=2){
            cost1=out[i-2]+one[one.size()-1]+one[one.size()-2];
        }
        if(one.size()>=1){
            cost3=out[i-1]+one[one.size()-1];
        }
        cout << cost1 << " " << cost2 << " " << cost3 << endl;
        cout << one.size() << " " << two.size() << endl;
        if(cost1>=cost2 && cost1>=cost3){
            out[i]=cost1;
            //one.pop_back();
            //one.pop_back();
        }
        else if(cost2>=cost3 && cost2>=cost1){
            out[i]=cost2;
            //two.pop_back();
        }
        else{
            out[i]=cost3;
            //one.pop_back();
        }
   }
   for(int i=0;i<out.size();i++){
        cout << out[i] << " ";
   }
   cout << endl;
}
