//
// Created by XYXYXY on 25-7-20.
//
#include "lexer/lexer.h"
using namespace pi::lexer;

#include "parser/parser.h"
using namespace pi::parser;

int main(){
    std::shared_ptr<Lexer> lexer(new Lexer("./../code.pi"));
    std::shared_ptr<Parser> parser(new Parser(lexer));

    auto program = parser->parse_program();

    cout<<"1"<<endl;
    Json json = program->json();

    cout<<json<<endl;

    ofstream ofs("./../ast.json");
    ofs<<json;
    ofs.close();
    return 0;
}