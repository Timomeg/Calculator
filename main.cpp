#include "calc.h"

int main(){

        std::vector<std::string>equation = LineToEquation(InputToLine());
        std::vector<std::string> polish = NormalToPolish(equation);
        std::cout << PolishCalc(polish);
        return 0;
}
