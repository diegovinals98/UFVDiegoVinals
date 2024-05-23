using System;
namespace PR0
{
    public class CCuentaAhorro : CCuenta
    {

        private double cuotaMantenimiento;

        public CCuentaAhorro()
        {

        }


        public CCuentaAhorro(string nombre, string cuenta, double saldo, double tipoDeInteres, double cuotaMantenimiento) : base(nombre, cuenta, saldo, tipoDeInteres)
        {
            this.cuotaMantenimiento = cuotaMantenimiento;
        }


        public void asignarCuota(double cuota)
        {
            cuotaMantenimiento = cuota;
        }

        public double obtenerCuota()
        {
            return cuotaMantenimiento;
        }

        public override void reintegro(double reint)
        {
            if(tipoDeInteres >= 3.5)
            {
                if(estado() > 1500)
                {
                    saldo = saldo + reint;
                }
            }
        }


    }
}
