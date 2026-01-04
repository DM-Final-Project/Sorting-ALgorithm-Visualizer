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

int main()
{
    while (true)
    {
        cout << "\n==============================================================\n";
        cout << "||  W E L C O M E   T O   S O R T I N G   A L G O R I T H M ||\n";
        cout << "||                    V I S U A L I Z E R                   ||\n";
        cout << "==============================================================\n\n";

        int size;
        cout << "Enter size of array: ";
        cin >> size;
        int *array = new int[size];
        cout << "Enter elements: ";
        for (int i = 0; i < size; i++)
            cin >> array[i];

        cout << "\nInitial Array:\n";
        visualizar(array, size);

        cout << "Select Sorting Algorithm:\n1. Bubble\n2. Selection\n3. Insertion\n4. Merge\n5. Quick\n6. Exit\nEnter choice: ";
        int choice;
        cin >> choice;
        cout << "\n";

        // Copy array to preserve input
        int *arrCopy = new int[size];
        for (int i = 0; i < size; i++)
            arrCopy[i] = array[i];

        // Start timer
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
            break;
        case 4:
            break;
        case 5:
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
        delete[] array;
        delete[] arrCopy;
        cout << "Press Enter to continue:";
        cin.ignore();
        cin.get();
        system("cls");
    }
}