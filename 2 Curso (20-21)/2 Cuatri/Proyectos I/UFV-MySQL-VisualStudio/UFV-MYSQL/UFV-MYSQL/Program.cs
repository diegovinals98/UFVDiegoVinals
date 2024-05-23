using System;
using MySql.Data.MySqlClient;

namespace UFV_MYSQL
{
    public class Program
    // gonzalo.delasheras@ufv.es
    {
        static void Main(string[] args)
        {      
            string query = @"
                SELECT 
	                M.nombre AS nombre_modelo, 
	                numero_plazas, 
	                F.nombre AS nombre_fabricante, 
	                nacionalidad
                FROM 
	                ufv.modelo M
	                INNER JOIN ufv.fabricante F 
		                ON M.id_fabricante = F.id;
            ";

            MySqlConnection databaseConn = new MySqlConnection(Utils.CONNECTION_STRING);
            MySqlCommand command = new MySqlCommand(query, databaseConn);
            command.CommandTimeout = 60;
            MySqlDataReader reader;

            try
            {
                databaseConn.Open();
                reader = command.ExecuteReader();

                if (reader.HasRows)
                {
                    while (reader.Read())
                    {
                        Console.WriteLine(reader.GetString(0) + " || " + reader.GetInt32(1) +
                            " || " + reader.GetString(2) + " || " + reader.GetString(3));
                    }
                }
                else 
                {
                    Console.WriteLine("No hay datos");
                }
            }
            catch (Exception Ex)
            {
                // Excepcion
                Console.WriteLine(Ex.Message);
            }
        }
    }
}
