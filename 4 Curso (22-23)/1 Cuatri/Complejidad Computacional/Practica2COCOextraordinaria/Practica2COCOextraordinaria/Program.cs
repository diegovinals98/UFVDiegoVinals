using System;
using System.Collections.Generic;
using System.Linq;

namespace Practica2COCOextraordinaria
{
        public class Producto
    {
        public string? Nombre { get; set; }
        public int Peso { get; set; }
        public int Valor { get; set; }
    }


    public class Program
    {

        
        public static void Main(string[] args)
        {
            // Crear lista de productos
            List<Producto> productos = new List<Producto>()
            {
                new Producto() { Nombre = "Café de Tanzania", Peso = 260000, Valor = 26000000 },
                new Producto() { Nombre = "Café de Hawaii", Peso = 150000, Valor = 18000000 },
                new Producto() { Nombre = "Café de Nicaragua", Peso = 240000, Valor = 19200000 },
                new Producto() { Nombre = "Café de Jamaica", Peso = 190000, Valor = 34200000 },
                new Producto() { Nombre = "Café de Colombia", Peso = 130000, Valor = 19500000 },
                new Producto() { Nombre = "Café de Kenya", Peso = 140000, Valor = 9800000 }
            };

            int capacidadMaxima = 600000;


            // Obtener mercancías seleccionadas mediante el algoritmo dinámico
            List<Producto> mercanciasSeleccionadas = Dinamico.SeleccionarMercanciasDinamico(productos, capacidadMaxima);

            // Mostrar los resultados
            Console.WriteLine("Mercancías seleccionadas (algoritmo dinámico):");
            foreach (Producto producto in mercanciasSeleccionadas)
            {
                Console.WriteLine($"Nombre: {producto.Nombre}, Peso: {producto.Peso}, Valor: {producto.Valor}");
            }

            Console.WriteLine("\n");

            // Obtener mercancías seleccionadas mediante el algoritmo voraz
            List<Producto> mercanciasSeleccionadasVoraz = Voraz.SeleccionarMercanciasVoraz(productos, capacidadMaxima);


            // Mostrar los resultados
            Console.WriteLine("Mercancías seleccionadas (algoritmo voraz):");
            foreach (Producto producto in mercanciasSeleccionadasVoraz)
            {
                Console.WriteLine($"Nombre: {producto.Nombre}, Peso: {producto.Peso}, Valor: {producto.Valor}");
            }

            Console.WriteLine("\n");

            // Obtener mercancías seleccionadas mediante el algoritmo de vuelta atrás
            List<Producto> mercanciasSeleccionadasVA = VueltaAtras.SeleccionarMercanciasVueltaAtras(productos, capacidadMaxima);

            // Mostrar los resultados
            Console.WriteLine("Mercancías seleccionadas (algoritmo de vuelta atrás):");
            foreach (Producto producto in mercanciasSeleccionadasVA)
            {
                Console.WriteLine($"Nombre: {producto.Nombre}, Peso: {producto.Peso}, Valor: {producto.Valor}");
            }


            Console.ReadKey();
        }
    }

}