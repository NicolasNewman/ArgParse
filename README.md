# ArgParse

Argument parsing library for arduino.

The library functions by splitting a string in the format `FUNC_NAME(ARG1,ARG2,...)` into an `Args` struct containing:

```c
struct Args
{
    unsigned int argc;
    char **argv;
};
```

Note that arguments are allocated on the heap and must be freed, either manually or with `free_args(Args args)`.

## Functions

```c
Args parse_args(String cmd); // Parse a string in the form `FUNC_NAME(ARG1,ARG2,...)` into an `Args` struct
void free_args(Args args); // Free the arguments from a `Args`` struct
```

## Example

```c
String cmd = "SET_COLOR(0,255,0)";
Args args = parse_args(cmd); // argc=4, argv=["SET_COLOR", "0", "255", "0"]
for (int i = 0; i < args.argc; i++) {
    Serial.println(args.argv[i]);
}
free_args(args);
```