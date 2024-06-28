#include <iostream>
#include <vector>
using namespace std;

// Función para buscar un número en una matriz estática
int buscarNumero(int matriz[3][3], int numero) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matriz[i][j] == numero) {
                return 1; // Retorna 1 si encuentra el número
            }
        }
    }
    return 0; // Retorna 0 si no encuentra el número
}

// Función para girar una matriz estática en 90 grados en sentido antihorario
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

// Función para imprimir una matriz estática
void imprimirMatriz(int matriz[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para imprimir una matriz dinámica
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Función para ordenar una matriz dinámica en orden descendente
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

// Función para buscar un número en una matriz dinámica y mostrar todas las posiciones
void searchNumber(const vector<vector<int>>& matrix, int target) {
    int positionCount = 0;

    // Recorrer la matriz para buscar el número
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == target) {
                ++positionCount;
                cout << "El número " << target << " está en la posición (" << i << ", " << j << ")." << endl;
                // No se necesita un booleano para marcar que se encontró el número
                // Puedes comentar la siguiente línea si deseas encontrar todas las ocurrencias
                // return; // Comentar esta línea si se desea encontrar todas las ocurrencias
            }
        }
    }

    if (positionCount == 0) {
        cout << "El número " << target << " no se encontró en la matriz." << endl;
    } else {
        cout << "Se encontró el número " << target << " " << positionCount << " vez/veces en la matriz." << endl;
    }
}

int main() {
    int opcion;
    int numero;

    do {
        // Menú de opciones
        cout << "\n----- Menú -----" << endl;
        cout << "1. Buscar un número en una matriz estática" << endl;
        cout << "2. Girar una matriz estática en 90 grados en sentido antihorario" << endl;
        cout << "3. Imprimir una matriz estática" << endl;
        cout << "4. Ordenar una matriz dinámica en orden descendente" << endl;
        cout << "5. Buscar un número en una matriz dinámica" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int matrizEstatica[3][3] = {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                };
                cout << "Ingrese el número a buscar en la matriz estática: ";
                cin >> numero;
                if (buscarNumero(matrizEstatica, numero)) {
                    cout << "El número " << numero << " está en la matriz estática." << endl;
                } else {
                    cout << "El número " << numero << " no está en la matriz estática." << endl;
                }
                break;
            }
            case 2: {
                int matrizEstatica[3][3] = {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                };
                cout << "Matriz estática original:" << endl;
                imprimirMatriz(matrizEstatica);
                girarMatriz(matrizEstatica);
                cout << "Matriz estática girada:" << endl;
                imprimirMatriz(matrizEstatica);
                break;
            }
            case 3: {
                int matrizEstatica[3][3] = {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                };
                cout << "Matriz estática:" << endl;
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
                cout << "Matriz dinámica ordenada en orden descendente:" << endl;
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
                cout << "Matriz dinámica:" << endl;
                printMatrix(matrizDinamica);
                cout << endl;
                cout << "Ingrese el número a buscar en la matriz dinámica: ";
                cin >> numero;
                searchNumber(matrizDinamica, numero);
                break;
            }
            case 6:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
        }

    } while (opcion != 6);

    return 0;
}
