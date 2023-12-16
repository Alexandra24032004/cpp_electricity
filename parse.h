#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstring>
#include <stdexcept>

#ifndef PARSE_H
#define PARSE_H


struct Expression {
    Expression(std::string token);
    Expression(std::string token, Expression a);
    Expression(std::string token, Expression a, Expression b);

    std::string token;
    std::vector<Expression> args;
};

class Parser {
public:
    explicit Parser(const char* input);
    Expression parse();
private:
    std::string parse_token();
    Expression parse_simple_expression();
    Expression parse_binary_expression(int min_priority);

    const char* input;
};

int get_priority(const std::string& binary_op);

double eval(const Expression& e);

bool replace_and_calc(std::string& str, int x, int y);

bool calc_all_expressions(std::vector <std::string> expressions, int x, int y);

#endif
