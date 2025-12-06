import { useParams } from "react-router-dom";
import { useState, useEffect } from "react";
import ReactMarkdown from 'react-markdown';
import remarkGfm from 'remark-gfm';
import 'github-markdown-css/github-markdown.css';

export default function NotePage() {
  const { subjectId, moduleId } = useParams();
  const [content, setContent] = useState("");
  const [error, setError] = useState(false);

  useEffect(() => {
    const path = `/subjects/${subjectId?.toLowerCase()}/mod${moduleId}.md`;
    fetch(path)
      .then(res => {
        if (!res.ok) throw new Error("Note not found");
        return res.text();
      })
      .then(text => {
        setContent(text);
        setError(false);
      })
      .catch(() => {
        setError(true);
        setContent("");
      });
  }, [subjectId, moduleId]);

  if (error) {
    return (
      <div className="note-page error">
        <h2>Note not found</h2>
        <p>The requested note (Subject: {subjectId}, Module: {moduleId}) does not exist yet.</p>
        <p>You can contribute by adding <code>mod{moduleId}.md</code> to <code>public/subjects/{subjectId?.toLowerCase()}/</code> via a Pull Request!</p>
      </div>
    );
  }

  return (
    <div className="note-page markdown-body" style={{ padding: '2rem' }}>
      <ReactMarkdown remarkPlugins={[remarkGfm]}>
        {content}
      </ReactMarkdown>
    </div>
  );
}
