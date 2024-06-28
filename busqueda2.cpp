#include <iostream>
#include <vector>
using namespace std;

// Funci�n para buscar un n�mero en una matriz est�tica
int buscarNumero(int matriz[3][3], int numero) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matriz[i][j] == numero) {
                return 1; // Retorna 1 si encuentra el n�mero
            }
        }
    }
    return 0; // Retorna 0 si no encuentra el n�mero
}

// Funci�n para girar una matriz est�tica en 90 grados en sentido antihorario
void girarMatriz(int matriz[3][3]) {
    int resultado[3][3];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            resultado[j][3 - 1 - i] = matriz[i][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matriz[i][j] = resultado[i][j];
        }
    }
}

// Funci�n para imprimir una matriz est�tica
void imprimirMatriz(int matriz[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Funci�n para imprimir una matriz din�mica
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Funci�n para ordenar una matriz din�mica en orden descendente
void sortMatrixDescending(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        for (int i = 0; i < row.size(); ++i) {
            for (int j = i + 1; j < row.size(); ++j) {
                if (row[i] < row[j]) {
                    swap(row[i], row[j]);
                }
            }
        }
    }
}

// Funci�n para buscar un n�mero en una matriz din�mica y mostrar todas las posiciones
void searchNumber(const vector<vector<int>>& matrix, int target) {
    int positionCount = 0;

    // Recorrer la matriz para buscar el n�mero
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == target) {
                ++positionCount;
                cout << "El n�mero " << target << " est� en la posici�n (" << i << ", " << j << ")." << endl;
                // No se necesita un booleano para marcar que se encontr� el n�mero
                // Puedes comentar la siguiente l�nea si deseas encontrar todas las ocurrencias
                // return; // Comentar esta l�nea si se desea encontrar todas las ocurrencias
            }
        }
    }

    if (positionCount == 0) {
        cout << "El n�mero " << target << " no se encontr� en la matriz." << endl;
    } else {
        cout << "Se encontr� el n�mero " << target << " " << positionCount << " vez/veces en la matriz." << endl;
    }
}

int main() {
    int opcion;
    int numero;

    do {
        // Men� de opciones
        cout << "\n----- Men� -----" << endl;
        cout << "1. Buscar un n�mero en una matriz est�tica" << endl;
        cout << "2. Girar una matriz est�tica en 90 grados en sentido antihorario" << endl;
        cout << "3. Imprimir una matriz est�tica" << endl;
        cout << "4. Ordenar una matriz din�mica en orden descendente" << endl;
        cout << "5. Buscar un n�mero en una matriz din�mica" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese su opci�n: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int matrizEstatica[3][3] = {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                };
                cout << "Ingrese el n�mero a buscar en la matriz est�tica: ";
                cin >> numero;
                if (buscarNumero(matrizEstatica, numero)) {
                    cout << "El n�mero " << numero << " est� en la matriz est�tica." << endl;
                } else {
                    cout << "El n�mero " << numero << " no est� en la matriz est�tica." << endl;
                }
                break;
            }
            case 2: {
                int matrizEstatica[3][3] = {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                };
                cout << "Matriz est�tica original:" << endl;
                imprimirMatriz(matrizEstatica);
                girarMatriz(matrizEstatica);
                cout << "Matriz est�tica girada:" << endl;
                imprimirMatriz(matrizEstatica);
                break;
            }
            case 3: {
                int matrizEstatica[3][3] = {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                };
                cout << "Matriz est�tica:" << endl;
                imprimirMatriz(matrizEstatica);
                break;
            }
            case 4: {
                vector<vector<int>> matrizDinamica = {
                    {5, 2, 9},
                    {3, 7, 1},
                    {8, 4, 6}
                };
                sortMatrixDescending(matrizDinamica);
                cout << "Matriz din�mica ordenada en orden descendente:" << endl;
                printMatrix(matrizDinamica);
                break;
            }
            case 5: {
                vector<vector<int>> matrizDinamica = {
                    {5, 2, 9, 5},
                    {3, 7, 1, 5},
                    {8, 4, 6, 5},
                    {5, 5, 5, 5}
                };
                cout << "Matriz din�mica:" << endl;
                printMatrix(matrizDinamica);
                cout << endl;
                cout << "Ingrese el n�mero a buscar en la matriz din�mica: ";
                cin >> numero;
                searchNumber(matrizDinamica, numero);
                break;
            }
            case 6:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opci�n no v�lida. Por favor, ingrese una opci�n v�lida." << endl;
        }

    } while (opcion != 6);

    return 0;
}
