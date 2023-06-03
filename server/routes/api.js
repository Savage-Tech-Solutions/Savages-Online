// api.js

var express = require('express');
var router = express.Router();

/*******************************************
 * HTTP GET /api/
 ******************************************/
router.get('/', function(req, res, next) {
  res.send('@/api');
  console.log('GET /api/');
});

/*******************************************
 * HTTP GET /api/registration
 ******************************************/
router.get('/registration', function(req, res, next) {
  res.send('GET /api/registration');
  console.log('GET /api/registration');
});

/*******************************************
 * HTTP POST /api/registration
 ******************************************/
router.post('/registration', async function(req, res, next) {
  // res.send('POST /api/registration');
  // console.log('POST /api/registration');

  // console.log(req.body.Username);
  // console.log(req.body.Email);
  // console.log(req.body.Password);

  let user = await User.findOne({ username: req.body.Username });
  
  if (user) {
      res.send("EXISTS");
      console.log("User Exists.");
  } else {

    user = new User({
        username: req.body.Username,
        email: req.body.Email,
        password: req.body.Password
    });

    if(req.body.Username.length > 0 && req.body.Email.length > 0 && req.body.Password.length > 0){
      await user.save();
      res.send("CREATED");
      console.log("Account Created!");

      playerData = new Player({
        username: req.body.Username,
        level: "1",
        spriteSheet: "HUMAN",
        playerX: "624",
        playerY: "200",
        playerDirection: "UP",
        cameraX: "670",
        cameraY: "190",
        map: "MAIN_VILLAGE",
      });
      await playerData.save();


    } else {
      res.send("INVALID");
      console.log("ALL FIELDS MUST BE FILLED.");
    }

  }

});

/*******************************************
 * HTTP GET /api/login
 ******************************************/
router.get('/login', function(req, res, next) {
  res.send('GET /api/login');
  console.log('GET /api/login');
});

/*******************************************
 * HTTP POST /api/login
 ******************************************/
router.post('/login', async function(req, res, next) {
  // res.send('POST /api/login');
  // console.log('POST /api/login');

  // console.log(req.body.Username);
  // console.log(req.body.Password);

  let user = await User.findOne({ username: req.body.Username, password: req.body.Password });

  if (user) {
      res.send("EXISTS");
      console.log("User Exists.");
  } else {
      res.send("UNDEFINED");
      console.log("Undefined.")
  }

});

module.exports = router;