using System;

namespace PR0
{
    class Test
    {
        static void Main(string[] args)
        {
            CCuentaAhorro nuevaCuenta = new CCuentaAhorro("JOSE PEREZ LOPEZ", "ES89 3025 8567 25 2400154956", 1500, 3.5, 35);
            Console.Write("La cuota de mantenimiento es: ");
            Console.WriteLine(nuevaCuenta.obtenerCuota() + " Euros.");

            nuevaCuenta.ingresar(30000);
            nuevaCuenta.reintegro(10000);

            Console.WriteLine("Titular: " + nuevaCuenta.obtenerNombre());
            Console.WriteLine("Numero de cuenta: " + nuevaCuenta.obtenerCuenta());
            Console.WriteLine("Saldo: " +  nuevaCuenta.estado());
            Console.WriteLine("Tipo interes: " + nuevaCuenta.obtenerTipoInteres());

        }
    }
}
