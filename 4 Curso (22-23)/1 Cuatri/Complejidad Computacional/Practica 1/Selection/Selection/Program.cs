// SELECTION SORT EN C#

using System;

class Selection
{
    static void sort(int[] arr)
    {
        int n = arr.Length;

        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n - 1; i++)
        {
            // Find the minimum element in unsorted array
            int min_idx = i;
            for (int j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            // Swap the found minimum element with the first
            // element
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }

    static void sort2(double[] arr)
    {
        double n = arr.Length;

        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n - 1; i++)
        {
            // Find the minimum element in unsorted array
            int min_idx = i;
            for (int j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            // Swap the found minimum element with the first
            // element
            double temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }



    // Prints the array
    static void printArray(int[] arr)
    {
        int n = arr.Length;
        for (int i = 0; i < n; ++i)
            Console.Write(arr[i] + " ");
        Console.WriteLine();
    }

    // Prints the double
    static void printArrayDouble(double[] arr)
    {
        int n = arr.Length;
        for (int i = 0; i < n; ++i)
            Console.Write(arr[i] + " ");
        Console.WriteLine();
    }

    // Driver code
    public static void Main()
    {
        int[] array1 ={ 20, 9, 23, 13, 6, 18, 25, 17, 4, 8, 15, 22, 16, 3, 24, 21, 14, 12, 1, 5, 7, 11, 19, 2, 10};
        int[] array5 = { 3, 8, 9, 6, 7, 5, 2, 3, 1, 4, 9, 7, 8, 10 };
        double[] array6 = { 6.9, 7.7, 5.1, 7.5, 7.8, 5.5, 7.3, 5.8,7.9, 6.1, 5.2, 6.4, 6.7,7.4, 6.5,6.8,7.1, 5.9, 7.0, 6.0,5.7, 5.4,7.2, 7.6,5.0, 5.3, 6.6, 8.0,5.6,6.2, 6.3 };
        int[] array7 = { 130, 690, 1888, 2579, 1, 9179, 6313, 748, 1514, 8103, 4998, 7211, 5144, 9127, 5, 777, 1113, 19, 2, 9304, 9999, 981, 394, 805 };
        string[] array8 = { "J", "G", "M", "A", "N", "E", "Z", "T", "B", "O", "D", "C" };

        Console.WriteLine(" ARRAY 1");
        Console.WriteLine("Array inicial");
        printArray(array1);
        sort(array1);
        Console.WriteLine("Array ordenado");
        printArray(array1);

        Console.WriteLine(" ARRAY 5");
        Console.WriteLine("Array inicial");
        printArray(array5);
        sort(array5);
        Console.WriteLine("Array ordenado");
        printArray(array5);

        Console.WriteLine(" ARRAY 6");
        Console.WriteLine("Array inicial");
        printArrayDouble(array6);
        sort2(array6);
        Console.WriteLine("Array ordenado");
        printArrayDouble(array6);

        Console.WriteLine(" ARRAY 7");
        Console.WriteLine("Array inicial");
        printArray(array7);
        sort(array7);
        Console.WriteLine("Array ordenado");
        printArray(array7);
    }

}