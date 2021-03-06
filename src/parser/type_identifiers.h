#ifndef TYPE_IDNETIFIERS_H
#define TYPE_IDNETIFIERS_H

typedef enum lexer_types lexer_types;
enum lexer_types {
    import_statement,
    from_statement,
    struct_declaration_keyword,
    enum_definition_keyword,
    type_def_keyword,
    function_declaration_keyword,
    return_keyword,

    volatile_keyword,
    restrict_keyword,
    static_keyword,

    if_keyword,
    elif_keyword,
    else_keyword,
    for_keyword,
    while_keyword,
    break_keyword,
    continue_keyword,

    int_keyword,
    float_keyword,
    double_keyword,
    char_keyword,
    bool_keyword,
    string_keyword,
    const_keyword,
    bool_true_literal,
    bool_false_literal,
    void_type,
    nil,
    
    open_brace,
    close_brace,
    open_paren,
    close_paren,
    open_curl,
    close_curl,
    comma,
    dot,
    star,

    set_operator,
    add_operator,
    add_set_operator,
    sub_operator,
    sub_set_operator,
    mult_operator,
    mult_set_operator,
    div_operator,
    div_set_operator,
    mod_operator,
    mod_set_operator,
    inc_operator,
    dec_operator,
    ref_operator,

    is_equ_operator,
    is_not_equ_operator,
    not_operator,
    or_operator,
    and_operator,
    less_comparator,
    less_equ_comparator,
    greater_comparator,
    greater_equ_comparator,

    int_literal,
    char_literal,
    float_literal,
    double_literal,
    string_literal,

    NO_TYPE,
};

#endif // TYPE_IDNETIFIERS_H