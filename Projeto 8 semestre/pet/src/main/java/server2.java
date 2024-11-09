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

/**
 * Servlet implementation class server
 */
public class server2 extends HttpServlet {
	private static final long serialVersionUID = 1L;

    /**
     * Default constructor. 
     */
    public server2() {
        // TODO Auto-generated constructor stub
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException{

 		response.setContentType("application/json");
		response.setCharacterEncoding("UTF-8");
 		
 		Connection conn = null;
 		
 		try {
 			Class.forName("com.mysql.cj.jdbc.Driver").newInstance();
 		} catch (Exception ex) {
 			System.out.println("erro:" + ex);
 		}
 		
 		try {
 			
 			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/db_esperanca_viva?user=root&password=admin");
 			
 			Statement Qry = conn.createStatement();
 			
 			ResultSet result = Qry.executeQuery("SELECT * FROM VW_DESPESAS_MENSAIS");
 			
 			JSONArray jsonArray = new JSONArray();
 			
 			while (result.next()) {
 				
 				String despesas = result.getString("DESPESAS");

 				
 				JSONObject dados = new JSONObject();
 				
 				dados.put("DESPESAS", despesas);

 				
 				jsonArray.put(dados);
 			}
 			
 			StringBuilder jsonContructor = new StringBuilder();
 			
 			jsonContructor.append("[");
 			
 			for (int i = 0; i < jsonArray.length(); i++) {
 				
 				jsonContructor.append(jsonArray.getJSONObject(i).toString());
 				
 				if (i < jsonArray.length() - 1)
 					jsonContructor.append(",");
 			}
 			
 			jsonContructor.append("]");
 			
 			PrintWriter out = response.getWriter();
 			
 			out.print(jsonContructor.toString());
 		
 			String json = jsonArray.toString();
 			
 			conn.close();
 			
 		} catch (SQLException  ex) {
 			System.out.println("SQLException: " + ex.getMessage());
 			System.out.println("SQLState: " + ((SQLException) ex).getSQLState());
 			System.out.println("VendorError: " + ((SQLException) ex).getErrorCode());
 		}
 	}

 	/**
 	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
 	 */
 	/**protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
 		// TODO Auto-generated method stub
 		doGet(request, response);
 	}
 	
 	**/

 	/**
 	 * @see HttpServlet#doPut(HttpServletRequest, HttpServletResponse)
 	 */
 	
 	/** protected void doPut(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
 		// TODO Auto-generated method stub
 	}
 **/
 	/**
 	 * @see HttpServlet#doDelete(HttpServletRequest, HttpServletResponse)
 	
 	 */
 	
 	/**
 	protected void doDelete(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
 		// TODO Auto-generated method stub
 	}
 	**/

 }
