#include <iostream>
#include <string>


long long simple_string_hash(const std::string& str) {
    long long hash = 0;
    for (char c : str) {
        hash += static_cast<unsigned char>(c);  
    }
    return hash;
}

int main() {
    std::string input;

    while (true) {
        std::cout << "Введите строку (или 'exit' для завершения): ";
        if (!std::getline(std::cin, input)) {
          
            break;
        }

        long long h = simple_string_hash(input);
        std::cout << "Хэш строки: " << h << "\n";

        if (input == "exit") {
            break;
        }
    }

    return 0;
}