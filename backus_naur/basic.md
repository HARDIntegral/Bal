```
<assignment>        ::= <typedef> <identifier> ";"
                    |   <typedef> <identifier> "=" <expressions> ";"
                    |   <identifier> "=" <expressions> ";"
                    ;

<expressions>       ::= <expression> | <expressions>;
<expression>        ::= <literal> <operator> <literal>
                    |    <operator> <literal>
                    |   <literal> <operator>
                    |   <assignment>
                    |   <ctr_flw_keyword>
                    ;

<identifier>        ::= <letter> <id>;
<id>                ::= <letters> | <digits>;

<letters>           ::= <letter> | <letters>
<letter>            ::= a | b | c | ... | z
                    |   A | B | C | ... | Z
                    |   _
                    ;

<digits>            ::= <digit> | <digits>
<digit>             ::= 0 | 1 | 2 | ... | 9;

<ctr_flw_keyword>   ::= break | continue | return;
```