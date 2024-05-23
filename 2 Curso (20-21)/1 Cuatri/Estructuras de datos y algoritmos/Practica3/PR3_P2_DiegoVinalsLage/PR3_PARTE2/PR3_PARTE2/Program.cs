using System;

namespace PR3_PARTE2
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] matriz1 = new int[] { 7, 8, 9, 1, 3, 15 };
            int[] matriz2 = new int[] { 12, 2, 6 };
            int[] matriz3 = new int[8];
            int contadorMatriz3 = 0;
            int contadorMatriz1 = 0;
            int contadorMatriz2 = 0;


            Array.Sort(matriz1);
            Array.Sort(matriz2);

            Console.WriteLine("Matriz 1 Ordenada:");
            for(int i = 0; i < matriz1.Length;i++)
            {
                Console.WriteLine(matriz1[i]);
            }
            Console.WriteLine();
            Console.WriteLine("Matriz 2 Ordenada:");
            for (int i = 0; i < matriz2.Length; i++)
            {
                Console.WriteLine(matriz2[i]);
            }
            Console.WriteLine();

            while(contadorMatriz3 < matriz3.Length)
            {
                if (matriz1[contadorMatriz1] < matriz2[contadorMatriz2])
                {
                    matriz3[contadorMatriz3] = matriz1[contadorMatriz1];
                    contadorMatriz1++;
                } else
                {
                    matriz3[contadorMatriz3] = matriz2[contadorMatriz2];
                    contadorMatriz2++;
                }
                contadorMatriz3++;
            }
            

            Console.WriteLine("Matriz 3 Ordenada:");
            for (int i = 0; i < matriz3.Length; i++)
            {
                Console.WriteLine(matriz3[i]);
            }
            Console.WriteLine();
        }


    }
}
