using System;
using System.Collections.Generic;
using System.Linq;

namespace Practica2COCOextraordinaria
{
    public class Voraz
    {
        // Función para seleccionar las mercancías utilizando el algoritmo voraz
        public static List<Producto> SeleccionarMercanciasVoraz(List<Producto> productos, int capacidad)
        {
            List<Producto> seleccionados = new List<Producto>(); // Almacena la selección de productos

            // Ordenar los productos por su relación valor-peso de forma descendente
            productos = productos.OrderByDescending(p => (double)p.Valor / p.Peso).ToList();

            foreach (Producto producto in productos)
            {
                // Comprobar si el producto puede ser incluido en la selección actual
                if (producto.Peso <= capacidad)
                {
                    seleccionados.Add(producto); // Incluir el producto en la selección
                    capacidad -= producto.Peso; // Actualizar la capacidad disponible
                }
            }

            return seleccionados; // Devolver la selección de productos
        }
    }
}
