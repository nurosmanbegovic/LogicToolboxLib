//
// Created by infloop on 7/16/17.
//

#ifndef LOGICTOOLBOX_TOKEN_H
#define LOGICTOOLBOX_TOKEN_H

#include <string>
#include <map>
#include <utility>

using namespace std;

enum TokenType{
    OPEN_PARENT,
    CLOSE_PARENT,
    UNARY_OP,
    BINARY_OP,
    BINARY_OP_TEMP,
    LITERAL,
    EXPR_END
};

struct Token {

    map<char,pair<TokenType,string>> token_map = {
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
            },
            {
                    '*',make_pair(TokenType::UNARY_OP, "NEXT")
            },
            {
                    '@',make_pair(TokenType::UNARY_OP, "ALL")
            },
            {
                    '<',make_pair(TokenType::UNARY_OP, "SOME")
            },
            {
                    '%',make_pair(TokenType::BINARY_OP_TEMP, "UNTIL")
            },
            {
                    '}',make_pair(TokenType::BINARY_OP_TEMP, "UNLESS")
            }
            
    };

    TokenType type;
    string value;

    Token(const char read);


};



#endif //LOGICTOOLBOX_TOKEN_H
