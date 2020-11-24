#include "client_cliente.h"
#include "../common_src/common_excepciones.h"
#include <string>
#include <iostream>

#define CANTIDAD_ARGUMENTOS 3
#define ERROR_CANT_ARGUMENTOS "cantidad de argumentos invalidos. Deben ser 3"

int main(int argc, char* argv[]){
    try{
        if (argc != CANTIDAD_ARGUMENTOS){
            throw Exception(ERROR_CANT_ARGUMENTOS);
        }
        std::string host(argv[1]);
        std::string service(argv[2]);
        Cliente client(host, service);
        client.run();
        return 0;
    }catch(const std::exception& exception){
          std::cerr << exception.what();
          return 0;
    }catch(...){
          std::cerr << "error desconocido";
    }
}
