#include "parse.h"

Expression::Expression(std::string token) : token(token) {}
Expression::Expression(std::string token, Expression a) : token(token), args{ a } {}
Expression::Expression(std::string token, Expression a, Expression b) : token(token), args{ a, b } {}

  
Parser::Parser(const char* input) : input(input) {}

std::string Parser::parse_token() {
    while (std::isspace(*input)) ++input;

    if (std::isdigit(*input)) {
        std::string number;
        while (std::isdigit(*input) || *input == '.') number.push_back(*input++);
        return number;
    }

    static const std::string tokens[] =
    { "+", "-", "**", "*", "/", "mod", "abs", "sin", "cos", "(", ")" };
    for (auto& t : tokens) {
        if (std::strncmp(input, t.c_str(), t.size()) == 0) {
            input += t.size();
            return t;
        }
    }

    return "";
}

Expression Parser::parse_simple_expression() {
    auto token = parse_token();
    if (token.empty()) throw std::runtime_error("Invalid input");

    if (token == "(") {
        auto result = parse();
        if (parse_token() != ")") throw std::runtime_error("Expected ')'");
        return result;
    }

    if (std::isdigit(token[0]))
        return Expression(token);

    return Expression(token, parse_simple_expression());
}

int get_priority(const std::string& binary_op) {
    if (binary_op == "+") return 1;
    if (binary_op == "-") return 1;
    if (binary_op == "*") return 2;
    if (binary_op == "/") return 2;
    if (binary_op == "mod") return 2;
    if (binary_op == "**") return 3;
    return 0;
}

Expression Parser::parse_binary_expression(int min_priority) {
    auto left_expr = parse_simple_expression();

    for (;;) {
        auto op = parse_token();
        auto priority = get_priority(op);
        if (priority <= min_priority) {
            input -= op.size();
            return left_expr;
        }

        auto right_expr = parse_binary_expression(priority);
        left_expr = Expression(op, left_expr, right_expr);
    }
}

Expression Parser::parse() {
    return parse_binary_expression(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double eval(const Expression& e) {
    switch (e.args.size()) {
    case 2: {
        auto a = eval(e.args[0]);
        auto b = eval(e.args[1]);
        if (e.token == "+") return a + b;
        if (e.token == "-") return a - b;
        if (e.token == "*") return a * b;
        if (e.token == "/") return a / b;
        if (e.token == "**") return pow(a, b);
        if (e.token == "mod") return (int)a % (int)b;
        throw std::runtime_error("Unknown binary operator");
    }

    case 1: {
        auto a = eval(e.args[0]);
        if (e.token == "+") return +a;
        if (e.token == "-") return -a;
        if (e.token == "abs") return abs(a);
        if (e.token == "sin") return sin(a);
        if (e.token == "cos") return cos(a);
        throw std::runtime_error("Unknown unary operator");
    }

    case 0:
        return strtod(e.token.c_str(), nullptr);
    }

    throw std::runtime_error("Unknown expression type");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool replace_and_calc(std::string& str, int x, int y) {
    size_t posX = str.find('x');
    if (posX != std::string::npos) {
        str.replace(posX, 1, std::to_string(x));
    }

    size_t posY = str.find('y');
    if (posY != std::string::npos) {
        str.replace(posY, 1, std::to_string(y));
    }

    size_t lessThanPos = str.find('<');
    size_t greaterThanPos = str.find('>');
    std::string substring;
    bool res = false;
    if (lessThanPos != std::string::npos) {
        substring = str.substr(0, lessThanPos);
        int num = std::stoi(str.substr(lessThanPos + 1));
        const int length = substring.length();
        char* char_array = new char[length + 1];
        strcpy(char_array, substring.c_str());
        Parser p(char_array);
        auto result = eval(p.parse());
        res = (result < num);
        delete[] char_array;
    }
    else if (greaterThanPos != std::string::npos) {
        substring = str.substr(0, greaterThanPos);
        int num = std::stoi(str.substr(greaterThanPos + 1));
        const int length = substring.length();
        char* char_array = new char[length + 1];
        strcpy(char_array, substring.c_str());
        Parser p(char_array);
        auto result = eval(p.parse());
        res = (result > num);
        delete[] char_array;
    }
    return res;
}

bool calc_all_expressions(std::vector <std::string> expressions, int x, int y) {
    bool res = true;
    for (auto it = expressions.begin(); it != expressions.end(); it++) {
        if ((*it).length() != 0) {
            res = res && replace_and_calc(*it, x, y);
        }
    }
    return res;
}
