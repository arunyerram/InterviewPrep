const { cloudinary } = require("../config/cloudinary");
const Gallery = require("../models/Gallery.Model");

const createGallery = async (req, res) => {
  try {
    const { name, content, galleryImages } = req.body;

    // validation process
    if (!name || !content || !galleryImages) {
      return res.status(400).json({
        message: "All fields are required",
      });
    }

    const newGallery = new Gallery({
      name,
      content,
      galleryImages,
    });
    await newGallery.save();
    res
      .status(201)
      .json({ message: "Gallery created successfully", gallery: newGallery });
  } catch (error) {
    console.error("Ersror:", error);
    res.status(500).json({ message: "Internal server error" });
  }
};

//ge all gallery
const getAllGallery = async (req, res) => {
  try {
    const Gallerys = await Gallery.find();

    res.status(200).json(Gallerys);
  } catch (error) {
    console.error("Error:", error);
    res.status(500).json({ message: "Internal server error" });
  }
};


const deleteGallery = async (req, res) => {
    try {
      const Gallerys=await Gallery.deleteMany();
     
  
      res.status(200).json({
        message: "Gallery deleted successfully",
      data: Gallerys
      });
    } catch (error) {
      console.error("Error:", error);
      res.status(500).json({ message: "Internal server error" });
    }
  };

module.exports = {
  createGallery,
  getAllGallery,
  deleteGallery
};
