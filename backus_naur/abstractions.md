```
<function>          ::= "func" <identifier> "()" "=" <type> "{" <expressions> "}"
                    |   "func" <identifier> "(" <parameters> ")" "=" <type> "{" <expressions> "}"
                    ;

<typedef>           ::= "typedef" <struct>
                    |   "typedef" <enum>
                    |   "int"
                    |   "char"
                    |   "float"
                    |   "double"
                    |   "String"
                    ;

<struct>            ::= "struct" <identifier> "{" <expressions> "}";
    
<enum>              ::= "enum" <identifier> "{" <expressions> "}";
```