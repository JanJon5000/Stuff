#include "Calculator_class.hpp"
Calculator::Calculator(){}

std::string Calculator::clear_addition(std::string input){
    std::string output = "";
    std::string current = "";
    int i = 0;

}

std::string Calculator::solve_equation(std::string input){
    int counter = 0;
    for(int i=0;i<input.size();i++){
        if(input[i] == '('){
            counter++;
        }
    }
    int brackets[counter][2];

    int begBrack, endBrack = 0;
    for(int i=0;i<input.size();i++){
        if(input[i] == '('){
            brackets[begBrack][0] = i;
            begBrack++;
        }else if(input[i] == ')'){
            brackets[endBrack][0] = i;
            endBrack++;
        }
    }
    
}