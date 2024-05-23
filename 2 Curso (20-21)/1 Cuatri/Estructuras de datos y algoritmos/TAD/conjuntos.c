
/* Curso EDA 2020-2021
   Autor: Mary Luz Mouronte López
*/


#include <stdio.h>
#include <string.h>


#define MAX_CARACTERES 1500
#define CORRECTO 0
#define MAX_NOMBRE_CONJUNTO 20
#define ERR_INTRODUCIR 1
#define ERR_ELIMINAR 2
#define N 50
#define OPCION_UNO 1
#define OPCION_DOS 2
#define OPCION_TRES 3
#define SALIR 4


/* ZONA DE DECLARACIÓN DE TIPOS*/

typedef enum {FALSE, TRUE} tBoolean;

typedef struct {
    char Nombre[MAX_NOMBRE_CONJUNTO];
    int Elementos[N];
    int Ultimo;
} tConjunto;

int Menu (void);
void IniCjto (tConjunto *Conjunto);
tBoolean  Esta (int Elemento, tConjunto C);
int Aniadir (tConjunto *X);
int Quitar (tConjunto *X);
void ImprimeCjto (tConjunto C);


int main() {


     tConjunto Conjunto;
     int Elemento;
     tBoolean FlgSalir;
     int Res;
     int Opcion;



     FlgSalir=FALSE;
     while(!FlgSalir)
        {
        Opcion = Menu();
    switch (Opcion)
    {
           case OPCION_UNO: /* 1. Aniadir */
         Res = Aniadir(&Conjunto);
         if (Res == CORRECTO)
             ImprimeCjto(Conjunto);
           break;

           case OPCION_DOS: /* 2. Quitar */
           Res = Quitar(&Conjunto);
           if (Res == CORRECTO )
             ImprimeCjto(Conjunto);
           break;

           case OPCION_TRES: /* 3. Inicializar conjuntos */
           IniCjto(&Conjunto);
           break;


           case SALIR:  /*  4.  Salir. */
           FlgSalir=TRUE;
            break;

            default:
               printf("Opcion no valida\n");
        }
     }

     return CORRECTO;

}

int Menu (void)
{
  int opcion;


  printf ("\n 1. Aniadir elemento");
    printf ("\n 2. Quitar elemento");
  printf ("\n 3. Crear conjunto");
  printf ("\n 4. Salir");
  printf ( "\n Elija opcion");
       scanf("%d", &opcion);

    return opcion;
}

void ImprimeCjto (tConjunto C)
{
      int i;

      printf(" %s = ", C.Nombre);
      printf("{");
      for (i=0; i<=C.Ultimo; i++)
      {
        printf("%d",C.Elementos[i]);
        if (i!=C.Ultimo)
          printf(",");
      }
      printf("}\n");

}



int Aniadir (tConjunto *X)
{
   tConjunto Z;
   char NomC[MAX_NOMBRE_CONJUNTO];
   int Elemento, Res;

   Res= CORRECTO;

   Z=*X;

   printf("Nombre conjunto:");
   scanf("%s",NomC);
   printf("Elemento:");
   scanf("%d", &Elemento);

   if (strcmp(NomC,Z.Nombre)==0)
   {

      if (!Esta (Elemento, Z))
      {
        Z.Ultimo++;
        Z.Elementos[Z.Ultimo] = Elemento;
      }
    }
    else
    {
        Res=ERR_INTRODUCIR;
        printf("No es posible aniadir el elemento. Compruebe que lo ha creado previamente con la opción 3\n");
    }
   (*X)=Z;
   return Res;
}

int Quitar (tConjunto *X)
{
   tConjunto Z;
   int i, j;
   tBoolean Enc;
   int Res;
   char NomC[MAX_NOMBRE_CONJUNTO];
   int Elemento;

   Res = CORRECTO;

   Z=*X;

   printf("Nombre conjunto:");
   scanf("%s",NomC);
   printf("Elemento:");
   scanf("%d", &Elemento);

   if (strcmp(NomC, Z.Nombre) == 0)
   {
    Enc = FALSE;
    i=0;
    while ((i<=Z.Ultimo) && !Enc)
    {
       if (Z.Elementos[i]==Elemento)
       {
          for (j=i; j<=Z.Ultimo;j++)
            Z.Elementos[j]=Z.Elementos[j+1];
          Z.Ultimo--;
        }
       i++;
       }
   }
   else
   {
  Res=ERR_INTRODUCIR;
        printf("No es posible eliminar el elemento. Compruebe que lo ha creado previamente con la opción 3.\n");
   }
   (*X)=Z;
   return Res;

}

tBoolean Esta(int Elemento, tConjunto C)
{
  tBoolean Enc;
  int i;

  Enc = FALSE;

  i=0;
  while ((i<=C.Ultimo) && !Enc)
  {
    Enc = (Elemento == C.Elementos[i]);
    i++;
  }

  return Enc;

}

void IniCjto (tConjunto *Conjunto)
{
    char NomC[MAX_NOMBRE_CONJUNTO];

    printf("Nombre conjunto:");
    scanf("%s",NomC);
    strcpy((*Conjunto).Nombre, NomC);
   (*Conjunto).Nombre[1]='\0';
   (*Conjunto). Ultimo = -1;

}









