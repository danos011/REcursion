#ifndef RECURSYA_HEADER_H
#define RECURSYA_HEADER_H

#endif //RECURSYA_HEADER_H
bool isUnsigned(const std::string &expression, size_t i)
bool isId(const std::string &expression, size_t i, size_t y)
bool isMultiplier(const std::string &expression)
size_t findMultSign (const std::string &expression, size_t i)
size_t findIncSign (const std::string &expression, size_t i)
std::string splitStrings(const std::string &expression, size_t begin, size_t end)
bool isTerm(const std::string &expression)
bool isExpression(const std::string &expression)
void doInit(std::string expressions[11])