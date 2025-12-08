const fs = require('fs');
const path = require('path');

// Since this script is moved to scripts/, we go up one level to root, then public/data/notes
// scripts/ is a sibling of src/, public/ etc.
// path.join(__dirname, '../public/data/notes') works if __dirname is scripts/
const notesDir = path.join(__dirname, '../public/data/notes');

if (!fs.existsSync(notesDir)) {
  console.log('No notes directory found at ' + notesDir);
  process.exit(0);
}

const subjects = fs.readdirSync(notesDir);

subjects.forEach(subject => {
  const subjectPath = path.join(notesDir, subject);
  if (fs.statSync(subjectPath).isDirectory()) {
    const files = fs.readdirSync(subjectPath);
    const modules = files
      .filter(f => f.match(/^module(\d+)\.md$/))
      .map(f => parseInt(f.match(/^module(\d+)\.md$/)[1]))
      .sort((a, b) => a - b);
    
    const hasIntro = files.includes('intro.md');
    
    const otherNotes = files.filter(f => f.endsWith('.md') && !f.startsWith('module') && f !== 'intro.md');

    const manifest = {
      modules,
      hasIntro,
      otherNotes
    };

    fs.writeFileSync(path.join(subjectPath, 'manifest.json'), JSON.stringify(manifest, null, 2));
    console.log(`Generated manifest for ${subject}`);
  }
});
