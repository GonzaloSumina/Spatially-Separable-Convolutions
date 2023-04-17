#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int A[5][5];
    int B[3][1] = { {2}, {4}, {1} };
    srand(time(NULL));
    const int filA = sizeof(A) / sizeof(*A);
    const int colA = sizeof(*A) / sizeof(**A);
    const int filB = sizeof(B) / sizeof(*B);
    const int colB = sizeof(*B) / sizeof(**B);
    int C[filB][colA];
    const int filC = sizeof(C) / sizeof(*C);
    const int colC = sizeof(*C) / sizeof(**C);
    int cont = 1;
    int* r = *C;
    for (int* p = *A; p < *(A + filA); p++) {
        *p = 0 + rand() % 9;
    }
    for (int* p = *A; p < *(A + filA); p++) {
        cout << *p<<' ';
        if (cont == colA) {
            cout << "\n";
            cont = 0;
        }
        cont++;
    }
    for (int* p = *B; p < *(B + filB); p++) {
        cout << *p;
        if (cont == colB) {
            cout << "\n";
            cont = 0;
        }
        cont++;
    }
    for (int* p = *A; p < *(A + filB); p++) {
        int mult = 0;
        int cont2 = 0;
        int suma = 0;
        for (int* q = *B ; q < *(B+filB); ) {
            mult = *p * *q;
            suma = suma + mult;
            q++;
            p = p + colA;
        }
        *r = suma;
        r++;
        p = p - (colA * filB);
        cout << suma << "\n";
    }

    for (int* p = *C; p < *(C + filC); p++) {
        cout << *p<< ' ';
        if (cont == colC) {
            cout << "\n";
            cont = 0;
        }
        cont++;
    }
    return 0;
}