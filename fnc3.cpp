#include <iostream>
#include <string>
#include <cstdint>


int find_substring_light_rabin_karp(const std::string& source, const std::string& substring) {
    if (substring.empty()) return 0;
    if (substring.length() > source.length()) return -1;

    const uint64_t p = 7;      
    const uint64_t n = 1000;   

    size_t m = substring.length();
    size_t len = source.length();

    
    uint64_t p_pow = 1;
    for (size_t i = 0; i + 1 < m; i++) {
        p_pow = (p_pow * p) % n;
    }

    
    uint64_t pattern_hash = 0;
    uint64_t window_hash = 0;
    for (size_t i = 0; i < m; i++) {
        pattern_hash = (pattern_hash * p + static_cast<unsigned char>(substring[i])) % n;
        window_hash = (window_hash * p + static_cast<unsigned char>(source[i])) % n;
    }

    for (size_t i = 0; i <= len - m; i++) {
       
        if (window_hash == pattern_hash) {
            bool match = true;
            for (size_t j = 0; j < m; j++) {
                if (source[i + j] != substring[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return static_cast<int>(i);
        }

       
        if (i + m < len) {
            uint64_t old_char = static_cast<unsigned char>(source[i]);
            uint64_t new_char = static_cast<unsigned char>(source[i + m]);
            window_hash = (window_hash + n - (old_char * p_pow % n)) % n;
            window_hash = (window_hash * p + new_char) % n;
        }
    }

    return -1;
}

int main() {
    std::string source;
    std::cout << "Введите строку: ";
    std::getline(std::cin, source);

    std::string substring;
    while (true) {
        std::cout << "Введите подстроку: ";
        if (!std::getline(std::cin, substring)) break;

        int index = find_substring_light_rabin_karp(source, substring);

        if (index != -1) {
            std::cout << "Подстрока " << substring << " найдена по индексу " << index << "\n";
        }
        else {
            std::cout << "Подстрока " << substring << " не найдена\n";
        }

        if (substring == "exit") break;
    }

    return 0;
}