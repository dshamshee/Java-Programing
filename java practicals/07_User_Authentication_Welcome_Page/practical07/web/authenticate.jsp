<%@ page import="java.sql.*" %>
<%@ include file="db.jsp" %>

<% 
String username = request.getParameter("username"); 
String password = request.getParameter("password"); 

if (username == null || password == null) {
    out.println("<p>Error: Username or password is missing!</p>");
    return;
}

out.println("<p>Debug: Username - " + username + "</p>"); 

Connection conn = null;
PreparedStatement ps = null;
ResultSet rs = null;

try {
    conn = getConnection();
    if (conn == null) {
        out.println("<p>Error: Database connection failed!</p>");
        return;
    }

    String query = "SELECT * FROM credit WHERE username=? AND password=?";
    ps = conn.prepareStatement(query);
    ps.setString(1, username);
    ps.setString(2, password);
    rs = ps.executeQuery();

    if (rs.next()) { 
        session.setAttribute("username", username);
        session.setAttribute("passsword", password);
        response.sendRedirect("welcome.jsp");
    } else { 
        request.setAttribute("errorMessage", "Invalid username or password.");
        request.getRequestDispatcher("login.jsp").forward(request, response);
    }
} catch (Exception e) {
    out.println("<p>Error: " + e.getMessage() + "</p>");
    e.printStackTrace();
} finally {
    if (rs != null) try { rs.close(); } catch (SQLException e) { e.printStackTrace(); }
    if (ps != null) try { ps.close(); } catch (SQLException e) { e.printStackTrace(); }
    if (conn != null) try { conn.close(); } catch (SQLException e) { e.printStackTrace(); }
}
%>
