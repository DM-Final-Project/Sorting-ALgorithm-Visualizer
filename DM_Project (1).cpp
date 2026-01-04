#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

void visualizar(int arr[], int X)
{
    for (int i = 0; i < X; i++)
    {
        int bars = arr[i];
        int dots = bars;
        if (bars > 30)
            bars = 30;
        for (int j = 0; j < bars; j++)
            cout << "# ";
        if (dots > 30)
            cout << " ... ";
        cout << " (" << arr[i] << ")" << endl;
    }
    cout << endl;
}

// --- Sorting Algorithms (same as before) ---
void bubblesort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                visualizar(array, n);
            }
        }
    }
}
void selectionSort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        swap(array[i], array[min_idx]);
        visualizar(array, n);
    }
}
void insertionSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
        visualizar(array, n);
    }
}
void merge(int arr[], int l, int m, int r, int n)
{
    int n1 = m - l + 1, n2 = r - m, *L = new int[n1], *R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
        visualizar(arr, n);
    }
    while (i < n1)
        arr[k++] = L[i++], visualizar(arr, n);
    while (j < n2)
        arr[k++] = R[j++], visualizar(arr, n);
    delete[] L;
    delete[] R;
}
void mergeSort(int arr[], int l, int r, int n)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m, n);
    mergeSort(arr, m + 1, r, n);
    merge(arr, l, m, r, n);
}
int partition(int arr[], int n, int low, int high)
{
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            visualizar(arr, n);
        }
    }
    swap(arr[i + 1], arr[high]);
    visualizar(arr, n);
    return i + 1;
}
void quickSort(int arr[], int n, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, n, low, high);
        quickSort(arr, n, low, pi - 1);
        quickSort(arr, n, pi + 1, high);
    }
}

void displayComplexity(int choice, double milliseconds)
{
    cout << "\nTime Complexity Info:\n";
    cout << "---------------------------------------------------------------\n";
    cout << "Algorithm       | Best Case   | Worst Case   | Average Case | Time (ms)\n";
    cout << "---------------------------------------------------------------\n";
    switch (choice)
    {
    case 1:
        cout << "Bubble Sort     | O(n)        | O(n^2)       | O(n^2)       | " << milliseconds << "\n";
        break;
    case 2:
        cout << "Selection Sort  | O(n^2)      | O(n^2)       | O(n^2)       | " << milliseconds << "\n";
        break;
    case 3:
        cout << "Insertion Sort  | O(n)        | O(n^2)       | O(n^2)       | " << milliseconds << "\n";
        break;
    case 4:
        cout << "Merge Sort      | O(n log n)  | O(n log n)   | O(n log n)   | " << milliseconds << "\n";
        break;
    case 5:
        cout << "Quick Sort      | O(n log n)  | O(n^2)       | O(n log n)   | " << milliseconds << "\n";
        break;
    }
    cout << "---------------------------------------------------------------\n\n";
}

int main()
{
    while (true)
    {
        cout << "\n==============================================================\n";
        cout << "||  W E L C O M E  T O  S O R T I N G  A L G O R I T H M ||\n";
        cout << "||                    V I S U A L I Z E R                   ||\n";
        cout << "==============================================================\n\n";

        int size;
        cout << "Enter size of array: ";
        // Error handling for size input
        while (!(cin >> size)) {
            cout << "Please enter only integer: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        int *array = new int[size];
        cout << "Enter elements: ";
        for (int i = 0; i < size; i++) {
            // Error handling for each element
            while (!(cin >> array[i])) {
                cout << "Please enter only integer: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }

        cout << "\nInitial Array:\n";
        visualizar(array, size);

        cout << "Select Sorting Algorithm:\n1. Bubble\n2. Selection\n3. Insertion\n4. Merge\n5. Quick\n6. Exit\nEnter choice: ";
        int choice;
        // Error handling for menu choice
        while (!(cin >> choice)) {
            cout << "Please enter only integer: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "\n";

        int *arrCopy = new int[size];
        for (int i = 0; i < size; i++)
            arrCopy[i] = array[i];

        auto start = high_resolution_clock::now();

        switch (choice)
        {
        case 1:
            bubblesort(arrCopy, size);
            break;
        case 2:
            selectionSort(arrCopy, size);
            break;
        case 3:
            insertionSort(arrCopy, size);
            break;
        case 4:
            mergeSort(arrCopy, 0, size - 1, size);
            break;
        case 5:
            quickSort(arrCopy, size, 0, size - 1);
            break;
        case 6:
            delete[] array;
            delete[] arrCopy;
            return 0;
        default:
            cout << "Invalid choice!\n";
            delete[] array;
            delete[] arrCopy;
            continue;
        }

        auto stop = high_resolution_clock::now();
        chrono::duration<double, milli> duration = stop - start;
        displayComplexity(choice, duration.count());

        delete[] array;
        delete[] arrCopy;
        cout << "Press Enter to continue:";
        cin.ignore();
        cin.get();
        system("cls");
    }
}
