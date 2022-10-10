#include <iostream>
#include <string>

bool isUnsigned(const std::string &expression, size_t i)
{
    if(!isdigit(expression[i])){
        return false;
    }
    else if(expression[i + 1] == '\0'){
        return true;
    }
    return isUnsigned(expression, ++i);
}

bool isId(const std::string &expression, size_t i, size_t y)
{
    const std::string word = {"abcde"};
    if(expression[i] == word[y] && expression[i + 1] == '\0'){
        return true;
    }
    else if(expression[i] == word[y]){
        return isId(expression, ++i, 0);
    }
    else if(expression[i] != word[y] && word[y + 1] == '\0'){
        return false;
    }
    return isId(expression, i, ++y);
}

bool isMultiplier(const std::string &expression)
{
    if(isUnsigned(expression,0) || isId(expression,0, 0)){
        return true;
    }

    return false;
}
size_t findMultSign (const std::string &expression, size_t i) {

    if (expression[i] == '*') {
        return i;
    }
    else if (expression[i + 1] == '\0') {
        return 0;
    }

    return findMultSign(expression, ++i);
}

size_t findIncSign (const std::string &expression, size_t i)
{
    if(expression[i] == '+' || expression[i] == '-'){
        return i;
    }
    else if(expression[i + 1] == '\0'){
        return 0;
    }

    return findIncSign(expression, ++i);
}

std::string splitStrings(const std::string &expression, size_t begin, size_t end)
{
    size_t size = end - begin;
    std::string array;
    array.resize(size);
    for(size_t j = begin,i = 0; j < end; j++, i++){
        array[i] = expression[j];
    }
    return array;
}

bool isTerm(const std::string &expression)
{
    size_t result = findMultSign(expression,0);
    if(result != 0){

        if(isMultiplier(splitStrings(expression,0, result))
        && isTerm(splitStrings(expression,result + 1, expression.size()))){
            return true;
        }

    }
    else{

        if(isMultiplier(expression)){
            return true;
        }
    }
    return false;
}

bool isExpression(const std::string &expression)
{
    if(expression == ""){
        return false;
    }
    size_t result = findIncSign(expression, 0);

    if(result != 0){

        if(isTerm(splitStrings(expression,0, result))
           && isExpression(splitStrings(expression,result + 1, expression.size()))){
            return true;
        }

    }
    else
    {
        if(isTerm(expression) == 1){
            return true;
        }
    }
    return false;
}

void doInit(std::string expressions[11])
{
    expressions[0] = "d()cd";
    expressions[1] = "12349+abcd";
    expressions[2] = "ghjklf";
    expressions[3] = "abcde";
    expressions[4] = "";
    expressions[5] = "a+c";
    expressions[6] = "12*09+ab)";
    expressions[7] = "a";
    expressions[8] = "12+va";
    expressions[9] = "ab12ba";
    expressions[10] = "da";
}

int main() {
    std::string expressions[11];

    doInit(expressions);

    for(size_t i = 0 ; i < 11; ++i) {
       if (isExpression(expressions[i]) == 1) {
           std::cout << "[" << i << "]" <<" - statement is true" << std::endl;
       }
       else {
           std::cout << "[" << i << "]" << " - statement is false" << std::endl;
       }
    }
    return 0;
}
