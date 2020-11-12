#ifndef SOCKET_H
#define SOCKET_H

#include <string>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <utility>


class Socket{
    public:
						/*
							* creara al socket dejandolo valido para uso
						*/
            Socket();
						/*
							* liberara al socket con sus recursos
						*/
            ~Socket();
						/*
							* cerrara el canal correspondiente en base al formato.
							* se consiera el formato como valido
						*/
						void Shutdown(int formato);
						/*
							* no se permitira el uso del constructor por copia
						*/
            Socket(const Socket &socket) = delete;
            /*
              * no se permitira el uso del operador = por copia
            */
            Socket& operator=(const Socket& socket) = delete;   
            /*
              * contructor por movimiento
            */
            Socket(Socket&& socket);
            /*
              * operador = por movimiento
            */
						Socket& operator=(Socket&& socket);
						/*
							* realizara un bine y luego un listen
						*/
            void bine_and_listen(const char* host, const char* service);
						/*
							* aceptara un conexion con un cliente y devolvera el socket
							* creado
						*/
            Socket aceptar();
						/*
							* realizara una conexion y lo asociara al socket
						*/
            void conectar(const char* host, const char* service);
						/*
							* enviara el mensaje que recibe por parametro
						*/
            void enviar(const char* mensaje, const size_t& tamanio) const;
						/*
							* recibira el mensaje y lo almacenara en el buffer que recibe
							* por parametro
						*/
            int recibir(char* mensaje, const size_t& tamanio) const;
						/*
							* realizara un close del socket
						*/
						void cerrar();


    private:
          int file_descriptor;
          explicit Socket(int file_descriptor);
};

#endif
