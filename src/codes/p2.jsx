import React, { useState } from 'react';
import './App.css';

function App() {

  const [votes, setVotes] = useState({
    option1: 0,
    option2: 0,
    option3: 0
  });

  const handleVote = (option) => {

    setVotes((prevVotes) => ({
      ...prevVotes,
      [option]: prevVotes[option] + 1,
    }));

  };

  return (

    <div className="App">

      <h1>Voting Application</h1>

      <div>

        <div>
          BJP
          <button
            onClick={() => handleVote('option1')}>
            Vote
          </button>

          <span>{votes.option1}</span>
        </div>

        <div>
          Congress
          <button
            onClick={() => handleVote('option2')}>
            Vote
          </button>

          <span>{votes.option2}</span>
        </div>

        <div>
          JDS
          <button
            onClick={() => handleVote('option3')}>
            Vote
          </button>

          <span>{votes.option3}</span>
        </div>

      </div>

    </div>
  );
}

export default App;
