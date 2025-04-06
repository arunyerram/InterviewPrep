const { cloudinary } = require("../config/cloudinary");
const Testimonial = require("../models/Testimonial.Model");

/// create a testimonial
const createTestimonial = async (req, res) => {
  try {
    const { name, content, profileimage } = req.body;

    if (!name || !content) {
      return res.status(400).json({ message: "Please fill in all fields" });
    }

    const newTestimonial = new Testimonial({
      name,
      content,
      profileimage,
    });
    await newTestimonial.save();

    res.status(201).json({
      message: "Testimonial is successfully created",
      data: newTestimonial,
    });
  } catch (error) {
    console.error("Error:", error);
    res.status(500).json({ message: "Internal server error" });
  }
};


//get all Testominail

const getAllTestimonial=async(req,res)=>{
     try{
         const Testimonials= await  Testimonial.find();
         
         if(!Testimonials.length){
             return res.status(404).json({message:"No Testimonial found"});
         }
          res.status(200).json({
             message:"Testimonial fetched successfully",
             data:Testimonials
          })
     }
     catch(error){
        console.error("Error:", error);
        res.status(500).json({ message: "Internal server error" });
     }
}

//get a single testimonial
 const getTestimonialByID=async(req,res)=>{
     try{
          const {id}=req.params;

          const Testimonials=await Testimonial.findById(id);

          if(!Testimonials){
            return res.status(404).json({message:"No Testimonial found"});
          }
          res.status(200).json({
             message:"Testimonial Fetched Successfully",
             data:Testimonials})
     }catch(error){
         console.error("Error:",error);
           res.status(500).json({message:"Internal server"})
     }
 }

//update testimonial
const updateTestimonial=async(req,res)=>{
     try{
         const {id}=req.params;

          const { name, content, profileimage}=req.body;
          
          let imageUrl="";

           if(profileimage){
             const result=await cloudinary.uploader.upload(profileimage,{
               folder:"testimonials",
             });
             imageUrl=result.secure_url;
           }
            const updateTestimonial=await Testimonial.findByIdAndUpdate(id,{
                 name, 
                 content,
                 profileimage:imageUrl
            },{new:true},)
            

            if(!updateTestimonial){
               return res.status(404).json({message:"Testimonial not found"});
            }
             res.status(200).json({
                message:"Testimonial updated successfully",
                data:updateTestimonial
             });

     }
     catch(error){
        console.error("Error:", error);
        res.status(500).json({ message: "Internal server error" });
     }
}


const deleteTestomonial=async(req,res)=>{
    try{
        const {id}=req.params;
        if (!id.match(/^[0-9a-fA-F]{24}$/)) {
            return res.status(400).json({ message: "Invalid blog ID format" });
          }
         
          const existingTestimonial=await Testimonial.findById(id); 
          if(!existingTestimonial){
            return res.status(404).json({message:"Testimonial not found"});
          }
           // delete the testimonial
            const deleteTestimonial=await Testimonial.findByIdAndDelete(id);

            res.status(200).json({
                message:"Testimonial Deleted Successfully",
                data:deleteTestimonial
            });

    }
    catch(error){
       console.error("Error:", error);
       res.status(500).json({ message: "Internal server error" });
    }
}


module.exports={
    createTestimonial,
    getAllTestimonial,
    getTestimonialByID,
    updateTestimonial,
    deleteTestomonial
    
};