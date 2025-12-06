import { useState } from "react";

export default function SearchBar() {

  const [query, setQuery] = useState("");
    return (
      <div>

        <label>Find your subject
          <input type="text" placeholder="MAT 101" className="search-input" value={query} onChange={(e) => setQuery(e.target.value)}/>
        </label>

        <p>You typed :{query}</p>

      </div>
    );
}
