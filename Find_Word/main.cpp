//Study project made by Szocs Andras
#include <iostream>
#include <fstream>


bool find_substring(const std::string &word_to_find, const std::string &target) {
   size_t found = target.find(word_to_find);
    if (found== std::string::npos)
        return false;
    else
        return true;
}

int main() {
    std::ifstream in_file {};
    std::string word_to_find {};
    std::string word_read {};
    int word_count {0};
    int match_count {0};
    
    //opening text file and check if the file is properly open
    in_file.open("romeoandjuliet.txt");
     if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        //return 1;
    }
   
    //imput string from user and loop through the text file checking if the target string is found
    std::cout<<"This application will search for a imput substring in the poem Romeo and Juliet."<<std::endl;
    std::cout << "Enter the substring to search for: ";
    std::cin >> word_to_find;
    while (in_file >> word_read) {
        ++word_count;//counter for all the word in the file
        if (find_substring(word_to_find, word_read)) {
           ++match_count; // update the counter each time the target word was find
           std::cout<<"[" << word_read <<"]"<<" ";
           if(match_count != 0 && match_count % 10 == 0){
               std::cout<<std::endl;
           }
        }        
    }
     //output the results
    std::cout <<std::endl<<std::endl<<"======================================"<<std::endl
                   << word_count << " words were searched..." << std::endl;
    std::cout << "The substring " << word_to_find << " was found " << match_count << " times " << std::endl;
    
    in_file.close();
    std::cout << std::endl;
    return 0;
}
