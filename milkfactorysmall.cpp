#include <bits/stdc++.h> using namespace std;
int n,i,r,o[101];int main(){freopen("factory.in","r",stdin);freopen("factory.out","w",stdout);scanf("%d", &n);for(i=0;i<n-1;i++){int a,b;scanf("%d%d",&a,&b);o[a]++;}r=-1;for(i=1;i<n;i++){if(o[i]==0&&r!=-1){r=-1;break;}else if(o[i]==0){r=i;}}printf("%d",r);}
