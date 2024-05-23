create database proyectosII;


--- creacion tabla usuarios
CREATE TABLE usuarios (
    id serial PRIMARY KEY,
    nombre varchar(255) ,
    apellidos varchar(255) ,
    usuario varchar(255) ,
    contraseña varchar(255) ,
    tipo varchar(255)
);

truncate usuarios;

insert into usuarios(nombre, apellidos, usuario, contraseña, tipo)
values 
	('Diego', 'Viñals Lage', 'diego98v', '1234567890', 'Arbitro');
	
select * from usuarios;


-- creacion de la tabla de equipos de futbol
CREATE TABLE equipos (
    id serial PRIMARY KEY,
    nombre varchar(255) ,
    PG int,
    PE int,
    PP int,
    GF int,
    GC int,
    DG int,
    puntos int
);

-- Para Borrar los elementos de la tabla
truncate equipos;
-- Añadimos los equipos de fitbol

INSERT INTO equipos (id, nombre, pg, pe, pp, gf, gc, dg, puntos)
VALUES 
    (1, 'Rayo Majadahonda', 5, 2, 3, 12, 9, 3, 17),
    (2, 'Pinto FC', 3, 5, 2, 8, 7, 1, 14),
    (3, 'Las Rozas CF', 4, 1, 5, 11, 13, -2, 13),
    (4, 'Villanueva del Pardillo FC', 2, 6, 2, 9, 9, 0, 12),
    (5, 'CF Pozuelo de Alarcón', 4, 2, 4, 11, 10, 1, 12),
    (6, 'Alcorcón United', 3, 4, 3, 8, 7, 1, 13),
    (7, 'Boadilla del Monte FC', 5, 1, 4, 13, 10, 3, 16),
    (8, 'UD Móstoles', 2, 4, 4, 7, 9, -2, 10),
    (9, 'Collado Villalba United', 1, 6, 3, 6, 9, -3, 9),
    (10, 'Fuenlabrada City', 3, 3, 4, 8, 10, -2, 12);
 
-- Mostrar los elementos de la tabla
select * from equipos;

----------- PICHICHI -------------------------

-- creacion de la tabla de pichichi de futbol
CREATE TABLE pichichi (
    id serial PRIMARY KEY,
    equipo varchar(255) ,
    nombreJugador varchar(255) ,
    goles int
);

-- Para Borrar los elementos de la tabla
truncate pichichi ;
-- Rellenar la tabla pichichi
INSERT INTO pichichi (equipo, nombreJugador, goles)
VALUES 
    ('Boadilla del Monte FC', 'Diego Pérez', 12),
    ('CF Pozuelo de Alarcón', 'Juan Gómez', 8),
    ('Pinto FC', 'Luis Suarez', 11),
    ('Fuenlabrada City', 'Rafael Núñez', 7),
    ('Las Rozas CF', 'Santiago Castro', 6);


-- Mostrar los elementos de la tabla
select * from pichichi;




----------- ASISTENCIAS -------------------------

-- creacion de la tabla de pichichi de futbol
CREATE TABLE asistencias (
    id serial PRIMARY KEY,
    equipo varchar(255) ,
    nombreJugador varchar(255) ,
    asistencias int
);

-- Para Borrar los elementos de la tabla
truncate asistencias ;

-- Rellenar la tabla asistencias
INSERT INTO asistencias (equipo, nombreJugador, asistencias)
VALUES 
    ('Boadilla del Monte FC', 'Miguel Ruiz', 4),
    ('CF Pozuelo de Alarcón', 'David Alonso', 8),
    ('Pinto FC', 'Pedro García', 6),
    ('Fuenlabrada City', 'Luis García', 7),
    ('Las Rozas CF', 'Juan Rodríguez', 9);


-- Mostrar los elementos de la tabla
select * from asistencias;




----------- ZAMORA -------------------------

-- creacion de la tabla de pichichi de futbol
CREATE TABLE zamora (
    id serial PRIMARY KEY,
    equipo varchar(255) ,
    nombreJugador varchar(255) ,
    golesencajados int
);

-- Para Borrar los elementos de la tabla
truncate zamora ;

-- Rellenar la tabla asistencias
INSERT INTO zamora (equipo, nombreJugador, golesencajados)
VALUES 
    ('Pinto FC', 'Francisco Ruiz', 5),
    ('CF Pozuelo de Alarcón', 'Javier Alonso', 8),
    ('Alcorcón United', 'Pedro Soria', 4),
    ('Fuenlabrada City', 'Alejandro Jiménez', 7),
    ('Las Rozas CF', 'Jose Juan Almeida', 9);


-- Mostrar los elementos de la tabla
select * from zamora;




----------- PARTIDOS JUGADOS -------------------------

-- creacion de la tabla de pichichi de futbol
CREATE TABLE partidosjugados (
    id serial PRIMARY KEY,
    equipoLocal varchar(255) ,
    equipoVisitante varchar(255) ,
    golesLocal int,
    golesVisitante int, 
    lugar varchar(255) ,
    fecha varchar(255) ,
    hora varchar(255),
    arbitro varchar(255)
);

-- Rellenar la tabla asistencias
INSERT INTO partidosjugados (equipoLocal, equipoVisitante, golesLocal, golesVisitante, lugar, fecha,hora, arbitro  )
VALUES 
    ('CF Pozuelo de Alarcón', 'Rayo Majadajonda', 2, 0, 'Pozuelo de Alarcón', '24 de Marzo 2022', '21:00hr', 'Manuel González' ),
    ('Pinto FC', 'UD Móstoles', 1, 1, 'Pinto', '25 de Marzo 2022', '14:00hr', 'Marcos Gomez' );

-- Para Borrar los elementos de la tabla
truncate partidosjugados ;
-- Mostrar los elementos de la tabla
select * from partidosjugados;







----------- PARTIDOS JUGADOS -------------------------

-- creacion de la tabla de pichichi de futbol
CREATE TABLE partidosnojugados (
    id serial PRIMARY KEY,
    equipoLocal varchar(255) ,
    equipoVisitante varchar(255) ,
    lugar varchar(255) ,
    fecha varchar(255) ,
    hora varchar(255),
    arbitro varchar(255)
);

-- Para Borrar los elementos de la tabla
truncate partidosnojugados ;



-- Rellenar la tabla asistencias
INSERT INTO partidosnojugados (equipoLocal, equipoVisitante, lugar, fecha,hora, arbitro  )
VALUES 
    ('Collado Villalba United', 'Villanueva del Pardillo FC', 'Collado-Villalba', '27 de Marzo 2022', '19:00hr', 'Manuel González' ),
    ('Alcorcón United', 'Boadilla del Monte FC', 'Alcorcón', '27 de Marzo 2022', '21:00hr', 'Jose Luis Garcia' );


-- Mostrar los elementos de la tabla
select * from partidosnojugados;


create table reclamaciones(
	id serial primary key, 
	idpartido int, 
	motivo varchar(255),
	reclamacion varchar(700)
	)
	
truncate reclamaciones ;

select * from reclamaciones;



--- para actulizar todo como nuevo 

-- Ponemos la tabla en 0
UPDATE equipos
SET pg = 0, pe = 0, pp = 0, gf = 0, gc = 0, dg = 0, puntos = 0; 
-- Para Borrar los elementos de la tabla
truncate partidosnojugados ;
-- Para Borrar los elementos de la tabla
truncate partidosjugados ;
-- Rellenar la tabla asistencias
INSERT INTO partidosnojugados (equipoLocal, equipoVisitante, lugar, fecha,hora, arbitro  )
VALUES 
    ('Collado Villalba United', 'Villanueva del Pardillo FC', 'Collado-Villalba', '27 de Marzo 2022', '19:00hr', 'Manuel González' ),
    ('Alcorcón United', 'Boadilla del Monte FC', 'Alcorcón', '27 de Marzo 2022', '21:00hr', 'Jose Luis Garcia' ),
	('Las Rozas CF', 'Rayo Majadahonda', 'El Cantizal - Las Rozas', '27 de Marzo 2022', '21:00hr', 'Manuel González' ),
    ('Fuenlabrada City', 'UD Móstoles', 'Fuenlabrada', '27 de Marzo 2022', '21:00hr', 'Jose Luis Garcia' ),
	('Pinto FC', 'Villanueva del Pardillo FC', 'Pinto', '27 de Marzo 2022', '21:00hr', 'Jose Luis Garcia' );
-- Mostrar los elementos de la tabla
select * from partidosnojugados;
