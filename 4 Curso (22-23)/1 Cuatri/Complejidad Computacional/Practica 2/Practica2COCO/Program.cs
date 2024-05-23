using System;

namespace Practica2COCO
{
    class Program
    {
        static void Main(string[] args)
        {
			
			Console.WriteLine("|  Practica 2  |");
			

			

			Console.WriteLine("\nNumero de Objetos:");
			int numobjetos = int.Parse(Console.ReadLine());

			Console.WriteLine("Peso de la mochila:");
			int pesomochila = int.Parse(Console.ReadLine());

			int[] valor = new int[numobjetos];
			int[] peso = new int[numobjetos];
			int[] valorpeso = new int[numobjetos];

			int[,] V = new int[numobjetos, pesomochila + 1];
			int[,] P = new int[numobjetos, pesomochila + 1];

			Objeto[] objetos = new Objeto[numobjetos];

			for (int i = 0; i < numobjetos; i++)
			{
				Console.WriteLine("\n¿Peso del objeto {0}?", i + 1);
				peso[i] = int.Parse(Console.ReadLine());
				Console.WriteLine("¿Valor del objeto {0}?", i + 1);
				valor[i] = int.Parse(Console.ReadLine());
				valorpeso[i] = valor[i] / peso[i];
				Console.WriteLine("\nValor/Peso del objeto {0}: {1}", i + 1, valorpeso[i]);
			}

			QuickSort Ordenar = new QuickSort();


			Console.WriteLine("Ordenamos el Array\n");
			Ordenar.Quicksort(valor, peso, valorpeso, 0, numobjetos-1);

			for (int i = 0; i < numobjetos; i++)
			{
				objetos[i] = new Objeto(peso[i], valor[i], valorpeso[i]);
				Console.WriteLine("Objeto {0} --> P:{1}  V:{2}  V/P:{3}", i+1 ,objetos[i].pesoObjeto(), objetos[i].valorObjeto(), objetos[i].valorpesoObjeto());
			}


			//Inicializamos las variables y la clase 
			float valortotal = 0;
			float[] solucionVoraz;
			VersionVoraz voraz = new VersionVoraz();

			
			Console.WriteLine("|  Método voraz  |");


            solucionVoraz = voraz.mochilavoraz(objetos, pesomochila);
			Console.Write("\n");

			
			for (int i = 0; i < solucionVoraz.Length; i++)
			{
				
				if (solucionVoraz[i] != 0.00)
				{
					Console.WriteLine("Objeto {0} guardado con una proporción del {1} %\n", i + 1, solucionVoraz[i] * 100);
					valortotal = valortotal + objetos[i].valorObjeto() * solucionVoraz[i];
				}
			}
			Console.WriteLine("Valor total = {0}", valortotal);



            Console.WriteLine("|  Version Dinamica  |");


			VersionDinamica dinamica = new VersionDinamica(objetos, pesomochila, V, P);
            
            int[] SolDinamica;

			SolDinamica = dinamica.calculoObjetos(objetos, pesomochila, V, P);

			Console.WriteLine("Solicion Dinamica: %d", SolDinamica);


        }
    }
}
