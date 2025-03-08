<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.sql.*, javax.servlet.http.*, javax.servlet.*" %>

<% 
String username = (String) session.getAttribute("username"); 
String password = (String) session.getAttribute("password"); 
if (username == null) { 
    response.sendRedirect("login.jsp");
    return;
} 
%>

<!DOCTYPE html>
<html>
<head>
    <title>Welcome</title>
</head>
<body>
    <h2>Welcome, <%= username %>!</h2>
    <a href="Logout.jsp">Logout</a>
</body>
</html>
