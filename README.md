# cpp_electricity
тут должен быть проект, но он не работает :( 

для запуска проекта необходима библиотека SFML, которую можно установить командой sudo apt-get install libsfml-dev

сборка происходит с помощью утилиты cmake, так что cmake должен быть установлен: sudo apt-get install cmake

в терминале переходим в папку (пишем cd <путь к папке>), в которой хотим оставить проект

пишем: git clone github.com/Alexandra24032004/cpp_electricity

cd cpp_electricity

cmake -S. -B build -- эта команда запустит cmake и скажет ему, где расположен сам проект и в какой папке его собирать

cmake --build build -- собираем проект

build/cpp_electricity -- запуск программы

В открышемся окне справа находятся поля для системы уравнений, которые должны задавать область заполненную заряженным веществом. После нажалия "Enter", и нажатия курсором на область визуализации (правее системы уравнений) должно начатся молерование электртического поля (но этого не происходит).

При нажатии на "Пробел" должна менятся визуализация с вектроного поля на скалярное (но оно не работает)

В любой момент можно написать новых уравнений и  добавить на картинку еще фигур (но это так жк не реальзовано)
