#include <iostream>
#include <sqlite3.h>
#include <string>
using namespace std;
static int callback(void* data,int argc,char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ",(const char*)data);
    
}
