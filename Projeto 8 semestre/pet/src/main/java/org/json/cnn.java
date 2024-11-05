package org.json;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.sql.Timestamp;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;
import org.json.JSONArray;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
public class cnn {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
 		
 		Connection conn = null;
 		
 		try {
 			Class.forName("com.mysql.cj.jdbc.Driver").newInstance();
 		} catch (Exception ex) {
 			System.out.println("erro:" + ex);
 		}
 		
 		try {
 			
 			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/db_esperanca_viva?user=admin&password=admin");
 			
 			Statement Qry = conn.createStatement();
 			
 			ResultSet result = Qry.executeQuery("SELECT * FROM vw_animais_disp_adocao");
 			
 			JSONArray jsonArray = new JSONArray();
 			
 			while (result.next()) {
 				
 				String id_animal = result.getString("ID_ANIMAL");
 				String especie = result.getString("ESPECIE");
 				String nome_raca = result.getString("NOME_RACA");
 				String nome = result.getString("NOME");
 				String genero = result.getString("GENERO");
 				String estado = result.getString("ESTADO");
 				
 				System.out.println(id_animal);
 				System.out.println(especie);
 				System.out.println(nome_raca);
 				System.out.println(nome);
 				System.out.println(genero);
 				System.out.println(estado);
 				
 				JSONObject dados = new JSONObject();
 				
 				dados.put("ID_ANIMAL", id_animal);
 				dados.put("ESPECIE", especie);
 				dados.put("NOME_RACA", nome_raca);
 				dados.put("NOME", nome);
 				dados.put("GENERO", genero);
 				dados.put("ESTADO", estado);
 				
 				jsonArray.put(dados);
 				
 				System.out.println(jsonArray);

 			}
 					
 			
 			conn.close();		
 			
 		} catch (SQLException  ex) {
 			System.out.println("SQLException: " + ex.getMessage());
 			System.out.println("SQLState: " + ((SQLException) ex).getSQLState());
 			System.out.println("VendorError: " + ((SQLException) ex).getErrorCode());
 		}

 }
}
