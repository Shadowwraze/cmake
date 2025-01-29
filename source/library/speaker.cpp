#include "speaker.h"
#include <stdio.h>
#include <string>

std::string FormatMessage(const char* name, const char* age)
{
    return std::string("Hi, my name is ") + name + ". I'm " + age + " years old. What about you?\n";
}

void LogNameAge(const char* name, const char* age)
{
    if (name && age)
    {
        printf("%s", FormatMessage(name, age).c_str());
    }
    else
    {
        printf("* INVALID PARAMETERS *\n");
    }
}