using System;
using System.Collections.Generic;

namespace Parte2
{
    class Program
    {
        static void Main(string[] args)
        {

            // Nos hacemos los Conjuntos Necesaios para esta practica
            HashSet<int> pares = new HashSet<int>();
            HashSet<int> multiplos = new HashSet<int>();
            HashSet<int> conjuntoUnion = new HashSet<int>();
            HashSet<int> conjuntoInterseccion = new HashSet<int>();
            HashSet<int> conjuntoDiferencia = new HashSet<int>();

            for (int i = 1; i <= 10; ++i)
            {
                if (i % 2 == 0)
                {
                    pares.Add(i);
                }

                if (i % 4 == 0)
                {
                    multiplos.Add(i);
                }

            }



            int menu = 0;
            int flag = 0;

            do
            {

                // Menu para los conjunto
                Console.WriteLine("Escoge una opcion (1-5)");
                Console.WriteLine("1. Mostrar conjuntos 1 y 2.");
                Console.WriteLine("2. Unir conjuntos 1 y 2.");
                Console.WriteLine("3. Interseccion de conjuntos 1 y 2.");
                Console.WriteLine("4. Diferencia de conjuntos 1 y 2.");
                Console.WriteLine("5. Salir.");
                menu = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine();

                switch (menu)
                {
                    case 1:
                        // Imprimimos los conjuntos
                        Console.WriteLine("Conjunto 1: ");
                        MostrarConjuntos(pares);
                        Console.WriteLine("Conjunto 2: ");
                        MostrarConjuntos(multiplos);

                        break;

                    case 2:
                        // Unimos conjuntos e imprimimos el conjunto
                        // Union
                        unirConjuntos(pares, multiplos, out conjuntoUnion);
                        Console.WriteLine("Conjunto Union: ");
                        MostrarConjuntos(conjuntoUnion);
                        break;

                    case 3:
                        //Hacemos la interseccion e imprimimos el conjunto interseccion
                        IntereccionConjnutos(pares, multiplos, out conjuntoInterseccion);
                        Console.WriteLine("Conjunto Interseccion: ");
                        MostrarConjuntos(conjuntoInterseccion);
                        break;
                    case 4:
                        // Hacemos la diferencia e imprimimos el conjunto diferencia
                        diferenciaConjuntos(pares, multiplos, out conjuntoDiferencia);
                        Console.WriteLine("Conjunto diferencia: ");
                        MostrarConjuntos(conjuntoDiferencia);
                        break;

                    default:
                        flag = 1;
                        Console.WriteLine("Adios.\n");
                        break;
                }


            } while (flag == 0);





        }




        // Muestra los numeros del conjunto c1
        public static void MostrarConjuntos(HashSet<int> c1)
        {
            foreach (int element in c1)
            {
                Console.WriteLine("{0} ", element);
            }
            Console.WriteLine();
        }


        // Une dos conjuntos y los pone en el nuevo conjunto
        public static void unirConjuntos(HashSet<int> c1, HashSet<int> c2, out HashSet<int> ConjuntoNuevo)
        {
            HashSet<int> auxiliar = c1;
            auxiliar.UnionWith(c2);
            ConjuntoNuevo = auxiliar;
        }



        // Calcula la interseccion del conjunto 1 con el conjunto 2 y lo guarda en el nuevo conjunto
        public static void IntereccionConjnutos(HashSet<int> c1, HashSet<int> c2, out HashSet<int> ConjuntoNuevo)
        {
            // HashSet ya tiene una funcion para la Interseccion de Conjuntos
            HashSet<int> auxiliar = c1;
            auxiliar.IntersectWith(c2);
            ConjuntoNuevo = auxiliar;

        }

        public static void diferenciaConjuntos(HashSet<int> c1, HashSet<int> c2, out HashSet<int> ConjuntoNuevo)
        {
            // HashSet ya tiene una funcion para la Interseccion de Conjuntos
            HashSet<int> auxiliar = c1;
            HashSet<int> auxiliar2 = c2;

            auxiliar2.ExceptWith(auxiliar);
            ConjuntoNuevo = auxiliar;

        }
    }
}
