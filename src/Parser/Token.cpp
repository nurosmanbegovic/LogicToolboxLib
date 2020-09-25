//
// Created by infloop on 7/16/17.
//

#include "../../include/Token.h"

Token::Token(const char read){

    token_map = {
            {
                    '&',make_pair(TokenType::BINARY_OP, "AND")
            },
            {
                    '|',make_pair(TokenType::BINARY_OP, "OR")
            },
            {
                    '>',make_pair(TokenType::BINARY_OP, "IMPL")
            },
            {
                    '=',make_pair(TokenType::BINARY_OP, "EQU")
            },
            {
                    '~',make_pair(TokenType::BINARY_OP, "NAND")
            },
            {
                    '?',make_pair(TokenType::BINARY_OP, "NOR")
            },
            {
                    '+',make_pair(TokenType::BINARY_OP, "EXOR")
            },
            {
                    '!',make_pair(TokenType::UNARY_OP, "NOT")
            },
            {
                    '#',make_pair(TokenType::UNARY_OP, "NESS")
            },
            {
                    '$',make_pair(TokenType::UNARY_OP, "POSS")
            },
            {
                    '(',make_pair(TokenType::OPEN_PARENT, "(")
            },
            {
                    ')',make_pair(TokenType::CLOSE_PARENT, ")")
            }
    };

    if(read == '\000' || read == '\0' || read == '\n'){
        type = TokenType::EXPR_END;
        value = "";
        return;
    }

    if(token_map.find(read) != token_map.end()){
        type = token_map[read].first;
        value = token_map[read].second;
    } else{

        type = TokenType::LITERAL;
        value = read;

    }

}