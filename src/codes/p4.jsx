import React from "react";
import "./first.css";

const Post = ({ post }) => {

  return (

    <div className="post-container">

      <h1>{post.title}</h1>

      <img
        src={post.imgUrl}
        alt="post"
        className="image"
      />

      <p>{post.body}</p>

      <h4>
        Written by: {post.author}
      </h4>

    </div>

  );
};

export default Post;
