const jwt = require('jsonwebtoken');
const JWT_SECRET = process.env.JWT_SECRET || "belowisasecretkey";
require('dotenv').config();  // ✅ Load environment variables

const verifyToken = (req, res, next) => {
    const authHeader = req.header('Authorization');
    if (!authHeader) {
        return res.status(401).json({ message: 'Access denied, token missing' });
    }

    const token = authHeader.split(' ')[1]; // ✅ Ensure this extracts only the token part

    try {
        const decoded = jwt.verify(token, JWT_SECRET);
        req.user = { userId: decoded.userId };  // ✅ Extract userId from token
        next();
    } catch (error) {
        console.error("JWT Verification Error:", error);
        res.status(400).json({ message: 'Invalid token', error: error.message });
    }
};

module.exports = { verifyToken };
