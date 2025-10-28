%{
#include "y.tab.h"
%}

%%
[0-9]+  {return NUM;}
[a-zA-Z][a-zA-Z0-9]*    {return ID;}
[+\-*/()]    {return yytext[0];}
[ \t\n] {}
.   {return yytext[0];}
%%