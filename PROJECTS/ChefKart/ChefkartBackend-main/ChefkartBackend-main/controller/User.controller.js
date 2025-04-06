const mongoose = require("mongoose");
const jwt = require("jsonwebtoken");
const bcrypt = require("bcryptjs");
const User = require("../models/User.model");

const JWT_SECRET = process.env.JWT_SECRET || "belowisasecretkey";

const generateToken = (userId) => {
  return jwt.sign({ userId }, JWT_SECRET, { expiresIn: "1h" });
};



const UserSignup = async (req, res) => {
  try {
    const { name, email, password } = req.body;

    if (!name || !email || !password) {
      return res.status(400).json({ message: "All fields are required" });
    }

    const existingUser = await User.findOne({ email });
    if (existingUser) {
      return res.status(400).json({ message: "User already exists" });
    }

    const hashedPassword = await bcrypt.hash(password, 12);

    const newUser = new User({
      name,
      email,
      password: hashedPassword,
    });

    await newUser.save();

    const token = generateToken(newUser._id);

    res.status(201).json({
      message: "User has been registered successfully",
      user: {
        _id: newUser._id,
        name: newUser.name,
        email: newUser.email,
      },
      token,
    });
  } catch (error) {
    console.error(error);
    res.status(500).json({ message: "Signup failed", error: error.message });
  }
};

const UserLogin = async (req, res) => {
  try {
    const { email, password } = req.body;


    //validation for email and password
    if (!email || !password) {
      return res.status(400).json({ message: "All fields are required" });
    }
    //existing email
    const user = await User.findOne({ email });
    if (!user) {
      return res.status(400).json({ message: "Invalid credentials" });
    }
    // password validation
    const isMatch = await bcrypt.compare(password, user.password);
    if (!isMatch) {
      return res.status(400).json({ message: "Invalid credentials" });
    }

    const token = generateToken(user._id);

    res.status(200).json({
      message: "Login successful",
      user: {
        _id: user._id,
        name: user.name,
        email: user.email,
      },
      token,
    });
  } catch (error) {
    console.error(error);
    res.status(500).json({ message: "Login failed", error: error.message });
  }
};

module.exports = { UserSignup, UserLogin };
