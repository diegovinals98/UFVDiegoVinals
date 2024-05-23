using System;

namespace Practica2COCOextraordinaria
{
    public class VueltaAtras
    {
        // Funcion para seleccionar las mercancías utilizando el algoritmo de vuelta atrás
        public static List<Producto> SeleccionarMercanciasVueltaAtras(List<Producto> productos, int capacidad)
        {
            List<Producto> mejorSeleccion = new List<Producto>(); // Almacena la mejor selección encontrada
            List<Producto> seleccionActual = new List<Producto>(); // Almacena la selección actual en cada iteración

            BuscarMejorSeleccion(productos, capacidad, 0, seleccionActual, ref mejorSeleccion); // Llamada al Funcion recursivo

            return mejorSeleccion; // Devuelve la mejor selección encontrada
        }

        // Funcion recursiva para buscar la mejor selección de mercancías
        public static void BuscarMejorSeleccion(List<Producto> productos, int capacidad, int indice, List<Producto> seleccionActual, ref List<Producto> mejorSeleccion)
        {
            if (indice == productos.Count)
            {
                // Comprobar si la selección actual cumple con las restricciones y tiene mayor valor que la mejor selección encontrada hasta ahora
                if (ObtenerPesoTotal(seleccionActual) <= capacidad && ObtenerValorTotal(seleccionActual) > ObtenerValorTotal(mejorSeleccion))
                {
                    mejorSeleccion = new List<Producto>(seleccionActual); // Actualizar la mejor selección encontrada
                }

                return; // Salir 
            }

            Producto productoActual = productos[indice]; // Obtener el producto actual

            seleccionActual.Add(productoActual); // Incluir el producto actual en la selección actual
            BuscarMejorSeleccion(productos, capacidad, indice + 1, seleccionActual, ref mejorSeleccion); // Llamada recursiva con el siguiente índice
            seleccionActual.Remove(productoActual); // Excluir el producto actual de la selección actual

            BuscarMejorSeleccion(productos, capacidad, indice + 1, seleccionActual, ref mejorSeleccion); // Llamada recursiva sin incluir el producto actual
        }

        // Obtiene el peso total de una lista de productos
        public static int ObtenerPesoTotal(List<Producto> productos)
        {
            int pesoTotal = 0;

            foreach (Producto producto in productos)
            {
                pesoTotal += producto.Peso; // Sumar el peso de cada producto
            }

            return pesoTotal; // Devolver el peso total
        }

        // Obtiene el valor total de una lista de productos
        public static int ObtenerValorTotal(List<Producto> productos)
        {
            int valorTotal = 0;

            foreach (Producto producto in productos)
            {
                valorTotal += producto.Valor; // Sumar el valor de cada producto
            }

            return valorTotal; // Devolver el valor total
        }
    }
}


