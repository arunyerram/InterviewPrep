const {cloudinary } = require("../config/cloudinary");
const Crousel=require('../models/Crousel.Model');
const {mongoose}=require('mongoose');
// create a crousel

const createCrousel=async(req,res)=>{
     try{
         const {title, content, image , action}=req.body;
         
         if(!title || !content || !image || !action){
             return res.status(400).json({message:"Please fill in all fields"});
         }
         const newCrousel=new Crousel({
            title, 
            content, 
            image, 
            action
         })
         await newCrousel.save();

         res.status(201).json({
            message:"Crousel created successfully",
            data:newCrousel
         
         })

     }
     catch(error){
         console.error("Error:",error);
         res.status(500).json({
             message:"Internal server error"
         });
     }
}
// get all crousel

const getAllCrousel=async(req,res)=>{
     try{
         const Crousels=await Crousel.find();

         res.status(200).json(Crousels);

     }
     catch(error){
            console.error("Error:",error);
            res.status(500).json({
                message:"Internal server error"
            });
     }
}

const getCrouselById=async(req,res)=>{
    try{

         const {id}= req.params;

         const Crousels=await Crousel.findById(id);

         res.status(200).json(Crousels);

    }
    catch(error){
        console.error("Error:", error);
        res.status(500).json({
            message:"Internal server error"
        });
    }
}

const updateCrousel = async (req, res) => {
    try {
        const { id } = req.params;
        const { title, content, image, action } = req.body;
        let imageUrl = "";

        console.log("Updating Crousel with ID:", id);

        // Validate ID
        if (!mongoose.Types.ObjectId.isValid(id)) {
            return res.status(400).json({ message: "Invalid Crousel ID" });
        }

        // Find existing Crousel
        const existingCrousel = await Crousel.findById(id);
        if (!existingCrousel) {
            return res.status(404).json({ message: "Crousel not found" });
        }

        // Upload new image if provided, otherwise keep existing image
        imageUrl = image
            ? (await cloudinary.uploader.upload(image, { folder: "Crousel" })).secure_url
            : existingCrousel.image;

        // Update the document
        const updatedCrousel = await Crousel.findByIdAndUpdate(
            id,
            { title, content, image: imageUrl, action },
            { new: true }
        );

        res.status(200).json({
            message: "Crousel updated successfully",
            data: updatedCrousel,
        });
    } catch (error) {
        console.error("Error updating Crousel:", error);
        res.status(500).json({ message: "Internal server error" });
    }
};

// delete a crousel
 const deleteCrouselById=async(req,res)=>{
     try{
        const {id}=req.params;

        if (!id.match(/^[0-9a-fA-F]{24}$/)) {
            return res.status(400).json({ message: "Invalid blog ID format" });
          }

        const existingCrousel=await Crousel.findById(id);

        if(!existingCrousel){
            return res.status(404).json({
                message: "Crousel not found"
            })
        }
        // delete the crousel
        const deleteCrousel=await Crousel.findByIdAndDelete(id);

        res.status(200).json({
            message:"Crousel deleted successfully",
            data:deleteCrousel
        })


     }catch(error){
            console.error("Error:", error);
            res.status(500).json({
                message:"Internal server error"
            });
     }
 }

 const deleteCrousel=async(req,res)=>{
     try{
         const Crousels=await Crousel.deleteMany();

         res.status(200).json({
            message:"All crousels deleted successfully",
            data:Crousels
         })
         

     }
     catch(error){
        console.error("Error:", error);
        res.status(500).json({
            message:"Internal server error"
        });
     }
 }

module.exports={createCrousel, getAllCrousel,getCrouselById,updateCrousel,deleteCrouselById,deleteCrousel}