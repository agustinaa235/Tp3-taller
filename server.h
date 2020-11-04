#ifndef SERVER_H
#define SERVER_H

#include <string>

class Servidor{
    public:
          Servidor(const std::string& service, const std::string& root_file);
          ~Servidor();
          run();
    private:
          const char* service;
          std::string root_file;
};
