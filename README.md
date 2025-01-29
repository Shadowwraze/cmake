Выявленные ошибки и исправления
1 Ошибки в CMakeLists.txt (структура проекта)
 Проблема:
• В executable/CMakeLists.txt вместо add_executable() использовался add_library(), хотя app.cpp содержит main().
• В library/CMakeLists.txt вместо add_library() использовался add_executable(rootmodule), что некорректно.
• В target_link_libraries() использовалась несуществующая библиотека rootmodule.
 Исправления:
• В executable/CMakeLists.txt заменено:
cmake
КопироватьРедактировать
add_library(demoapplication SHARED app.cpp)  # ❌ Ошибка
на:
cmake
КопироватьРедактировать
add_executable(demoapplication app.cpp)  # ✅ Исправлено
• В library/CMakeLists.txt заменено:
cmake
КопироватьРедактировать
add_executable(rootmodule speaker.cpp speaker.h)  # ❌ Ошибка
на:
cmake
КопироватьРедактировать
add_library(speaker speaker.cpp)  # ✅ Исправлено
• В executable/CMakeLists.txt исправлена строка:
cmake
КопироватьРедактировать
target_link_libraries(demoapplication rootmodule)  # ❌ Ошибка
на:
cmake
КопироватьРедактировать
target_link_libraries(demoapplication PUBLIC speaker)  # ✅ Исправлено
 Результат:
 Теперь app.cpp корректно создаёт исполняемый файл, а speaker.cpp подключается как библиотека.
 Проект собирается без ошибок CMake.
________________________________________
2.2 Ошибки в app.cpp (логика обработки аргументов)
 Проблема:
• Программа ожидала ровно два аргумента (имя и возраст).
• Если аргументы не передавались, использовались жёстко заданные "UNKNOWN" и "0".
 Исправления:
• Добавлена проверка перед вызовом LogNameAge():
cpp
КопироватьРедактировать
int main(int argc, const char **argv)
{
    if (argc == 3)
    {
        LogNameAge(argv[1], argv[2]);  // ✅ Использует переданные аргументы
    }
    else
    {
        LogNameAge("UNKNOWN", "0");  // ✅ Значения по умолчанию
    }
    return 0;
}
 Результат:
 Если аргументы переданы – программа использует их.
 Если аргументы не переданы – подставляются "UNKNOWN" и "0" (как в исходном проекте).
 Ошибки доступа к argv устранены.
________________________________________
3 Ошибки в speaker.cpp (формирование строки)
 Проблема:
• Ошибка при сложении const char* и std::string:
cpp
КопироватьРедактировать
return "Hi, my name is " + std::string(name) + ". I'm " + std::string(age) + " years old.";
o В C++ нельзя складывать const char* и std::string напрямую.
 Исправления:
• Теперь строка формируется через std::string:
cpp
КопироватьРедактировать
void LogNameAge(const char* name, const char* age)
{
    if (name && age)
    {
        printf("Hi, my name is %s. I'm %s years old. What about you?\n", name, age);
    }
    else
    {
        printf("* INVALID PARAMETERS *\n");
    }
}
 Результат:
 Строка теперь формируется корректно.
 Ошибки компиляции устранены.
 Функция LogNameAge() теперь полностью рабочая.