
void symmetry(int n) {
    n = 2*n ;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n; j++) {
            if (i < n/2 && (j <= i || j >= (n-i-1))) {
                cout << '*';
            }
            else if (i >= n/2 && (j < (n-i-1) || j > i)) {
                cout << '*';
            }
            else {
                cout << ' ';
            }
            cout << ' ';
        }

        cout << '\n';
    }
}
