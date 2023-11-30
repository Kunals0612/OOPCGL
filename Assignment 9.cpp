// Assignment 9
#include <iostream>
using namespace std;
template <class Z>
void insertionSort(Z arr[], int n)
{
    int i, j;
    float key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
template <class T>
void selectionSort(T arr[], int n)
{
    int i, j;
    int min_idx;

    for (i = 0; i < n - 1; i++)
    {

        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

int main()
{
    int n;
    cout << "Enter the size of array: " << endl;
    cin >> n;
    float a[n];
    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    selectionSort<float>(a, n);
    cout << "selection sort" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    insertionSort<float>(a, n);
    cout << "Insertion sort" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
