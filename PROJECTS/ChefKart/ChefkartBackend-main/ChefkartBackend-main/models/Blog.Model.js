const mongoose = require('mongoose');

const blogSchema = new mongoose.Schema({
    title: { type: String, required: true },
    content: { type: String, required: true },
    
    category: {
        type: String,
        required: true
    },
    image: { type: String }, // Field to store the image URL or path
    updatedAt: { type: Date, default: Date.now }
});

// Middleware to update the updatedAt field before saving
blogSchema.pre('save', function(next) {
    this.updatedAt = Date.now();
    next();
});

module.exports = mongoose.model('Blog', blogSchema);