#include "menu.h"

//#include "stdlib.h"
using namespace std;

int chooseTypeMatrix(){
    int type;
    cout << "Select type of numbers: \n"
         << "\t1: int\n"
         << "\t2: float\n"
         << "\t3: complex\n\n"
         << "\t0: Return to select class\n"
         << "Enter a number: ";
    getchar();
    cin >> type;
    cout<<endl;
    getchar();
    return type;
}

///Diagonal Matrix
int chooseFunctionDiagonalMatrix(){
    int func;
    cout << "What function do you want to use?: \n"
         << "\t1: Sum of Matrices\n"
         << "\t2: Multiplication of scalar and matrix\n"
         << "\t3: Matrix Norm\n"
         << "\t0: Return to select type\n"
         << "Enter a number: ";
    getchar();
    cin >> func;
    cout<<endl;
    getchar();
    return func;
}

DiagonalMatrix<int>* inputDiagonalMatrix_int(){
    int dim;
    cout << "Enter a dimension of matrix:";
    cin >> dim;
    DiagonalMatrix<int>* matrix = new DiagonalMatrix<int>();
    cout << "Enter Main Diagonal Coordinates:" << endl;
    int coord;
    for(int i = 0; i < dim; i++){
        cin >> coord;
        matrix->Set(coord, i, i);//не уверена
    }
    return matrix;
}

DiagonalMatrix<float>* inputDiagonalMatrix_real(){
    int dim;
    cout << "Enter a dimension of matrix:";
    cin >> dim;
    cout << endl;
    DiagonalMatrix<float>* matrix = new DiagonalMatrix<float>();
    cout << "Enter Main Diagonal Coordinates:" << endl;
    float coord;
    for(int i = 0; i < dim; i++){
        cin >> coord;
        matrix->Set(coord, i, i);//не уверена
    }
    return matrix;
}

DiagonalMatrix<complex>* InputComplexDiagonalMatrix() {
    int dim;
    cout << "Enter a dimension of Matrix:";
    cin >> dim;
    cout << endl;
    auto* matrix = new DiagonalMatrix<complex>();
    cout << "Enter Main Diagonal Coordinates (one by one):" << endl;
    complex coord;
    float real, im;
    for(int i = 0; i < dim; i++){
        cout << "Enter Real and Imaginary number (separated by a space): " << endl;
        cin >> real >> im;
        coord = complex(real, im);
        matrix->Set(coord,i,i);//не уверена
    }
    return matrix;
}

void ComplexMatrixPrint(DiagonalMatrix<complex>& matrix) {
    cout<<"YOUR MATRIX IS:"<<endl;
    cout<<endl;
    for (int i=0; i<matrix.GetSize(); i++) {
        for (int j=0; j<matrix.GetSize(); j++) {
            matrix.Get(i,j).print_complex();
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void MenuDiagonalMatrix(){
    while(true){
        int type = chooseTypeMatrix(); // 1 - int ; 2 - float ; 3 - complex ; 0 - return to select class
        if(type == 0){
            break;
        }
        else if (type == 1){
            while (true){
                int function = chooseFunctionDiagonalMatrix();  // 1 - sum; 2 - mult scalar and matrix; 3 - matrix norm; 0 - return
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = inputDiagonalMatrix_int();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = inputDiagonalMatrix_int();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl << matrix1 << endl;
                        cout << "Second matrix = " << endl << matrix2 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl << sum << endl << endl;
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = inputDiagonalMatrix_int();
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultiplyOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl << MatrixMult << endl;
                }
                else if (function == 3){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = inputDiagonalMatrix_int();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix1 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<float>();
                    cout << "Matrix Norm = " << matrixNorm << endl;
                }
                else if (function == 0)
                    break;
                else
                    throw invalid_argument("Incorrect number"); // ошибку выдать
            }
        }
        else if (type == 2){
            while (true){
                int function = chooseFunctionDiagonalMatrix();  // 1 - sum; 2 - mult scalar and matrix; 3 - matrix norm; 0 - return
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = inputDiagonalMatrix_real();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = inputDiagonalMatrix_real();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl << matrix1 << endl;
                        cout << "Second matrix = " << endl << matrix2 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl << sum << endl;
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = inputDiagonalMatrix_real();
                    cout << "Enter scalar: " << endl;
                    float scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultiplyOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl << MatrixMult << endl;
                }
                else if (function == 3){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = inputDiagonalMatrix_real();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix1 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<float>();
                    cout << "Matrix Norm = " << matrixNorm << endl;
                }
                else if (function == 0) break;
                else
                    throw invalid_argument("Incorrect number"); //выдавать ошибку
            }
        }
        else if (type == 3){
            while (true){
                int function = chooseFunctionDiagonalMatrix();  // 1 - sum; 2 - mult scalar and matrix; 3 - matrix norm; 0 - return
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputComplexDiagonalMatrix();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputComplexDiagonalMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        ComplexMatrixPrint(*matrix1);
                        cout << endl;
                        cout << "Second matrix = " << endl;
                        ComplexMatrixPrint(*matrix2);
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl;
                    ComplexMatrixPrint(*sum);
                    cout << endl;
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexDiagonalMatrix();
                    cout << "Enter scalar: " << endl;
                    complex scalar;
                    float real, im;
                    cout << "Enter Real and Imaginary number (separated by a space): " << endl;
                    cin >> real >> im;
                    scalar = complex(real, im);
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        ComplexMatrixPrint(*matrix);
                        cout << endl;
                        cout << "Scalar = ";
                        scalar.print_complex();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultiplyOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl;
                    ComplexMatrixPrint(*MatrixMult);
                    cout << endl;
                }
                else if (function == 3){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = InputComplexDiagonalMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        ComplexMatrixPrint(*matrix1);
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<complex>();
                    cout << "Matrix Norm = ";
                    matrixNorm.print_complex();
                }
                else if (function == 0) break;
                else
                    throw invalid_argument("Incorrect number");// было cout << "Enter the correct number!" << endl;
            }
        }
    }
}


///Square Matrix
int СhooseFunctionSquareMatrix(){
    int func;
    cout << "What function do you want to use?: \n"
         << "\t1: Sum of Matrices\n"
         << "\t2: Multiplication of scalar and matrix\n"
         << "\t3: Multiplication of two matrix\n"
         << "\t4: Matrix Norm\n"
         << "\t5: Multiplication of scalar and row\n"
         << "\t6: Addition of row and row\n"
         << "\t0: Return to select type\n"
         << "Enter a number: ";
    cin >> func;
    cout << endl;
    return func;
}

/*template <typename T>
SquareMatrix<T>* InputSquareMatrix(){
    int dim;
    cout << "Enter a dimension of matrix:";
    cin >> dim;
    cout << endl;
    auto* matrix = new SquareMatrix<T>();
    cout << "Enter Coordinates:" << endl;
    T coord;
    for(int i = 0; i < dim*dim; i++){
        cin >> coord;
        matrix->Append(coord);//не уверена
    }
    return matrix;
}*/

/*SquareMatrix<complex>* inputComplexSquareMatrix() {
    int dim;
    cout << "Enter a dimension of Matrix:";
    cin >> dim;
    cout << endl;
    auto* matrix = new SquareMatrix<complex>();
    cout << "Enter Coordinates (one by one):" << endl;
    complex coord;
    float real, im;
    for(int i = 0; i < dim; i++){
        cout << "Enter Real and Imaginary number (separated by a space): " << endl;
        cin >> real >> im;
        coord = complex(real, im);
        matrix->Append(coord);//не уверена
    }
    return matrix;
}*/

/*void MenuSquareMatrix(){
    while(true){
        int type = chooseTypeMatrix(); // 1 - int ; 2 - float ; 3 - complex ; 0 - return to select class
        if(type == 0){
            break;
        }
        else if (type == 1){
            while (true){
                int function = СhooseFunctionSquareMatrix();  // 1 - sum; 2 - mult scalar and matrix; 3 - mult two matrix; 4 - norm; 5 -Multiplication of scalar and row;
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<int>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputSquareMatrix<int>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl << matrix1 << endl;
                        cout << "Second matrix = " << endl << matrix2 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl << sum << endl;
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<int>();
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultiplyOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl << MatrixMult << endl << endl;
                }
                else if (function == 3){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<int>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputSquareMatrix<int>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl << matrix1 << endl;
                        cout << "Second matrix = " << endl << matrix2 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* mult = matrix1->multiplyMatrix(matrix2);
                    cout << "Multiplication of first matrix and second matrix = " << endl << mult << endl;
                }
                else if (function == 4){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<int>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix1 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<float>();
                    cout << "Matrix Norm = " << matrixNorm << endl;
                }
                else if(function == 5) { //Multiplication of scalar and row
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<int>();
                    cout << "Enter number row:" << endl;
                    int numRow;
                    cin >> numRow;
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->MultiplyRow(matrix, numRow, scalar);
                    cout << "Multiplication of scalar and row = " << endl << matrix << endl;
                }
                else if(function == 6){ //Addition of row and row
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<int>();
                    cout << "Enter number first row:" << endl;
                    int numRow1;
                    cin >> numRow1;
                    cout << "Enter number second row:" << endl;
                    int numRow2;
                    cin >> numRow2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->AddRowToRow(matrix, numRow1, numRow2);
                    cout << "Addition of row and row = " << endl << matrix << endl;
                }
                else if (function == 0)
                    break;
                else
                    throw invalid_argument("Incorrect number"); // ошибку выдать
            }
        }
        else if (type == 2){
            while (true){
                int function = СhooseFunctionSquareMatrix();
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<float>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputSquareMatrix<float>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl << matrix1 << endl;
                        cout << "Second matrix = " << endl << matrix2 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl << sum << endl;
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<float>();
                    cout << "Enter scalar: " << endl;
                    float scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultiplyOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl << MatrixMult << endl;
                }
                else if (function == 3){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<float>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputSquareMatrix<float>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl << matrix1 << endl;
                        cout << "Second matrix = " << endl << matrix2 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* mult = matrix1->multiplyMatrix(matrix2);
                    cout << "Multiplication of first matrix and second matrix = " << endl << mult << endl;
                }
                else if (function == 4){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<float>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix1 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<float>();
                    cout << "Matrix Norm = " << matrixNorm << endl;
                }
                else if(function == 5) { //Multiplication of scalar and row
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<float>();
                    cout << "Enter number row:" << endl;
                    int numRow;
                    cin >> numRow;
                    cout << "Enter scalar: " << endl;
                    float scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->MultiplyRow(matrix, numRow, scalar);
                    cout << "Multiplication of scalar and row = " << endl << matrix << endl;
                }
                else if(function == 6){ //Addition of row and row
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<float>();
                    cout << "Enter number first row:" << endl;
                    int numRow1;
                    cin >> numRow1;
                    cout << "Enter number second row:" << endl;
                    int numRow2;
                    cin >> numRow2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->AddRowToRow(matrix, numRow1, numRow2);
                    cout << "Addition of row and row = " << endl << matrix << endl;
                }
                else if (function == 0)
                    break;
                else
                    throw invalid_argument("Incorrect number"); // ошибку выдать
            }
        }
        else if (type == 3){
            while (true){
                int function = СhooseFunctionSquareMatrix();  // 1 - sum; 2 - mult scalar and matrix; 3 - mult two matrix; 4 - norm; 5 -Multiplication of scalar and row;
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputComplexDiagonalMatrix();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputComplexDiagonalMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        matrix1->ComplexMatrixPrint();
                        cout << endl;
                        cout << "Second matrix = " << endl;
                        matrix2->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl;
                    sum->ComplexMatrixPrint();
                    cout << endl;
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexDiagonalMatrix();
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        matrix->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->ScalarMultiplyMatrix(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl;
                    MatrixMult->ComplexMatrixPrint();
                    cout << endl;
                }
                else if (function == 3){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputComplexDiagonalMatrix();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputComplexDiagonalMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        matrix1->ComplexMatrixPrint();
                        cout << endl;
                        cout << "Second matrix = " << endl;
                        matrix2->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* mult = matrix1->MultiplyMatrix(matrix2);
                    cout << "Multiplication first matrix and second matrix = " << endl;
                    mult->ComplexMatrixPrint();
                    cout << endl;
                }
                else if (function == 4){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = InputComplexDiagonalMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        matrix1->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<complex>();
                    cout << "Matrix Norm = ";
                    matrixNorm.print_complex();
                    cout<< endl;
                }
                else if(function == 5) { //Multiplication of scalar and row
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexDiagonalMatrix();
                    cout << "Enter number row:" << endl;
                    int numRow;
                    cin >> numRow;
                    cout << "Enter scalar: " << endl;
                    float x, y;
                    cin >> x;
                    cin >> y;
                    complex scalar = complex(x, y);
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        matrix->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->MultiplyRow(matrix, numRow, scalar);
                    cout << "Multiplication of scalar and row = " << endl << matrix << endl;
                }
                else if(function == 6){ //Addition of row and row
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexDiagonalMatrix();
                    cout << "Enter number first row:" << endl;
                    int numRow1;
                    cin >> numRow1;
                    cout << "Enter number second row:" << endl;
                    int numRow2;
                    cin >> numRow2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        matrix->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->AddRowToRow(matrix, numRow1, numRow2);
                    cout << "Addition of row and row = " << endl << matrix << endl;
                }
                else if (function == 0)
                    break;
                else
                    throw invalid_argument("Incorrect number"); // ошибку выдать
            }
        }
    }
}*/

///Menu
int menu(){
    while(true){
        int classType;
        cout << "Diagonal matrix - 1 \n Square matrix - 2 \n Exit - 0 ->" << endl;
        cin >> classType;
        cout << endl;
        if (classType != 0 & classType != 1 & classType != 2){
            cout << "The number is incorrect. Please, enter the correct number" << endl;
        }
        if(classType == 1){
            MenuDiagonalMatrix();
        }
        else if (classType == 2){
            cout<<":)";
            //MenuSquareMatrix();
        }
        else if (classType == 0){
            break;
        }
    }
    return 0;
};
