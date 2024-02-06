
#include <stdio.h>
#include <stdlib.h>
#include "AstNodeDefinition.h"
#include "parser.h"
typedef struct {
    FILE *input;
    FILE *output;
} IOConfig;

IOConfig IOConfigBegin(int argc, char **argv) {
    if (argc == 1) {
        return (IOConfig) {stdin, stdout};
    }
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
        exit(1);
    }
    FILE *input = freopen(argv[1], "r", stdin);
    FILE *output = freopen(argv[2], "w", stdout);
    return (IOConfig) {input, output};
}

void IOConfigEnd(IOConfig config) {
    if (config.input != stdin) {
        fclose(config.input);
    }
    fclose(config.input);
    if (config.output != stdout) {
        fclose(config.output);
    }
    fclose(config.output);
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(int argc, char **argv) {
    IOConfig config = IOConfigBegin(argc, argv);
    yyparse();
    IOConfigEnd(config);
    return 0;
}
