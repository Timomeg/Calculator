#include "calc.h"

std::vector<std::string>NormalToPolish(const std::vector<std::string>& vect) {
    std::vector<std::string> equation;
    std::stack<std::string>stack;
    stack.push("!");
    for (auto elem: vect) {
        // префиксные операции записываются в стек
        if (elem == "exp" || elem == "sin" || elem == "cos" || elem == "_"
            || elem == "tg" || elem == "ctg" || elem=="(") {
            stack.push(elem);
        }
        // числа записываются в выходной массив
        if (isdigit(elem[0])) {
            equation.push_back(elem);
        }
        // обработка скобок
        if (elem == ")") {
            while(stack.top() != "(") {
                equation.push_back(stack.top());
                stack.pop();
            }
            stack.pop();
        }
        // не работает
        if (elem == "*" || elem == "/") {
            while ((stack.top() != "-") && (stack.top() != "+") && (stack.top() != "!") && (stack.top() != "(")) {
                    equation.push_back(stack.top());
                    stack.pop();
                }
            stack.push(elem);
        }
        // работает
        if (elem == "-" || elem == "+") {
            while (stack.top() != "!" && (stack.top() != "(")) {
                    equation.push_back(stack.top());
                    stack.pop();
                }
            stack.push(elem);
        }
    }
    while(stack.top() != "!") {
        equation.push_back(stack.top());
        stack.pop();
    }
    return equation;
}

double PolishCalc(const std::vector<std::string>& equation) {
    std::stack<double>stack;
    double second_op;
    double result;

    for(auto elem: equation) {
        if (isdigit(elem[0])) {
            stack.push(std::stod(elem));
        }
        if(elem == "_") {
            result = stack.top();
            stack.pop();
            stack.push(minus(result));
        }
        if (elem == "+") {
            second_op = stack.top();
            stack.pop();
            result = stack.top();
            stack.pop();
            stack.push(add(result, second_op));
        }
        if (elem == "-") {
            second_op = stack.top();
            stack.pop();
            result = stack.top();
            stack.pop();
            stack.push(subtract(result, second_op));
        }
        if (elem == "*") {
            second_op = stack.top();
            stack.pop();
            result = stack.top();
            stack.pop();
            stack.push(multiply(result, second_op));
        }
        if (elem == "/") {
            second_op = stack.top();
            stack.pop();
            result = stack.top();
            stack.pop();
            stack.push(division(result, second_op));
        }
        if (elem == "sin") {
            result = stack.top();
            stack.pop();
            stack.push(sinus(result));
        }
        if (elem == "cos") {
            result = stack.top();
            stack.pop();
            stack.push(cosine(result));
        }
        if (elem == "tg") {
            result = stack.top();
            stack.pop();
            stack.push(tangent(result));
        }
        if (elem == "ctg") {
            result = stack.top();
            stack.pop();
            stack.push(cotangent(result));
        }
        if (elem == "exp") {
            result = stack.top();
            stack.pop();
            stack.push(exponent(result));
        }
    }
    return stack.top();
}