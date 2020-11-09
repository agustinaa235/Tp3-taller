#include "client_cliente.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]){
    try{
        std::string host(argv[1]);
        std::string service(argv[2]);
        Cliente client(host, service);
        client.run();
        return 0;
    }catch(const SocketError &exception){
        std::cout << ' ' << exception.getError();
    }
}
