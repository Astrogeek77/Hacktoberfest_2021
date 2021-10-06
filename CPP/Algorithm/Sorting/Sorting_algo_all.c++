//This repositry include all sorting algorithm
#include<bits/stdc++.h>
using namespace std;
/******************************Selection sort*********************/
void swap(int*a,int*b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void selction_sort(int arr[],int n)
{
	int min_val;
	for(int i=0;i<n-1;i++)
	{
		min_val=i;
		for(int j=i+1;j<n;j++)
		{
			min_val=j;
		}
		swap(&arr[min_val],&arr[i]);
	}

	

}
/*****************************Merge sort*********************/

void merge(int *a, int *l, int nL, int *r, int nR)
{
    // int nL = sizeof(l)/sizeof(int);
    // int nR = sizeof(r)/sizeof(int);
    int i=0,j=0,k=0;
    while(i < nL && j < nR)
    {
        if(l[i] < r[j])
            a[k++] = l[i++];
        else
            a[k++] = r[j++];
    }
    while(i < nL)
    {
        a[k++] = l[i++];
    }
    while(j < nR)
    {
        a[k++] = r[j++];
    }
}


void merge_sort(int *a, int len)
{
    if(len<2)
        return;
    int mid = len/2;
    int *left = (int *)malloc(mid*sizeof(int));
    int *right = (int *)malloc(sizeof(int)*(len-mid));
    for(int i=0;i<mid;i++)
        left[i] = a[i];
    for(int i=mid;i<len;i++)
        right[i-mid] = a[i];
    merge_sort(left, mid);
    merge_sort(right, len-mid);
    merge(a, left, mid, right, len-mid);
}
/******************************Quick sort*********************/
void quick_sort(int *array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quick_sort(array, low, j);
    if (i < high)
        quick_sort(array, i, high);
}

/******************************Insertion sort*********************/
void insertion_sort(int arr[], int length) {
      int i, j, tmp;
      for (i = 1; i < length; i++) {
            j = i;
            while (j > 0 && arr[j - 1] > arr[j]) {
                  tmp = arr[j];
                  arr[j] = arr[j - 1];
                  arr[j - 1] = tmp;
                  j--;
            }
      }
}



using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	//Insertion sort
	selction_sort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	//Merge_sort
	merge_sort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	//Quick sort
	quick_sort(arr,0,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	//Insertion sort

    insertion_sort(arr,n);
    for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}

}