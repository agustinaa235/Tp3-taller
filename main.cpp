#include "common_socket.h"
#include <iostream>


int main(){
  try{
      Socket socket;
      const char* host = "127.0.0.1";
      const char* service = "7777";
      socket.conectar(host, service);
      socket.enviar("hola", 4);
      return 0;
  }catch(const SocketError &exception){
      std::cout << ' ' << exception.getError();
  }
}
