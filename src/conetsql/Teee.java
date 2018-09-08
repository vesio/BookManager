package conetsql;

import java.sql.*;
public class Teee {
	public static void main(String[] args) {
        Connection conn;
        Statement stmt;
        ResultSet rs;
        String url = "jdbc:sqlserver://localhost:1433;DatabaseName=BookManager;";
        String sql = "select * from Books";
        try {
            // 连接数据库
            conn = DriverManager.getConnection(url, "mima123456", "123456");
            // 建立Statement对象
            stmt = conn.createStatement();
            /**
             * Statement createStatement() 创建一个 Statement 对象来将 SQL 语句发送到数据库。
             */
            // 执行数据库查询语句
            rs = stmt.executeQuery(sql);
            /**
             * ResultSet executeQuery(String sql) throws SQLException 执行给定的 SQL
             * 语句，该语句返回单个 ResultSet 对象
             */
            while (rs.next()) {
                int id = rs.getInt("Bnum");
                String name = rs.getString("Bname");
                String btime=rs.getString("Btime");
                System.out.println("Bnum:" + id + "\tBname:" + name+"\tBtime"+btime);
            }
            if (rs != null) {
                rs.close();
                rs = null;
            }
            if (stmt != null) {
                stmt.close();
                stmt = null;
            }
            if (conn != null) {
                conn.close();
                conn = null;
            }
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("数据库连接失败");
        }
    }

}
