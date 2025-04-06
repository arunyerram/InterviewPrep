const { createTestimonial, getAllTestimonial, getTestimonialByID, updateTestimonial, deleteTestomonial } = require('../controller/Testimonial.Controller');

const router = require('express').Router();

router.post('/createTestimonial',  createTestimonial)
router.get('/get',   getAllTestimonial)
router.get('/get/:id', getTestimonialByID);
router.put('/update/:id',updateTestimonial) ;
router.delete('/delete/:id',deleteTestomonial)
module.exports = router;
