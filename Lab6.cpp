#include <iostream>
#include <cstdlib>

int* getZeroColumns(int** matrix, int rows, int cols, int* count) {
    *count = 0;
    int* zero_columns = nullptr;

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == 0) {
                int* temp = (int*)realloc(zero_columns, (*count + 1) * sizeof(int));
                zero_columns = temp;
                zero_columns[*count] = j;
                (*count)++;
                break;
            }
        }
    }
    return zero_columns;
}

void removeColumns(int** matrix, int rows, int* cols, int* zero_columns, int zero_count) {
    if (zero_count == 0) return;

    int new_col = 0;

    for (int j = 0; j < *cols; j++) {
        bool is_zero_column = false;
        for (int k = 0; k < zero_count; k++) {
            if (j == zero_columns[k]) {
                is_zero_column = true;
                break;
            }
        }

        if (!is_zero_column) {
            if (new_col != j) {
                for (int i = 0; i < rows; i++) {
                    matrix[i][new_col] = matrix[i][j];
                }
            }
            new_col++;
        }
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)realloc(matrix[i], new_col * sizeof(int));
        if (!matrix[i] && new_col > 0) {
            std::cout << "Ошибка realloc!" << std::endl;
            return;
        }
    }
    *cols = new_col;
}

void point1() {
    int** matrix = (int**)calloc(2, sizeof(int*));

    for (int i = 0; i < 2; i++) {
        matrix[i] = (int*)calloc(2, sizeof(int));
        if (!matrix[i]) {
            std::cout << "Ошибка выделения памяти!" << std::endl;
            for (int j = 0; j < i; j++) free(matrix[j]);
            free(matrix);
            return;
        }
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

    int rows = 2 + chA;
    int cols = 2 + chB;

    matrix = (int**)realloc(matrix, rows * sizeof(int*));
    if (!matrix) {
        std::cout << "Ошибка realloc!" << std::endl;
        return;
    }

    for (int i = 2; i < rows; i++) {
        matrix[i] = (int*)calloc(cols, sizeof(int));
        if (!matrix[i]) {
            std::cout << "Ошибка выделения памяти!" << std::endl;
            for (int j = 0; j < i; j++) free(matrix[j]);
            free(matrix);
            return;
        }
    }

    for (int i = 0; i < 2; i++) {
        matrix[i] = (int*)realloc(matrix[i], cols * sizeof(int));
        if (!matrix[i]) {
            std::cout << "Ошибка realloc!" << std::endl;
            for (int j = 0; j < rows; j++) {
                if (j < i || j >= 2) free(matrix[j]);
            }
            free(matrix);
            return;
        }
        for (int j = 2; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < 2 && j < 2) {
                continue;
            }
            else {
                matrix[i][j] = (i - 1) * chC + (j - 1) * chD;
            }
        }
    }
    std::cout << "Исходная матрица (" << rows << "x" << cols << "):" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "      ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    int zero_count;
    int* zero_columns = getZeroColumns(matrix, rows, cols, &zero_count);

    if (!zero_columns && zero_count > 0) {
        std::cout << "Ошибка при получении индексов столбцов" << std::endl;
        for (int i = 0; i < rows; i++) free(matrix[i]);
        free(matrix);
        return;
    }

    std::cout << "Столбцы с нулями: ";
    for (int i = 0; i < zero_count; i++) {
        std::cout << zero_columns[i] << " ";
    }
    std::cout << std::endl;

    removeColumns(matrix, rows, &cols, zero_columns, zero_count);
    std::cout << "Матрица после удаления столбцов (" << rows << "x" << cols << "):" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "      ";
        }
        std::cout << std::endl;
    }
    free(zero_columns);
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
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