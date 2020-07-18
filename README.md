# upgraded-happiness

## Connectivity of SQLite3 with C++ and NodeJS

### Problem Statement
* Write a C++ code to insert & sort data in an Sqlite database (one table with columns: id, firstname, lastname). 
* Write another Javascript/Html file to view the data in a tabular format.
  The Javascript/Html program should check if the C++ program is running. If the C++ program isn't running, then the first program should throw en error message

##### C++ program
------------
* C++ UI should be console based.
* UI prompt: 
    - 1st prompt: Insert or Sort. 
    - 2nd prompt:
        - If insert, input firstname and then lastname. 
        - If sort, then prompt sort by firstname or lastname.
    - 3rd prompt: Success message (and update table data)

##### Javascript/Html program
------------
* Open the sqlite table in tabular format
------------
### Features!
  - Create database
  - Create table
  - Insert data
  - delete data
  - sort data
  - show data on localhost
  
------------

### Tech

* [C++] - Low level programming language for CRUD operations
* [SQLite3] - Database
* [NodeJS] - JavaScript runtime environment that executes JavaScript code outside a web browser.
* [Express] -  It is a web application framework for Node.js
* [Swig] - Simplified Wrapper and Interface Generator

------------

### Installation

```sh
$ cd upgraded-happiness
$ sudo apt-get install sqlite3 libsqlite3-dev
$ sudo apt-get install nodejs
$ sudo apt-get install npm
$ npm install .
```
------------
### Run code :
1. In one terminal run following code 
```sh
$ g++ run.cpp -l sqlite3
```
and in other terminal 
```sh
$ npm run start:dev
```
then open browser and open site
```sh
$ localhost:3000
```
you will see the database on browser.

------------

problem statement given by **Grafieks Analytics Limited**
