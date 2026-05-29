const { MongoClient, ObjectId } = require('mongodb');

// MongoDB URL
const url = 'mongodb://localhost:27017';

// Database Name
const dbName = 'College';

// Create client
const client = new MongoClient(url);


// Connect to MongoDB
async function connectDB() {

  try {

    await client.connect();

    console.log("Connected to database");

  } catch (error) {

    console.log("Connection Error");

  }
}


// INSERT OPERATION
async function insertStudent(student) {

  const db = client.db(dbName);

  try {

    const result =
      await db.collection('student')
      .insertOne(student);

    console.log("Student inserted");

  } catch (err) {

    console.log("Insert Error");

  }
}


// FIND OPERATION
async function findAllStudents() {

  const db = client.db(dbName);

  try {

    const students =
      await db.collection('student')
      .find({})
      .toArray();

    console.log(students);

  } catch (err) {

    console.log("Find Error");

  }
}


// UPDATE OPERATION
async function updateStudent() {

  const db = client.db(dbName);

  try {

    await db.collection('student').updateOne(

      { _id: new ObjectId('YOUR_ID') },

      {
        $set: { Dept: "CSE" }
      }

    );

    console.log("Student Updated");

  } catch (err) {

    console.log("Update Error");

  }
}


// DELETE OPERATION
async function deleteStudent(id) {

  const db = client.db(dbName);

  try {

    await db.collection('student').deleteOne({

      _id: new ObjectId(id)

    });

    console.log("Student Deleted");

  } catch (err) {

    console.log("Delete Error");

  }
}


// Main Function
connectDB().then(async () => {

  // Student Data
  const student = {
    name: "Monisha",
    age: 18,
    cgpa: 6.38,
    Dept: "CSE"
  };

  // Insert
  await insertStudent(student);

  // Display
  await findAllStudents();

  // Update
  await updateStudent();

  // Delete
  await deleteStudent("YOUR_ID");

  // Close connection
  client.close();

});
