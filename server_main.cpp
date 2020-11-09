#include "server_servidor.h"
#include <iostream>
#include <string>


int main(int argc, char* argv[]){
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
      std::cout << ' ' << exception.getError();
      return 0;
  }
}
