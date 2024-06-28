#include <iostream>
using namespace std;

void llenarmatriz (int matriz[3][3]){
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++) {
            cout<<"Ingresar valor en Fila "<< i<<" Columna "<<j<<": ";
            cin>>matriz[i][j];
        }
    }
    system("cls");
}
void mostrarMatriz (int matriz[3][3]) {
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++) {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}
///----------------------------------------------BUSCAR ALGO DENTRO DE MATRIZ-----------------------------------------------------------
void buscarMat (int matriz[3][3],int numBuscar){
    bool esta=false;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++) {
            if (matriz[i][j] == numBuscar) {
                esta=true;
            }
        }
    }
    if (esta == true) {
        cout<<"El numero se encuentra dentro de la matriz";
    } else {
        cout<<"El numero NO se encuentra dentro de la matriz";
    }
}
///---------------------------------------------ROTAR MATRIZ A LA DER------------------------------------------------------------
void rotarMat (int matriz[3][3], int matrizRot[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrizRot[3 - 1 - j][i] = matriz[i][j];
            // para rotar a la izq --->>   matrizRot[3 - 1 - j][i] = matriz[i][j];
            // para girar 180 --->> matrizRot[3 - 1 - i][3 - 1 - j] = matriz[i][j];
        }
    }
}
int main() {
    int matriz[3][3];
    cout<<"Vamos a llenar la matriz"<<endl;
    llenarmatriz(matriz);
    cout<<"La matriz quedaria asi: "<<endl;
    mostrarMatriz(matriz);
///---------------------------------------------------------------------------------------------------------
    cout<<endl<<"Ahora vamos a buscar un numero dentro de la matriz"<<endl;
    int numeroABuscar;
    cout<<"Ingresar numero a buscar: ";
    cin>>numeroABuscar;
    buscarMat(matriz, numeroABuscar);
///---------------------------------------------------------------------------------------------------------
    cout<<endl<<endl<<"Ahora vamos a rotar la matriz a la Derecha"<<endl;
    int matrizRotada[3][3];
    rotarMat(matriz, matrizRotada);
    cout<<"La matriz rotada quedaria asi: "<<endl;
    mostrarMatriz(matrizRotada);

    return 0;
}
