typedef long long ll;

// P(x) es tu función de condición. Devuelve true o false.
bool check(ll mid) {
    // Aca va la logica del problema
    return true; 
}

void busquedaBinaria() {
    ll low = 0;       // P(low) es FALSO
    ll high = 1e18;   // P(high) es VERDADERO
    
    while (high - low > 1) {
        // En vez de (low+high)/2, usamos esto para evitar overflow
        ll mid = low + (high - low) / 2; 
        
        if (check(mid)) {
            high = mid; // El punto medio cumple la condicion
        } else {
            low = mid;  // El punto medio NO cumple
        }
    }
    // Al terminar el while, low y high son contiguos (ej: low=4, high=5)
    // 'high' es el primer valor que cumple la condicion.
    // 'low' es el ultimo valor que NO la cumple.
}
