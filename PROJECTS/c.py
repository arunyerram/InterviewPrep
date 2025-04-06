from fastapi import FastAPI
from motor.motor_asyncio import AsyncIOMotorClient

app = FastAPI()

# Replace <db_password> with your actual password
MONGO_URI = "mongodb+srv://fastapi_user:gUGr6bCvcuFVvhH4@cluster0.mmyigrp.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0"
client = AsyncIOMotorClient(MONGO_URI)

# Select database and collection
db = client["chat_db"]  # You can rename "chat_db" as needed
collection = db["messages"]

@app.get("/")
async def root():
    return {"message": "MongoDB Atlas connected successfully!"}
