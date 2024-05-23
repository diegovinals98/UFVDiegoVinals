library(MASS)
painters

#El signo del dolar nos selecciona una de las columnas#
painters$School
school = painters$School
school
#la funcion table lo que hace es contar cuantos datos tiene la variable o la columna
frecuenciaAbs = table(school)
frecuenciaRel = frecuenciaAbs / nrow(painters)
frecuenciaRel
old = options(digit = 1)
frecuenciaRel
cbind(frecuenciaRel)
barplot(frecuenciaRel)
pie(frecuenciaRel)
data(cars)
summary(cars)
velocidad = cars$speed
boxplot(velocidad)