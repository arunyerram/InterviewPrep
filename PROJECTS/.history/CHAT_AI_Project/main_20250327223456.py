from fastapi import FastAPI
from database import db  # Import the MongoDB connection

app = FastAPI()

# Test Route
@app.get("/")
async def root():
    return {"message": "FastAPI Chat API is running!"}

# Database Connection Test
@app.get("/test_db")
async def test_db():
    collections = await db.list_collection_names()
    return {"collections": collections}
