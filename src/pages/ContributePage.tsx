import './ContributePage.css';

export default function ContributePage() {
  return (
    <div className="contribute-page">
      <h2 className="quote">
        "Alone we can do so little; together we can do so much."
      </h2>

      <h2>Join the OpenKTU Community</h2>

      <p className="intro-text">
        OpenKTU is a community-driven initiative powered by volunteers who dedicate their time to curate and transcribe the notes you use every day. By contributing, you help countless students access high-quality, free learning resources.
      </p>

      <div className="github-link-container">
        <a href="https://github.com/Sabari-Vijayan/openktu" target="_blank" rel="noopener noreferrer" className="github-btn">
          View on GitHub
        </a>
      </div>

      <hr />

      <h2>Ways to Contribute</h2>

      <div className="contribution-methods">
        <div className="method-card">
          <div className="card-header">
            <span className="step-number">01</span>
            <h3>Add New Notes</h3>
          </div>
          <p>
            Contributing notes is the most direct way to help.
            All notes are stored in the <code>public/notes</code> directory, with each module or program as a separate file.
          </p>
          <ul className="checklist">
            <li>Ensure the subject is listed in <code>subjects.json</code>.</li>
            <li>Keep notes concise, accurate, and preserving main points.</li>
            <li>Use <strong>Markdown</strong> format. (Pro tip: You can use LLMs to convert your raw text to Markdown!)</li>
          </ul>
        </div>

        <div className="method-card">
          <div className="card-header">
            <span className="step-number">02</span>
            <h3>Update & Fix Errors</h3>
          </div>
          <p>
            Found a typo or a mistake? It's the easiest way to contribute!
            Navigate to the specific note in the <code>notes</code> folder and submit a fix.
          </p>
          <p className="note-warning">
            Please raise an issue on GitHub before making major changes.
          </p>
        </div>

        <div className="method-card">
          <div className="card-header">
            <span className="step-number">03</span>
            <h3>Improve the Platform</h3>
          </div>
          <p>
            OpenKTU is open source. There is always room for structural and optimizational improvements.
            If you are a developer, feel free to dive into the codebase.
          </p>
        </div>
      </div>
    </div>
  );
}
