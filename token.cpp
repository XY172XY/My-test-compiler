#include "lexer/lexer.h"
#include<iostream>
using namespace pi::lexer;

int main(){
    auto lexer = new Lexer("./../code.pi");
    Json tokens;
    while(true){
        auto token = lexer->next_token();
        token.show();
        tokens.append(token.json());
        if(token.type() == Token::TOKEN_EOF) {
            break;
        }
    }

    Json json;
    json["tokens"] = tokens;

    ofstream ofs("./../token.json");
    ofs<<json.str();
    ofs.close();

    return 0;
}
