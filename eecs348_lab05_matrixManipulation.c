/*
Name: Ellie Thach
KUID: 3139476
LAB Session: 05
LAB Assignment Number: 05
Program Description: Program reads input for two matrices and develops a function for the following matrix manipulations: add two matrices, multiply two matrices, transpose a matrix, and print a matrix.
Collaborators: None
*/

#include <stdio.h>

#define SIZE 5

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    /* Function takes two matrices as input and returns their sum. */
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    /* Function takes two matrices as input and returns their product. */
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    /* Function takes a matrix as input and returns its transpose. */
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void printMatrix(int matrix[SIZE][SIZE]) {
    /* Function takes a matrix as input and prints it in user-friendly format. */
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    /* Function runs the entire code. */
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9 , 8 , 7, 6},
        {5, 4, 3, 2, 1}
    };

    int sum[SIZE][SIZE];
    int product[SIZE][SIZE];
    int transpose[SIZE][SIZE];

    addMatrices(m1, m2, sum);
    printf("Sum of Matrices:\n");
    printMatrix(sum);

    multiplyMatrices(m1, m2, product);
    printf("\nProduct of Matrices:\n");
    printMatrix(product);

    transposeMatrix(m1, transpose);
    printf("\nTranspose of Matrix:\n");
    printMatrix(transpose);

    return 0;
}