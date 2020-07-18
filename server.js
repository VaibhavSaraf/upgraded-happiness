const express = require('express');
const bodyParser = require('body-parser');
const swig = require('swig');
swig.setDefaults({ cache: false });
const sqlite = require('sqlite3').verbose();

const db = new sqlite.Database('./main.db', (err) => console.log(err));

const app = express();
app.use(bodyParser.urlencoded({ extended: false }));

require("fs").readFile("check.txt", function (err, cont) {
    if (err) {
        console.log("Main Program is not running!!");
        throw err;
    }
    console.log("Program is running");

    
});

// read file
// const fs = require('fs')
// fs.readFile('check.txt', (err, data) => {
//     if (err) {
//         console.log('Error')
//         throw err;
//     }
//     // console.log("File present!!")
//     console.log(data.toString());
// })


app.set('view engine', 'html');
app.engine('html', swig.renderFile);

app.get('/', (req, res, next) => res.render('index'));
// 
app.post('/', (req, res, next) => {
    db.all('select * from PERSON', (err, results) => {
        console.log(results);
        console.log(err);
        res.render('index', { results: results, error: err });
    });
});

const port = process.env.PORT || 3000;

app.listen(port, () => console.log('listening on port ${port}'));

