const mongoose = require('mongoose');

const UserSchema = new mongoose.Schema({
    name: { type: String, required: true },
    email: { type: String, required: true },
    password: { type: String }, // Field to store the image URL or path
    updatedAt: { type: Date, default: Date.now }
});

// Middleware to update the updatedAt field before saving
UserSchema.pre('save', function(next) {
    this.updatedAt = Date.now();
    next();
});

module.exports = mongoose.model('User', UserSchema);