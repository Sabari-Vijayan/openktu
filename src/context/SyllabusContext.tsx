import React, { createContext, useContext, useState, type ReactNode } from 'react';

type SyllabusYear = '2019' | '2024';

interface SyllabusContextType {
  year: SyllabusYear;
  setYear: (year: SyllabusYear) => void;
}

const SyllabusContext = createContext<SyllabusContextType | undefined>(undefined);

export const SyllabusProvider: React.FC<{ children: ReactNode }> = ({ children }) => {
  const [year, setYear] = useState<SyllabusYear>('2024');

  return (
    <SyllabusContext.Provider value={{ year, setYear }}>
      {children}
    </SyllabusContext.Provider>
  );
};

export const useSyllabus = () => {
  const context = useContext(SyllabusContext);
  if (context === undefined) {
    throw new Error('useSyllabus must be used within a SyllabusProvider');
  }
  return context;
};
