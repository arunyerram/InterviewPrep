const { createBlog, getallBlogs, getBlogById, updateBlog, deleteBlog } = require('../controller/Blog.Controller');

const router = require('express').Router();

router.post('/create', createBlog)
router.get('/getAll', getallBlogs);
router.get('/get/:id', getBlogById);
router.put('/update/:id',updateBlog) ;
router.delete('/delete/:id', deleteBlog)
 


module.exports = router;