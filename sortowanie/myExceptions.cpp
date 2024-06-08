#include "myExceptions.h"

MyExceptions::MyExceptions(const std::string& message) : message(message) {}

const char* MyExceptions::what() const noexcept {
    return message.c_str();
}
