```
<assignment>    ::= <typedef> <identifier> ";"
                |   <typedef> <identifier> "=" <expressions> ";"
                |   <identifier> "=" <expressions> ";";

<identifier>    ::= <letter> <id>
                |   _ <id>;
<id>            ::= <letter> | <digit> | _
                |   <letter> <id>
                |   <digit> <id>
                |   _ <id>;
<letter>        ::= a | b | c | ... | z
                |   A | B | C | ... | Z;
<digit>         ::= 0 | 1 | 2 | ... | 9;
```