%{
#include "y.tab.h"    
%}

%%
[a-zA-Z][a-zA-Z0-9]*    {return VAR;}
[ \t\n] ;
.   {return INVALID;}


%%