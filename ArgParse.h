#ifndef ARG_PARSE_H
#define ARG_PARSE_H

#include <Arduino.h>

struct Args
{
    unsigned int argc;
    char **argv;
};

Args parse_args(String cmd);
void free_args(Args args);

#endif