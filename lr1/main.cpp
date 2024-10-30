#include <iostream>
#include <string>
#include <fstream>
#include <cmath>  // для математических функций
using namespace std;

// Функция для проверки операций и генерации соответствующего кода
string generateOperationCode(const string& operation, const string& type1, const string& type2) {
    if (operation == "+") {
        return "std::cout << \"Result (" + type1 + " + " + type2 + "): \" << (var1 + var2) << std::endl;";
    } else if (operation == "-") {
        return "std::cout << \"Result (" + type1 + " - " + type2 + "): \" << (var1 - var2) << std::endl;";
    } else if (operation == "*") {
        return "std::cout << \"Result (" + type1 + " * " + type2 + "): \" << (var1 * var2) << std::endl;";
    } else if (operation == "/") {
        return "if (var2 != 0) { std::cout << \"Result (" + type1 + " / " + type2 + "): \" << (var1 / var2) << std::endl; } else { std::cout << \"Error: Division by zero!\" << std::endl; }";
    } else if (operation == "//") {
        if (type1 == "int" && type2 == "int") {
            return "if (var2 != 0) { std::cout << \"Result (" + type1 + " // " + type2 + "): \" << (var1 / var2) << std::endl; } else { std::cout << \"Error: Division by zero!\" << std::endl; }";
        } else {
            return "std::cout << \"Warning: Unsupported operation '//' for non-integer types.\" << std::endl;";
        }
    } else if (operation == "%") {
        if (type1 == "int" && type2 == "int") {
            return "if (var2 != 0) { std::cout << \"Result (" + type1 + " % " + type2 + "): \" << (var1 % var2) << std::endl; } else { std::cout << \"Error: Division by zero!\" << std::endl; }";
        } else {
            return "std::cout << \"Warning: Unsupported operation '%' for non-integer types.\" << std::endl;";
        }
    } else if (operation == "**") {
        return "std::cout << \"Result (" + type1 + " ** " + type2 + "): \" << pow(var1, var2) << std::endl;";
    } else {
        return "std::cout << \"Warning: Unsupported operation '" + operation + "' skipped.\" << std::endl;";
    }
}

// Функция для генерации кода
void generateFunction(const string& type1, const string& type2, const string& val1, const string& val2, const string& operationsFile) {
    ifstream fin(operationsFile);
    ofstream fout("func_1.cpp");

    fout << "#include <iostream>" << endl;
    fout << "#include <cmath>" << endl;  // для возведения в степень
    fout << "int main() {" << endl;
    fout << "    " << type1 << " var1 = " << val1 << ";" << endl;
    fout << "    " << type2 << " var2 = " << val2 << ";" << endl;

    fout << "    std::cout << \"===========================================\" << std::endl;" << endl;
    fout << "    std::cout << \"var1 (" << type1 << "): \" << var1 << std::endl;" << endl;
    fout << "    std::cout << \"var2 (" << type2 << "): \" << var2 << std::endl;" << endl;
    fout << "    std::cout << \"===========================================\" << std::endl;" << endl;

    string operation;
    while (getline(fin, operation)) {
        fout << "    " << generateOperationCode(operation, type1, type2) << endl;
    }

    fout << "    std::cout << \"===========================================\" << std::endl;" << endl;
    fout << "    return 0;" << endl;
    fout << "}" << endl;

    fout.close();
    fin.close();
}

// Функция для проверки поддерживаемых типов
bool isTypeSupported(const string& type) {
    // Поддерживаемые типы
    return (type == "int" || type == "float" || type == "double" || type == "long long int");
}

int main() {
    string type1, type2, val1, val2;
    
    cout << "Enter first type: ";
    getline(cin, type1);  // Ввод типа с пробелами
    cout << "Enter second type: ";
    getline(cin, type2);  // Ввод типа с пробелами

    // Проверка типов
    if (!isTypeSupported(type1)) {
        cerr << "Error: Type " << type1 << " is not supported." << endl;
        return 1;
    }
    if (!isTypeSupported(type2)) {
        cerr << "Error: Type " << type2 << " is not supported." << endl;
        return 1;
    }

    // Ввод значений
    cout << "Enter value for first variable (var1): ";
    cin >> val1;
    cout << "Enter value for second variable (var2): ";
    cin >> val2;

    cout << "Generating function..." << endl;
    generateFunction(type1, type2, val1, val2, "operations.txt");
    return 0;
}
