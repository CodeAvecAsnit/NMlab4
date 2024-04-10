#include<iostream>
using namespace std;

int main() {
    float a[3][4];

    // Input the system of equations
    for(int i = 0; i < 3; ++i) {
        cout << "Equation number " << i + 1 << endl;
        for(int j = 0; j < 4; ++j) {
            cout << "Enter coefficient x" << j + 1 << ": ";
            cin >> a[i][j];
        }
    }

    // Perform the Gaussian elimination
    for(int i = 0; i < 3; ++i) {
        // Normalize the pivot row
        float pivot = a[i][i];
        for(int j = i; j < 4; ++j) {
            if(pivot) a[i][j] /= pivot;
        }

        // Eliminate column entries other than the pivot
        for(int k = 0; k < 3; ++k) {
            if(k != i) {
                float factor = a[k][i];
                for(int j = 0; j < 4; ++j) {
                    a[k][j] -= factor * a[i][j];
                }
            }
        }
    }

    // The system should now be solved with variables in the last column
    cout << "The required values are: " << endl;
    for(int i = 0; i < 3; ++i) {
        cout << "x" << i + 1 << ": " << a[i][3] << endl;
    }

    return 0;
}
