import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from './assets/vite.svg'
import heroImg from './assets/hero.png'
import './App.css'
import Post from './first.jsx'

function App() {
  const [count, setCount] = useState(0)

  const blogPost = [
      {title: "a", content : "abcd" , body : "body", author : "author"},
      
      {title: "b", content : "abcd" , body : "body", author : "author"},
      
    ]

  return (
    
    <>
      {blogPost.map((post, idx) => (
        <Post
          key={idx}
          post={post}
        />
      )) 
      }

    </>
  )
}

export default App
