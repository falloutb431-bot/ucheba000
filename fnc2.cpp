#include <iostream>
#include <string>
#include <cstdint>  // для uint64_t


uint64_t real_string_hash(const std::string& str, uint64_t p, uint64_t n) {
    if (n == 0) return 0;  

    uint64_t hash = 0;
    uint64_t power = 1;   // p^0 = 1

    for (char c : str) {
        uint64_t code = static_cast<unsigned char>(c);
        hash = (hash + code * power) % n;
        power = (power * p) % n;  
    }

    return hash;
}

int main() {
    uint64_t p, n;

    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;
    std::cin.ignore();  

    std::string input;
    while (true) {
        std::cout << "Введите строку: ";
        if (!std::getline(std::cin, input)) break;

        uint64_t h = real_string_hash(input, p, n);
        std::cout << "Хэш строки: " << h << "\n";

        if (input == "exit") break;
    }

    return 0;
}