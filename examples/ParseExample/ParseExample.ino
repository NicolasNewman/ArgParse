/*
This example demonstrates how to use ArgParse.

Example contributor: Nicolas Newman
*/

#include <ArgParse.h>

void setup() {
    Serial.being(9600);
    String cmd = "SET_COLOR(0,255,0)";
    Args args = parse_args(cmd);
    for (int i = 0; i < args.argc; i++) {
        Serial.println(args.argv[i]);
    }
    free_args(args);
}

void loop() {}