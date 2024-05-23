using System;
using System.Collections.Generic;
using System.Text;

namespace Practica2COCO
{
    class Objeto
    {
		int peso;
		int valor;
		int valorpeso;

		public Objeto(int p, int v, int vp)
		{
			this.peso = p;
			this.valor = v;
			this.valorpeso = vp;
		}

		public int pesoObjeto()
		{
			return this.peso;
		}
		public int valorObjeto()
		{
			return this.valor;
		}
		public int valorpesoObjeto()
		{
			return this.valorpeso = valor/peso;
		}
	}
}
