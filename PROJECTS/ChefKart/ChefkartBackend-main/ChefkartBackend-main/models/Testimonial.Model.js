const mongoose = require('mongoose');

const TestimonialSchema = new mongoose.Schema({
    name: { type: String, required: true },
    content: { type: String, required: true },
    profileimage: { type: String }, // Field to store the image URL or path
    updatedAt: { type: Date, default: Date.now }
});

// Middleware to update the updatedAt field before saving
TestimonialSchema.pre('save', function(next) {
    this.updatedAt = Date.now();
    next();
});

module.exports = mongoose.model('Testimonial', TestimonialSchema);