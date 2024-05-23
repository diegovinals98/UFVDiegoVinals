% Parcial 1
% Nombre: Diego Vinals Lage
% Modelo: A
% Fecha: 18/05/2021


% Ejercicio 1
clc, clear
disp('Ejercicio 1')

disp('Apartado A)')
disp('La funcion de la ganancia esta marcada por la suma de las ventas de los cuadros')
disp('por lo tanto, G = 300*m + 150*A, siendo M cuadros de madera y A cuadros de aluminio')
disp('Las restricciones son que M no puede ser mayor que 6, y A no puede ser mayor que 4')
disp('EL hijo va a una velocidad de 4,6 m^2, por lo tanto, 0.55*M + 0.75*A no puede ser mayor que 4,6')
disp('M+A no puede ser mayor que 10')

disp('Apartado B)')
%x = 300*m + 150*A

f = [-300 -150];
%restricciones
% M + A <= 10
% M < 6
% A < 4
% 0.55*M + 0.75A < 4,6
A = [1 1
    1 0
    0 1
    0.55 0.75];

b = [10 6 4 4.6];

[x , G] = linprog(f,A,b);
disp(['El padre tiene que hacer: ', num2str(x(1)) , ' y la madre tiene que hacer: ', num2str(x(2)) , ' Cuadros.'])
disp(['La Ganancia total seria: ' , num2str(-G) , ' Euros'])

disp('Apartado C')
disp('Apartado NO resuelto')

pause
% Ejercicio 2
disp('Ejercicio 2')
clc, clear
syms s t
A = [3,-1,-3,-1;1,1,-3,-1;0,0,-1,-1;0,0,1,-3]
disp('Apartado A)')
[V, D] = eig(A)
disp(['Los autovalores son Lambda = ', num2str(D(1,1)) , ', Lambda = ' , num2str(D(2,2)), ', Lambda = ', num2str(D(3,3)) , ', Lambda = ' , num2str(D(4,4))])
disp('Lambda = 2 tiene multiplicidad 2, y Lambda = -2 tiene multiplicidad 2')
disp('Apartado B)')
vp11 = D(1,1)*eye(4) - A; 
vp22 = D(2,2)*eye(4) - A; 
vp33 = D(3,3)*eye(4) - A; 
vp44 = D(4,4)*eye(4) - A;

% vp11 y vp22 son iguales, calcularemos una sola base
% vp33 y vp44 son iguales, calcularemos una sola base
GJ11 = rref(vp11) 
GJ22 = rref(vp33)

% en GJ11 Cogemos x2 como t
BaseLambda = t*[1 -1 0 0]
% en GJ22 Cogemos x4 como s
BaseLambd2 = s*[1 1 1 1]


disp('Apartado C)')
[P, ~] = eig(A);
Pinv = round(inv(P)); % Inversa de la matriz de autovectores
D = round(Pinv*A*P); % P-1*A*P es una matriz diagonal (los autovalores)
disp('Si que es diagonalizable')
disp('La matriz es: ')
Pinv
disp('Podemos comprobar que si multiplicamos inv(P)*A*P nos sale una matriz diagonal')
D


pause
% Ejercicio 3
clc, clear
disp('Ejercicio 3')
syms lambda
A = sym([3,1,2;1,3,2;2,2,6])

disp('Apartado A)')
[P, ~] = eig(A);
Pinv = round(inv(P)); % Inversa de la matriz de autovectores
D = round(Pinv*A*P); % P-1*A*P es una matriz diagonal (los autovalores)
disp('Si que es diagonalizable')
disp('La matriz es: ')
Pinv
disp('Podemos comprobar que si multiplicamos inv(P)*A*P nos sale una matriz diagonal')
D

disp('Apartado B)')
P = det(lambda*eye(3)- A)

lambda = solve(P==0) % Valores de lambda

[V, ~] = eig(A) % Matriz de autovectores
% v2 y v3 no son ortogonales:
v2 = V(:, 2); v3 = V(:, 3);
pe = dot(v2, v3);
if pe ~= 0
    display('v2 y v3 no son ortogonales') 
end
% Ortonormalización de Gram-Schmidt
w2 = v2;
w3 = v3 - (dot(v3, w2)/dot(w2, w2))*w2;
u1 = V(:, 1);
u2 = w2/norm(w2); u3 = w3/norm(w3);
% Matriz P:
P = [u1 u2 u3]

disp('Apartado C)')
S = [2 0 0
    0 8 0
    0 0 2]
% Tenemos que Qt * Q = inv(A) * S
syms Q

ec1 = Q'*Q == inv(A) * S
sol = solve(ec1, Q)






