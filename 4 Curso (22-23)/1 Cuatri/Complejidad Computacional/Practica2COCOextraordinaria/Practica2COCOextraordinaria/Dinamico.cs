using System;
namespace Practica2COCOextraordinaria
{
	public class Dinamico
	{
        public static List<Producto> SeleccionarMercanciasDinamico(List<Producto> productos, int capacidad)
        {
            // Crear una matriz para almacenar los resultados intermedios
            int[,] matriz = new int[productos.Count + 1, capacidad + 1];

            // Llenar la matriz con los resultados óptimos
            for (int i = 0; i <= productos.Count; i++)
            {
                for (int j = 0; j <= capacidad; j++)
                {
                    if (i == 0 || j == 0)
                        matriz[i, j] = 0;
                    else if (productos[i - 1].Peso <= j)
                        matriz[i, j] = Math.Max(productos[i - 1].Valor + matriz[i - 1, j - productos[i - 1].Peso], matriz[i - 1, j]);
                    else
                        matriz[i, j] = matriz[i - 1, j];
                }
            }

            // Recuperar la selección óptima de productos
            List<Producto> seleccionados = new List<Producto>();
            int fila = productos.Count;
            int columna = capacidad;

            while (fila > 0 && columna > 0)
            {
                if (matriz[fila, columna] != matriz[fila - 1, columna])
                {
                    seleccionados.Add(productos[fila - 1]);
                    columna -= productos[fila - 1].Peso;
                }

                fila--;
            }

            return seleccionados;
        }
    }
}

