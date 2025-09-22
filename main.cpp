#include <fstream>
#include <cstring>
#include <iostream>


char* arg_word;
char* arg_filepath;

bool ParsingArgs(char** argv) {
    if ((strcmp(argv[1], "--word") != 0) == (strcmp(argv[3], "--word") != 0) || 
        (strcmp(argv[1], "--file") != 0) == (strcmp(argv[3], "--file") != 0)) { //проверка корректности аргументов
        std::cout << "Incorrect type of arguments: use [--word <word>] [--file <file path>]" << std::endl;
        return false;
    }

    if (strcmp(argv[1], "--word") == 0) {
        arg_word = argv[2];
        arg_filepath = argv[4];
    } else {
        arg_filepath = argv[2];
        arg_word = argv[4];
    }

    if (strlen(arg_word) > 32) { //проврека корректности длины слова

        std::cout << "Words no longer than 32 characters are accepted" << std::endl;
        return false;
    }
    
    return true;
}

int СountOfWords(std::fstream &file, char* arg_word) {
    int cnt = 0;
    char word[100];
    while (file >> word) {
        bool flag = false;
        for (int i = 0; i < strlen(arg_word); i++) {
            flag = false;
            for (int j = 0; j < strlen(word); j++) {
                if (arg_word[i] == word[j]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                break;
            } 
        }

        if (flag) {
            cnt++;
        }
    }
    return cnt;
}

int main(int argc, char** argv) {
    if (!ParsingArgs(argv)) {
        return -1;
    }

    std::fstream fs(arg_filepath, std::ios::in);
    if (!fs.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return -1;
    }

    std::cout << "Count of words: " << СountOfWords(fs, arg_word) << std::endl;
    fs.close();
    return 0;
}
