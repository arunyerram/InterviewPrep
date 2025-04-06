const { UserSignup, UserLogin } = require('../controller/User.controller');

const router = require('express').Router();

router.post('/signup', UserSignup)
router.post('/login',UserLogin )
 


module.exports = router;