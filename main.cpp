
#include <fstream>
#include <cstring>
#include <iostream>

int main(int argc, char** argv) {
    
    if (strcmp(argv[1], "--word") != 0 || strcmp(argv[3], "--file") != 0) {
        std::cout << "Incorrect type of arguments: use --word <word> --file <file path>" << std::endl;
        return -1;
    }
    if (strlen(argv[2]) > 32) {
        std::cout << "Words no longer than 32 characters are accepted" << std::endl;
        return -1;
    }

    char* arg_word = argv[2];
    char* filepath = argv[4];
    std::fstream fs(filepath, std::ios::in);
    
    if (!fs.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return -1;
    }

    char word[100];
    int cnt = 0;
    while (fs >> word) {
        int flag = 0;
        for (int i = 0; i < strlen(arg_word); i++) {
            flag = 0;
            for (int j = 0; j < strlen(word); j++) {
                if (arg_word[i] == word[j]) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                break;
            } 
        }

        if (flag == 1) {
            cnt++;
        }
    }
    
    std::cout << "Count of words: " << cnt << std::endl;
    fs.close();
    return 0;
}
