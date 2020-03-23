# Matrix
 

C++ библиотекка для нахождения матрицы, обратной квадратной матрице

Интерфейс библиотеки - `struct Matrix` с полями: 
 * `rows` - количество строк матрицы
 * `cols` - количество столбцов матрицы
 * `matrix` - динмическая матрица типа `double`
 
 И методами:
 * `void create(std::string path)` - Считывание матрицы из файла
 * `int inverse_matrix(Matrix &inverse)` - Инвертирование матрицы и ее передача через переменную inverse
 * `void print_file(std::string path)` - Вывод матрицы в файл
 * `void clear()` - Очистка памяти от динамической матрицы, cols и rows присваивается 0
 
 Также в библиотеке можно найти следующие полезные функции:
 * `void status(int status)` - Печать матрицы в консоль или вывод сообщения об ошибке
 * `void print_console(Matrix *matrix)` - Вывод матрицы в консоль
 
 Остальные функции используются внутри `inverse_matrix` и подробно описаны в заголовочном файле библиотеки