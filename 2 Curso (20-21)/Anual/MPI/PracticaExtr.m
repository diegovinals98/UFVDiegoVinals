% Practica Extraordinaria
% Nombre: Diego Vinals Lage


% Ejercicio: 1 (Globo)
clc, clear
disp('Ejercicio 1: Globo')
fprintf('\n')
% Sabemos que la velocidad es incremento de distancia / incremento de
% tiempo, para calcular el incremento de distancia tenemos que calcular la
% distancia cuando el globo esta a 50 metros de altura, como es un
% triangulo
dist = sqrt(150^2 + 50^2);
incrementoDist = dist - 150;
% el tiempo que tarda en subir 50 metros es: 50 metros/ 8 metros por
% segundo
tiempo = 50/8;
velocidadDistancia = incrementoDist / tiempo;
fprintf('La distacia aumenta a una velocidad de %.2f metros/segundo cuando el globo esta a 50 metros de altura\n' ,velocidadDistancia)

pause


% Ejercicio: 2 (Volumen 1)
clc, clear
disp('Ejercicio 2: Volumen 1')
fprintf('\n')
syms x y
f = exp(x) * sin(x);
pretty(f)
disp('El arco esta entre el punto de corte con el eje X, es decir, 0, y el maximo de esa funcion')
der = diff(f);
sol = solve(cos(x) == -sin(x), x);
a = 0;
b = subs(f, -sol*pi);
func = @(x) (exp(x) .* sin(x)).^2;
int = pi*integral(func , a , double(b));
fprintf('Tenemos que el punto a es: %.0f\n' , a)
fprintf('Tenemos que el punto b es: %.4f\n' , b)
fprintf('El volumen es: %.4f\n' ,int);



pause
%Ejercicio: 3 (Volumen 2)
clc, clear
disp('Ejercicio 3: Volumen 2')
fprintf('\n')
syms x 
f1 = x;
f2 = x^2;
sol = solve(f1 == f2 , x);
fprintf('Los cortes entre las dos funciones son: %.0f y %.0f\n' , sol(1), sol(2))
disp('Calculamos el area entre 0 y 1 de la funcion (x-x^2) elevado al cuadrado')
func = @(x) (x - x.^2).^2;
inte = integral(func , 0, 1);
disp('Le multiplicamos PI a ese valor')
volumen = pi*inte; 
fprintf('El volumen es: %.4f' , volumen)
pause


% Ejercicio: 4 (Cine de verano)
clc, clear
disp('Ejercicio 4: Cine de Verano')
fprintf('\n')
syms x
%la funcion a optimizar es esta, el angulo theta en funcion de x
f = atan(41/x)-atan(5/x);
% derivamos
derivada = diff(f);
% resolvemos para la derivada = 0, como nos da dos valores, nos quedamos
% con el positivo porque el negativo no tiene sentido
sol = solve(derivada == 0, x);
fprintf('La distancia optima es: %.2f metros\n', sol(1))
pause




% Ejercicio: 5 (Estaño)
clc, clear
disp('Ejercicio 5: Estaño')
fprintf('\n')
syms x k a

v = k*x*(a-x);
%Como la definicion de la velocidad es una funcion cuadrática ax^2+bx+c con
%a<0, el máximo se encuentra donde la derivada se hace cero
deriv_v = diff(v);
x_vertice = solve(deriv_v==0, x);
fprintf('Apartado A)\n')
fprintf('Alcanza la velovidad maxima para: %s\n\n' , char(x_vertice))
%apartado b:
fprintf('Apartado B)\n')
max_v = subs(v, x, x_vertice);
fprintf('Sustituimos %s en la funcion y nos da: %s\n\n' , char(x_vertice), char(max_v))

pause


%Ejercicio: 6 (Wilson)
clc, clear
disp('Ejercicio 6: Wilson')
fprintf('\n')
syms k m q c h b

A = k*m/q+c*m+h*q/2;

deriv_A = diff(A);
fprintf('La derivada de la funcion es: %s\n' , char(deriv_A))

ptos_critics = solve(deriv_A==0, q);
fprintf('Los puntos criticos son: %s\n' ,ptos_critics);
fprintf('Sustituimos en la funcion (El positivo)\n')
max_A = simplify(subs(A, q, ptos_critics(1)));
fprintf('La cantidad que minimiza A(q) es: %s\n' , char(max_A))

A2 = subs(A, k, k+b*q);

deriv_A2 = diff(A2);

ptos_critics = solve(deriv_A2==0, q);


max_A2 = simplify(subs(A2, q, ptos_critics(1)));
fprintf('La cantidad que minima A en el apartado b es: %s\n', char(max_A2))
pause

% Ejercicio: 7 (Area)
clc, clear
disp('Ejericio 7: Area')
fprintf('\n')
syms x

f1 = 3*sin(x);
f1Int = @(x) 3*sin(x);
f2Int = @(x) sqrt(cos(x));
f2 = sqrt(cos(x));
ptoCorte = solve(f1==f2, x<pi/2,x>0, x);
fprintf('Igualando funciones, tenemos que el punto de corte es: %f\n', ptoCorte)

area1 = integral(f1Int, 0, double(ptoCorte));
area2 = integral(f2Int, double(ptoCorte), pi/2);
area_total = vpa(area1+area2);
fprintf('El area es: %.4f\n' , area_total)
pause

% Ejercicio: 8 (Coste Marginal)
clc, clear
disp('Ejercicio 8: Coste Marginal')
fprintf('\n')
syms x z
f = @(x,z) (110 + 4*x + 0.02*x^2 + z) - ((110 + 4*x + 0.02*x^2)/z);
limite = limit(f, z, 0);

maybe = 4*x + limit(z - (4*x + x^2/50 + 110)/z, z, 0) + x^2/50 + 110;

subs(maybe, x, 50);
disp('No realizado')

pause

% Ejercicio: 9 (Trapecio)
clc, clear
disp('Ejercicio 9: Trapecio')
fprintf('\n')
syms x y
y = 1-x^2;
f =  @(x) 1 - x.^2;

for z = -1:0.1:0
    y1 = subs(y , x , z);
    y2 = subs(y,x,z+1);
    A = [z 1
        z+1 1];
    B = [y1
        y2];
    c = inv(A)*B;
    

    rect = @(x) x.*(double(c(1))) + double(c(2));
    
    integralRecta = integral(rect , z , z+1);
    integralCurva = integral(f, z, z+1);
    solucion = integralCurva - integralRecta;
    fprintf('Para el valor z = %.2f el area sombreada es A = %f\n' , z , solucion)
    
end
disp('Por lo tanto se cumple que para cualquier valor de Z, el area sombreada es 1/6 = 0.166667')
pause



% Ejercicio: 10 (Poblacion)
clc, clear
disp('Ejercicio 10: Poblacion')
fprintf('\n')
% Esta normalizado a millones, es decir, 45,20 millones, para que no queden
% numeros tan grandes
A = [45.200737 46.157822 46.745807 47.021031 47.190493 47.265321];
b = [2007 2008 2009 2010 2011 2012];
disp('Apartado A)')
fprintf('\n')

p = polyfit(b, A, 4);
fprintf('Los coeficientes son: %f\n', p)
fprintf('\n')
%ap b
disp('Apartado B)')
fprintf('\n')
valor = polyval(p, 2013.25);
fprintf('La estimacion con la funcion de ajuste es: %f millones de personas\n', valor)
fprintf('\n')
disp('Apartado C)')
fprintf('\n')
error = valor - 47.129783;
fprintf('El error cometido es: %f\n\n', error)
disp('Apartado D)')
fprintf('\nVer en grafica\n')

f = polyval(p,b);

plot(b, A, 'o', b, f)
title('Funcion de estimacion y datos dados');
xlabel('Año');
ylabel('Poblacion');
pause



% Ejercicio: 11 (Taylor)
clc,clear
disp('Ejercicio 11: Taylor')
fprintf('\n')
syms x
Miexp = @(x,n) polyval(1./[factorial(linspace(n,1,n)),1],x);
for i = 1:1:6
    fprintf('Grado = %.0f \n', i)
    valor = Miexp(0.2, i);
    polinomio = taylor(exp(x),x,0.2,'Order',i);
    valorPolinomio = subs(polinomio , 0.2);
    error = round(valorPolinomio - valor , 16);
    fprintf('El valor con la funcion Taylor es: %.16f\n', valorPolinomio)
    fprintf('El valor con Miexp es: %.16f\n', valor)
    fprintf('El error es: %.16f\n' , error)
end

error = 100;
f = 0;
grado = 0;
while error > 10^-4
    valor = Miexp(0.2, i);
    polinomio = taylor(exp(x),x,0.2,'Order',i);
    valorPolinomio = subs(polinomio , 0.2);
    error = valorPolinomio - valor;
    grado = f;
    f = f+1;
end
fprintf('Es imposible llegar a un error menor que 10^-16, ya que MatLab tiene el limite de calculo justo en ese numero')
pause




% Ejercicio: 12 (Arco Parabolico)
clc, clear
disp('Ejercicio 12: Arco Parabolico')
fprintf('\n')
syms  h b x

y = h-(4*h/b^2)*x^2;

%Pedimos valores al usuario
valorb = input('Introduce el valor de la base: ');
valorh = input('Introduce el valor de la altura: ');


y = subs(y,h, valorh);
y = subs(y,b,valorb);

xplot = -valorb/2:0.1:valorb/2;
yplot = subs(y, x, xplot);
plot(xplot, yplot);

areaEjemplo = int(y, x, -valorb/2,valorb/2);
fprintf('El area del arco encerrado con la base: %.0f\ny la altura: %.0f\nes: %.2f\n' , valorb, valorh, areaEjemplo)


pause 

% Ejercicio: 13 (Quilla)
clc, clear
disp('Ejercicio 13: Quilla')
fprintf('\n')
syms x a

% AREA TRIANGULO: b= 2a, H= a^2. AREA = b*H/2
areaTriang = a^3;
%AREA PARAB 
areaParab = 2*a^3 - int(x^2,x, -a,a);
limiteRazon = limit(areaTriang/areaParab, a, 0);
fprintf('El limite de la razon entre el area del triangulo\ny el area de la region de la parabola es: %.2f\n' , limiteRazon)
pause

% Ejercicio: 14 (Plomada)
clc, clear
disp('Ejercicio 14: Plomada')
fprintf('\n')
syms x y
f = y == (x/12)*sqrt(36-x^2);
pretty(f)
fcuadrado = @(x) ((x./12).*sqrt(36-x.^2)).^2;
a = 0;
b = 6;
volumen = pi * integral(fcuadrado, a , b);
fprintf('El volumen de la plomada es: %.4f\n' , volumen)
disp('Si la densidad es el peso/volumen, sabemos que el peso es igual al volumen por la densidad')
densidad = 8.5;
peso = round(volumen * densidad);
fprintf('El peso de la plomada es: %.0f gramos\n' , peso)
pause


% Ejercicio: 15 (Integral)
clc, clear
syms x  
disp('Ejercicio 15: Integral')
fprintf('\n')
func = exp(x^2);
disp('Usando Rectangulos inscritos')
a = 0;
b = 1;
% Vamos a usar 20 rectangulos 
n = 30;
dim = 1/n;
total = 0;
for i = 0:dim:1
    m = 0 + (i -1) * (2/n);
    sol = subs(func, m) * dim;
    total = total + sol;
    
end

% Nos da 1.0536 segun la suma de rectangulos
suma = round(total , 6);
f = @(x) exp(x.^2);
int = integral(f , 0 ,1);
% nos da 1.4627 segun la funcion
error = round(int - total, 6);
fprintf('Algebraicamente da que la integral definida es: %.6f\n' , suma)
fprintf('Segun la funcion integral(), la integral definida es: %.6f\n' , int)
fprintf('Por lo tanto el error que he cometido es de: %.6f\n', error)
fprintf('He usado N=%.0f, es decir, %.0f rectangulos de mismo ancho\n', n , n)
fprintf('Si este numero se va haciendo mayor, la aproximacion sera mejor\n')
fprintf('Por lo tanto, el error sera menor')
pause 

% Ejericio: 16 (Economia 1)
clc, clear
disp('Ejercicio 16: Economia 1')
fprintf('\n')
syms x y z 
%{
x = Cantidad de electricidad en euros a producir
y = Cantidad de carbon en euros a producir
z = Cantidad de manufactura en euros a producir
%}
ec1 = 75000 == 0.9*x+0.7*y+0.9*z;
ec2 = 50000 == 0.75*x+0.6*y+0.85*z ;
ec3 = 1250000 == 0.8*x+0.5*y+0.9*z ;


sol = solve(ec1, ec2, ec3);
fprintf('No satisface la demanda, ya que el dinero necesario es: \n%.2f euros de electricidad \n%.2f euros de carbon \n%.2f euros de manufactura \nuno es negativo por lo que no tiene sentido', sol.x, sol.y, sol.z)
pause

% Ejercicio: 17 (Economia 2)
clc, clear
disp('Ejercicio 17: Economia 2')
fprintf('\n')
A = [0.2 0.8 0.4
    0.3 0.1 0.4
    0.5 0.1 0.2];

disp('Apartado A)')
M = array2table(A, 'RowNames', {'Quimicos y Metales','Combustibles y Energia' , 'Maquinaria'},...
              'VariableNames', {'Quimicos y Metales','Combustibles y Energia' , 'Maquinaria'});
disp(M);
          
disp('Apartado B)')
fprintf('Apartado No realizado\n')

syms x y z 
%{
Quimicos -> x
Combustibles -> y
Maquinaria -> z
A la izquierda es lo que venden (Ingresos)
A la derecha es lo que compra (Gastos) mas lo retenido
Nos pide el enunciado igualarlos
%}
ec1 = 0.8*x == 0.8*y + 0.4*z + 0.2*x ;
ec2 = 0.9*y == 0.3*x + 0.4*z ;
ec3 = 0.8*z == 0.5*x + 0.1*y ;

%{

disp('Si x es el precio de los quimicos');
disp('Si y es el precio de los combustibles');
disp('Si z es el precio de la maquinaria');
disp('El sistema de ecuaciones seria el siguiente:')
disp(ec1);
disp(ec2);
disp(ec3);
%}

sol = solve(ec1, ec2, ec3);
round(sol.x, 2);
round(sol.y, 2);
round(sol.z, 2);
fprintf('Apartado C)\n')
fprintf('Apartado No realizado\n\n')
pause


% Ejericio: 18 (Bx=0)
clc, clear 
disp('Ejercicio 18: Bx=0')
fprintf('\n')  
syms x a
A = [8 -3 0 -7 2
    -9 4 5 11 -7
    6 -2 2 -4 4
    5 -1 7 0 10];

%Como el rango de la matriz dada es 3, y como sabemos que la solucion a un
%sistema de ecuaciones lineales es unicamente la trivial si el nucleo de la
%aplicacion lineal asociada es el 0 lo que es equivalente a que el rango de
%la matriz sea máximo. Por ello, calculamos el rango de A
rank(A);
%Visto que el rango de A es 3, sabemos que podemos elegir, como mucho, 3
%columnas de A que seanm linealmente independientes por lo tanto, si
%encontramos una submatriz de A compuesta por 3 columnas linealmente
%independientes(rango 3), hemos encontrado la B requerida. Tras probar, se
%ha llegado a la siguiente submatriz (columnas 3 a 5 de A)
B = A(:,3:5)
fprintf('La matriz es: \n[%.0f %.0f %.0f\n%.0f %.0f %.0f\n%.0f %.0f %.0f\n%.0f %.0f %.0f]\n', B(1,1), B(1,2) ,B(1,3),B(2,1), B(2,2) ,B(2,3), B(3,1), B(3,2) ,B(3,3), B(4,1), B(4,2) ,B(4,3))

rank(B);

%Comprobamos que la solucion unica es la trivial:

sol = linsolve(B, [0;0;0;0]);
fprintf('La solucion al sistema Bx=0 es: [%.0f, %.0f, %.0f], es decir, la solucion trivial\n' , sol(1),sol(2), sol(3))


pause

% Ejercicio: 19 (Alquiler de coches)
clc, clear
disp('Ejercicio 19: Alquiler de Coches')
fprintf('\n')
A = [0.97 0.05 0.10
    0.00 0.90 0.05
    0.03 0.05 0.85];

X = [295;
    55; 
    150];
dia1 = A*X;
dias2 = A*dia1;
fprintf('Al cabo de un dia (Martes) habra %.0f en el Aeropuerto, %.0f en la Zona Este, y %.0f en la Zona Oeste\n' , dia1(1,:), dia1(2,:) , dia1(3,:))
fprintf('Al cabo de dos dias (Miercoles) habra %.0f en el Aeropuerto, %.0f en la Zona Este, y %.0f en la Zona Oeste\n' , dias2(1,:), dias2(2,:) , dias2(3,:))

pause



%Ejercicio: 20(Apartamentos)
clc, clear
disp('Ejercicio 20: Apartamentos')
fprintf('\n')
disp('Apartado A)')
disp('Ese vector nos dice el numero de unidades de cada tipo de habitacion del plan A')
fprintf('\n')
disp('Apartado B)')
syms x1 x2 x3
f = x1*[3 7 8] + x2*[4 4 8] + x3*[5 3 9];
disp('La combinacion lineal en forma de vectores es: ')
disp(f)
fprintf('\n')
disp('Apartado C)')
b = [66 74 136];
% Matriz Ampliada
A = [3 4 5 66;
    7 4 3 74
    8 8 9 136];
reducida = rref(A);
disp('La matriz ampliada del sistema es: ')
disp(A)
disp('La matriz reducida es: ')
disp(reducida)
disp('Como hay una fila entera de ceros, se puede concluir que no existe solucion')
disp('Es decir, no se puede diseñar un edificio con ese numero exacto de habitaciones')









