/*#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
int mx=-1;
int x=-1;
int y=-1;
int dr[] = {0,0,-1,1};
int dc[] = {1,-1,0,0};
int r,c;
vector< vector<char> > a(1005,vector<char>(1005));
vector< vector<bool> > vis(1005,vector<bool>(1005,false));
void dfs(int g,int h,int l){
    if(l>mx){
        mx=l;
        x=g,y=h;
    }
    vis[g][h]=true;
    for(int i=0;i<4;i++){
        if(g+dr[i]>=0 && g+dr[i]<r && h+dc[i]>=0 && h+dc[i]<c && vis[g+dr[i]][h+dc[i]]==false && a[g+dr[i]][h+dc[i]]=='.'){
            dfs(g+dr[i],h+dc[i],l+1);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t){
        cin >> c >> r;
        int i=0,j=0;
        while(i<r){
        	j=0;
            while(j<c){
                cin >> a[i][j];
                j++;
            }
            i++;
        }
        bool q=false;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]=='.'){
                    dfs(i,j,0);
                    for(int i=0;i<1005;i++){
                        for(int j=0;j<1005;j++){
                            vis[i][j]=false;
                        }
                    }
                    mx=-1;
                    dfs(x,y,0);
                    q=true;
                }
                if(q)
                	break;
            }
            if(q)
            	break;
        }
        printf("Maximum rope length is %d.\n",mx);
        t--;
    }
}
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define For(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define Fill(a,b) memset(&a,b,sizeof(a))

const int dr[]={0,0,1,-1};
const int dc[]={1,-1,0,0};

int cols, rows, maxd, maxr, maxc;
char s[1005][1005], v[1005][1005];

void dfs(int r, int c, int l){
	if (l > maxd) {maxd=l; maxr=r; maxc=c;}
	v[r][c]=1;
	For(i,0,3) if (r+dr[i]>=0&&r+dr[i]<rows&&c+dc[i]>=0&&c+dc[i]<cols&&
			v[r+dr[i]][c+dc[i]]==0&&s[r+dr[i]][c+dc[i]]=='.')
		dfs(r+dr[i],c+dc[i],l+1);
}

int main(){
	int t;
	scanf("%d",&t);

	For(z,1,t) {
		scanf("%d%d\n",&cols,&rows);
		For(j,1,rows) gets(s[j-1]);
		For(i,0,rows-1) For(j,0,cols-1) if (s[i][j]=='.') {
			maxd=-1; Fill(v,0);
			dfs(i,j,0);

			maxd=-1; Fill(v,0);
			dfs(maxr,maxc,0);

			printf("Maximum rope length is %d.\n",maxd);
			goto fin;
		}
		fin:;
	}

	return 0;
}
