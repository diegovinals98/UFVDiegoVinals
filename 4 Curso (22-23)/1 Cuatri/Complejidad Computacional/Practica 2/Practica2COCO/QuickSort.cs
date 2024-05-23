using System;
using System.Collections.Generic;
using System.Text;

namespace Practica2COCO
{
    class QuickSort
    {
		public QuickSort()//Funcion para crear elementos del tipo quicksort
		{

		}

		

		//MÉTODO QUICKSORT PARA ORDENAR DE MAYOR A MENOR POR VALOR
		public void Quicksort(int[] a, int[] b, int[] c, int izq, int der)
		{

			// Declaracion de la variable pivote
			int pivote;

			if (izq < der)
			{
				// Posición definitiva del pivote y recoloca los elementos menores y mayores
				pivote = particionar(a, b, c, izq, der);
                //Recursividad del subvector izquierdo
                Quicksort(a, b, c, izq, pivote - 1);
                //Recursividad del subvector derecho
                Quicksort(a, b, c, pivote + 1, der);
			}
		}

		public int particionar(int[] a, int[] b, int[] c, int izq, int der)
		{
			// Declaracion de variables
			int i;
			int pivote, valor_pivote;
			int aux, aux2, aux3; //Variable auxiliar para realizar el intercambio
			pivote = izq; //Posición del pivote
			valor_pivote = a[pivote]; //Valor pivote

			//Recorremos vector
			for (i = izq + 1; i <= der; i++)
			{
				//Ordenamos de mayor a menor
				if (a[i] > valor_pivote)
				{
					pivote++; //Avanzamos el pivote 1 posición e intercambiamos
					aux = a[i];
					a[i] = a[pivote];
					a[pivote] = aux;

					aux2 = b[i];
					b[i] = b[pivote];
					b[pivote] = aux2;

					aux3 = c[i];
					c[i] = c[pivote];
					c[pivote] = aux3;
				}
			}
			//Intercambio de valores del peso
			aux = a[izq];
			a[izq] = a[pivote];
			a[pivote] = aux;

			//Intercambio de valores de los valores
			aux2 = b[izq];
			b[izq] = b[pivote];
			b[pivote] = aux2;

			//Intercambio de valores del valor/peso
			aux3 = c[izq];
			c[izq] = c[pivote];
			c[pivote] = aux3;

			return pivote; //Nos devuelve la posición correcta del pivote
		}

		
	}
}
