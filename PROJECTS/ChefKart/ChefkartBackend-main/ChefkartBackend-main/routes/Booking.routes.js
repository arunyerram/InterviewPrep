const { createBooking, getBookings, getBookingById, updateBooking, deleteBooking } = require('../controller/Booking.Controller');
const {verifyToken}=require('../middleware/AuthMiddleware')
const router = require('express').Router();

router.post('/createBook',verifyToken ,createBooking );
router.get('/get',  getBookings );
router.get('/get/:id', getBookingById);
router.put('/update/:id',updateBooking) ;

router.delete('/delete', deleteBooking)
module.exports = router;
