#include <iostream>

template<typename T, size_t N, size_t M>
class Matrix{
private:
    T matrix[N][M] = {0};
public:
    Matrix() = default;
    Matrix(const Matrix<T, N, M>& other) {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    Matrix<T, N, M>& operator = (const Matrix<T, N, M>& other){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
        return *this;
    }

    Matrix<T, N, M> operator + (const Matrix<T, N, M>& other) const {
        Matrix<T, N, M> result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix<T, N, M>& operator +=(const Matrix<T, N, M>& other){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] += other.matrix[i][j];
            }
        }
        return *this;
    }

    Matrix<T, N, M> operator * (const Matrix<T, N, M>& other) const {
        Matrix<T, N, M> result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M ; k++){
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }

    Matrix<T, N, M> operator *= (const Matrix<T, N, M>& other){
        Matrix<T, N, M> temp;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                for (int k = 0; k < N; k++){
                    temp.matrix[i][j] += (matrix[i][k] * other.matrix[k][j]);
                }
            }
        }
        *this = temp;

    return *this;
    }

    Matrix<T, N, M>& operator++() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j]++;
            }
        }
        return *this;
    }

    T& operator()(int i, int j){
        return matrix[i][j];
    }

    double det() {
        if (N == M){
            switch (N) {
                case 1:
                    return matrix[0][0];
                case 2:
                    return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
                case 3:
                    return (matrix[0][0] * matrix[1][1] * matrix[2][2]) +
                            (matrix[0][1] * matrix[1][2] * matrix[2][0]) +
                            (matrix[0][2] * matrix[1][0] * matrix[2][1]) -
                            (matrix[0][2] * matrix[1][1] * matrix[2][0]) -
                            (matrix[0][0] * matrix[1][2] * matrix[2][1]) -
                            (matrix[0][1] * matrix[1][0] * matrix[2][2]);
            }
        }
        else{
            abort();
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T, N, M>& other) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                os << other.matrix[i][j] << ' ';
            }
            os << '\n';
        }
    }

    friend std::istream& operator>>(std::istream& is, Matrix<T, N, M>& other) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                is >> other.matrix[i][j];
            }
        }
        return is;
    }
};



int main() {
    Matrix<int, 3, 3> m1;
    std::cin >> m1;
    std::cout << m1;

    Matrix<int, 3, 3> m2;
    std::cin >> m2;
    std::cout << m2;

    Matrix<int, 3, 3> m3;
    //m3 = m1 + m2;
    //std::cout << m3 << std::endl;

    m3 = m1 * m2;
    //std::cout << m3 << std::endl;

    std::cout << m2.det() << std::endl;

}
