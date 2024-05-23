using System;

namespace PR0
{
    public class CCuenta
    {
        public string nombre;
        public string cuenta;
        public double saldo;
        public double tipoDeInteres;

        public CCuenta() { }

        public CCuenta(string nombre, string cuenta, double saldo, double tipoDeInteres)
        {
            this.nombre = nombre;
            this.cuenta = cuenta;
            this.saldo = saldo;
            this.tipoDeInteres = tipoDeInteres;


        }

        public void asignarNombre(string nombre)
        {
            if (!string.IsNullOrEmpty(nombre))
            {
                this.nombre = nombre;
            }
        }

        public string obtenerNombre()
        {
            return nombre;
        }

        public void asignarCuenta(string cuenta)
        {
            this.cuenta = cuenta;
        }

        public string obtenerCuenta()
        {
            return cuenta;
        }

        public double estado()
        {
            return saldo;
        }

        public void ingresar(double ingreso)
        {
            if (ingreso >= 0)
            {
                saldo = estado() + ingreso;
            }
            else
            {
                Console.WriteLine("La cantidad ingresada no puede ser nagativa.");
            }
        }

        public virtual void reintegro(double reint)
        {
            double saldoAc = estado();
            if (reint > saldoAc)
            {
                Console.WriteLine("No se puede sacar mas dinero del disponible.");

            }
            else
            {
                saldo = estado() - reint;
            }
        }

        public void asignarTipoInteres(double tipoInt)
        {
            if (tipoInt < 0)
            {
                Console.WriteLine("El interes no puede ser negativo.");
            }
            else
            {
                tipoDeInteres = tipoInt;
            }

        }


        public double obtenerTipoInteres()
        {
            return tipoDeInteres;
        }
    }
}

