#include <string>
class Calculator{
    public:
        Calculator();
        std::string solve_equation(std::string input);
        std::string clear_powers(std::string input);
        std::string clear_multiplication(std::string input);
        std::string clear_addition(std::string input);
};