#include "common_excepciones.h"

SocketError::SocketError(const std::string& error){
    this->error = error;
}
SocketError::~SocketError(){}

std::string SocketError::get_error() const {
    return this->error;
}

ArchivoError::ArchivoError(const std::string& error){
    this->error = error;
}

ArchivoError::~ArchivoError(){}

std::string ArchivoError::get_error() const {
    return this->error;
}
