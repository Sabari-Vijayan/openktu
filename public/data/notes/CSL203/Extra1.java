class RowThread extends Thread
{
    Matrix A,B,C;
    int rows, cols;
    int rowNum;
    RowThread(Matrix A, Matrix B,Matrix C, int rowNum)
    {
        this.A = A;
        this.B = B;
        this.C = C;
        this.rowNum = rowNum;
    }
    public void run(){
        for(int j=0;j<B.cols;j++)
        {
            int sum = 0;
            for(int k=0;k<A.cols;k++)
            {         
                sum += A.mat[rowNum][k]*B.mat[k][j];
            }

            synchronized (C)
            {
                C.mat[rowNum][j] = sum;
            } 
        }   
        System.out.printf("Row %d Done.\n", rowNum);
    }
}

class Matrix
{
    int mat[][];
    int rows, cols;
    
    Matrix(int rows, int cols)
    {
        this.rows=rows;
        this.cols=cols;
        this.mat = new int[rows][cols];
    }
    Matrix(int mat[][])
    {
        this.mat = mat;
        this.rows = mat.length;
        this.cols = mat[0].length;
    }

    public void display()
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                System.out.print(mat[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public Matrix multiply(Matrix B)
    {
        Matrix C = new Matrix(this.rows, B.cols);
        Thread[] threads = new Thread[this.rows];

        for (int i = 0; i < this.rows; i++)
        {
            threads[i] = new RowThread(this, B, C, i);
            threads[i].start();
        }
        for (int i = 0; i < this.rows; i++)
        {
            try
            {
                threads[i].join();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
        return C;
    }
}

class Main
{
    public static void main(String args[])
    {
        Matrix A = new Matrix(new int[][]{{1,3,5},{7,9,0}});
        Matrix B = new Matrix(new int[][]{{1,2,3},{4,5,6},{7,8,9}});
        A.display();
        B.display();
        Matrix C = A.multiply(B);
        C.display();
    }
}
