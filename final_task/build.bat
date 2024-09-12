chcp 65001
REM Демонстрация работы программы temp_stats.
REM "Сборка программы с помощью утилиты make..."
mingw32-make
REM "Запуск программы без опций..."
call temp_stats.exe
REM "Запуск программы с опцией «-h»..."
call temp_stats.exe -h
REM "Убедитесь в наличии файла temperature_small.csv в директории с исполняемым файлом."
pause
REM "Запуск программы с указанием имени файла..."
call temp_stats.exe -f temperature_small.csv
REM Запуск программы с указанием файла и опцией выбора месяца...
call temp_stats.exe -f temperature_small.csv -m 1
call temp_stats.exe -f temperature_small.csv -m 2
call temp_stats.exe -f temperature_small.csv -m 12
REM Вызов утилиты make для удаления программы...
mingw32-make clean
REM Спасибо за внимание!
pause
: exit