#include "client_cliente.h"
#include "../common_src/common_excepciones.h"
#include <string>
#include <iostream>

#define CANTIDAD_ARGUMENTOS 3
#define ERROR_CANT_ARGUMENTOS "cantidad de argumentos invalidos. Deben ser 3"

int main(int argc, char* argv[]){
    if (argc != CANTIDAD_ARGUMENTOS){
        std::cout << ERROR_CANT_ARGUMENTOS;
        return 0;
    }
    try{
        std::string host(argv[1]);
        std::string service(argv[2]);
        Cliente client(host, service);
        client.run();
        return 0;
    }catch(const SocketError &exception){
        std::cout << ' ' << exception.get_error();
        return 0;
    }catch(const ArchivoError &exception){
        std::cout << ' ' << exception.get_error();
        return 0;
    }catch(const std::exception& exception){
          std::cout << ' ' << exception.what();
          return 0;
    }catch(...){
          std::cout << "error desconocido";
    }
}
