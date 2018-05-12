#include "vector"
#include "iostream"

using namespace std;

int equal(vector <int> arr) {
    size_t size = arr.size();
    int minimum = arr[0];

    for (size_t i = 1; i < size; i++)
        if (arr[i] < minimum)
            minimum = arr[i];

    int difference;
    int steps;
    int min_steps = -1;

    for (int decrease = 0; decrease <= 4; decrease++) {
        steps = 0;

        for (size_t i = 0; i < size; i++) {
            difference = abs(arr[i] - minimum + decrease);
            steps += difference / 5 + difference % 5 / 2 + difference % 5 % 2;
        }

        if (min_steps == -1 || steps < min_steps) {
            min_steps = steps;
        }
    }

    return min_steps;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        size_t n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
            cin >> arr[arr_i];
        }
        int result = equal(arr);
        cout << result << endl;
    }
    return 0;
}
