#include <iostream>
#include<stdio.h>
using namespace std;
void merge(int*,int*,int,int,int);
void mergesort(int *a, int*b, int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=(low+high)/2;
        mergesort(a,b,low,pivot);
        mergesort(a,b,pivot+1,high);
        merge(a,b,low,pivot,high);
    }
}
void merge(int *a, int *b, int low, int pivot, int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;
 
    while((h<=pivot)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>pivot)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=pivot; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
}
void sort (int *array, int low, int high) {
    //Insertion sort
    for (int i = low; i < high; i++) {
        for (int j = i - 1; j >= low; j--) {
            if (array[i] < array [j]) {
                int holder = array[j];
                array[j] = array[i];
                array[i] = holder;
                i--;
            }
        }
    }
}
void merge_improved (int *array, int *sub, int low, int mid, int high) {
    //Merge part of mergesort
    int a = low;
    int b = low;
    int c = mid;

    while ((a < mid) && (c < high)) {
        if (array[a] <= array[c]) {
            sub[b] = array[a];
            a++;
        } else {
            sub[b] = array[c];
            c++;
        }
        b++;
    }
    while (a == mid && c < high) {
        sub[b] = array[c];
        c++;
        b++;
    }
    while (c == high && a < mid) {
        sub[b] = array[a];
        a++;
        b++;
    }
    for (int d = low; d < high; d++) {
        array[d] = sub[d];
    }
}
void split (int *array, int *sub, int low, int high) {
    //Split part of mergesort
    if (low < high - 1) {
        int mid = (low + high) / 2;
        split(array, sub, low, mid);
        split(array, sub, mid, high);
        if ((high - low) > 10){
            merge_improved(array, sub, low, mid, high);
        } else {
            sort(array, low, high);
        }

    }
}

int main()
{
   
    int num;
   

     int a[100000],a1[100000],c,d,swap;
    time_t start,end,start1,end1;
    double tc,tc1,tc2;
    int n;
    cout<<"enter total elements:   ";
    cin >> n;
    
    for(c=n;c>0;c--)
    {
        a[c]=c+1;
	a1[c]=c+1;
    }
/*     for(c=n;c>0;c--)
    {
        a1[c]=c+1;
        
    }*/
    int * sub = new int [n];
    int b[n];
     start1=clock();
      mergesort(a1,b,0,n-1);
      end1=clock();
       tc1=(difftime(end1,start1)/CLOCKS_PER_SEC);
    start=clock();
    split(a, sub, 0, n);
     end=clock();
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
     printf("Time taken by mergesort %lf second\n",tc1);
    printf("Time taken by improved mergesort is %lf second\n",tc);
     tc2=((tc1-tc)/tc1)*100;
     printf("time efficiency is %lf\%\n\n",tc2);
    return 0;

}       
