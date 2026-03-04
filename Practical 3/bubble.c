#include<stdio.h>
#include<stdlib.h>
#include<time.h>
    void bubbleSort(int a[], int n){
int i,j,temp;
   for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
    if(a[j]>a[j+1]){
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
      }
    }
 }
}
   int main(){
int n,i;
printf("Enter Size:");
scanf("%d",&n);
int arr[n],sorted[n];
for(i=0;i<n;i++) arr[i]=rand()%1000;
for(i=0;i<n;i++) sorted[i]=i;
clock_t start,end;
start=clock();
bubbleSort(arr,n);
end=clock();
printf("Random Data Time: %lf\n",(double)(end-start)/CLOCKS_PER_SEC);
start=clock();
bubbleSort(sorted,n);
end=clock();
printf("Sorted Data Time: %lf\n",(double)(end-start)/CLOCKS_PER_SEC);
}