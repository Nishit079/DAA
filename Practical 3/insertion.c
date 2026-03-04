#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertionSort(int a[], int n){
int i,key,j;
for(i=1;i<n;i++){
key=a[i];
j=i-1;
while(j>=0 && a[j]>key){
a[j+1]=a[j];
j--;
} a
[j+1]=key;
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
insertionSort(arr,n);
end=clock();
printf("Random Data Time: %lf\n",(double)(end-start)/CLOCKS_PER_SEC);
start=clock();
insertionSort(sorted,n);
end=clock();
printf("Sorted Data Time: %lf\n",(double)(end-start)/CLOCKS_PER_SEC);
}