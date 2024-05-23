% Nombre: Diego Vinals Lage
% Fecha: 18/05/2021
% Modelo: B

% EJERCICIO 1
clc, clear
disp('Ejercicio 1')
syms x
y = (x^2-2*x + 7)/(sqrt(3*x^2 - 2*x -5))

disp('Apartado A)')
disp('Calcular el dominio')
[~, den]= numden(y);


sol = solve(den==0, x, 'Real', true); % Con Real, solo nos da las soluciones reales, no las imaginarias.
re=0;
for i=1:length(sol)
    if(isreal(sol(i)))
        fprintf('Para x = %1.1f la funcion no existe \n', sol(i))
        re=1;
    end
end


if(re==1)
    fprintf('El dominio de la funcion es: (-inf , %1.2f ) y  (%1.2f, +inf)', sol(1) , sol(2)) 
end
fprintf('\n')

disp('Apartado B)')
disp('Con el eje OY:')

cOY = subs(y, x, 0);
if isreal(cOY)
    n = length(cOY); 
    if n >= 1
        for i = 1:n 
            if isreal(cOY(i)) 
                disp(['Corta con OY en: y = ',num2str(round(double(cOY(i)),2))])
            end
        end
    end
else
 disp('No hay cortes con el eje OY')
end

disp(' ')
disp('Con el eje OX:')

cOX = solve(y, y==0);
if isempty(cOX)
    disp('No hay cortes con el eje OX')
else
    n = length(cOX);
    real=0;
    if n >= 1
        for i = 1:n
            if isreal(cOX(i))
                real=1;
                disp(['Corta con OX en: x = ',num2str(round(double(cOX(i)),2))])
            end
        end
        if(real==0)
            disp('No se han hallado cortes con el eje OX')
        end
    end
end

disp('Apartado C) y D)')
disp('Maximos, minimos, decrecimiento y crecimiento')
disp('Calculamos la derivada:...')

dy = diff(y,x);
pretty(dy)

disp('... y la igualamos a cero, con solucion:')
disp(' ')
[dy0, para, condicion] = solve(dy==0, x,'ReturnConditions', true, 'Real', true);

j=1; %numero cualquiera del dominio para evaluar en caso de que no exista solucion a la derivada igualada a cero
% j lo cogemos en funcion de la grafica, mejor que sea pequena 
sw = 0;
if isempty(dy0)
 disp('La derivada no tiene solucion en dy = 0')
 sw = 1;
 inter1 = subs(dy, x, j); % Tomamos un valor a la izquierda de x (arbitrario), j dependera de la funcion
    v1 = double(inter1);
    if v1 < 0
        disp('La funcion es decreciente')
    else
        if v1 > 0
            disp('La funcion es creciente')
        else
            disp('La funcion ni crece ni decrece')
        end
    end
end
if sw == 0 % Solo buscamos valores de y para las soluciones reales
    y0(i)=length(dy0);
    for i = 1:length(dy0)
        y0(i) = subs(y, x, dy0(i));
        if isreal(y0(i))
            fprintf('x = %6.3f', dy0(i))
            disp([' con y = ', num2str(round(double(y0(i)),2))])
        end
    end
end
disp(' ')
disp('Estudiamos el crecimiento:')
disp(' ')

%usando el bucle for en vez de preguntar varias veces.
%Inicializo el array de soluciones de crecimientos posibles
v1= zeros(length(dy0));
v2= zeros(length(dy0));
reg1_puntos= zeros(length(dy0));
reg2_puntos= zeros(length(dy0));

%Creo dos arrays con puntos a la izquierda y a la derecha de las soluciones
%respectivamente
for i=1:length(dy0)
    reg1_puntos(i)=dy0(i)-0.05;%Tolerancia a los puntos
    reg2_puntos(i)=dy0(i)+0.05;%Tolerancia a los puntos
end

% conprobar con otras funciones, para entenderlo bien. 

for i=1:length(dy0)
    if isreal(y0(i))
        fprintf('\nEn el punto (%6.3f, %6.3f):...\n', round(double(dy0(i)),2), double(y0(i)))
        inter1 = subs(dy, x, reg1_puntos(i) );
        v1(i) = double(inter1);
        if v1(i) < 0
            disp('La funcion es decreciente a la izquierda')
        else
            disp('La funcion es creciente a la izquierda')
        end
        inter2 = subs(dy, x, reg2_puntos(i));
        v2(i) = double(inter2);
        if v2(i) < 0
            disp('La funcion es decreciente a la derecha')
        else
            disp('La funcion es creciente a la derecha')
        end
        
        if v1(i)<0 && v2(i)>0
            fprintf('Por tanto, existe un MINIMO en x = %1.2f e y = %1.2f \n',round(double(dy0(i)),2), round(double(y0(i)),2))
        else
            if v1(i)>0 && v2(i)<0
                fprintf('Por tanto, existe un MAXIMO en x = %1.2f e y = %1.2f \n',round(double(dy0(i)),2), round(double(y0(i)),2))
            else
                fprintf('No existe ni m?ximo ni m?nimo en el punto x = %1.2f e y = %1.2f \n',round(double(dy0(i)),2), round(double(y0(i)),2))
            end
        end
    end
end

disp('Apartado E)')
disp('Asintotas');
disp('Asintotas horizontales')%Nuestra funcion nunca tiende al infinito en las x, por lo que no existe asintota horizontal
AH = limit(y, x, Inf);
if isinf(AH) || isnan(AH)
    % No se pueden hacer limites laterales en asintotas horizontales, por
    % lo tanto no hay asintotas horizontales.
    disp('No hay asintotas horizontales')
else
    disp(['Asintota horizontal en y = ', num2str(double(AH))])
end
disp(' ')
disp('Asintotas verticales')
[num, den] = numden(y);
AV = solve(den==0);
if isreal(AV)
    fprintf('Existe una ASINTOTA VERTICAL en x = %1.2f \n', AV)
else
    fprintf('No hay asintotas verticales\n')
end
disp(' ')
disp('Asintotas oblicuas')
m = limit(y/x, x, Inf);
if isinf(m) || m == 0
    disp('No hay asintotas oblicuas')
else
    n = limit((y - m*x), x, Inf);
    if n > 0
        signo = '+';
    else
        signo = '-';
    end
    if n == 0
        disp(['Existe una asintota oblicua en y = ', num2str(double(m)), 'x'])
        
    else
        disp(['Existe una asintota oblicua en y = ',num2str(double(m)), 'x ', signo, ' ', num2str(abs(double(n)))])
    end
end

disp('Apartado F)')
disp(' ')

%usando el bucle for en vez de preguntar varias veces.
%Inicializo el array de soluciones de crecimientos posibles
v1= zeros(length(dy0));
v2= zeros(length(dy0));
reg1_puntos= zeros(length(dy0));
reg2_puntos= zeros(length(dy0));

%Creo dos arrays con puntos a la izquierda y a la derecha de las soluciones
%respectivamente
for i=1:length(dy0)
    reg1_puntos(i)=dy0(i)-0.05;%Tolerancia a los puntos
    reg2_puntos(i)=dy0(i)+0.05;%Tolerancia a los puntos
end
disp(' ')
disp('Calculamos la segunda derivada y la igualamos a cero')
dy2 = diff(y, x, 2); % Calculamos la segunda derivada
% pretty(d2y) % Esto es innecesario aunque a veces puede ayudar
d2y= solve(dy2==0,x);
sw = 0;
if isempty(d2y)
    disp('La segunda derivada no tiene solucion en d2y = 0')
    sw = 1;
    reg1_inflex = subs(d2y, x, -0.5);
    if reg1_inflex> 0
        disp('La funcion es concava hacia arriba')
    else
        if reg1_inflex<0
            disp('La funcion es concava hacia abajo')
        else
            disp('La funcion es una recta en todo el dominio')
        end
    end
end
y02=zeros(length(d2y));
if sw == 0 % Solo buscamos valores de y para las soluciones reales
 for i = 1:length(d2y)
     y02(i) = subs(y, x, d2y(i));
     if isreal(y02(i))
        fprintf('x = %6.3f', d2y(i))
        disp([' con y = ', num2str(round(double(y02(i)),2))])
     end
 end
end

clf % Borrado de cualquier figura anterior
xx = -15:0.001:15; 
%yy = 4*(xx-1).^2./(xx.^2-4.*xx+5);%y = 4*(x-1)^2/(x^2-4*x+5);

yy = (xx.^2-2.*xx + 7)/(sqrt(3.*xx.^2 - 2.*xx -5))

plot(xx, yy, 'b')
hold on


axis([-12 12 -3 9]) % se puede no poner esto, pero si pones esto, la figura te queda centrada y bien dibujada.
grid minor % Se pone una rejilla para que se vea mejor
% Escribimos la funcion en el titulo
tt = title(['$' latex(y) '$']); % los signos de dolar indica que lo que esta en medio esta en codigo latex.

tt.Interpreter = 'latex';
tt.FontSize =16;
tt.Color = 'b';
% Leyenda del eje X
tx = xlabel('x');
tx.FontName = 'Times';
tx.FontSize = 14;
tx.Color = 'k';
tx.FontAngle = 'italic';
%Leyenda del eje Y
ty = ylabel('y');
ty.FontName = 'Times';
ty.FontSize = 14;
ty.Color = 'k';
ty.FontAngle = 'italic';
% Dibujamos la asintota oblicua
hold on
%Dibujamos la asintota horizontal
if ~isinf(AH) || ~isnan(AH)
    plot([20, -20], [AH, AH], '--')
end
text(-10,4.5, ['y = ', num2str(double(AH))], 'horizontalAlignment','left', 'FontSize', 8, 'Color', 'b' )
% Dibujamos la asintota vertical y ejes
for i=1:length(AV)
    if isreal(AV(i))
        plot([AV(i) AV(i)], [-20 20]) % Asintota vertical
    end
end

plot([0 0], [-3 9], 'k-') % Eje X
plot([-12 12], [0 0], 'k-') % Eje Y
% Corte con los ejes
% Corte con el eje OY
if isreal(cOY)
    plot(0, cOY, 'ro') % Corte con el eje OY
    plot([0, -3],[cOY, 6], 'k.-')
    text(-3.5, 6, 'Corte con el eje Y', 'horizontalAlignment','right', 'FontSize', 8)
end
% Corte con el eje OX
if real==1
    for i=1:length(cOX)
        plot(cOX(i), 0, 'ro') % Corte con el eje OX
        plot([cOX(i), -5],[0, -1.5], 'k.-')
    end
    text(-2, -2, 'Corte con el eje X', 'horizontalAlignment','right', 'FontSize', 8)
end
% Dibujamos minimo y punto de inflexion
plot(dy0(2), y0(2), 'ro')
plot([dy0(2), 3.8],[y0(2), 8], 'k.-')
text(4, 8, 'Maximo', 'horizontalAlignment','left') %USAR ANNOTATION MIRAR AYUDA
plot(dy0(1), y0(1), 'ro')
plot([dy0(1), 2.3],[y0(1), -1.5], 'k.-')
text(2.5, -1.5, 'Minimo', 'horizontalAlignment','left')
    for i=1:length(d2y)
        plot(d2y(i), y02(i), 'ro')
        plot([d2y(i),5],[y02(i), 2], 'k.-')
    end
    text(5.5, 2, 'Puntos de Inflexion', 'horizontalAlignment','left', 'FontSize', 8)

pause

% EJERCICIO: 2
clc, clear
disp('EJERCICIO 2')
syms f(x) C1 C2
edo = diff(f(x) , x , 2) == -4*x ; 
y = dsolve(edo);
ec1 = diff(y, x, 1) == f;
ec1 = - 2*(pi/4)^2 + C1 == 1;
sol1 = solve(ec1, C1); % despejamos para calcular c1
ec2 = C2 + sol1*(pi/4) - (2*(pi/4)^3)/3 == -1;
sol2 = solve(ec2, C2); % despejamos para calcular c2
disp('Solucion General')
gen = y
disp('Solucion Particular')
part = sol2 + sol1*x - (2*x^3)/3 % Ecuacion con los valores c1 y c2 

xx = -15:0.1:15;
yy = sol2 + sol1.*xx - (2.*xx.^3)/3
plot(xx, yy, 'b')
hold on


pause 
% EJERCICIO 3
clc, clear
disp('Ejercicio 3') 
syms x
y = (sin(x)/cos(x)) + log(x+1)
disp('Apartado A)')
disp('Polinomio de Maclaurin es un polinimio de Taylor centrado en 0, por lo que hacemos un polinomio de taylor de grado 6 con c = 0')
T = taylor(y,x, 0, 'Order', 6)
disp('Apartado B)')
disp('No realizado')
disp('')
disp('Apartado C)')
error = 100;
valor = (subs(y, x, 0.1));
int = 0;
while error > 10^-6
    int = int + 1;
    tAux= taylor(y, x, 0, 'Order' , int);
    valorAux = subs(tAux , x, 0.1);
    error = valor - valorAux;
end

disp(['El grado minimo es: ', num2str(int)])

