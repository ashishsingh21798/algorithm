#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include  <time.h>
#include <stdio.h>
using namespace std;
int partition_improved(int arr[], int l, int r, int k);
int kthSmallest(int arr[], int l, int r, int k);
void quickSort_improved(int arr[], int l, int h)
{
    if (l < h)
    {
        int n = h-l+1;
        int med = kthSmallest(arr, l, h, n/2);
        int p = partition_improved(arr, l, h, med);
        quickSort_improved(arr, l, p - 1);
        quickSort_improved(arr, p + 1, h);
    }
}
int findMedian(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[n/2]; 
}
int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1;
        int i, median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }
        int medOfMed = (i == 1)? median[i-1]:
                                 kthSmallest(median, 0, i-1, i/2);
        int pos = partition_improved(arr, l, r, medOfMed);
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return kthSmallest(arr, l, pos-1, k);
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
    return INT_MAX;
}
 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition1(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    
    do
    {
        do
            i++;
            
        while(a[i]<v&&i<=u);
        
        do
            j--;
        while(v<a[j]);
        
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    
    a[l]=a[j];
    a[j]=v;
    
    return(j);
}
void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition1(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}

int partition_improved(int arr[], int l, int r, int x)
{
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[100000],a1[100000],c,d,swap;
    time_t start,end,start1,end1;
    double tc,tc1,tc2;
    int n;
    printf("enter total elements:   ");
    scanf("%d",&n);
    
    for(c=n;c>0;c--)
    {
        arr[c]=c+1;
	a1[c]=c+1;
    }
/*     for(c=n;c>0;c--)
    {
        a1[c]=c+1;
        
    }*/
    start1=clock();
    quick_sort(a1,0,n-1);
    end1=clock();
    tc1=(difftime(end1,start1)/CLOCKS_PER_SEC);
    start=clock();
    quickSort_improved(arr, 0, n-1);
    //printArray(arr, n);
    end=clock();
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
     printf("Time taken by quicksort %lf second\n",tc1);
    printf("Time taken by improved quicksort is %lf second\n",tc);
     tc2=((tc1-tc)/tc1)*100;
    printf("time efficiency is %lf\%\n\n",tc2);
    return 0;
}
