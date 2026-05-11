#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) -1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
#ifdef ANARAP
// local
#else
// judge
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

// ===================== UNION FIND (DSU) =====================
// Maneja grupos de elementos. Operaciones casi O(1) por:
//   - Path compression: find() aplana el árbol hacia la raíz
//   - Union by rank:    siempre pone el árbol menor debajo del mayor
//
// CUIDADO: no usar "sz" como nombre de vector, choca con el macro del template
// ============================================================
struct DSU {
    vector<int> par; // par[x] = padre de x (si par[x]==x, x es raíz)
    vector<int> rnk; // rnk[x] = altura aproximada del árbol con raíz x
    vector<int> tam; // tam[x] = tamaño del componente (solo válido en la raíz)
    int componentes; // cantidad de componentes conexas actuales

    // Inicializar con n nodos 0-indexed, cada uno en su propio grupo
    DSU(int n) : par(n), rnk(n, 0), tam(n, 1), componentes(n) {
        iota(par.begin(), par.end(), 0); // par[i] = i
    }

    // Devuelve el representante (raíz) del grupo de x
    // No usar el valor en sí, solo comparar: find(x)==find(y)
    int find(int x) {
        if (par[x] != x)
            par[x] = find(par[x]); // path compression: x apunta directo a la raíz
        return par[x];
    }

    // Une los grupos de x e y
    // Retorna true si estaban separados (se hizo algo)
    // Retorna false si ya estaban en el mismo grupo (no pasó nada)
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;          // ya están unidos
        if (rnk[x] < rnk[y]) swap(x, y);  // x queda como la raíz mayor
        par[y] = x;                        // y pasa a ser hijo de x
        tam[x] += tam[y];                  // x absorbe el tamaño de y
        if (rnk[x] == rnk[y]) rnk[x]++;   // si eran iguales, sube el rango
        componentes--;
        return true;
    }

    // true si x e y están en el mismo grupo
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    // Tamaño del componente al que pertenece x
    // Hace find() internamente, se puede llamar con cualquier nodo del grupo
    int size(int x) {
        return tam[find(x)];
    }
};
// ===================== FIN UNION FIND =======================

int main() {
#ifdef ANARAP
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;

    DSU dsu(n); // n nodos, 0-indexed (restar 1 a la entrada si es 1-indexed)

    forn(i, m) {
        int a; cin >> a;          // cantidad de elementos en este grupo
        int k;
        if (a > 0) { cin >> k; k--; }        // representante del grupo
        forn(j, a - 1) {
            int h; cin >> h; h--;
            dsu.unite(k, h);      // unir cada elemento con el representante
        }
    }

    forn(i, n) {
        cout << dsu.size(i) << " ";
    }
	//~ find → solo sirve para comparar, no para usar el valor
	//~ unite → retorna bool, útil para detectar ciclos o saber si algo cambió
	//~ dsu.unite(0, 1); // true  → estaban separados, los uní
	//~ dsu.unite(0, 1); // false → ya estaban juntos, no cambió nada
	//~ size → llamalo con cualquier nodo del grupo, siempre llega a la raíz
	//~ componentes → se actualiza solo con cada unite exitoso
	//~ Siempre restar 1 a la entrada si los nodos vienen 1-indexed
	
    return 0;
}
