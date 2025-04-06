const {cloudinary}=require('../config/cloudinary');
const {mongoose}=require('mongoose');
const ChefModel = require('../models/Chef.model');

//create chef
const createChef=async(req,res)=>{
     try{ 
        const {name, Address,profilepic, city, state,area, country, pincode,email,
            phone,experience}=req.body;

         

         if(!name || !Address || !city || !state || !area || !country || !pincode || !email || !phone || !experience){
            return res.status(400).json({message:"All fields are required"})
         }

         const existingChef=await ChefModel.findOne({email:email});
         if(existingChef){
            return res.status(400).json({message:"Chef already exists"});
         }
         const newChef=new ChefModel({
            name,
            Address,
            city,
            state,
            area,
            country,
            pincode,
            email,
            phone,
            experience,
            profilepic
         })
         await newChef.save();
         res.status(201).json({
            message:"Chef Created Succcessfully ",
            data:newChef
         })
     }
     catch(error){
        console.error("Error :",error);
        res.status(500).json({message:"internal server error"})
     }
}


const getAllChef=async(req,res)=>{
     try{
         const Chef=await ChefModel.find();

         res.status(200).json({
            message:"Chef fetched Successfully",
            data:Chef
         })
     }
     catch(error){
        console.error("Error",error);
        res.status(500).json({message:"internal server error"})

     }
}
//get by id 
const getById=async(req,res)=>{
     try{
        const {id}=req.params;

        const Chef=await ChefModel.findById(id);

        res.status(200).json({
            message:"Chef fetched successfully",
            data:Chef
        })

     }catch(error){
        console.error("Error ",error);
        res.status(500).json({
            message:"internal sever"
        });
     }
}

const updateChef=async(req,res)=>{
     try{
         const {id}=req.params;

          const { name,
            Address,
            city,
            state,
            area,
            country,
            pincode,
            email,
            phone,
            experience,
            profilepic}=req.body;
          
          let imageUrl="";

           if(profilepic){
             const result=await cloudinary.uploader.upload(profilepic,{
               folder:"Chef",
             });
             imageUrl=result.secure_url;
           }
            const updateChefs=await ChefModel.findByIdAndUpdate(id,{
                name,
                Address,
                city,
                state,
                area,
                country,
                pincode,
                email,
                phone,
                experience,
                 profilepic:imageUrl
            },{new:true},)
            

            
             res.status(200).json({
                message:"Chef updated successfully",
                data:updateChefs
             });

     }
     catch(error){
        console.error("Error:", error);
        res.status(500).json({ message: "Internal server error" });
     }
}



const deleteCheftById=async(req,res)=>{
    try{
        const {id}=req.params;
        if (!id.match(/^[0-9a-fA-F]{24}$/)) {
            return res.status(400).json({ message: "Invalid blog ID format" });
          }
         
          const existingTestimonial=await ChefModel.findById(id); 
          if(!existingTestimonial){
            return res.status(404).json({message:"Chef not found"});
          }
           // delete the testimonial
            const deleteChef=await ChefModel.findByIdAndDelete(id);

            res.status(200).json({
                message:"ChefModel Deleted Successfully",
                data:deleteChef
            });

    }
    catch(error){
       console.error("Error:", error);
       res.status(500).json({ message: "Internal server error" });
    }
}

const DeleteAllChef=async(req,res)=>{
    try{
        const Chef=await ChefModel.deleteMany();

        res.status(200).json({
           message:"Chef Deleted Successfully",
           data:Chef
        })
    }
    catch(error){
       console.error("Error",error);
       res.status(500).json({message:"internal server error"})

    }
}

module.exports={createChef,getAllChef,getById,updateChef,deleteCheftById,DeleteAllChef};