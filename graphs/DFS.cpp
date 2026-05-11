#include <bits/stdc++.h>
using namespace std;

// Macros de tu template
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define pb push_back

typedef long long ll;

// Variables globales para el grafo
vector<vector<int>> ady;
vector<bool> visit;

void dfs(int u) {
    visit[u] = true;
    
    // [ACCION AL DESCUBRIR EL NODO]
    
    for (int v : ady[u]) {
        if (!visit[v]) {
            // [ACCION ANTES DE VISITAR AL HIJO]
            dfs(v);
            // [ACCION AL VOLVER DEL HIJO]
        } else {
            // [ACCION SI EL VECINO YA ESTABA VISITADO - CICLOS]
        }
    }
    
    // [ACCION AL TERMINAR DE EXPLORAR EL NODO]
}

int main() {
    // Optimizacion de I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; // n = nodos, m = aristas
    if (!(cin >> n >> m)) return 0;

    // IMPORTANTE: resize para evitar out_of_range
    // Usamos n + 1 por si el problema usa nodos indexados desde 1
    ady.resize(n + 1);
    visit.assign(n + 1, false);

    // Lectura de la lista de adyacencia
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        
        // Agregar segun sea dirigido o no dirigido
        ady[u].pb(v);
        ady[v].pb(u); 
    }

    // Lanzamos el DFS (ejemplo desde el nodo 1)
    // dfs(1);

    // Si el grafo puede tener varias componentes conexas:
    forr(i, 1, n + 1) {
        if (!visit[i]) {
            dfs(i);
        }
    }

    return 0;
}
