void conversiones() {
    // 1. String a Entero (int)
    // stoi = String TO Integer
    string s1 = "1234";
    int a = stoi(s1);

    // 2. String a Long Long (ll)
    // stoll = String TO Long Long
    string s2 = "123456789012345";
    ll b = stoll(s2);

    // 3. Numero (int o long long) a String
    int c = 42;
    string s3 = to_string(c);

    ll d = 1e18;
    string s4 = to_string(d);

}
