#include <iostream>
#include <vector>
#include <climits>
#include <cstdio>
using namespace std;

int main(){
    int n,m,k,p;
    cin>>n>>m>>k>>p;
    //vector< vector<int> > inp(n+1,vector<int>(m+1,0));
    vector<int> row(n+1,0);
    vector<int> col(m+1,0);
    int i=1;
    while(i<n+1){
        int j=1;
        while(j<m+1){
            int t;
            scanf("%d",&t);
            //inp[i][j]=t;
            row[i]+=t;
            col[j]+=t;
            j++;
        }
        i++;
    }
    int sum=0;
    while(k){
        int rmax=INT_MIN;
        int cmax=INT_MIN;
        int rind=0;
        int cind=0;
        for(int i=1;i<n+1;i++){
            if(row[i]>rmax){
                rmax=row[i];
                rind=i;
            }
        }
        for(int i=1;i<m+1;i++){
            if(col[i]>cmax){
                cmax=col[i];
                cind=i;
            }
        }
        //cout << rmax << " " << cmax << endl;
        if(rmax>=cmax){
            sum+=rmax;
            row[rind]-=(m*p);
            for(int i=1;i<m+1;i++){
                col[i]-=p;
            }
        }
        else{
            sum+=cmax;
            col[cind]-=(n*p);
            for(int i=1;i<n+1;i++){
                row[i]-=p;
            }
        }
        k--;
    }
    cout << sum << endl;
}
