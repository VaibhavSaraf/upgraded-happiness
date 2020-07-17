#include <iostream>
#include <sqlite3.h>
using namespace std;
int main()
{
    sqlite3* DB;
    string sql = "CREATE TABLE PERSON ( ID INT PRIMARY KEY NOT NULL,FIRSTNAME VACHAR(255),LASTNAME VARCHAR(255));";
    int exit = 0;
    exit = sqlite3_open("example.db",&DB);
    char* messageError;
    exit = sqlite3_exec(DB,sql.c_str(),NULL,0,&messageError);
    if(exit!= SQLITE_OK)
    {
        cerr<< "Error Create Table"<<"\n";
        sqlite3_free(messageError);
    }
    else
    {
        cout<<"Table created Successfully"<<"\n";
    }
    sqlite3_close(DB);
    return 0;
    
}