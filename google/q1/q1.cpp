#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

void transpose(vector< vector<int> >& matrix,int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
    }
}
void left(vector< vector<int> >& a,int n){
    for(int i=0;i<n;i++){
        int k=0;int j=0;
        while(j<n-1){
            if(a[i][j]==a[i][j+1] && a[i][j]!=0){
                //cout << "h " << i << " " << j <<" " << k << endl;;
                int c=a[i][j];a[i][j+1]=0;a[i][j]=0;
                a[i][k]=2*c;k++;j+=2;
            }
            else if(a[i][j]==0){
                j++;
            }
            else if(a[i][j]!=a[i][j+1] && a[i][j]!=0 && a[i][j+1]!=0){
                int c=a[i][j];
                a[i][j]=0;
                a[i][k]=c;
                j++;k++;
            }
            else if(a[i][j+1]==0){
                int t=j+1;
                //cout << i << " " << t << endl;
                while(a[i][t]==0 && t<n)
                    t++;
                if(a[i][t]==a[i][j]){
                    //cout << "e\n";
                    int c=a[i][j];
                    a[i][j]=0;a[i][t]=0;
                    a[i][k]=2*c;
                    k++;
                    j=t+1;
                }
                else{
                	int c=a[i][j];
                	a[i][j]=0;
                	a[i][k]=c;
                	j=t;
                    k++;
                }
            }
        }
        if(a[i][k]==0 && a[i][n-1]!=0){
            int c=a[i][n-1];
            a[i][n-1]=0;
            a[i][k]=c;

        }
    }
}

void right(vector< vector<int> >& a,int n){
    for(int i=0;i<n;i++){
        int k=n-1;int j=n-1;
        while(j>0){
            if(a[i][j]==a[i][j-1] && a[i][j]!=0){
                //cout << "h " << i << " " << j <<" " << k << endl;;
                int c=a[i][j];a[i][j-1]=0;a[i][j]=0;
                a[i][k]=2*c;k--;j-=2;
            }
            else if(a[i][j]==0){
                j--;
            }
            else if(a[i][j]!=a[i][j-1] && a[i][j]!=0 && a[i][j-1]!=0){
                int c=a[i][j];
                a[i][j]=0;
                a[i][k]=c;
                j--;k--;
            }
            else if(a[i][j-1]==0){
                int t=j-1;
                //cout << i << " " << t << endl;
                while(a[i][t]==0 && t>=0)
                    t--;
                if(a[i][t]==a[i][j]){
                    //cout << "e\n";
                    int c=a[i][j];
                    a[i][j]=0;a[i][t]=0;
                    a[i][k]=2*c;
                    k--;
                    j=t-1;
                }
                else{
                    int c=a[i][j];
                	a[i][j]=0;
                	a[i][k]=c;
                    j=t;
                    k--;
                }
            }
        }
        if(a[i][k]==0 && a[i][0]!=0){
            int c=a[i][0];
            a[i][0]=0;
            a[i][k]=c;

        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
	freopen("input_l.txt", "rt", stdin);
	freopen("output_l.txt", "wt", stdout);
	int t;
	cin >> t;
	int q=1;
	while(t){
        int n;
        string d;
        cin >> n >> d;
        vector< vector<int> > a(n,vector<int>(n));
        int i=0,j;
        while(i<n){
            j=0;
            while(j<n){
                cin >> a[i][j];
                j++;
            }
            i++;
        }
        if(d=="right"){
            right(a,n);
        }
        else if(d=="left"){
            left(a,n);
        }
        else if(d=="up"){
            transpose(a,n);
            left(a,n);
            transpose(a,n);
        }
        else if(d=="down"){
            transpose(a,n);
            right(a,n);
            transpose(a,n);
        }
        i=0;
        cout << "Case #"<< q << ":" << endl;
        q++;
         while(i<n){
            j=0;
            while(j<n){
                cout << a[i][j] << " ";
                j++;
            }
            cout << endl;
            i++;
        }
    t--;
	}
}
