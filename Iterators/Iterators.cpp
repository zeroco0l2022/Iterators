// Iterators.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <stdexcept>

// Определение класса ConstForwardVectorIterator
template <typename T>
class ConstForwardVectorIterator {
private:
    const std::vector<T>& _vec;  // Reference to the vector
    size_t _index;                // Current index in the vector

public:
    // Конструктор
    ConstForwardVectorIterator(const std::vector<T>& vec, const size_t index = 0) : _vec(vec), _index(index) {}

    // Оператор разыменования
    const T& operator*() const {
        return _vec[_index];
    }

    // Оператор инкремента
    ConstForwardVectorIterator& operator++() {
        ++_index;
        return *this;
    }

    // Оператор инкремента с параметром
    ConstForwardVectorIterator operator++(int) {
        ConstForwardVectorIterator temp = *this;
        ++_index;
        return temp;
    }

    // Оператор сравнения
    bool operator!=(const ConstForwardVectorIterator& other) const {
        return _index != other._index;
    }
};

// Пример использования
int main() {
    const std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Использование for-цикла с ConstForwardVectorIterator
    for (ConstForwardVectorIterator<int> it(numbers); it != ConstForwardVectorIterator<int>(numbers, numbers.size()); ++it) {
        std::cout << *it << " ";  // Вывод элементов вектора
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
