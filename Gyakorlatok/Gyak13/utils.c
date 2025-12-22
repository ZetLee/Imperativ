#include <string.h>

#include "utils.h"

void trim_newline(char *str)
{
    str[strcspn(str, "\r\n")] = '\0';
}
