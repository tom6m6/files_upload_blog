//Eɸ 
#include <cstdio>
using namespace std;
bool a[100000000];
int n; 
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		if(a[i])continue;
		printf("%d is prime\n",i);
		for(int j=2;j*i<=n;j++)a[i*j]=1;
	}
	return 0;
}
