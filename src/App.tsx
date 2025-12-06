import { BrowserRouter } from "react-router-dom";
import AppRouter from "./router/AppRouter";
import './App.css'
import Header from "./components/header.tsx";
import Footer from "./components/footer.tsx";
import { SyllabusProvider } from "./context/SyllabusContext";

export default function App() {
  return (
    <SyllabusProvider>
      <BrowserRouter>
        <Header />
        <div className="main container">
          <AppRouter />
        </div>
        <Footer />
      </BrowserRouter>
    </SyllabusProvider>
  );
}

