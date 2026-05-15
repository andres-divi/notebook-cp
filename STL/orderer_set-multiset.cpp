#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Ordered set SIN repetidos (less)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// Ordered set CON repetidos (less_equal)
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main() {

    // ════════════════════════════════════════════
    //  INSERCIÓN / BORRADO
    // ════════════════════════════════════════════

    ordered_set os;

    os.insert(10);           // O(log N) — inserta elemento (ignorado si ya existe)
    os.insert(3);
    os.insert(7);
    os.insert(15);
    os.insert(1);
    // Estado: {1, 3, 7, 10, 15}

    os.erase(7);             // O(log N) — borra por valor
    // Estado: {1, 3, 10, 15}

    auto it = os.find(3);
    os.erase(it);            // O(log N) — borra por iterador
    // Estado: {1, 10, 15}

    os.insert(5);
    os.insert(8);
    os.insert(12);
    // Estado: {1, 5, 8, 10, 12, 15}


    // ════════════════════════════════════════════
    //  OPERACIONES EXCLUSIVAS DE PB_DS
    // ════════════════════════════════════════════

    // order_of_key(x) → cantidad de elementos ESTRICTAMENTE MENORES a x
    cout << os.order_of_key(8)  << "\n";  // 2  → {1, 5}            O(log N)
    cout << os.order_of_key(9)  << "\n";  // 3  → {1, 5, 8}         O(log N)
    cout << os.order_of_key(1)  << "\n";  // 0  → {}                 O(log N)
    cout << os.order_of_key(99) << "\n";  // 6  → todos              O(log N)

    // find_by_order(k) → iterador al k-ésimo elemento (base 0)
    cout << *os.find_by_order(0) << "\n"; // 1   (índice 0)          O(log N)
    cout << *os.find_by_order(2) << "\n"; // 8   (índice 2)          O(log N)
    cout << *os.find_by_order(5) << "\n"; // 15  (índice 5)          O(log N)
    // find_by_order(os.size()) → os.end(), NO desreferenciar


    // ════════════════════════════════════════════
    //  DERIVADOS ÚTILES (combinando las anteriores)
    // ════════════════════════════════════════════

    int x = 8;

    // Cantidad de elementos MENORES que x
    int menores       = os.order_of_key(x);                       // O(log N)

    // Cantidad de elementos MAYORES que x (sin repetidos: mayores = size - menores_o_iguales)
    int mayores       = os.size() - os.order_of_key(x + 1);       // O(log N)

    // Cantidad de elementos MENORES O IGUALES que x
    int menores_o_ig  = os.order_of_key(x + 1);                   // O(log N)

    // Cantidad de elementos MAYORES O IGUALES que x
    int mayores_o_ig  = os.size() - os.order_of_key(x);           // O(log N)

    // ¿Existe x en el set?
    bool existe       = os.find(x) != os.end();                    // O(log N)

    // K-ésimo menor (base 1)
    int k = 3;
    cout << *os.find_by_order(k - 1) << "\n";                     // O(log N)

    cout << "menores=" << menores << " mayores=" << mayores
         << " <=x=" << menores_o_ig << " >=x=" << mayores_o_ig
         << " existe=" << existe << "\n";


    // ════════════════════════════════════════════
    //  ITERADORES (heredados de std::set)
    // ════════════════════════════════════════════

    // Recorrer en orden ascendente
    for (auto v : os) cout << v << " ";          // O(N)
    cout << "\n";

    // Recorrer en orden descendente
    for (auto it2 = os.rbegin(); it2 != os.rend(); ++it2)
        cout << *it2 << " ";                      // O(N)
    cout << "\n";

    // Mínimo y máximo
    cout << *os.begin()  << "\n";  // mínimo     O(1)  (amortizado)
    cout << *os.rbegin() << "\n";  // máximo      O(1)  (amortizado)

    // lower_bound(x) → primer elemento >= x
    auto lb = os.lower_bound(8);                  // O(log N)
    if (lb != os.end()) cout << *lb << "\n";      // 8

    // upper_bound(x) → primer elemento > x
    auto ub = os.upper_bound(8);                  // O(log N)
    if (ub != os.end()) cout << *ub << "\n";      // 10


    // ════════════════════════════════════════════
    //  TAMAÑO / ESTADO
    // ════════════════════════════════════════════

    cout << os.size()  << "\n";   // cantidad de elementos     O(1)
    cout << os.empty() << "\n";   // true si está vacío        O(1)
    os.clear();                   // borra todo                 O(N)
    cout << os.empty() << "\n";   // 1


    // ════════════════════════════════════════════
    //  ORDERED_MULTISET (con repetidos, usar less_equal)
    //  ⚠ find() y erase() por valor NO funcionan bien
    //     → siempre borrar por iterador
    //  ⚠ lower_bound / upper_bound pueden comportarse distinto
    // ════════════════════════════════════════════

    ordered_multiset oms;
    oms.insert(5);
    oms.insert(5);
    oms.insert(10);
    // Estado lógico: {5, 5, 10}

    // order_of_key con less_equal: cuenta estrictamente menores
    cout << oms.order_of_key(5)  << "\n"; // 0 → ninguno menor que 5   O(log N)
    cout << oms.order_of_key(6)  << "\n"; // 2 → {5, 5}                O(log N)
    cout << oms.order_of_key(11) << "\n"; // 3 → todos                 O(log N)

    // Borrar UNA ocurrencia de 5
    auto it2 = oms.find_by_order(oms.order_of_key(5)); // O(log N)
    oms.erase(it2);                                     // O(log N)
    // Estado lógico: {5, 10}

    cout << oms.size() << "\n"; // 2


    return 0;
}
