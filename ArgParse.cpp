#include "ArgParse.h"

Args parse_args(String cmd)
{
    // number of detected arguments, including the function name
    unsigned int argc = 0;
    // starting index of the first '('
    int start = 0;
    // char array for the function name
    char *param = new char[cmd.length() + 1];
    for (int i = 0; i < cmd.length(); i++)
    {
        param[i] = cmd.charAt(i);
        if (cmd.charAt(i) == '(') // end of the function name found, mark the location and increment argc
        {
            start = i + 1;
            argc = 1;
            continue;
        }
        if (argc <= 0)
        {
            continue;
        }
        if (argc > 0) // we are now parsing the arguments, if a seperator is found, increment argc
        {
            if (cmd.charAt(i) == ',')
            {
                argc++;
            }
        }
    }
    param[cmd.length()] = '\0';

    char **argv = new char *[1 + argc];
    argv[0] = param;
    int cnt = -1;
    int size = 0;
    int pos;
    // outer loop to add each argument into argv
    for (int i = 0; i < argc; i++)
    {
        // inner loop to to parse the character of a single argument 
        for (pos = start; pos < cmd.length(); pos++)
        {
            if (cmd.charAt(pos) != ',' && cmd.charAt(pos) != ')')
            {
                size++;
            }
            else
            {
                argv[i + 1] = new char[size + 1];
                for (int j = start; j < pos; j++)
                {
                    argv[i + 1][j - start] = cmd.charAt(j);
                }
                argv[i + 1][size] = '\0';
                size = 0;
                start = pos + 1;
                break;
            }
        }
    }
    Args args;
    args.argc = argc + 1;
    args.argv = argv;
    return args;
}

void free_args(Args args)
{
    for (int i = 0; i < args.argc; i++)
    {
        delete[] args.argv[i];
    }
    delete[] args.argv;
}