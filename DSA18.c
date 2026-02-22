  #include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    
    // Optimize k: since rotating by n is same as 0
    k = k % n;
    
    // Print last k elements first, then first n-k elements
    for(int i = n - k; i < n; i++) {
        cout << arr[i] << " ";
    }
    for(int i = 0; i < n - k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
