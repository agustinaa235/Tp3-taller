#ifndef SOCKET_H
#define SOCKET_H

#include <string>
#include <sstream>
#include <exception>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>


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
						void Shutdown(int formato);
            Socket(const Socket &socket) = delete;
            Socket(Socket&& socket);
						Socket& operator=(Socket&& other);
            void bine_and_listen(const char* host, const char* service);
            Socket aceptar();
            void conectar(const char* host, const char* service);
            void enviar(const char* mensaje, const size_t& tamanio) const;
            int recibir(char* mensaje, const size_t& tamanio) const;
						void cerrar();


    private:
          int file_descriptor;
          Socket(int file_descriptor);
};

#endif
