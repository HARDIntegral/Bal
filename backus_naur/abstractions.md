
```
<function>      ::= "func" <identifier> "() {" <expressions> "}"
                |   "func" <identifier> "() =" <type> "{" <expressions> "}"
                |   "func" <identifier> "(" <parameters> ") {" <expressions> "}"
                |   "func" <identifier> "(" <parameters> ") =" <type> "{" <expressions> "}"
                ;

<typedef>       ::= "typedef" <struct>
                |   "typedef" <enum>
                ;

<struct>        ::= "struct" <identifier> "{" <expressions> "};";

<enum>          ::= "enum" <identifier> "{" <expressions> "};";
```