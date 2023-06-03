// dependencies
var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
var mongoose  = require('mongoose');

// include routers
var indexRouter = require('./routes/index');
var apiRouter = require('./routes/api');

var databaseInformation = require('./secrets');  // Database Information

/************************************************************************/
// Database Connection
/************************************************************************/
var db = mongoose.connection;
var mongoDB = databaseInformation.DatabaseURL;

mongoose.connect(mongoDB, {useNewUrlParser: true, useUnifiedTopology: true});

db.on('error', console.error.bind(console, 'Database Connection Error'));

db.once("open", function () {
  console.log("Savages-Online Database Connected successfully");
});
/************************************************************************/
// End Database Connection
/************************************************************************/

var app = express();  // Create variable for express server

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'jade');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/api', apiRouter);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});

module.exports = app;
