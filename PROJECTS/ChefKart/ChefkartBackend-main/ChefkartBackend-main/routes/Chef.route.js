const { createChef, getAllChef, getById, updateChef, deleteCheftById, DeleteAllChef } = require('../controller/Chefs.Controller');

const router = require('express').Router();

router.post('/createChef',createChef  );
router.get('/get',  getAllChef);
router.get('/get/:id', getById);
router.put('/update/:id',updateChef) ;
router.delete('/delete/:id', deleteCheftById)
router.delete('/delete', DeleteAllChef)
module.exports = router;
