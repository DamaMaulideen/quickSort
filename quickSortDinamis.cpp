#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    // memposisikan element pivot
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // sorting bagian kiri dan kanan pivot
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // mem partisi array
    int p = partition(arr, start, end);

    // Sorting bagian kiri
    quickSort(arr, start, p - 1);

     // Sorting bagian kanan
    quickSort(arr, p + 1, end);
}

void show(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int size;
    cout << "\nmasukan banyaknya data : ";
    cin >> size;
    int arr[size];
    cout << "\nmasukan nilai : ";
    for (int i = 0; i < size; ++i)
    {
        cout << "\n";
        cin >> arr[i];
    }
    quickSort(arr, 0, size - 1);
    cout << "Sorted array\n";
    show(arr, size);
    return 0;
}