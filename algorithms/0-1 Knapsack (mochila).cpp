//n es cantidad de cosas, x es el precio maximo
//meter h cosas dadas n de ellas de peso ji en una mochila, maximizando el peso con 
//un peso maximo, en el ejemplo eran libros con un costo precio[i]
//y una cantidad de hojas[i], hay que maximizar la cantidad de hojas dadas un precio maximo
for (int i=0; i<n; i++)
    for (int j=x; j>0; j--)
        if(j-precio[i] >= 0) dp[j]=max(dp[j], dp[j-precio[i]] + hojas[i]);
cout << dp[x] << endl;
