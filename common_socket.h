#ifndef SOCKET_H
#define SOCKET_H

#include <string>
#include <sstream>
#include <exception>


class SocketError : public std::exception{
private:
	std::string error;

public:
	SocketError(std::string error): error(error){}

	 const char* getError() const { return this->error.c_str(); }
};

class Socket{
    public:
            Socket();
            ~Socket();
            Socket(const Socket &socket) = delete;
            //Socket& operador=(const Socket &copy) = delete;
            Socket(Socket&& socket);
            void bine_and_listen(const char* host, const char* service);
            Socket aceptar();
            void conectar(const char* host, const char* service);
            void enviar(const char* mensaje, const size_t& tamanio) const;
            void recibir(char* mensaje, const size_t& tamanio) const;


    private:
          int file_descriptor;
          Socket(int file_descriptor);
};

#endif
