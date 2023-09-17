#include <iostream>
#include <initializer_list>

void appendOk(std::unique_ptr<std::string> string) {
    string->append("Ok");
}

int main() {
    std::unique_ptr<std::string> unique_string{std::make_unique<std::string>("")};
    appendOk(unique_string);
    std::cout << *unique_string << std::endl;

    return 0;
}