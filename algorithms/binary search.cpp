#include <bits/stdc++.h>
using namespace std;

void busquedaEnVector() {
    vector<int> v = {10, 20, 30, 30, 30, 40, 50};

    // 1. binary_search (bool)
    bool existe = binary_search(v.begin(), v.end(), 30); // true

    // 2. lower_bound (primer >= x)
    auto lb = lower_bound(v.begin(), v.end(), 30);
    // Para obtener el INDICE (posicion), restamos v.begin()
    int pos_lb = lb - v.begin(); // pos_lb = 2 (el primer 30)

    // 3. upper_bound (primer > x)
    auto ub = upper_bound(v.begin(), v.end(), 30);
    int pos_ub = ub - v.begin(); // pos_ub = 5 (el 40)
    
    // TRUCO CP: ¿Cuantos 30 hay en el vector?
    int cantidad = ub - lb; // 5 - 2 = 3
}

void busquedaEnSetYMap() {
    // --- EN UN SET ---
    set<int> s = {10, 20, 30, 40};
    
    auto it_set = s.lower_bound(25); 
    
    if (it_set != s.end()) {
        cout << "Primer elemento >= 25 es: " << *it_set << endl; // 30
    }

    // --- EN UN MAP ---
    // En el map, las busquedas siempre operan sobre las CLAVES (keys), no sobre los valores.
    map<int, string> m;
    m[10] = "Diez";
    m[20] = "Veinte";
    m[30] = "Treinta";

    // Busca la primera clave >= 25
    auto it_map = m.lower_bound(25);
    
    if (it_map != m.end()) {
        cout << "Clave: " << it_map->first << " | Valor: " << it_map->second << endl; 
        // Imprime Clave: 30 | Valor: Treinta
    }
}
