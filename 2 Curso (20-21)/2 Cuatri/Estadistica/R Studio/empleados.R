str(Empleados) #Muestra la estructura y las caracteristicas del archivo. Vemos el tipo de variable, el numero de variables y el numero de observaciones
summary(Empleados)
Empleados<- subset(Empleados, Empleados$Age>=18)
Empleados<- subset(Empleados, Empleados$Age<=65)
summary(Empleados)
Empleados$AbsentRate<-(Empleados$AbsentHours/2080)*100 #Creamos nueva variable en mi data set
str(Empleados)
counts <- table(Empleados$BusinessUnit)
barplot(counts, horiz = TRUE)
# Estadistica descriptiva, solo para variables cuantitivas
summary(Empleados)
Age <- Empleados$Age
ratioAbs <- Empleados$AbsentRate
summary(Age)
summary(ratioAbs)
var(Age)
sd(Age)
var(ratioAbs)
sd(ratioAbs)
# Correlacion
cov(Age, ratioAbs)
cor(Age,ratioAbs)
plot(Age, ratioAbs)
boxplot(Age)
boxplot(ratioAbs)

