# OpenKTU

**OpenKTU** is a free, open-source platform dedicated to providing KTU engineering students with reliable, high-quality learning resources.
**No ads. No paywalls. No distractions.**

We believe education is a right, not a commodity. Students shouldn't have to navigate sketchy links, intrusive ads, or paywalls just to access study materials. OpenKTU is built to be **minimalist, fast, and privacy-focused**.

## Why OpenKTU?

- **Zero Ads & Paywalls:** Education should be free.
- **Privacy First:** No login required, no data collection.
- **Community Driven:** Powered by volunteers and students like you.
- **Open Source:** Transparent and improvable by anyone.

## 🤝 How to Contribute

This project survives and thrives on community contributions. Whether you have notes to share, corrections to make, or coding skills to offer, your help is invaluable.

### 1. Contributing Notes
This is the most direct way to help. We need concise, accurate notes in Markdown format.

1.  **Format:** Notes are written in Markdown (`.md`). You can use LLMs to convert your raw text notes into clean Markdown.
2.  **Location:** All notes are stored in the `public/notes` directory.
    *   Each module or program should be a separate file.
    *   Organize them by subject code/name folders.
3.  **Manifest:** Ensure the subject is listed in `public/data/subjects.json` (or the respective year json) so it appears on the site.
4.  **Submission:** Submit a Pull Request (PR) with your new files.

### 2. Updating & Fixing Errors
Found a typo, incorrect formula, or broken link?
*   Navigate to the specific file in `public/notes`.
*   Make the correction and submit a PR.
*   For major changes, please **raise an issue** first to discuss.

### 3. Website Development
OpenKTU is a React-based application. If you are a developer, you can help improve the site's structure, performance, or design.

#### Tech Stack
*   **Framework:** React + Vite
*   **Routing:** React Router
*   **Styling:** CSS
*   **Deployment:** GitHub Pages

## 🛠️ Local Development Setup

To run the project locally on your machine:

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/Sabari-Vijayan/openktu.git
    cd openktu
    ```

2.  **Install dependencies:**
    ```bash
    npm install
    ```

3.  **Start the development server:**
    ```bash
    npm run dev
    ```

4.  **Build for production:**
    ```bash
    npm run build
    ```

## 📂 Project Structure

*   `public/data/`: Contains JSON configuration for subjects and years.
*   `public/notes/`: The core content! Markdown files for all subjects.
*   `src/`: React source code.

## Philosophy

**Knowledge should be free, open, and accessible to everyone.**
This project is open source. Feel free to use, reuse, and redistribute.
