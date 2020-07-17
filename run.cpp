#include <iostream>
#include <string>
#include <sqlite3.h>
using namespace std;
class Database
{
public:
    sqlite3 *DB;
    Database()
    {
        create_db();
    }
    int create_db()
    {
        int exit = 0;
        exit = sqlite3_open("main.db", &DB);
        if (exit)
        {
            cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
            return (-1);
        }
        else
            cout << "Opened Database Successfully!" << std::endl;
    }
    void close_db()
    {
        sqlite3_close(DB);
    }

    void create_table()
    {
        string sql = "CREATE TABLE PERSON ( ID INT PRIMARY KEY NOT NULL,FIRSTNAME VACHAR(255),LASTNAME VARCHAR(255));";
        int exit = 0;
        exit = sqlite3_open("main.db", &DB);
        char *messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK)
        {
            cerr << "Error Create Table"
                 << "\n";
            sqlite3_free(messageError);
        }
        else
        {
            cout << "Table created Successfully"
                 << "\n";
        }
    }
    static int callback(void *data, int argc, char **argv, char **azColName)
    {
        int i;
        fprintf(stderr, "%s: ", (const char *)data);
        for (i = 0; i < argc; i++)
        {
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }
        printf("\n");
        return 0;
    }
    void insert()
    {
        string id, first_name, last_name;
        char *messaggeError;
        int exit = sqlite3_open("main.db", &DB);
        string select = "SELECT * FROM PERSON;";
        cout << "please insert data"
             << "\n";
        cout << "Id: ";
        cin >> id;
        cout << "First name: ";
        cin >> first_name;
        cout << "Last name: ";
        cin >> last_name;

        string query = "INSERT INTO PERSON VALUES(" + id + ", " + "\'" + first_name + "\'"
                                                                                      ", " +
                       "\'" + last_name + "\'" + ");";

        exit = sqlite3_exec(DB, query.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK)
        {
            cerr << "Error Insert" << endl;
            sqlite3_free(messaggeError);
        }
        else
        {
            std::cout << "Records created Successfully!" << std::endl;
        }
        sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    }
    void show_database()
    {
        string query = "SELECT * FROM PERSON;";
        sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    }
    void sort()
    {
        int m;
        cout << "1. sort by first name\n"
             << "2. sort by last name\n";
        cin >> m;
        string sort_firstName = "SELECT * FROM PERSON ORDER BY FIRSTNAME ASC;";
        string sort_lastName = "SELECT * FROM PERSON ORDER BY LASTNAME ASC;";
        if (m == 1)
        {
            sqlite3_exec(DB, sort_firstName.c_str(), callback, NULL, NULL);
        }
        else if (m == 2)
        {
            sqlite3_exec(DB, sort_lastName.c_str(), callback, NULL, NULL);
        }
        else
        {
            cout << "please select proper choice! \n";
            sort();
        }
    }
    void delete_record()
    {
        char *messaggeError;
        cout << "print id which record wants to delete\n";
        string l;
        cin >> l;
        string del = "DELETE FROM PERSON WHERE ID = " + l + ";" ;
        int exit = sqlite3_exec(DB, del.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK)
        {
            std::cerr << "Error DELETE" << std::endl;
            sqlite3_free(messaggeError);
        }
        else
            std::cout << "Record deleted Successfully!" << std::endl;
    }
};

int main()
{
    Database d;
    int x;
    bool flag = true;
    while (flag)
    {
        cout << "0. Create table \n"
             << "1. Insert data into table \n"
             << "2. Print Table \n"
             << "3. delete record from table \n"
             << "4. sort the record from table \n"
             << "5. exit\n";
        cin >> x;
        switch (x)
        {
        case 0:
            d.create_table();
        case 1:
            d.insert();
            break;
        case 2:
            // cout << 2 << "\n";
            d.show_database();
            break;
        case 3:
            d.delete_record();
            break;
        case 4:
            d.sort();
            break;
        case 5:
            flag = false;
            break;
        default:
            cout << "please select proper choise! \n";
            break;
        }
    }
    return 0;
}