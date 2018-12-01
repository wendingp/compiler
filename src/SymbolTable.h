//
// Created by monotasker on 2018/11/29.
//

#ifndef COMPILER_SYMBOLTABLE_H
#define COMPILER_SYMBOLTABLE_H

#include <unordered_map>
#include <string>
#include <vector>

#include "utils.h"

class Symbol;

class VariableSymbol;

class ConstantSymbol;

class LocalSymbolTable;

typedef std::unordered_map<std::string, ConstantSymbol *> ConstantTable;
typedef std::unordered_map<std::string, VariableSymbol *> VariableTable;
typedef std::unordered_map<std::string, LocalSymbolTable *> FunctionTable;

extern ConstantTable global_constant_table;
extern VariableTable global_variable_table;
extern FunctionTable function_table;

/* SymbolType 枚举类型与 symbol_type_strs 一一对应 */
enum SymbolType {
    UNKNOWN_SYMBOL_TYPE, INT_SYMBOL_TYPE, CHAR_SYMBOL_TYPE, VOID_SYMBOL_TYPE,
};

static std::string symbol_type_strs[] = {"Unknown symbol type", "int", "char", "void"};

class Symbol {
public:
    Symbol(const std::string &name, SymbolType symbol_type);
    
    std::string get_name();
    
    SymbolType get_symbol_type();

private:
    std::string name;
    SymbolType symbol_type = UNKNOWN_SYMBOL_TYPE;
};

class VariableSymbol : public Symbol {
public:
    VariableSymbol(const std::string &name, SymbolType symbol_type, int length);
    
    int get_length();
    
    bool is_array();

private:
    int length;
};

class ConstantSymbol : public Symbol {
public:
    ConstantSymbol(const std::string &name, SymbolType symbol_type, int value);
    
    int get_value();

private:
    int value;
};

class LocalSymbolTable : public Symbol {
public:
    LocalSymbolTable(const std::string &name, SymbolType symbol_type);
    
    VariableTable parameter_table;
    ConstantTable constant_table;
    VariableTable variable_table;
    
    std::vector<SymbolType> parameter_types;
private:
};

/**
 * 编译开始时清空各符号表
 */
void init_symbol_tables();

/* --------------------------------------------------Global------------------------------------------------------------*/

bool is_function(const std::string &function_name);

bool insert_function(const std::string &function_name, SymbolType return_type);

LocalSymbolTable *get_function(const std::string &function_name);


bool is_global_const(const std::string &const_name);

bool insert_global_const(const std::string &const_name, SymbolType symbol_type, int value);

ConstantSymbol *get_global_const(const std::string &const_name);


bool is_global_variable(const std::string &var_name);

bool insert_global_variable(const std::string &variable_name, SymbolType symbol_type, int length = 0);

VariableSymbol *get_global_variable(const std::string &variable_name);


bool is_global_symbol(const std::string &symbol_name);

bool is_non_function_global_symbol(const std::string &symbol_name);

/* ------------------------------------------------Local-------------------------------------------------------------*/

bool is_parameter(const std::string &function_name, const std::string &parameter_name);

bool insert_parameter(const std::string &function_name, const std::string &parameter_name, SymbolType symbol_type);

VariableSymbol *get_parameter(const std::string &function_name, const std::string &parameter_name);


bool is_local_const(const std::string &function_name, const std::string &const_name);

bool insert_local_const(const std::string &function_name, const std::string &const_name, SymbolType symbol_type,
                        int value);

ConstantSymbol *get_local_const(const std::string &function_name, const std::string &const_name);


bool is_local_variable(const std::string &function_name, const std::string &var_name);

bool insert_local_variable(const std::string &function_name, const std::string &variable_name, SymbolType symbol_type,
                           int length = 0);

VariableSymbol *get_local_variable(const std::string &function_name, const std::string &variable_name);


bool is_local_symbol(const std::string &function_name, const std::string &symbol_name);

bool is_valid_parameter_type(const std::string &function_name, const std::vector<SymbolType> &value_parameters);


#endif //COMPILER_SYMBOLTABLE_H
