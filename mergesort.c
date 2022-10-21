#include <stdio.h>
#include <limits.h>

void merge(int arr[], int lb, int mid1, int mid2, int mid3, int up)
{
    int n1 = mid1 - lb + 1;
    int n2 = mid2 - mid1;
    int n3 = mid3 - mid2;
    int n4 = up - mid3;
    int arr1[n1 + 1], arr2[n2 + 1], arr3[n3 + 1], arr4[n4 + 1];
    arr1[n1] = INT_MAX;
    arr2[n2] = INT_MAX;
    arr3[n3] = INT_MAX;
    arr4[n4] = INT_MAX;

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[lb + i];
    }
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[mid1 + i + 1];
    }
    for (int i = 0; i < n3; i++)
    {
        arr3[i] = arr[mid2 + i + 1];
    }
    for (int i = 0; i < n4; i++)
    {
        arr4[i] = arr[mid3 + i + 1];
    }
    int i = 0, j = 0, k = 0, l = 0, z = lb;

    while (i <= n1 && j <= n2 && k <= n3 && l <= n4 && z <= up)
    {
        if (arr1[i] < arr2[j] && arr1[i] < arr3[k] && arr1[i] < arr4[l])
        {
            arr[z++] = arr1[i++];
        }
        else if (arr2[j] < arr3[k] && arr2[j] < arr4[l])
        {
            arr[z++] = arr2[j++];
        }
        else if (arr3[k] < arr4[l])
        {
            arr[z++] = arr3[k++];
        }
        else
        {
            arr[z++] = arr4[l++];
        }
    }
}

void mergesort(int arr[], int lb, int up)
{
    if (lb < up)
    {
        int mid2 = (lb + up) / 2;
        int mid1 = (lb + mid2) / 2;
        int mid3 = (mid2 + up + 1) / 2;
        mergesort(arr, lb, mid1);
        mergesort(arr, mid1 + 1, mid2);
        mergesort(arr, mid2 + 1, mid3);
        mergesort(arr, mid3 + 1, up);
        merge(arr, lb, mid1, mid2, mid3, up);
    }
}

void main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
