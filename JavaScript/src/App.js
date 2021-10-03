import React, { useState } from "react";
import "./styles.css";

const animeDB = {
  Action: [
    { name: "One piece", rating: "10/10" },
    { name: "Naruto", rating: "8/10" },
    { name: "Code geass", rating: "8/10" },
    { name: "Attack On Titan", rating: "10/10" },
    { name: "Naruto Shippuden", rating: "10/10" },
    { name: "Cowboy bebop", rating: "6/10" },
    { name: "One punch man", rating: "9/10" },
    { name: "Full Metal Alchemist: Brotherhood", rating: "8/10" },
    { name: "Boruto", rating: "8/10" }
  ],

  Adventure: [
    { name: "One piece", rating: "10/10" },
    { name: "Naruto", rating: "8/10" },
    { name: "Naruto Shippuden", rating: "10/10" },
    { name: "Cowboy bebop", rating: "6/10" },
    { name: "Full Metal Alchemist: Brotherhood", rating: "8/10" },
    { name: "Boruto", rating: "8/10" }
  ],

  Shounen: [
    { name: "One piece", rating: "10/10" },
    { name: "Naruto", rating: "8/10" },
    { name: "Attack On Titan", rating: "10/10" },
    { name: "Naruto Shippuden", rating: "10/10" },
    { name: "Death Note", rating: "8/10" },
    { name: "Full Metal Alchemist: Brotherhood", rating: "8/10" },
    { name: "Boruto", rating: "8/10" }
  ],

  Superpower: [
    { name: "One piece", rating: "10/10" },
    { name: "Naruto", rating: "8/10" },
    { name: "Code geass", rating: "8/10" },
    { name: "Attack On Titan", rating: "10/10" },
    { name: "Naruto Shippuden", rating: "10/10" },
    { name: "One punch man", rating: "9/10" },
    { name: "Boruto", rating: "8/10" }
  ],

  Comedy: [
    { name: "One piece", rating: "10/10" },
    { name: "Naruto", rating: "8/10" },
    { name: "Naruto Shippuden", rating: "10/10" },
    { name: "One punch man", rating: "9/10" }
  ],

  Drama: [
    { name: "One piece", rating: "10/10" },
    { name: "Code geass", rating: "8/10" },
    { name: "Attack On Titan", rating: "10/10" },
    { name: "Cowboy bebop", rating: "6/10" }
  ],

  SciFi: [
    { name: "Code geass", rating: "8/10" },
    { name: "Cowboy bebop", rating: "6/10" },
    { name: "One punch man", rating: "9/10" }
  ]
};

export default function App() {
  const [selectedGenre, setGenre] = useState("Action");
  function genreClickHandler(genre) {
    setGenre(genre);
  }

  return (
    <div className="App">
      <h1> my anime recommendation </h1>
      <p style={{ fontSize: "smaller" }}>
        Checkout my favourite anime. Select a genre to get started.
      </p>

      <div>
        {Object.keys(animeDB).map((genre) => (
          <button
            onClick={() => genreClickHandler(genre)}
            style={{
              cursor: "pointer",
              background: "#E5E7EB",
              borderRadius: "0.5rem",
              padding: "0.5rem 1rem",
              border: "1px solid black",
              margin: "1rem 0.3rem"
            }}
          >
            {genre}
          </button>
        ))}
      </div>
      <hr />
      <div style={{ textAlign: "left" }}>
        <ul style={{ paddingInlineStart: "0" }}>
          {animeDB[selectedGenre].map((anime) => (
            <li
              key={anime.name}
              style={{
                listStyle: "none",
                padding: "1rem",
                border: "1px solid #D1D5DB",
                width: "70%",
                margin: "1rem 0rem",
                borderRadius: "0.5rem"
              }}
            >
              {" "}
              <div style={{ fontSize: "larger" }}> {anime.name} </div>
              <div style={{ fontSize: "smaller" }}> {anime.rating} </div>
            </li>
          ))}
        </ul>
      </div>
    </div>
  );
}
