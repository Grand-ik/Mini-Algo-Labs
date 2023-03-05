#include <iostream>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    int A[2][m], B[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            B[i][j] = 0;
        }
    }


    // Первая строка
    cin >> A[0][0];
    for (int j = 1; j < m; ++j) {
        cin >> A[0][j];
        if (A[0][j] == A[0][j - 1]) {
            ++B[0][j];
            ++B[0][j - 1];
        }
    }

    // Остальные строки
    for (int i = 1; i < n; ++i) {
        cin >> A[1][0];

        if (A[1][0] == A[0][0]) {
            ++B[i][0];
            ++B[i - 1][0];
        }

        for (int j = 1; j < m; ++j) {
            cin >> A[1][j];

            if (A[1][j] == A[0][j]) {
                ++B[i][j];
                ++B[i - 1][j];
            }
            if (A[1][j] == A[1][j - 1]) {
                ++B[i][j - 1];
                ++B[i][j];
            }
            if (A[1][j] == A[0][j - 1]) {
                ++B[i][j];
                ++B[i - 1][j - 1];
            }

            if (A[1][j - 1] == A[0][j]) {
                ++B[i][j - 1];
                ++B[i - 1][j];
            }
        }

        for (int p = 0; p < m; ++p) {
            A[0][p] = A[1][p];
            A[1][p] = 0;
        }
    }


    cout << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << B[i][j] << ' ';
        }
        cout << '\n';
    }


    cout << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            (B[i][j] < 2) ? cout << '0' : cout << '1';
            cout << ' ';
        }
        cout << '\n';
    }


    return 0;
}

// int main() {
//     cout << "Ведите размерность матрицы(строки х столбцы): ";
//     int n, m;
//     cin >> n >> m;
//     int** A = new int*[3];
//     for (int i = 0; i < 3; ++i) {
//         A[i] = new int[m];
//     }
//     int B[n][m];
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             B[i][j] = 0;
//         }
//     }

//     cin >> A[0][0];
//     for (int j = 1; j < m; ++j) {
//         cin >> A[0][j];
//         if (A[0][j] == A[0][j - 1]) {
//             ++A[0][j];
//             ++A[0][j - 1];
//         }
//     }

//     for (int i = 1; i < n; ++i) {
//         cin >> A[i][0];
//         if (A[i][0] == A[i - 1][0]) {
//             ++A[i - 1][0];
//             A[i][0] = A[i - 1][0];
//         }
//         for (int j = 1; j < m; ++j) {
//             cin >> A[i][j];
//             if (A[i][j] == A[i - 1][j - 1]) {
//                 ++A[i - 1][j - 1];
//                 ++A[i][j];
//             }
//             if (A[i][j] == A[i][j - 1]) {
//                 ++A[i][j - 1];
//                 ++A[i][j];
//             }
//             if (A[i][j] == A[i - 1][j]) {
//                 ++A[i - 1][j];
//                 ++A[i][j];
//             }
//         }
//     }


//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             (B[i][j] > 0) ? cout << '1' : cout << '0';
//             cout << ' ';
//         }
//         cout << '\n';
//     }



//     return 0;
// }