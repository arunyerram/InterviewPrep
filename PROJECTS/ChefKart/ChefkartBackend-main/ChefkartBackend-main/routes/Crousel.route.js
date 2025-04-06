const { createCrousel, getCrouselById, updateCrousel, deleteCrouselById, deleteCrousel, getAllCrousel } = require('../controller/Crousel.Controller');

const router = require('express').Router();

router.post('/createCrousel',createCrousel  );
router.get('/get',  getAllCrousel);
router.get('/get/:id', getCrouselById);
router.put('/update/:id',updateCrousel) ;
router.delete('/delete/:id', deleteCrouselById)
router.delete('/delete', deleteCrousel)
module.exports = router;
