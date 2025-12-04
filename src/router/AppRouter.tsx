import { Routes, Route } from "react-router-dom";
import HomePage from "../pages/HomePage";

export default function AppRouter() {
  return (
    <Routes>
      <Route path="/" element={<HomePage />} />
      <Route path="/home" element={<HomePage />} />

      {/* other routes */}
      <Route path="*" element={<div>Not Found</div>} />
    </Routes>
  );
}

