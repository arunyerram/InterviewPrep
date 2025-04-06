from fastapi import FastAPI
from motor.motor_asyncio import AsyncIOMotorClient

# Create FastAPI app
app = FastAPI()

# MongoDB Connection
MONGO_URI = "mongodb+srv://fastapi_user:gUGr6bCvcuFVvhH4@cluster0.mmyigrp.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0"
client = AsyncIOMotorClient(MONGO_URI)

# Select database and collection
db = client["chat_db"]  # You can rename "chat_db"
collection = db["messages"]  # You can rename "messages"

# Root endpoint
@app.get("/")
async def root():
    return {"message": "MongoDB Atlas connected successfully!"}

# Example: Add a message to the database
@app.post("/add_message/")
async def add_message(content: str):
    result = await collection.insert_one({"content": content})
    return {"inserted_id": str(result.inserted_id)}

# Example: Fetch all messages
@app.get("/get_messages/")
async def get_messages():
    messages = []
    async for doc in collection.find():
        messages.append({"id": str(doc["_id"]), "content": doc["content"]})
    return {"messages": messages}
