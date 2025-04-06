from fastapi import FastAPI
from database import db  # Import the database connection

app = FastAPI()

@app.get("/")
async def root():
    return {"message": "FastAPI Chat API is running!"}

@app.get("/test_db")
async def test_db():
    collections = await db.list_collection_names()
    return {"collections": collections}
