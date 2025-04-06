from motor.motor_asyncio import AsyncIOMotorClient

# MongoDB Connection URI
MONGO_URI = "mongodb+srv://fastapi_user:gUGr6bCvcuFVvhH4@cluster0.mmyigrp.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0"

# Connect to MongoDB
client = AsyncIOMotorClient(MONGO_URI)
db = client["chat_db"]  # Database name
collection = db["chats"]  # Collection for storing chat messages
