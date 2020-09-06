//Project made by Szocs Andras
#include <iostream>
#include <string>


int main()
{
    std::string letters{};
    std::cout << "Enter a string of letters so I can create a Letter Pyramid from it: "<<std::endl;
    getline(std::cin, letters);

    size_t num_letters = letters.length();
    int position {0};

    for (char c: letters) {

        size_t num_spaces = num_letters - position;
        while (num_spaces > 0) {
            std::cout << " ";
            --num_spaces;
        }

        for (int j=0; j < position; j++) {
            std::cout << letters.at(j);
        }

        std::cout << c;
        
        for (int j=position-1; j >=0; --j) {
            auto k = static_cast<size_t>(j);
            std::cout << letters.at(k);
        }

        std::cout << std::endl; 
        ++position;
    }

    return 0;
}