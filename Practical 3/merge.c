#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int l,int m,int r){
int i,j,k;
int n1=m-l+1;
int n2=r-m;
int L[n1],R[n2];
for(i=0;i<n1;i++) L[i]=a[l+i];
for(j=0;j<n2;j++) R[j]=a[m+1+j];
i=0;j=0;k=l;
while(i<n1 && j<n2){
if(L[i]<=R[j]) a[k++]=L[i++];
else a[k++]=R[j++];
}
while(i<n1) a[k++]=L[i++];
while(j<n2) a[k++]=R[j++];
}
void mergeSort(int a[],int l,int r){
if(l<r){
int m=(l+r)/2;
mergeSort(a,l,m);
mergeSort(a,m+1,r);
merge(a,l,m,r);
 }
}
int main(){
int n,i;
scanf("%d",&n);
int arr[n],sorted[n];
for(i=0;i<n;i++) arr[i]=rand()%1000;
for(i=0;i<n;i++) sorted[i]=i;
clock_t start,end;
start=clock();
mergeSort(arr,0,n-1);
end=clock();
printf("Random Data Time: %lf\n",(double)(end-start)/CLOCKS_PER_SEC);
start=clock();
mergeSort(sorted,0,n-1);
end=clock();
printf("Sorted Data Time: %lf\n",(double)(end-start)/CLOCKS_PER_SEC);
}