using System;
using System.Collections.Generic;
using System.Text;

namespace Practica2COCO
{
    class VersionVoraz
    {
		public VersionVoraz()
		{

		}

		//Algoritmo de la mochila voraz conforme a las especificaciones del pseudocódigo del tema 3
		public float[] mochilavoraz(Objeto[] objetos, int pesomochila)
		{
			float[] x = new float[objetos.Length];
			float peso_acumulado = 0;
			int i = 0;
			while (peso_acumulado < pesomochila && i < objetos.Length)
			{
				if (objetos[i].pesoObjeto() + peso_acumulado < pesomochila)
				{
					x[i] = 1;
				}
				else
				{
					x[i] = (pesomochila - peso_acumulado) / objetos[i].pesoObjeto();
				}
				peso_acumulado = (int)(peso_acumulado + (x[i] * objetos[i].pesoObjeto()));
				i++;
			}
			return x;
		}

		//Método voraz para objetos no divisibles
		public float[] mochilavorazNoDiv(Objeto[] objetos, int pesomochila)
		{
			float[] x = new float[objetos.Length];
			int peso_acumulado = 0;
			int i = 0;
			while (peso_acumulado < pesomochila && i < objetos.Length)
			{
				if (objetos[i].pesoObjeto() + peso_acumulado < pesomochila)
				{
					x[i] = 1;
				}
				else
				{
					i = objetos.Length;
				}
				if (i < objetos.Length)
				{
					peso_acumulado = (int)(peso_acumulado + (x[i] * objetos[i].pesoObjeto()));
					i++;
				}
			}
			return x;
		}
	}
}
