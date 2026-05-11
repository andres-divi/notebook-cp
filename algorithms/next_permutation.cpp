#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)

void generarPermutaciones() {
    // 1. Definir el conjunto inicial
    vector<int> v = {1, 2, 3, 4, 5, 6};

    // 2. REGLA DE ORO: El conjunto DEBE estar ordenado 
    // para obtener TODAS las permutaciones posibles.
    sort(v.begin(), v.end());

    int contador = 0;
    do {
        // [MODIFICAR ACA - LOGICA POR PERMUTACION]
        // Por ejemplo, imprimirla:
        /*
        forn(i, v.size()) cout << v[i] << " ";
        cout << "\n";
        */
        
        contador++;
    } while (next_permutation(v.begin(), v.end()));

    // cout << "Total: " << contador << " permutaciones." << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    generarPermutaciones();

    return 0;
}
