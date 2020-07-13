#include <iostream>
#include <sqlite3.h>
#include <string>
using namespace std;
static int callback(void* data,int argc,char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ",(const char*)data);
    for(i=0;i<argc;i++)
    {
        printf("%s = %s\n",azColName[i],argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
int main(int argc, char** argv)
{
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("example.db",&DB);
    string query = "SELECT * FROM PERSON;";
    cout << "STATE OF TABLE BEFORE INSERT" << endl; 
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 

    string sql("INSERT INTO PERSON VALUES(1, 'VAIBHAV', 'SARAF');"
               "INSERT INTO PERSON VALUES(2, 'PRATIKSHA', 'SANCHETI');"
               "INSERT INTO PERSON VALUES(3, 'YASH', 'HIRAN');"
               "INSERT INTO PERSON VALUES(4, 'YASH', 'RODE');"
               "INSERT INTO PERSON VALUES(5, 'KRISHNA', 'HUDGE');"); 
    
    // string sql("INSERT INTO PERSON VALUES(6, 'SHRUTI', 'AHER');"); 
    
    
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError); 

    if (exit != SQLITE_OK) { 
        std::cerr << "Error Insert" << std::endl; 
        sqlite3_free(messaggeError); 
    } 
    else
    {
        std::cout << "Records created Successfully!" << std::endl; 
    }
    cout << "STATE OF TABLE AFTER INSERT" << endl;
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
    return (0);
}
