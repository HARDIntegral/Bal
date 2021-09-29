```
<for_loop>          ::= "for" "(" <assignment> ";" <expression> ";" <expression> ")" 
                    "{" <expressions> "}";
<while_loop>        ::= "while" "(" <expression> ")" "{" <expressions> "}";

<if_statement>      ::= "if" "(" <expression> ")" "{" <expressions> "}";
<elif_statement>    ::= "elif" "(" <expression> ")" "{" <expressions> "}";
<else_statement>    ::= "else" "{" <expressions> "}";
```