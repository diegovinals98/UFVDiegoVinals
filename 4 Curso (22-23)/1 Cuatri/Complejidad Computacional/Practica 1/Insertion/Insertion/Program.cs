// INSERTION SORT EN C#
using System;

class InsertionSort
{

    // Function to sort array
    // using insertion sort
    void sort(int[] arr)
    {
        int n = arr.Length;
        for (int i = 1; i < n; ++i)
        {
            int key = arr[i];
            int j = i - 1;

            // Move elements of arr[0..i-1],
            // that are greater than key,
            // to one position ahead of
            // their current position
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    // A utility function to print
    // array of size n
    static void printArray(int[] arr)
    {
        int n = arr.Length;
        for (int i = 0; i < n; ++i)
            Console.Write(arr[i] + " ");

        Console.Write("\n");
    }

    // Driver Code
    public static void Main()
    {
        int[] array2 = { 1, 2, 3, 4, 20, 6, 7, 8, 24, 10, 11, 12, 14, 13, 15, 16, 17, 18, 19, 5, 21, 22, 23, 9, 25 };
        int[] array3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
        int[] array4 ={ 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2,1};

        Console.WriteLine(" ARRAY 2");
        Console.WriteLine("Array inicial");
        printArray(array2);
        InsertionSort ob = new InsertionSort();
        ob.sort(array2);
        Console.WriteLine("Array ordenado");
        printArray(array2);

        Console.WriteLine(" ARRAY 3");
        Console.WriteLine("Array inicial");
        printArray(array3);
        InsertionSort ob1 = new InsertionSort();
        ob1.sort(array3);
        Console.WriteLine("Array ordenado");
        printArray(array3);

        Console.WriteLine(" ARRAY 4");
        Console.WriteLine("Array inicial");
        printArray(array4);
        InsertionSort ob2 = new InsertionSort();
        ob2.sort(array4);
        Console.WriteLine("Array ordenado");
        printArray(array4);
    }
}


