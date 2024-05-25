import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;


public class delete {

	public static void main(String[] args) {
		
		
		String alt_QtdProd = "50";
		String idProd = "3";
		
		Connection conn = null;
		
		try {
			Class.forName("com.mysql.cj.jdbc.Driver").newInstance();
		} catch (Exception ex) {
			System.out.println("erro:" + ex);
		}
		
		try {
			
			int id_Prod = Integer.parseInt(idProd);
			
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/armazem?user=root&password=admin");
			
			Statement Qry = conn.createStatement();
			
			Qry.executeUpdate("UPDATE ESTOQUE SET QTD_PRODUTO =" + "'" + alt_QtdProd + "'" + "WHERE COD_PRD =" + id_Prod + ";");
			
			conn.close();
			
		} catch (SQLException ex) {
			
			System.out.println("SQLException: " + ex.getMessage());
			System.out.println("SQLState: " + ex.getSQLState());
			System.out.println("VendorError: " + ex.getErrorCode());
			
		}
	}

}
