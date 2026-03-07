#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionSort(int a[], int n){
int i,j,min,temp;
for(i=0;i<n-1;i++){
min=i;
for(j=i+1;j<n;j++){
if(a[j]<a[min]) min=j;
}
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
}
int main(){
int n,i;
printf("Enter size: ");
scanf("%d",&n);
int arr[n],sorted[n];
for(i=0;i<n;i++) arr[i]=rand()%1000;
for(i=0;i<n;i++) sorted[i]=i;
clock_t start,end;
start=clock();
selectionSort(arr,n);
end=clock();
printf("Random Data Time: %lf\n",(double)(end-start)/CLOCKS_PER_SEC);
start=clock();
selectionSort(sorted,n);
end=clock();
printf("Sorted Data Time: %lf\n",(double)(end-start)/CLOCKS_PER_SEC);
}