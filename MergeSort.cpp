#include <iostream>
using namespace std;
void mergeSort(int length);
void partition(int start, int end);
void merge(int start, int mid, int end);
void printArray(int arr[], int length);

int arr[10000001];
int* tempArr;

int main()
{
    int length;
    cin >> length;

    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    tempArr = new int[length];

    mergeSort(length);

    printArray(arr, length);

    cout << endl;

    delete[] tempArr;
}

void mergeSort(int length)
{
    partition(0, length - 1);
}

void partition(int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        partition(start, mid);
        partition(mid + 1, end);
        merge(start, mid, end);
    }
}

void merge(int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;

    // 나눠진 요소들을 합친다
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            tempArr[k] = arr[i];
            i++;
        }
        else
        {
            tempArr[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i <= mid)
    {
        while (i <= mid)
        {
            tempArr[k] = arr[i];
            i++;
            k++;
        }
    }

    if (j <= end)
    {
        while (j <= end)
        {
            tempArr[k] = arr[j];
            j++;
            k++;
        }
    }

    for (int n = start; n <= end; n++)
    {
        arr[n] = tempArr[n];
    }
}

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }
}