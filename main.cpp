
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

int main(int argc, char *argv[]){

    if(argc < 2){

        std::cout << "Error: Not enough arguments.\n"
        << "Please use 'acalc -h' for help.\n";

        return 1;
    }

    std::string flag = argv[1];

    if(flag == "-h"){

        std::cout << "Usage:\n"
        << "  acalc <num1> <operator> <num2>\n"
        << "  acalc <num1> sqrt\n"
        << "  acalc -h\n"
        << "  acalc -v\n"
        << "  acalc -o\n";

        return 0;
    }

    else if(flag == "-v"){

        if(argc != 2){

            std::cout << "Error: The version flag does not accept additional arguments.\n";

            return 1;
        }

        std::cout << "acalc v1.0\n";

        return 0;
    }

    else if(flag == "-o"){

        if(argc != 2){

            std::cout << "Error: The explanation flag does not accept additional arguments.\n";

            return 1;
        }

        std::cout << "1. + > usage: acalc <num1> + <num2>\n"
        << "2. - > usage: acalc <num1> - <num2>\n"
        << "3. x > or '*' usage: acalc <num1> x <num2>\n"
        << "4. / > usage: acalc <num1> / <num2>\n"
        << "5. % > or perc usage: acalc <num1> % <num2>\n"
        << "   Note: percentage results are always 'num1 of num2'.\n"
        << "6. mod > usage: acalc <num1> mod <num2>\n"
        << "7. sqrt > usage: acalc <num1> sqrt\n";

        return 0;
    }

    if(argc < 3){

        std::cout << "Error: Please provide an operator.\n"
        << "Please use 'acalc -h' or 'acalc -o' for help.\n";

        return 1;
    }

    if(argc > 4){

        std::cout << "Error: Too many arguments were provided.\n"
        << "Please use 'acalc -h' for the correct usage.\n";

        return 1;
    }

    float a;

    try{

        std::size_t pos;
        std::string number = argv[1];

        a = std::stof(number, &pos);

        if(pos != number.length()){

            std::cout << "Error: '" << argv[1]
            << "' contains invalid trailing characters.\n";

            return 1;
        }
    }
    catch(const std::invalid_argument&){

        std::cout << "Error: '" << argv[1] << "' is not a valid number.\n";

        return 1;
    }
    catch(const std::out_of_range&){

        std::cout << "Error: '" << argv[1]
        << "' is outside the supported number range.\n";

        return 1;
    }

    std::string op = argv[2];

    if(op == "sqrt"){

        if(argc != 3){

            std::cout << "Error: The sqrt operation requires exactly one number.\n";

            return 1;
        }

        if(a < 0){

            std::cout << "Error: Square roots of negative numbers are not supported.\n";

            return 1;
        }

        double result = std::sqrt(static_cast<double>(a));

        if(!std::isfinite(result)){

            std::cout << "Error: The calculation produced an invalid result.\n";

            return 1;
        }

        std::cout << result << "\n";

        return 0;
    }

    if(argc < 4){

        std::cout << "Error: Please provide a second number.\n"
        << "Please use 'acalc -h' for help.\n";

        return 1;
    }

    float b;

    try{

        std::size_t pos;
        std::string number = argv[3];

        b = std::stof(number, &pos);

        if(pos != number.length()){

            std::cout << "Error: '" << argv[3]
            << "' contains invalid trailing characters.\n";

            return 1;
        }
    }
    catch(const std::invalid_argument&){

        std::cout << "Error: '" << argv[3] << "' is not a valid number.\n";

        return 1;
    }
    catch(const std::out_of_range&){

        std::cout << "Error: '" << argv[3]
        << "' is outside the supported number range.\n";

        return 1;
    }

    float res;

    if(op == "+"){

        res = a + b;
        std::cout << res << "\n";
    }

    else if(op == "-"){

        res = a - b;
        std::cout << res << "\n";
    }

    else if(op == "x" || op == "*"){

        res = a * b;
        std::cout << res << "\n";
    }

    else if(op == "/"){

        if(b == 0){

            std::cout << "Error: Division by zero is not allowed.\n";

            return 1;
        }

        res = a / b;
        std::cout << res << "\n";
    }

    else if(op == "perc" || op == "%"){

        res = (b / 100) * a;
        std::cout << res << "\n";
    }

    else if(op == "mod"){

        int int_a = static_cast<int>(a);
        int int_b = static_cast<int>(b);

        if(int_b == 0){

            std::cout << "Error: Modulo by zero is not allowed.\n";

            return 1;
        }

        res = int_a % int_b;
        std::cout << res << "\n";
    }

    else{

        std::cout << "Error: '" << op
        << "' is not a recognized operator.\n"
        << "Please use 'acalc -o' to see the available operators.\n";

        return 1;
    }

    if(!std::isfinite(res)){

        std::cout << "Error: The calculation produced an invalid result.\n";

        return 1;
    }

    return 0;
}

