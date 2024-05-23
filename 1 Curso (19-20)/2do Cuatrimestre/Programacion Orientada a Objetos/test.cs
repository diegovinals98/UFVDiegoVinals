using System;
class Vehiculo{

    private int numRuedas;
    private string color;
    private string marca;
    private int numPlazas; 
    // Constructor por defecto
    // Vehiculo(){
    //     int numRuedas = 4;
    //     string ConsoleColor = " ";
    //     int numPlazas = 5;
    // }

    // consrtructor parametrizado
    // el orden es importante, no se puede cambiar el orden de los atributos
    Vehiculo(int nR, string c, string m, int nP){
        numRuedas = nR;
        color = c;
        marca = m;
        numPlazas = nP;
    }
}