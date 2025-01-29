#include "../library/speaker.h"

int main(int argc, const char **argv)
{
    if (argc == 3)
    {
        LogNameAge(argv[1], argv[2]); // Вызываем правильную функцию
        return 0;
    }
    else
    {
        LogNameAge("UNKNOWN", "0"); // Корректный вызов для некорректных параметров
        return argc;
    }
}