from motor.motor_asyncio import AsyncIOMotorClient
import os

# MongoDB Connection URL
MONGO_URI = "mongodb+srv://fastapi_user:        @cluster0.mmyigrp.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0"

# Connect to MongoDB
client = AsyncIOMotorClient(MONGO_URI)
db = client["chat_db"]  # Database name
collection = db["chats"]  # Collection for storing chat messages
