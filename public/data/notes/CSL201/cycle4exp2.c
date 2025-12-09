#include<stdio.h>

typedef struct tuple{
    int row;
    int col;
    int value;
}tuple;


void readMat(int arr[][5], int* r, int* c) {
    int row, col;
    printf("Enter rows, cols: ");
    scanf("%d %d", &row, &col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("Enter element for %d %d: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    *r = row;
    *c = col;
    
}

void display(int arr[][5], int row, int col) {
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");    
    }
    printf("\n"); 
}

void matTotup(int mat[][5], int r, int c, struct tuple tup[]){
    int k=1,row,cols;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]!=0){
                tup[k].row = i;
                tup[k].col = j;
                tup[k].value = mat[i][j];
                k++;
            }
        }
    }
    tup[0].row = r;
    tup[0].col = c;
    tup[0].value =k-1;
}

void displayTup(struct tuple tup[]){
    int n = tup[0].value+1;
    printf("Row Col Val\n");
    for(int i=0; i<n;i++){
        printf("%d %d %d\n", tup[i].row, tup[i].col, tup[i].value);

    }
}

void transpose(struct tuple tup[]){
    int n = tup[0].value;
    struct tuple trans[10];
    trans[0].row = tup[0].col;
    trans[0].col = tup[0].row;
    trans[0].value = tup[0].value;
    int q=1;
    if(n>0){
        for(int i=0;i<tup[0].col;i++){
            for(int j=i;j<=n;j++){
                if(tup[j].col == i){
                    trans[q].row = tup[j].col;
                    trans[q].col = tup[j].row;
                    trans[q].value = tup[j].value;
                    q++;
                }
            }
        }
    }
    displayTup(trans);
}

void sum(struct tuple a[], struct tuple b[]){
    int k=1, i=1, j=1;
    struct tuple c[20];
    while(i<=a[0].value && j<=b[0].value){
        if(a[i].row<b[j].row || (a[i].row==b[j].row && a[i].col<b[j].col)){
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].value = a[i].value;
            k++;i++;
        }
        else if(a[i].row>b[j].row || (a[i].row==b[j].row && a[i].col>b[j].col)){
            c[k].row = b[j].row;
            c[k].col = b[j].col;
            c[k].value = b[j].value;
            k++;j++;
        }
        else if(a[i].row==b[j].row && a[i].col==b[j].col){
            c[k].row = b[j].row;
            c[k].col = b[j].col;
            c[k].value = b[j].value+a[i].value;
            j++;i++;
            if(c[k].value!=0){
                k++;
            }
        }
    }
    while(i<=a[0].value){
        c[k].row = a[i].row;
        c[k].col = a[i].col;
        c[k].value = a[i].value;
        k++;i++;
    }
    while(j<=b[0].value){
        c[k].row = b[j].row;
        c[k].col = b[j].col;
        c[k].value = b[j].value;
        k++;j++;
    }
    c[0].row = b[0].row;
    c[0].col = b[0].col;
    c[0].value = k-1;
    displayTup(c);
}

int main(){
    int mat1[5][5];
    int mat2[5][5];
    int r1,c1,r2,c2;
    struct tuple tup1[10],tup2[10],tup3[10];
    readMat(mat1, &r1, &c1);
    readMat(mat2, &r2, &c2);
    display(mat1,r1,c1);
    display(mat2,r2,c2);

    matTotup(mat1, r1,c1,tup1);
    matTotup(mat2, r2,c2,tup2);

    transpose(tup1);
    transpose(tup2);

    sum(tup1, tup2);
}
