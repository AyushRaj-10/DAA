import mongoose from 'mongoose'
import { MongoClient } from 'mongodb';


const client = new MongoClient('mongodb://localhost:27017/college');
const dbname = 'college';


const student = {
    name: "Ayush",
    age: 21,
    course: "CSE"
};

const connectDB = async() => {
    try {
        const db = await client.connect();
        console.log("Connected");
    } catch (error) {
        console.log("Error");
    }
}

connectDB();

const insert = async() => {
    const db = await client.db(dbname)
    try {
        const result = await db.collection('student').insertOne(student);
        console.log("Student inserted");
    } catch (error) {
        console.log("Error in insert")
    }
}

const update = async() => {
    const db = await client.db(dbname)
    try {
        const result = await db.collection('student').findOneAndUpdate({
            name: "Ayush"},
            {$set : {
                age : 22
            }},
            {returnDocument : "after"}
        );
        console.log("Student updated");
    } catch (error) {
        console.log("Error in update")
    }
}

const get = async() => {
    const db = await client.db(dbname)
    try {
        const result = await db.collection('student').findOne({
            name : "Ayush"
        });
        console.log("get Student");
        console.log(result)
    } catch (error) {
        console.log("Error in get")
    }
}

const deleteS = async(name) => {
    const db = await client.db(dbname)
    try {
        const result = await db.collection('student').findOneAndDelete({
            name : "Ayush"
        });
        console.log("Student deleted");
    } catch (error) {
        console.log("Error in delete")
    }
}

// insert();
// update();
// get();
deleteS();


