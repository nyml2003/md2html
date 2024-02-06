    /* calculator #1 */
%{
    #include "AstNodeDefinition.h"
    #include "parser.h"
    #include <stdlib.h>
    void yyerror(char *);
%}

%%

"#"              { return H1; }
"##"              { return H2; }
"###"             { return H3; }
"####"            { return H4; }
"#####"           { return H5; }
"######"          { return H6; }
"\n"              { return NEWLINE; }
"\r"              { return NEWLINE; }
"\r\n"            { return NEWLINE; }

[ \t]           { /* ignore whitespace */ }

[^# \t\n\r]+    {
                    yylval.node = createText(yytext);
                    return TEXT;
                }

<<EOF>>           {
                    return 0;
                }



%%

int yywrap(void) {
    return 1;
}
