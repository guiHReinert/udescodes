<programa> ::= <lista_comandos>
<lista_comandos> ::= <comando> | <comando> <lista_comandos>
<comando> ::= <atribuicao>
    | <expressao>
    | <if>
    | <while>
    | <for>
    | <funcao>
    | <return>
    | <import>
<atribuicao> ::= <identificador> "=" <expressao>
<expressao> ::= <termo>
    | <expressao> "+" <termo>
    | <expressao> "-" <termo>
<termo> ::= <fator>
    | <termo> "*" <fator>
    | <termo> "/" <fator>
<fator> ::= <numero>
    | <identificador>
    | "(" <expressao> ")"
<if> ::= "if" <condicao> ":" <bloco>
    | "if" <condicao> ":" <bloco> "else" ":" <bloco>
<while> ::= "while" <condicao> ":" <bloco>
<for> ::= "for" <identificador> "in" <expressao> ":" <bloco>
<funcao> ::= "def" <identificador> "(" <parametros> ")" ":"
<bloco>
<parametros> ::= ε
    | <identificador>
    | <identificador> "," <parametros>
<return> ::= "return"
    | "return" <expressao>
<condicao> ::= <expressao> <op_relacional> <expressao>
<op_relacional> ::= "=="
    | "!="
    | "<"
    | ">"
    | "<="
    | ">="
<bloco> ::= INIDEBL <lista_comandos> FIMDEBL
<identificador> ::= NOME
<numero> ::= NUMERO

