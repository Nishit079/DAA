#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int a[],int low,int high){
int pivot=a[high];
int i=low-1,temp,j;
for(j=low;j<high;j++){
if(a[j]<pivot){
i++;
temp=a[i]; a[i]=a[j]; a[j]=temp;
}
}
temp=a[i+1]; a[i+1]=a[high]; a[high]=temp;
return i+1;
}
void quickSort(int a[],int low,int high){
if(low<high){
int pi=partition(a,low,high);
quickSort(a,low,pi-1);
quickSort(a,pi+1,high);
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
quickSort(arr,0,n-1);
end=clock();
printf("Random Data Time: %lf\n",(double)(end-start)/CLOCKS_PER_SEC);
start=clock();
quickSort(sorted,0,n-1);
end=clock();
printf("Sorted Data Time: %lf\n",(double)(end-start)/CLOCKS_PER_SEC);
}