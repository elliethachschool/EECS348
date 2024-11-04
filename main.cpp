/*
Name: Ellie Thach
KUID: 3139476
LAB Session: 07
LAB Assignment Number: 07
Program Description: Implementing a C++ program to perform various operations on matrices (reading values from a file into a matrix, adding two matrices, multiplying two matrices, getting sum of matrix diagonal elements, and swapping matrix rows)
Collaborators: None
*/

#include <iostream>
#include <fstream>

using namespace std;

class Matrix {
public:
    int matrix_size;
    double** matrix_data;

    Matrix(int size = 0) : matrix_size(size) {
        matrix_data = new double*[matrix_size];
        for (int i = 0; i < matrix_size; ++i) {
            matrix_data[i] = new double[matrix_size];
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this;
        }

        for (int i = 0; i < matrix_size; ++i) {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;

        matrix_size = other.matrix_size;

        matrix_data = new double*[matrix_size];
        for (int i = 0; i < matrix_size; ++i) {
            matrix_data[i] = new double[matrix_size];
            for (int j = 0; j < matrix_size; ++j) {
                matrix_data[i][j] = other.matrix_data[i][j];
            }
        }

        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < matrix_size; ++i) {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;
    }
};

void read_matrix_from_file(const string& file_name, Matrix& matrix_1, Matrix& matrix_2) {
    // This function reads the matrix size and the matrix from the text file.
    ifstream fin(file_name);
    if (!fin.is_open()) { // Error message if the file cannot be opened.
        cerr << "Error: The file " << file_name << " cannot be opened." << endl;
    }

    int matrix_size;
    fin >>  matrix_size; // Saves matrix size from the file

    matrix_1 = Matrix(matrix_size);
    matrix_2 = Matrix(matrix_size);


    for (int i=0; i < matrix_1.matrix_size; i++) { // Creates matrix 1
        for (int j=0; j < matrix_1.matrix_size; j++) {
            fin >> matrix_1.matrix_data[i][j];
        }
    }
    for (int i=0; i < matrix_2.matrix_size; i++) { // Creates matrix 2
        for (int j=0; j < matrix_2.matrix_size; j++) {
            fin >> matrix_2.matrix_data[i][j];
        }
    }
    fin.close();

    return;
}

void print_matrix(const Matrix& matrix) {
    // This function prints the matrix given
    for (int i=0; i < matrix.matrix_size ; i++) {
        for (int j=0; j < matrix.matrix_size; j++) {
            cout << matrix.matrix_data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void print_matrix(const Matrix& matrix_1, const Matrix& matrix_2) {
    // This function prints out both matrices (calls print_matrix function for both)
    print_matrix(matrix_1);
    print_matrix(matrix_2);
    return;
}

Matrix add_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
    // This function adds the values of matrix 1 and matrix 2 together (same index)
    Matrix adding_matrix(matrix_1.matrix_size);
    adding_matrix.matrix_size = matrix_1.matrix_size;
    for (int i=0; i < adding_matrix.matrix_size; i++) {
        for (int j=0; j < adding_matrix.matrix_size; j++) {
            adding_matrix.matrix_data[i][j] = matrix_1.matrix_data[i][j] + matrix_2.matrix_data[i][j];
        }
    }
    return adding_matrix;
}

Matrix multiply_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
    // This function multiplies the values of matrix 1 and matrix 2 together (same index)
    Matrix multiplying_matrix(matrix_1.matrix_size);
    for (int i=0; i < matrix_1.matrix_size; i++) {
        for (int j=0; j < matrix_1.matrix_size; j++) {
            multiplying_matrix.matrix_data[i][j] = matrix_1.matrix_data[i][j] * matrix_2.matrix_data[i][j];
        }
    }
    return multiplying_matrix;
}

// Overloaded + operator for matrix addition
Matrix operator+(const Matrix& matrix_1, const Matrix& matrix_2) {
    Matrix adding_matrix(matrix_1.matrix_size);
    adding_matrix.matrix_size = matrix_1.matrix_size;
    for (int i=0; i < adding_matrix.matrix_size; i++) {
        for (int j=0; j < adding_matrix.matrix_size; j++) {
            adding_matrix.matrix_data[i][j] = matrix_1.matrix_data[i][j] + matrix_2.matrix_data[i][j];
        }
    }
    return adding_matrix;
}

// Overloaded * operator for matrix multiplication
Matrix operator*(const Matrix& matrix_1, const Matrix& matrix_2) {
    Matrix multiplying_matrix(matrix_1.matrix_size);
    for (int i=0; i < matrix_1.matrix_size; i++) {
        for (int j=0; j < matrix_1.matrix_size; j++) {
            multiplying_matrix.matrix_data[i][j] = matrix_1.matrix_data[i][j] * matrix_2.matrix_data[i][j];
        }
    }
    return multiplying_matrix;
}

void get_diagonal_sum(const Matrix& matrix) {
    // This function gets the sum of the diagonal of a matrix
    int primary = 0;
    int secondary = 0;
    for (int i=0; i < matrix.matrix_size; i++) {
        primary += matrix.matrix_data[i][i];
        secondary += matrix.matrix_data[i][matrix.matrix_size-1-i];
    }
    cout << "Primary Diagonal: " << primary << endl;
    cout << "Secondary Diagonal: " << secondary << endl;
    cout << endl;
}

void swap_matrix_row(Matrix& matrix, int row1, int row2) {
    // This function swaps the first row and second row of the matrix given
    if (row1 < 0 || row1 > matrix.matrix_size-1 || row2 < 0 || row2 > matrix.matrix_size-1) {
        cout << "Invalid row or column" << endl;
        return;
    }
    double* temp = matrix.matrix_data[row1];
    matrix.matrix_data[row1] = matrix.matrix_data[row2];
    matrix.matrix_data[row2] = temp;
    print_matrix(matrix);
}

int main(int argc, char* argv[]) {
    // This function calls all of the functions above
    Matrix matrix_1, matrix_2;
    read_matrix_from_file("matrix.txt", matrix_1, matrix_2);
    
    cout << "print_matrix" << endl;
    print_matrix(matrix_1, matrix_2);
    
    cout << "add_matrices result:" << endl;
    Matrix add_result_1 = add_matrices(matrix_1, matrix_2);
    Matrix add_result_2 = matrix_1 + matrix_2;
    print_matrix(add_result_1);
    print_matrix(add_result_2);
    
    cout << "multiply_matrices result:" << endl;
    Matrix multiply_result_1 = multiply_matrices(matrix_1, matrix_2);
    Matrix multiply_result_2 = matrix_1 * matrix_2;
    print_matrix(multiply_result_1);
    print_matrix(multiply_result_2);

    cout << "get matrix diagonal sum" << endl;
    get_diagonal_sum(matrix_1);

    cout << "swap matrix rows" << endl;
    swap_matrix_row(matrix_1, 0, 1);
    
    return 0;
}