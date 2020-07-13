#include <iostream>
#include <sqlite3.h>
using namespace std;
int main(int argc, char **argv)
{
    sqlite3 *DB;
    int exit = 0;
    exit = sqlite3_open("example.db", &DB);
    if (exit)
    {
        cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
        cout << "Opened Database Successfully!" << std::endl;
    sqlite3_close(DB);
    return (0);
}