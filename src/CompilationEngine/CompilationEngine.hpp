#include <iostream>
#include <vector>
#include <regex>
#include <numeric>
#include <string>
#include <algorithm>
#include <cctype>
#include "../JackTokenizer/JackTokenizer.hpp"
#include "../SymbolTable/SymbolTable.hpp"


static CODE validVarTypes = {"int", "char", "boolean"};
static CODE validSubroutineTypes = {"void", "int", "boolean", "char"};
static CODE validStatementInitials = {"var", "let", "do", "if", "else", "while", "return"};
static std::vector<char> validPositiveInt = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
static std::vector<std::string> validNegativeInt = {"-1", "-2", "-3", "-4", "-5", "6", "7", "8", "9"};

class CompilationEngine {
public:
    explicit CompilationEngine(std::string fName);
    CODE vmCode = {};

private:
    bool insideClass = false;
    bool insideSubroutine = false;
    bool insideWhile = false;
    bool insideIf = false;

private:
    std::map<std::string, std::string> reservedValues = {
            {"true", "-1"},
            {"false", "0"}
    };

private:
    CODE tempTokens;

private:
    CODE m_code;
    SymbolTable classSymbolTable;
    SymbolTable subroutineSymbolTable;
    int m_currentLine;

public:
    void compileDo();
    void compileLet();
    void compileClass();
    void compileReturn();
    void compileVarDec();
    void compileStatement();
    void compileSubroutine();
    void compileParameterList();
    void compileSubroutineBody();
    void compileExpressionList(std::string expressions);
    static bool isNumber(char &ch);
    std::string getNthToken(int n);
    void compileTerm(std::string term);
    void compileClassVarDec(CODE tokens);
    static CODE removeBrackets(CODE code);
    static bool isNumber(std::string &str);
    void callSubroutine(std::string line);
    void compileExpression(std::string &expr);
    static bool isValidName(std::string name);
    static std::string clearName(std::string name);
    static CODE getExpressionVector(std::string expr);
    static long long countParameters(CODE parameterList);
    std::string prioritizeBrackets(std::string& expression);
    static std::string removeBrackets(const std::string& str);
    std::vector<std::string> splitString(std::string &str, char delim);
    static char isCharacterPresent(const std::string &str, const std::string &str2);
};