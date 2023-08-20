#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string searched_word = "Armenia";

std::vector<std::string> analyze(std::ifstream& f) {
    std::vector<std::string> result;
    std::string line;

    while (std::getline(f, line)) {
        int index = line.find(searched_word);
        if ( index != std::string::npos) {
            line.insert(index, " <");
            line.insert(index + searched_word.length() + 2, "> ");
            result.push_back(line);
        }
    }
    return result;
}

template<typename T>
void print(const std::vector<T>& vec, std::ofstream& f) {
    for (const auto& elem : vec) {
        f << elem << std::endl;
    }
}

int main() {
    std::ifstream f1("./f1.txt");
    std::ofstream f2("./out.txt");

    std::vector<std::string> result = analyze(f1);
    f2.clear();
    print(result, f2);

    f1.close();
    f2.close();

    return 0;
}
