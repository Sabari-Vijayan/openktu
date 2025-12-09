class Matrix  
{ 
    private int[][] data; 
    public Matrix(int[][] data)  
    { 
        this.data = data; 
    } 
    public Matrix multiply(Matrix other)  
    { 
        int rowsA = this.data.length; 
        int colsA = this.data[0].length; 
        int rowsB = other.data.length; 
        int colsB = other.data[0].length; 
        if (colsA != rowsB)  
        { 
            System.out.println("Invalid matrices"); 
            return null; 
        } 
        int[][] resultData = new int[rowsA][colsB]; 
        for (int i = 0; i < rowsA; i++)  
        { 
            for (int j = 0; j < colsB; j++)  
            { 
                for (int k = 0; k < colsA; k++)  
                { 
                    resultData[i][j] += this.data[i][k] * other.data[k][j]; 
                } 
            } 
        } 
        return new Matrix(resultData); 
    } 
    public void display()  
    { 
        for (int i = 0; i < data.length; i++)  
        { 
            for (int j = 0; j < data[i].length; j++)  
            { 
                System.out.print(data[i][j] + " "); 
            } 
            System.out.println(); 
        } 
    } 
} 
 
public class MatrixMultiplication  
{ 
    public static void main(String[] args)  
    { 
        int[][] matrixA = {{1, 2, 3}, {4, 5, 6}}; 
        int[][] matrixB = {{7, 8}, {9, 10}, {11, 12}}; 
        Matrix matA = new Matrix(matrixA); 
        Matrix matB = new Matrix(matrixB);         
        Matrix result = matA.multiply(matB); 
        System.out.println("Result of matrix multiplication:"); 
        result.display(); 
    } 
}
