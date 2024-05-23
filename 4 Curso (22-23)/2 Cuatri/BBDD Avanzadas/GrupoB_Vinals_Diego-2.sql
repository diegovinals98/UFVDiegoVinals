
/** CREAMOS LA BASE DE DATOS UNIVERISDAD **/

USE [master]
GO

/****** Object:  Database [Universidad]    Script Date: 20/04/2023 19:51:21 ******/
DROP DATABASE [Universidad]
GO


/** FILEGROUPS PARA LAS PARTICIONES **/
/****** Object:  Database [Universidad]    Script Date: 20/04/2023 19:51:21 ******/
CREATE DATABASE [Universidad]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'Universidad', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL13.MSSQLSERVER\MSSQL\DATA\Universidad.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB ), 
 FILEGROUP [FacA] 
( NAME = N'FacultadA', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL13.MSSQLSERVER\MSSQL\DATA\FacultadA.ndf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB ), 
 FILEGROUP [FacB] 
( NAME = N'FacultadB', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL13.MSSQLSERVER\MSSQL\DATA\FacultadB.ndf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB ), 
 FILEGROUP [FacC] 
( NAME = N'FacultadC', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL13.MSSQLSERVER\MSSQL\DATA\FacultadC.ndf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB ), 
 FILEGROUP [FacD] 
( NAME = N'FacultadD', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL13.MSSQLSERVER\MSSQL\DATA\FacultadD.ndf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB ), 
 FILEGROUP [FacE] 
( NAME = N'FacultadE', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL13.MSSQLSERVER\MSSQL\DATA\FacultadE.ndf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'Universidad_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL13.MSSQLSERVER\MSSQL\DATA\Universidad_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
GO

IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [Universidad].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO

ALTER DATABASE [Universidad] SET ANSI_NULL_DEFAULT OFF 
GO

ALTER DATABASE [Universidad] SET ANSI_NULLS OFF 
GO

ALTER DATABASE [Universidad] SET ANSI_PADDING OFF 
GO

ALTER DATABASE [Universidad] SET ANSI_WARNINGS OFF 
GO

ALTER DATABASE [Universidad] SET ARITHABORT OFF 
GO

ALTER DATABASE [Universidad] SET AUTO_CLOSE OFF 
GO

ALTER DATABASE [Universidad] SET AUTO_SHRINK OFF 
GO

ALTER DATABASE [Universidad] SET AUTO_UPDATE_STATISTICS ON 
GO

ALTER DATABASE [Universidad] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO

ALTER DATABASE [Universidad] SET CURSOR_DEFAULT  GLOBAL 
GO

ALTER DATABASE [Universidad] SET CONCAT_NULL_YIELDS_NULL OFF 
GO

ALTER DATABASE [Universidad] SET NUMERIC_ROUNDABORT OFF 
GO

ALTER DATABASE [Universidad] SET QUOTED_IDENTIFIER OFF 
GO

ALTER DATABASE [Universidad] SET RECURSIVE_TRIGGERS OFF 
GO

ALTER DATABASE [Universidad] SET  DISABLE_BROKER 
GO

ALTER DATABASE [Universidad] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO

ALTER DATABASE [Universidad] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO

ALTER DATABASE [Universidad] SET TRUSTWORTHY OFF 
GO

ALTER DATABASE [Universidad] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO

ALTER DATABASE [Universidad] SET PARAMETERIZATION SIMPLE 
GO

ALTER DATABASE [Universidad] SET READ_COMMITTED_SNAPSHOT OFF 
GO

ALTER DATABASE [Universidad] SET HONOR_BROKER_PRIORITY OFF 
GO

ALTER DATABASE [Universidad] SET RECOVERY FULL 
GO

ALTER DATABASE [Universidad] SET  MULTI_USER 
GO

ALTER DATABASE [Universidad] SET PAGE_VERIFY CHECKSUM  
GO

ALTER DATABASE [Universidad] SET DB_CHAINING OFF 
GO

ALTER DATABASE [Universidad] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO

ALTER DATABASE [Universidad] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO

ALTER DATABASE [Universidad] SET DELAYED_DURABILITY = DISABLED 
GO

ALTER DATABASE [Universidad] SET QUERY_STORE = OFF
GO

USE [Universidad]
GO

ALTER DATABASE SCOPED CONFIGURATION SET LEGACY_CARDINALITY_ESTIMATION = OFF;
GO

ALTER DATABASE SCOPED CONFIGURATION SET MAXDOP = 0;
GO

ALTER DATABASE SCOPED CONFIGURATION SET PARAMETER_SNIFFING = ON;
GO

ALTER DATABASE SCOPED CONFIGURATION SET QUERY_OPTIMIZER_HOTFIXES = OFF;
GO

ALTER DATABASE [Universidad] SET  READ_WRITE 
GO

/** CREACION DE LA TABLA TB_PROFESORES **/
USE [Universidad]
GO

/** Si ya existe,la borramos para que se pueda crear otra con el mismo nombre **/
/****** Object:  Table [dbo].[Tb_Profesores]    Script Date: 20/04/2023 19:56:06 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[Tb_Profesores]') AND type in (N'U'))
DROP TABLE [dbo].[Tb_Profesores]
GO

/****** Object:  Table [dbo].[Tb_Profesores]    Script Date: 20/04/2023 19:56:06 ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[Tb_Profesores](
	[email] [nchar](25) NULL,
	[Acro] [nchar](25) NOT NULL,
	[Titulacion] [nchar](25) NULL,
	[Dedicacion] [int] NULL,
 CONSTRAINT [PK_Tb_Profesores] PRIMARY KEY CLUSTERED 
(
	[Acro] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO


/** CREACION DE LA TABLA TB_HISTOPROFESORES **/
USE [Universidad]
GO

/****** Object:  Table [dbo].[Tb_Histoprofesores]    Script Date: 20/04/2023 20:05:31 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[Tb_Histoprofesores]') AND type in (N'U'))
DROP TABLE [dbo].[Tb_Histoprofesores]
GO

/****** Object:  Table [dbo].[Tb_Histoprofesores]    Script Date: 20/04/2023 20:05:31 ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[Tb_Histoprofesores](
	[email] [nchar](25) NOT NULL,
	[OldAcro] [nchar](25) NULL,
	[NewAcro] [nchar](25) NULL,
	[Titulacion] [nchar](25) NULL,
	[Dedicacion] [int] NULL,
	[FechaCambio] [datetime] NULL,
 CONSTRAINT [PK_Tb_Histoprofesores] PRIMARY KEY CLUSTERED 
(
	[email] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO



/**** fin de la creacion de las tablas NO particionadas *****/

/**** CREAR TABLA PARTICIONADA ******/
create partition function Particion_Ejericio(nchar(25))
		/** Uso el acronimo de la facultad para dividir en la pariticion **/

		as range left for values('A', 'B', 'C', 'D')

		create partition scheme esquema_facultad as partition Particion_Ejericio
		to (FacA, FacB, FacC, FacD, FacE)

		CREATE TABLE [dbo].[Tb_Facultad](
			[Acro] [nchar](25) NULL,
			[Nombre] [nchar](25) NULL,
			[Edificio] [nchar](25) NULL
		) ON esquema_facultad (Acro)
		GO


/*** CREAMOS EL PROCEDIMIENTO  *****/

/** Dado un email, nos devuelve el acronimo de la facultad al cual pertenece ese profesor **/
CREATE PROCEDURE email_profesor
	@email as nchar (25)
AS 
	SELECT Acro
	FROM Tb_Profesores
	WHERE email = @email;
GO


/** CREACION DEL TRIGGER **/
CREATE TRIGGER cambio_facultad
ON Tb_profesores /* La TABLA donde se ejecuta el disparador */
AFTER UPDATE
AS
BEGIN

/** declaramos las variables que vamos a rellenar **/
    DECLARE @old_ACRO varchar(50);
    DECLARE @new_ACRO varchar(50);
    DECLARE @fecha_cambio datetime;
	DECLARE @email varchar(50);
	DECLARE @titulacion varchar(50);
	DECLARE @dedicacion int;

/** rellenamos las variables nuevas, con la informacion del antiguo y del nuevo elemento **/
    SELECT @old_ACRO = Acro FROM DELETED; /* Variable operador de la eliminada */
	SELECT @new_ACRO = Acro FROM INSERTED;
	SET @fecha_cambio = GETDATE();
	SELECT @email = email from DELETED;
	SELECT @titulacion = Titulacion from DELETED; 
	SELECT @dedicacion = Dedicacion from DELETED; 
    
    IF (@old_ACRO <> @new_ACRO) /* Si son distintos, es que ha cambiado */
    BEGIN
        INSERT INTO Tb_Histoprofesores (email, OldAcro, NewAcro, Titulacion, Dedicacion, FechaCambio)
        VALUES (@email, @old_ACRO, @new_ACRO, @titulacion, @dedicacion, @fecha_cambio);
    END
END










