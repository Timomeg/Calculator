#include "calc.h"
std::string InputToLine() {
    std::string express;
    std::cout << "Enter expression:" << std::endl;
    std::getline(std::cin, express);
    return express;
}

std::vector<std::string> LineToEquation(const std::string &express) {
    int flag{};
    std::string elem;
    std::string x;
    std::string punc;
    std::vector<std::string> express_div;
    const std::string express_change =  express + '!';
    // преобразование строки инфиксной формы в массив
    for (int i{}; i <= express_change.length(); i++) {
        // обработка вводимой пользователем переменной
        if (express_change[i] == 'x' && express_change[i+1] != 'p') {
            if(flag == 0) {
                std::cout << "Enter x:" << std::endl;
                std::cin >> x;
                flag += 1;
            }
            express_div.push_back(x);
            continue;
        }
        if (isalnum(express_change[i]) || express_change[i] == '.') {
            elem += express_change[i];
        }
        // разделение строки по символам операндов и скобкам
        if (ispunct(express_change[i]) && express_change[i] != '.') {
            punc = express_change[i];
            if (express[i] == '-' && (express[i-1] == '(' || i == 0)) {
                punc = '_';
            }
            if (not elem.empty()) {
                express_div.push_back(elem);
            }
            express_div.push_back(punc);
            elem = "";
        }
    }
    express_div.pop_back();
    return express_div;
}