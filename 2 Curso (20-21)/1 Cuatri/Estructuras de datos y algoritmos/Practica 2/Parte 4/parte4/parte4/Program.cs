using System;
using System.Collections.Generic;

namespace parte4
{
    class Program
    {
        static void Main(string[] args)
        {

            Stack<int> pila1 = new Stack<int>();
            Stack<int> pila2 = new Stack<int>();
            Stack<int> pila3 = new Stack<int>();
            Stack<int> pila4 = new Stack<int>();

            Queue<int> cola1 = new Queue<int>();
            Queue<int> cola2 = new Queue<int>();
            Queue<int> cola3 = new Queue<int>();
            Queue<int> cola4 = new Queue<int>();

            int menu = 0;
            int flag = 0;

            do
            {
                // Menu para el prgrama
                Console.WriteLine("Escoge una opcion (1-5)");
                Console.WriteLine("1. Gestionar Pilas.");
                Console.WriteLine("2. Visualizar Pilas.");
                Console.WriteLine("3. Gestionar Colas.");
                Console.WriteLine("4. Visualizar Colas.");
                Console.WriteLine("5. Salir.");
                menu = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine();

                switch (menu)
                {
                    case 1:

                        int i;
                        int j;
                        Console.WriteLine("Elija numero i: "); // NUMERO i ES LA PILA
                        i = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine("Elija numero j: "); // NUMERO j ES EL NUMERO A ANADIR
                        j = Convert.ToInt32(Console.ReadLine());
                        switch (i)
                        {
                            case 1:
                                gestionarPila(i, j , pila1);
                                break;
                            case 2:
                                gestionarPila(i, j, pila2);
                                break;
                            case 3:
                                gestionarPila(i, j, pila3);
                                break;
                            case 4:
                                gestionarPila(i,j,  pila4);
                                break;
                        }

                        break;

                    case 2:
                        mostrarPilas(pila1, pila2, pila3, pila4);
                        break;

                    case 3:
                        int icola;
                        int jcola;
                        Console.WriteLine("Elija numero i: "); // NUMERO i ES LA COLA
                        icola = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine("Elija numero j: "); // NUMERO j ES EL NUMERO A ANADIR
                        jcola = Convert.ToInt32(Console.ReadLine());
                        switch (icola)
                        {
                            case 1:
                                gestionarCola(icola, jcola, cola1);
                                break;
                            case 2:
                                gestionarCola(icola, jcola, cola2);
                                break;
                            case 3:
                                gestionarCola(icola, jcola, cola3);
                                break;
                            case 4:
                                gestionarCola(icola, jcola, cola4);
                                break;
                        }
                        break;
                    case 4:
                        mostrarCola(cola1, cola2, cola3, cola4);
                        break;

                    default:
                        flag = 1;
                        break;
                }


            } while (flag == 0);
        }


        // Funcion para gestionar una pila
        // Depende de i, anade o quita un elemento en la pila
        static void gestionarPila(int i, int j, Stack<int> pila)
        {
            if (i > 0)
            {
                pila.Push(j);
            }
            else if (i < 0){
                if (pila.Count != 0)
                {
                    Console.WriteLine("No se puede eliminar ningun elemento, porque no hay elementos en la pila.");
                } else
                {
                    eliminarPila(j, pila);
                    
                }
            }
        }


        // Elimina el elemento de la pila
        // Va quitando elementos de la pila (por la cima)
        // y los guarda en una pila auxiliar
        // hasta que encuentra en elemento a borrar, que ese no lo guarda en ningun sitio
        // Luego, mete los elementos de la pila auxiliar en la original
        static void eliminarPila(int numero, Stack<int> pila)
        {
            Stack<int> temp = new Stack<int>();
            int x;
            int y;
            
            while((x = pila.Pop()) != numero)
            {
                temp.Push(numero);
            }
            while (temp.Count != 0)
            {
                y = temp.Pop();
                pila.Push(y);
            }

        }

        // Gestiona las colas.
        // Depende de i, quita o anade elemetos  
        static void gestionarCola(int i, int j, Queue<int> cola)
        {
            if (i > 0)
            {
                cola.Enqueue(j);
            }
            else if (i < 0)
            {
                if (cola.Count != 0)
                {
                    Console.WriteLine("No se puede eliminar ningun elemento, porque no hay elementos en la pila.");
                }
                else
                {
                    eliminarCola(j, cola);

                }
            }

        }

        // Funciona igual que eliminar Pila, pero con colas. 
        static void eliminarCola(int numero, Queue<int> cola)
        {
            Queue<int> temp = new Queue<int>();
            int x;
            int y;

            while ((x = cola.Dequeue()) != numero)
            {
                temp.Enqueue(x);
            }
            while (temp.Count != 0)
            {
                y = temp.Dequeue();
                cola.Enqueue(y);
            }
        }


        // Imprime las cuatros pilas
        static void mostrarPilas(Stack<int> pila1, Stack<int> pila2, Stack<int> pila3, Stack<int> pila4)
        {
            Console.WriteLine("Pila 1:");
            if(pila1.Count != 0)
            {
                for(int i = 0; i <= pila1.Count; i++)
                {
                    Console.Write("\tNumero: ");
                    Console.WriteLine(pila1.Pop());
                }
            }

            Console.WriteLine("Pila 2:");
            if (pila2.Count != 0)
            {
                for (int i = 0; i <= pila2.Count; i++)
                {
                    Console.Write("\tNumero: ");
                    Console.WriteLine(pila2.Pop());
                }
            }

            Console.WriteLine("Pila 3:");
            if (pila3.Count != 0)
            {
                for (int i = 0; i <= pila3.Count; i++)
                {
                    Console.Write("\tNumero: ");
                    Console.WriteLine(pila3.Pop());
                }
            }

            Console.WriteLine("Pila 4:");
            if (pila4.Count != 0)
            {
                for (int i = 0; i <= pila4.Count; i++)
                {
                    Console.Write("\tNumero: ");
                    Console.WriteLine(pila4.Pop());
                }
            }


        }

        // Imprime las cuatro colas.
        static void mostrarCola(Queue<int> cola1, Queue<int> cola2, Queue<int> cola3, Queue<int> cola4)
        {
            Console.WriteLine("Cola 1:");
            if (cola1.Count != 0)
            {
                for (int i = 0; i <= cola1.Count; i++)
                {
                    Console.Write("\tNumero: ");
                    Console.WriteLine(cola1.Dequeue());
                }
            }

            Console.WriteLine("Cola 2:");
            if (cola2.Count != 0)
            {
                for (int i = 0; i <= cola2.Count; i++)
                {
                    Console.Write("\tNumero: ");
                    Console.WriteLine(cola2.Dequeue());
                }
            }

            Console.WriteLine("Cola 3:");
            if (cola3.Count != 0)
            {
                for (int i = 0; i <= cola3.Count; i++)
                {
                    Console.Write("\tNumero: ");
                    Console.WriteLine(cola3.Dequeue());
                }
            }

            Console.WriteLine("Cola 4:");
            if (cola4.Count != 0)
            {
                for (int i = 0; i <= cola4.Count; i++)
                {
                    Console.Write("\tNumero: ");
                    Console.WriteLine(cola4.Dequeue());
                }
            }

        }

    }
}
