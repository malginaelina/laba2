
#ifndef LABA2_MENU_H
#define LABA2_MENU_H

#include "ArraySequence.h"
#include "Matrix.h"
#include "SquareMatrix.h"
#include <iostream>
#include "Complex.h"
#include <ctime>

int chooseTypeMatrix();
int chooseFunctionDiagonalMatrix();
template <typename T> DiagonalMatrix<T>* inputDiagonalMatrix();
DiagonalMatrix<complex>* InputComplexDiagonalMatrix();
void MenuDiagonalMatrix();

template <typename T> SquareMatrix<T>* InputSquareMatrix();
SquareMatrix<complex>* inputComplexSquareMatrix();
int СhooseFunctionSquareMatrix();
void MenuSquareMatrix();
int menu();

#endif //LABA2_MENU_H
