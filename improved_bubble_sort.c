#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int newgap(int gap)
{
    gap = (gap * 10) / 13;
    if (gap == 9 || gap == 10)
        gap = 11;
    if (gap < 1)
        gap = 1;
    return gap;
}
void bubblesort_improved(int a[], int aSize)
{
    int gap = aSize;
    int temp, i;
    for (;;)
    {
        gap = newgap(gap);
        int swapped = 0;
        for (i = 0; i < aSize - gap; i++) 
        {
            int j = i + gap;
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                swapped  =  1;
            }
        }
        if (gap  ==  1 && !swapped)
            break;
    }
}
int main ()
{
    int a[100000],a1[100000],c,d,swap;
    time_t start,end,start1,end1;
    double tc,tc1,tc2;
    int n;
    printf("enter total elements:   ");
    scanf("%d",&n);
    
    for(c=n;c>0;c--)
    {
        a[c]=c+1;
    }
     for(c=n;c>0;c--)
    {
        a1[c]=c+1;
        
    }
    start1=clock();
    
    for(c=0;c<n-1;c++)
    {
        for(d=0;d<n-c-1;d++)
        {
            if(a1[d]>a1[d+1])
            {
                swap=a1[d];
                a1[d]=a1[d+1];
                a1[d+1]=swap;
            }
        }
    }
    
    end1=clock();
    tc1=(difftime(end1,start1)/CLOCKS_PER_SEC);


    start=clock();
   
    bubblesort_improved(a, n);
    end=clock();
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("Time taken by bubble sort %lf second\n",tc1);
    printf("Time taken by improved bubble sort is %lf second\n",tc);
    tc2=((tc1-tc)/tc1)*100;
    printf("time efficiency is %lf\%\n",tc2);
    return 0;
}