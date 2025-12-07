import { Routes, Route } from "react-router-dom";
import HomePage from "../pages/HomePage";
import SubjectPage from "../pages/SubjectPage";
/*import NotePage from "../pages/NotePage";*/

export default function AppRouter() {
  return (
    <Routes>
      <Route path="/" element={<HomePage />} />
      <Route path="/home" element={<HomePage />} />
      <Route path="/subject/:subjectId" element={<SubjectPage />} />
      <Route path="/subject/:subjectId/module/:moduleId" element={<SubjectPage />} />

      <Route path="*" element={<div>Not Found</div>} />
    </Routes>
  );
}

