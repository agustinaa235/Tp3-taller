#include "server_servidor.h"
#include "../common_src/common_excepciones.h"
#include <iostream>
#include <string>

#define CANTIDAD_ARGUMENTOS 3
#define ERROR_CANT_ARGUMENTOS " cantidad de argumentos invalida. Debe ser 3"

int main(int argc, char* argv[]){
    if (argc != CANTIDAD_ARGUMENTOS){
        std::cout << ERROR_CANT_ARGUMENTOS;
        return 0;
    }
    try{
        std::string service(argv[1]);
        std::string root_name(argv[2]);
        Servidor servidor(service, root_name);
        servidor.run();
        char salir = 0;
        do {
            salir = getchar();
        } while (salir != 'q');
        servidor.close();
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
