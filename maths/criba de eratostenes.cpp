bool isPrime[100500]; 

void criba() { 
    isPrime[0] = isPrime[1] = false; 
    
    for(int i = 2; i < 100500; i++) isPrime[i] = true; 

    for(int p = 2; p < 100500; p++) { 
        if (isPrime[p]) { 
            for(int m = 2 * p; m < 100500; m += p) isPrime[m] = false; 
        }
    }
}
