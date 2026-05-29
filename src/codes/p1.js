// Get chat window
const chatWindow =
document.getElementById("chatWindow");

// Get input box
const msgInput =
document.getElementById("msgInput");


// Chatbot replies
const responses = {

  "hi": "Hello there!",

  "hello": "Hi! How can I help?",

  "how are you":
  "I'm doing great!",

  "what is html":
  "HTML structures web pages.",

  "what is css":
  "CSS styles web pages.",

  "what is javascript":
  "JavaScript makes pages interactive.",

  "bye":
  "See you soon!"
};


// Send message function
function handleSend() {

  // Get input text
  const text =
  msgInput.value.trim();

  // Stop if empty
  if (text === "")
    return;

  // Add user message
  addMessage(text, "user");

  // Convert to lowercase
  const key =
  text.toLowerCase();

  // Get bot reply
  let reply =
  responses[key];

  // Default reply
  if (!reply) {

    reply =
    "Sorry, I don't understand.";

  }

  // Show bot reply after delay
  setTimeout(() => {

    addMessage(reply, "bot");

  }, 500);

  // Clear input box
  msgInput.value = "";
}


// Function to add messages
function addMessage(text, type) {

  // Create div
  const div =
  document.createElement("div");

  // Add classes
  div.classList.add("msg", type);

  // Add text
  div.innerText = text;

  // Add message to chat window
  chatWindow.appendChild(div);

  // Auto scroll
  chatWindow.scrollTop =
  chatWindow.scrollHeight;
}


// Send message using Enter key
msgInput.addEventListener(
  "keypress",

  function (e) {

    if (e.key === "Enter") {

      handleSend();

    }

  }
);
