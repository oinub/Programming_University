#include <iostream>
#include <cstdlib>

void point1() {
    int** matrix = (int**)calloc(2, sizeof(int*));
    for (int i = 0; i < 2; i++) {
        matrix[i] = (int*)calloc(2, sizeof(int));
    }

    do {
        std::cout << "A = ";
        std::cin >> matrix[0][0];
        if (matrix[0][0] < 0) std::cout << "введи положительное число" << std::endl;
    } while (matrix[0][0] < 0);

    do {
        std::cout << "B = ";
        std::cin >> matrix[0][1];
        if (matrix[0][1] < 0) std::cout << "введи положительное число" << std::endl;
    } while (matrix[0][1] < 0);

    std::cout << "C = ";
    std::cin >> matrix[1][0];
    std::cout << "D = ";
    std::cin >> matrix[1][1];
    std::cout << std::endl;

    int chA = matrix[0][0];
    int chB = matrix[0][1];
    int chC = matrix[1][0];
    int chD = matrix[1][1];

    int row = 2 + chA;
    int col = 2 + chB;

    matrix = (int**)realloc(matrix, row * sizeof(int*));

    for (int i = 0; i < 2; i++) {
        matrix[i] = (int*)realloc(matrix[i], col * sizeof(int));
        for (int j = 2; j < col; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 2; i < row; i++) {
        matrix[i] = (int*)calloc(col, sizeof(int));
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if ((i == 0 || i == 1) && (j == 0 || j == 1)) {
                if (i == 0 && j == 0) matrix[i][j] = chA;
                else if (i == 0 && j == 1) matrix[i][j] = chB;
                else if (i == 1 && j == 0) matrix[i][j] = chC;
                else if (i == 1 && j == 1) matrix[i][j] = chD;
            }
            else {
                matrix[i][j] = (i - 1) * chC + (j - 1) * chD;
            }
        }
    }

    std::cout << "Исходная матрица:" << std::endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    int cnt = 0;
    int* zero_columns = nullptr;

    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            if (matrix[i][j] == 0) {
                int* temp = (int*)realloc(zero_columns, (cnt + 1) * sizeof(int));
                if (temp != nullptr) {
                    zero_columns = temp;
                    zero_columns[cnt] = j;
                    cnt++;
                }
                else {
                    std::cout << "Ошибка realloc!" << std::endl;
                    free(zero_columns);
                    for (int k = 0; k < row; k++) {
                        free(matrix[k]);
                    }
                    free(matrix);
                    return;
                }
                break;
            }
        }
    }

    std::cout << "Столбцы с нулями: ";
    for (int i = 0; i < cnt; i++) {
        std::cout << zero_columns[i] << " ";
    }
    std::cout << std::endl;

    if (cnt > 0) {
        int new_cols = col - cnt;

        int** temp_matrix = (int**)calloc(row, sizeof(int*));

        for (int i = 0; i < row; i++) {
            temp_matrix[i] = (int*)calloc(new_cols, sizeof(int));
            int new_j = 0;

            for (int j = 0; j < col; j++) {
                bool skip_column = false;
                for (int k = 0; k < cnt; k++) {
                    if (j == zero_columns[k]) {
                        skip_column = true;
                        break;
                    }
                }

                if (!skip_column) {
                    temp_matrix[i][new_j] = matrix[i][j];
                    new_j++;
                }
            }
        }

        for (int i = 0; i < row; i++) {
            free(matrix[i]);
        }
        free(matrix);

        matrix = temp_matrix;
        col = new_cols;

        std::cout << std::endl;
        std::cout << "Матрица после удаления столбцов:" << std::endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    else {
        std::cout << "Нет столбцов для удаления" << std::endl;
    }

    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(zero_columns);
}

void point2() {
    std::cout << std::endl;
    std::cout << "Введите 2 числа: " << std::endl;

    float* a = new float;
    float* b = new float;

    std::cout << "a = ";
    std::cin >> *a;

    std::cout << "b = ";
    std::cin >> *b;

    std::cout << "Исходные значения: a = " << *a << ", b = " << *b << std::endl;

    *a = *a * 3;
    std::cout << "После умножения a на 3: a = " << *a << ", b = " << *b << std::endl;
    float* с = new float;
    *с = *a;
    *a = *b;
    *b = *с;

    std::cout << "После обмена значений: a = " << *a << ", b = " << *b << std::endl;


    delete a;
    delete b;
    delete с;
}

int main() {
    setlocale(LC_ALL, "Russian");
    point1();
    point2();
    return 0;
}