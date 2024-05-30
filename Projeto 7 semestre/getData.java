import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.json.JSONArray;
import org.json.JSONObject;

@WebServlet({"/getData"})
public class getData extends HttpServlet {
  private static final long serialVersionUID = 1L;
  
  protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
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
      out.flush();
      conn.close();
    } catch (SQLException ex) {
      System.out.println("SQLException: " + ex.getMessage());
      System.out.println("SQLState: " + ex.getSQLState());
      System.out.println("VendorError: " + ex.getErrorCode());
    } 
  }
}

