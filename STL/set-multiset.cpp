#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())

typedef long long ll;

void explicarSet() {
    // 1. Declaracion y Basicos
    set<int> s;
    
    // Insertar elementos O(log N)
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(10); // No hace nada, ya existe el 10

    // Borrar O(log N)
    s.erase(5);

    // 2. Busqueda y Verificacion
    // count() devuelve 1 si existe, 0 si no
    if (s.count(10)) {
        // [MODIFICAR ACA - LOGICA SI EXISTE]
    }

    // 3. Iterar (Siempre salen en orden ascendente)
    forall(it, s) {
        // cout << *it << " "; 
    }

    // 4. Lower y Upper Bound (Lo mas importante en CP)
    // lower_bound: primer elemento >= x
    // upper_bound: primer elemento > x
    auto it = s.lower_bound(15); 
    if (it != s.end()) {
        // [MODIFICAR ACA - LOGICA SI ENCONTRO]
        // *it seria el 20 en este caso
    }

    // 5. Multiset (Si necesitas guardar elementos repetidos)
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10); // Ahora hay dos 10
    
    // OJO al borrar en multiset:
    // ms.erase(10); // BORRA TODOS los 10
    // ms.erase(ms.find(10)); // BORRA SOLO UN 10 (usa el iterador)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<ll> mis_nodos;

    forn(i, n) {
        ll x;
        cin >> x;
        mis_nodos.insert(x);
    }

    // Ejemplo rapido: ¿Cuantos elementos distintos hay?
    // cout << sz(mis_nodos) << endl;

    return 0;
}
