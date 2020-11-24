#include "common_excepciones.h"

SocketError::SocketError(const std::string& error){
    this->error = error;
}
SocketError::~SocketError(){}

const char* SocketError::what() const noexcept {
    return this->error.c_str();
}

Exception::Exception(const std::string& error){
    this->error = error;
}

Exception::~Exception(){}

const char* Exception::what() const noexcept {
    return this->error.c_str();
}
