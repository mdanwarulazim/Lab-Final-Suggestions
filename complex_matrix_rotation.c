/**************************************************

Write a program that left/right rotates an array n
times on each row.

SAMPLE INPUT
------------
Enter number of rows: 3
Enter number of columns: 3

Enter matrix elements:
1 2 3
4 5 6
7 8 9

Enter times of rotation: 2

SAMPLE OUTPUT
-------------
Left Rotated Matrix:
3 1 2
6 4 5
9 7 8

Right Rotated Matrix:
2 3 1
5 6 4
8 9 7

**************************************************/



#include <stdio.h>
int main(){
    int i, j, k, m, n, r, temp;

    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);

    int mat[m][n];
    int left_rotate[m][n];
    int right_rotate[m][n];

    printf("Enter matrix elements: \n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            left_rotate[i][j] = mat[i][j];
            right_rotate[i][j] = mat[i][j];
        }
    }

    printf("Enter times of rotation: ");
    scanf("%d", &r);

    if (r>n){
        r=r%n; //takes the modulus without rotating multiple n times
    }

    for (i=0; i<m; i++){
        for (j=0; j<r; j++){
            temp=right_rotate[i][n-1];
            for (k=n-1; k>0; k--){
                right_rotate[i][k] = right_rotate[i][k-1];
            }
            right_rotate[i][0]=temp;
        }
    }

    for (i=0; i<m; i++){
        for (j=0; j<r; j++){
            temp=left_rotate[i][0];
            for (k=0; k<n-1; k++){
                left_rotate[i][k] = left_rotate[i][k+1];
            }
            left_rotate[i][n-1]=temp;
        }
    }

    printf("\nLeft Rotated Matrix: \n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            printf("%d ", left_rotate[i][j]);
        }
        printf("\n");
    }

    printf("\nRight Rotated Matrix: \n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            printf("%d ", right_rotate[i][j]);
        }
        printf("\n");
    }
    
}
