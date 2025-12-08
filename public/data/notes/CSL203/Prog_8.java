import java.io.*; 
public class FileReadWriteExample  
{ 
    public static void main(String[] args)  
    { 
        String inputFilePath = "input.txt";   
        String outputFilePath = "output.txt";  
        FileReader fileReader = null; 
        FileWriter fileWriter = null; 
        try  
        { 
            fileReader = new FileReader(inputFilePath); 
            fileWriter = new FileWriter(outputFilePath); 
            int character; 
            while ((character = fileReader.read()) != -1)  
            { 
                fileWriter.write(character); 
            } 
        }  
        catch (FileNotFoundException e)  
        { 
            System.out.println("File not found: " + e.getMessage()); 
        }  
        catch (IOException e)  
        { 
            System.out.println("Error reading or writing file: " + e.getMessage()); 
        }  
        finally  
        { 
            try  
            { 
                if (fileReader != null)  
                { 
                    fileReader.close(); 
                } 
                if (fileWriter != null)  
                { 
                    fileWriter.close(); 
                } 
            }  
            catch (IOException e)  
            { 
                System.out.println("Error closing the file: " + e.getMessage()); 
            } 
        } 
    } 
} 
