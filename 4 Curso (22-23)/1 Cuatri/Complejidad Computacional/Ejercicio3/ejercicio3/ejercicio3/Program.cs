
using System;
using System.Collections.Generic;

namespace ejercicio3
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] lista = { 1, 21, 15, 39, 26, 89, 46, 108, 45, 97, 120, 57, 8, 35, 19, 12, 94, 47, 131 };
            int numero = posicionElemento(lista, 0, lista.Length, 11);
            Console.Write(numero);
            Console.ReadLine();
        }


       

        public static int posicionElemento(int[] lista, int inicio, int fin, int posicion)
        {

            
            if (lista.Length < 2)
            {
                return lista[inicio];
            }
            else
            {
                int pivote = particionar(lista, inicio, fin);
                
                if (pivote > posicion)
                {
                     posicionElemento(lista, inicio, pivote, posicion);
                    return 0;

                }
                else if (pivote < posicion)
                {

                     posicionElemento(lista, pivote, fin,posicion);
                    return 0;

                }
                else
                {
                    return lista[posicion];


                }


            }

            

        }
        static int particionar(int[] lista, int izq, int der)
        {
            int i;
            int pivote, valor_pivote;
            int aux;
            pivote = izq;
            valor_pivote = lista[pivote];
            for (i = izq + 1; i <= der; i++)
            {
                if (lista[i] < valor_pivote)
                {
                    pivote++;
                    aux = lista[i];
                    lista[i] = lista[pivote];
                    lista[pivote] = aux;

                }
            }
            aux = lista[izq];
            lista[izq] = lista[pivote];
            lista[pivote] = aux;
            return pivote;
        }




    }

    





}



