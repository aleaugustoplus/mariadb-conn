//============================================================================
// Name        : db-conn.cpp
// Author      : alopes
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <mysql/mysql.h>  // require libmysqlclient-dev
#include <string>

using namespace std;


/*
 * Execution
 */
int main(){
	try	{
		MYSQL     *conn;
		MYSQL_RES *res;
		MYSQL_ROW row;
		// Format a MySQL object
		conn = mysql_init(NULL);

		// Establish a MySQL connection
		if (!mysql_real_connect(conn, "127.0.0.1", "alopes", "2C? 4ubp4ddL2Dsk", "alopes_test", 5000, NULL, 0)) {
			cerr << mysql_error(conn) << endl;
			return false;
		}

		// Execute a sql statement
		if (mysql_query(conn, "SHOW TABLES")) {
			cerr << mysql_error(conn) << endl;
			return false;
		}

		// Get a result set
		res = mysql_use_result(conn);

		// Fetch a result set
		cout << "* MySQL - SHOW TABLES in `"
			 << "database" << "`" << endl;
		while ((row = mysql_fetch_row(res)) != NULL)
			cout << row[0] << endl;

		// Release memories
		mysql_free_result(res);

		// Close a MySQL connection
		mysql_close(conn);
	} catch (char *e) {
		cerr << "[EXCEPTION] " << e << endl;
		return 1;
	}
	return 0;
}


