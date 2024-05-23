% Nombre: Diego Vinals Lage
% Parcial: 1
% Modelo: D
% Fecha: 13/02/2021

% Ejercicio: 1
clc, clear
display('Ejercicio 1')
y = [ 400 369 302 277 235 268 323 ];
x = [ 2013 2014 2015 2016 2017 2018 2019 ];
display('Apartado A)')
p = polyfit(x, y , 3);
display('Los coeficientes del polinomio son: ' );
p
% la ecuacion es y = 0.0031*t - 2.0668
%ec = 0.0031*t - 2.0668 == y
%subs(ec, 2020)
t2 = 2013: 0.1: 2021;
y2 = polyval(p, t2);
yy2 = [ 400 369 302 277 235 268 323 438];
x2 = [ 2013 2014 2015 2016 2017 2018 2019 2020];
plot(x2,yy2,'o', t2, y2);
display('Apartado B)')
display('Como podemos ver en la grafica, estan cerca, pero no son exactos');
display('Para el polinomio ajustado el valor de 2020 es: 458.143');
display('Y en los datos nos viene que el valor es 438');
display('Apartado C)');
display('El error de la estimacion es:');
error = 458.143 - 438
display('Apartado D)');
display('Podemos observar que si el grado del polinomio es 5');
display('El valor estimado es: 440.25');
display('Por tanto el error es: ');
error = 440.25 -438
display('Que es mucho menor');
pD = polyfit(x,y,5);
yD = polyval(pD, t2);
plot(x2,yy2,'o', t2, yD);







pause
% Ejercicio: 2
clc, clear
display('Ejercicio 2');
syms s t
A = [-14 4 -6 0 
    3 2 -6 -6
    0 4 -3 3
    -15 -2 18 15]
display('Apartado A)');
display('Los autovalores son los siguientes (diagonal de la matriz)');
[~ , vp] = eig(A) % con esto ~ obvia los calculos de los autovectores, variable muda
display('Apartado B)');
display('No resuelto'); 
% calculamos (lambda*I - M)
vp11 = vp(1,1) * eye(4) - A;
vp22 = vp(2,2) * eye(4) - A;
vp33 = vp(3,3) * eye(4) - A;
vp44 = vp(4,4) * eye(4) - A;

% reducimos con gauss-jordas
GJ11 = rref(vp11);
GJ22 = rref(vp22);
GJ33 = rref(vp33);
GJ44 = rref(vp44);

BaseLambda1 = s*[0 1 0 0] + t*[-2 0 2 1];

display('Apartado C)');

A = sym(A);
[P , ~] = eig(A);
Pinv = round(inv(P));
display('SI que es diagonalizable');
display('La  matriz es la siguiente:');
D = round(Pinv*A*P)

pause

% Ejercicio: 3 
clc, clear
syms lambda
display('Ejercicio 3');

A = [ 3 -2 -4
    -2 6 -2
    -4 -2 3]
A = sym(A);
display('Apartado A)');
[P , ~] = eig(A);
Pinv = round(inv(P));
display('Si que es diagonalizable');
display('La matriz es: ');
D = round(Pinv*A*P)
display('Apartado B)');
p = det(lambda*eye(3) - A);
display('Los autovalores son:');
lambda = solve(p == 0)
display('Calculamos la matriz de autovectores');
[V, ~] = eig(A)
v2 = V(:, 2); 
v3 = V(:, 3);
display('Hacemos Gram-Schmidt');
pe = dot(v2, v3);
w2 = v2;

w3 = v3 - (dot(v3, w2)/dot(w2, w2))*w2;

u1 = V(:, 1);

u2 = w2/norm(w2); u3 = w3/norm(w3);

% Matriz P:
display('La Base ortonormal son los vectores columna de la sieguiente matriz:');
p = [u1 u2 u3]

display('Apartado C)');
display('No resuelto');


