%{
    #include "AstNodeDefinition.h"
    void yyerror(char *);
    int yylex(void);
%}

%union{
    AstNode* node;
}

%token H1 H2 H3 H4 H5 H6
%token NEWLINE
%token<node> TEXT
%type<node> HEADING
%type<node> LINES
%type<node> LINE
%%

DOCUMENT: LINES { compile($1); }
    ;

LINES : LINE { $$ = documentAddChild(createDocument(), $1); }
    | LINES LINE { $$ = documentAddChild($1, $2); }
    ;

LINE: NEWLINE { $$ = NULL; }
    | HEADING NEWLINE { $$ = $1; }
    | TEXT NEWLINE { $$ = createParagraph($1); }
    ;

HEADING: H1 TEXT { $$ = createHeading(1, $2); }
    | H2 TEXT { $$ = createHeading(2, $2); }
    | H3 TEXT { $$ = createHeading(3, $2); }
    | H4 TEXT { $$ = createHeading(4, $2); }
    | H5 TEXT { $$ = createHeading(5, $2); }
    | H6 TEXT { $$ = createHeading(6, $2); }
    ;


%%



