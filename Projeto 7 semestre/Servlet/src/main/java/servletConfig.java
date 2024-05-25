import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
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


@WebServlet("/servletConfig")
public class servletConfig extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public servletConfig() {
		super();

	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {


		JSONObject json_Obj;

		JSONParser transform = new JSONParser();

		BufferedReader getReq = request.getReader();
		
		String nome_Prod = "";
		String preco_Prod = "";
		String categoria_Prod = "";
		String tamanho_Prod = "";
		String qtd_Prod = "";
		
		try {
			
			json_Obj = (JSONObject) transform.parse(getReq);
			
			nome_Prod = (String) json_Obj.get("nameProd");
			preco_Prod = (String) json_Obj.get("priceProd");
			categoria_Prod = (String) json_Obj.get("catProd");
			tamanho_Prod = (String) json_Obj.get("sizeProd");
			qtd_Prod = (String) json_Obj.get("qtdProd");
			
			getReq.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ParseException e) {
			e.printStackTrace();
		}
		
		Connection conn = null;
		
		try {
			Class.forName("com.mysql.cj.jdbc.Driver").newInstance();
		} catch (Exception ex) {
			System.out.println("erro:" + ex);
		}
		
		try {
			
			Long data = System.currentTimeMillis();
			Timestamp timestamp = new Timestamp(data);
			
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/armazem?user=root&password=admin");
			
			Statement Qry = conn.createStatement();
			
			Qry.executeUpdate(
					"INSERT INTO ESTOQUE (NOME, PRECO_PRODUTO, CATEGORIA_PRODUTO, TAMANHO_PRODUTO, QTD_PRODUTO, ESTOQUE_TIMESTAMP) VALUES ('"
							+ nome_Prod + "','" + preco_Prod + "','" + categoria_Prod + "','" + tamanho_Prod + "','"
							+ qtd_Prod + "','" + timestamp + "');");
			conn.close();
			
		} catch (SQLException ex) {
			
			System.out.println("SQLException: " + ex.getMessage());
			System.out.println("SQLState: " + ex.getSQLState());
			System.out.println("VendorError: " + ex.getErrorCode());
			
		}
		

	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException{

		response.setContentType("application/json");
		
		Connection conn = null;
		
		try {
			Class.forName("com.mysql.cj.jdbc.Driver").newInstance();
		} catch (Exception ex) {
			System.out.println("erro:" + ex);
		}
		
		try {
			
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/armazem?user=root&password=admin");
			
			Statement Qry = conn.createStatement();
			
			ResultSet result = Qry.executeQuery("SELECT * FROM ESTOQUE");
			
			JSONArray jsonArray = new JSONArray();
			
			while (result.next()) {
				
				String codProd = result.getString("COD_PRD");
				String nameProd = result.getString("NOME");
				String priceProd = result.getString("PRECO_PRODUTO");
				String catProd = result.getString("CATEGORIA_PRODUTO");
				String sizeProd = result.getString("TAMANHO_PRODUTO");
				String qtdProd = result.getString("QTD_PRODUTO");
				
				JSONObject dados = new JSONObject();
				
				dados.put("Cod_prd", codProd);
				dados.put("Nome_produto", nameProd);
				dados.put("Preco_produto", priceProd);
				dados.put("Categoria_produto", catProd);
				dados.put("Tamanho_produto", sizeProd);
				dados.put("Quantidade_produto", qtdProd);
				
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
			
			conn.close();
			
		} catch (SQLException ex) {
			System.out.println("SQLException: " + ex.getMessage());
			System.out.println("SQLState: " + ex.getSQLState());
			System.out.println("VendorError: " + ex.getErrorCode());
		}
	}
	
	protected void doPut(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	
		JSONObject json_Obj;

		JSONParser transform = new JSONParser();

		BufferedReader getReq = request.getReader();
		
		String alt_QtdProd = "";
		String idProd = "";
		
		try {
			
			json_Obj = (JSONObject) transform.parse(getReq);
			
			alt_QtdProd = (String) json_Obj.get("altProdQtd");
			idProd = (String) json_Obj.get("idProd");

			getReq.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ParseException e) {
			e.printStackTrace();
		}
		
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
		
	protected void doDelete(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

		JSONObject json_Obj;

		JSONParser transform = new JSONParser();

		BufferedReader getReq = request.getReader();
		
		String idProd = "";
		
		try {
			
			json_Obj = (JSONObject) transform.parse(getReq);
			
			idProd = (String) json_Obj.get("idProd");

			getReq.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ParseException e) {
			e.printStackTrace();
		}
		
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
			
			Qry.executeUpdate("DELETE FROM ESTOQUE " +  "WHERE COD_PRD =" + id_Prod + ";");
			
			conn.close();
			
		} catch (SQLException ex) {
			
			System.out.println("SQLException: " + ex.getMessage());
			System.out.println("SQLState: " + ex.getSQLState());
			System.out.println("VendorError: " + ex.getErrorCode());
			
		}
		
	
	}

}


