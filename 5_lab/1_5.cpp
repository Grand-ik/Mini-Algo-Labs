#include <iostream>
#include <fstream>
#include <cmath>
#include <locale.h>

using namespace std;


bool keyboard(int& n, int& m, int**& A) {
    cin >> n >> m;
    cout << "\nВведите матрицу:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    return true;
}


bool file(int& n, int& m, int**& A) {
    ifstream data_in("input.txt");
    if (!data_in.is_open()) {
        cout << "\n\n[!] Ошибка открытия файла. Проверьте корректность (название: \"input.txt\").";
        return 0;
    }

    data_in >> n >> m;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            data_in >> A[i][j];
        }
        flag = true;
    }

    return true;
}


void stats(int& n, int& m, int**& A) {
    int minimum[3]{A[0][0], 0, 0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i][j] < minimum[0]) {
                minimum[0] = A[i][j];
                minimum[1] = i;
                minimum[2] = j;
            }
        }
    }

    int mid_n, mid_m;
    mid_n = ceil(n * 1.0 / 2);
    mid_m = ceil(m * 1.0 / 2);
    ++minimum[1];
    ++minimum[2];
    int k = floor(minimum[2] * mid_n * 1.0 / mid_m);
    int p = abs(min(minimum[1], n - minimum[1] + 1));
    if (minimum[2] <= mid_m and k <= p) {
        cout << "Матрица корректна.";
    }
    else {
        cout << "Матрица не корректна.";
    }
}


void changes(int& n, int& m, int**& A) {
    int mini[2]{A[0][0], 0};
    int maxi[2]{A[0][0], 0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mini[0] > A[i][j]) {
                mini[0] = A[i][j];
                mini[1] = i;
            }
            if (maxi[0] < A[i][j]) {
                maxi[0] = A[i][j];
                maxi[1] = i;
            }
        }
    }

    int dop;
    for (int j = 0; j < m; ++j) {
        dop = A[mini[1]][j];
        A[mini[1]][j] = A[maxi[1]][j];
        A[maxi[1]][j] = dop;
    }

    cout << "Замена выполнено.";
}


void print_matrix(int& n, int& m, int**& A) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}


int main() {
    setlocale(LC_ALL, "Russian");
    int n, m;
    n = m = 1000;
    int** A = new int*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[m];
    }

    while (true) {
        for (int i = 0; i < 30; ++i) { cout << '-'; }
        cout << '\n';
        cout << "1. Ввод матрицы с клавиатуры.\n";
        cout << "2. Ввод матрицы из файла.\n";
        cout << "3. Вычисление характеристики.\n";
        cout << "4. Преобразование матрицы.\n";
        cout << "5. Печать матрицы.\n";
        cout << "6. Выход.\n\n";
        int num;
        cin >> num;
        cout << "\n\n";
        switch (num) {
            case (1): {
                keyboard(n, m, A);
                break;
            }
            case (2): {
                file(n, m, A);
                break;
            }
            case (3): {
                stats(n, m, A);
                break;
            }
            case (4): {
                changes(n, m, A);
                break;
            }
            case (5): {
                print_matrix(n, m, A);
                break;
            }
            case (6): {
                return 0;
            }
            default: {
                cout << "\n[!] Введите корректное значение.\n";
            }
        }
        cout << "\n\n\n";
    }

    return 0;
}