


from fastapi import FastAPI, HTTPException, Depends
from pydantic import BaseModel
from typing import List, Optional
from motor.motor_asyncio import AsyncIOMotorClient
import openai
import os

app = FastAPI()

-- mongodb+srv://fastapi_user:<db_password>@cluster0.mmyigrp.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0

# Database Configuration
MONGO_URI = "mongodb://localhost:27017"
DB_NAME = "chatDB"
COLLECTION_NAME = "chats"
client = AsyncIOMotorClient(MONGO_URI)
db = client[DB_NAME]
collection = db[COLLECTION_NAME]

# OpenAI API Key (Replace with your own key)
os.environ["OPENAI_API_KEY"] = "your-api-key"
openai.api_key = os.getenv("OPENAI_API_KEY")

# Data Models
class ChatMessage(BaseModel):
    user_id: str
    message: str
    timestamp: str

class ChatSummaryRequest(BaseModel):
    conversation_id: str

# API Endpoints
@app.post("/chats")
async def store_chat(chat: ChatMessage):
    chat_dict = chat.dict()
    result = await collection.insert_one(chat_dict)
    return {"inserted_id": str(result.inserted_id)}

@app.get("/chats/{conversation_id}")
async def get_chats(conversation_id: str):
    chats = await collection.find({"user_id": conversation_id}).to_list(100)
    return chats

@app.post("/chats/summarize")
async def summarize_chat(request: ChatSummaryRequest):
    chats = await collection.find({"user_id": request.conversation_id}).to_list(100)
    conversation_text = "\n".join([chat["message"] for chat in chats])
    response = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages=[{"role": "system", "content": "Summarize the following conversation."},
                  {"role": "user", "content": conversation_text}]
    )
    return {"summary": response["choices"][0]["message"]["content"]}

@app.get("/users/{user_id}/chats")
async def get_user_chats(user_id: str, page: int = 1, limit: int = 10):
    skip = (page - 1) * limit
    chats = await collection.find({"user_id": user_id}).skip(skip).limit(limit).to_list(limit)
    return chats

@app.delete("/chats/{conversation_id}")
async def delete_chat(conversation_id: str):
    result = await collection.delete_many({"user_id": conversation_id})
    return {"deleted_count": result.deleted_count}
