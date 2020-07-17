#include <iostream>
#include <sqlite3.h>
#include <string>
using namespace std;
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
int main()
{
    bool flag = true;
    int x,m;

    string id, first_name, last_name, query;
    int exit;
    sqlite3 *DB;
    char *messaggeError;
    int exit = sqlite3_open("example.db", &DB);
    if (exit != SQLITE_OK)
    {
        cerr << "Error Create Table"
             << "\n";
        sqlite3_free(messaggeError);
    }
    else
    {
        cout << "Table created Successfully"
             << "\n";
    }
    string select_all = "SELECT * FROM PERSON;";
    string sort_firstName = "SELECT * FROM PERSON ORDER BY FIRSTNAME ASC;";
    string sort_lastName = "SELECT * FROM PERSON ORDER BY LASTNAME ASC;";
    while (flag)
    {
        cout << "1. Insert data into table \n"
             << "2. Print Table \n"
             << "3. delete record from table \n"
             << "4. sort the record from table \n"
             << "5. exit\n";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << 1 << "\n";
            cout << "please insert data"
                 << "\n";
            cout << "Id: ";
            cin >> id;
            cout << "First name: ";
            cin >> first_name;
            cout << "Last name: ";
            cin >> last_name;

            query = "INSERT INTO PERSON VALUES(" + id + ", " + "\'" + first_name + "\'"
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
        case 2:
            cout << "-- Table --" << endl;
            sqlite3_exec(DB, select_all.c_str(), callback, NULL, NULL);
            break;
            break;
        case 3:
            cout << 3 << "\n";
            break;
        case 4:
            cout << "1. sort by first name\n"
                 << "2. sort by last name\n";
            cin>>m;
            if(m==1)
            {
                sqlite3_exec(DB, sort_firstName.c_str(), callback, NULL, NULL);
            }
            else if (m==2)
            {
                sqlite3_exec(DB, sort_lastName.c_str(), callback, NULL, NULL);
            }
            else
            {
                cout<<"please select proper choice! \n";
            }
            break;
        case 5:
            flag = false;
            break;
        default:
            break;
        }
    }
    return 0;
}