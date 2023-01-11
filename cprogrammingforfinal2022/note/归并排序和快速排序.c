/*今天晚上自由练习，我凭借自己的理解写一下主要的那两种排序吧*/
/*快速排序，归并排序,从小到大版本*/
#include <stdio.h>
#include <stdlib.h>
int n,a[100000+6],b[100000+6];
int get1(int arr[],int left,int right){
    int i=left,j=right,k=arr[left];
    int tmp;
    while(i<j){
        while((i<j)&&(arr[j]>=k))j--;
        while((i<j)&&(arr[i]<=k))i++;
        tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
    }
    arr[left]=arr[i];
    arr[i]=k;
    return i;
}
void quicksort(int arr[],int left,int right){
    if(left>=right)return;
    int mid=get1(arr,left,right);
    quicksort(arr,left,mid-1);
    quicksort(arr,mid+1,right);
    return;
}
void merge(int *arrl,int *arrr,int x,int y,int *arr){
    int i=1,j=1,k=1;
    while(i<=x&&j<=y){
        if((*(arrl+i))<=(*(arrr+j))){
            *(arr+k)=*(arrl+i);
            i++;k++;
        }
        else{
            *(arr+k)=*(arrr+j);
            j++;k++;
        }
    }
    while(i<=x){
        *(arr+k)=*(arrl+i);
        i++;k++;
    }
    while(j<=y){
        *(arr+k)=*(arrr+j);
        j++;k++;
    }
    return;
}
void mergesort(int *arr,int lenn){
    if(lenn==1)return;
    int x=lenn/2,y;y=lenn-x;
    int *arrleft;int *arrright;
    arrleft=(int *)malloc(x*sizeof(int)+sizeof(int));
    arrright=(int *)malloc(y*sizeof(int)+sizeof(int));
    for(int i=1;i<=x;i++)*(arrleft+i)=arr[i];
    for(int i=1;i<=y;i++)*(arrright+i)=arr[i+x];

    mergesort(arrleft,x);
    mergesort(arrright,y);
    merge(arrleft,arrright,x,y,arr);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);b[i]=a[i];}

    quicksort(b,1,n);
    for(int i=1;i<=n;i++)printf("%d ",b[i]);
    printf("\n");
    mergesort(a,n);
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}