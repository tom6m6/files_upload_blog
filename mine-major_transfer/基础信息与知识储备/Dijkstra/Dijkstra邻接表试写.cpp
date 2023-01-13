#include <cstdio>
#include <iostream>
#define INF 2147483647
using namespace std;
int n,m,s;
int u[50006],v[50006],w[50006];
int nnext[50006],first[50006];
int book[10006],ans[10006];
int main(){
	std::ios::sync_with_stdio(false);
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++)first[i]=-1;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		nnext[i]=first[u[i]];
		first[u[i]]=i;
	}
	book[s]=1;
	for(int i=1;i<=n;i++)ans[i]=INF;
	ans[s]=0;
	int k=first[s];
	while(k!=-1){
		ans[v[k]]=w[k];
		k=nnext[k];
	}
	int tmp;
	for(int i=1;i<=n;i++){
		int minn=INF;
		for(int j=1;j<=n;j++)if(book[j]==0 && ans[j]<INF){
			if(minn>ans[j]){
				minn=ans[j];
				tmp=j;
			}
		}
		book[tmp]=1;
		k=first[tmp]; 
		while(k!=-1){
			if(ans[v[k]]>ans[tmp]+w[k])ans[v[k]]=ans[tmp]+w[k];
			k=nnext[k];
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}
