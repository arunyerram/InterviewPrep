 const cloudinary= require('cloudinary');
const {CloudinaryStorage}=require('multer-storage-cloudinary');

const multer=require('multer');

 require('dotenv').config();
  
 cloudinary.config({
    cloud_name:process.env.CLOUDINARY_CLOUD_NAME,
    api_key:process.env.CLOUDINARY_API_KEY,
    api_secret:process.env.CLOUDINARY_API_SECRET
 })

 // define storage setting in multer 
  const storage= new CloudinaryStorage({
     cloudinary:cloudinary,
     params:{
        folder:'Image_folder',
        allowed_formats:['jpg','png','jpeg','webp']
     }

  });

   const upload=multer({storage});
   module.exports={cloudinary,upload};