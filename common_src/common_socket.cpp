#define _POSIX_C_SOURCE 200112L
#include "common_socket.h"


#include <cstring>
#include <iostream>
#define ERROR 1
#define EXITO 0
#define FALLA_SOCKET -1
#define EXITO_GET_ADD_INFO 0
#define ESCUCHA 20




void inicializar_struct_hints(struct addrinfo* hints, int ai_family,
                              int ai_socktype, int ai_flags){
      memset(hints, 0, sizeof(struct addrinfo));
      hints->ai_family = ai_family;
      hints->ai_socktype = ai_socktype;
      hints->ai_flags = ai_flags;
}

Socket::Socket(){
    this->file_descriptor = -1;
}
Socket::~Socket(){
    if (this->file_descriptor != -1){
        close(this->file_descriptor);
    }
}
void Socket::Shutdown(int formato){
    if (this->file_descriptor != -1){
        shutdown(this->file_descriptor, formato);
    }
}
void Socket::cerrar(){
    if (this->file_descriptor !=-1){
        close(this->file_descriptor);
    }
}

Socket::Socket(Socket&& socket){
    this->file_descriptor = socket.file_descriptor;
    socket.file_descriptor = -1;
}
Socket::Socket(int file_descriptor){
    this->file_descriptor = file_descriptor;
}


Socket Socket::aceptar(){
    if (this->file_descriptor == -1){
        throw SocketError("No esta habilitado el el socket listener");
    }
    int file_descriptor = accept(this->file_descriptor, nullptr, nullptr);
    if (file_descriptor == FALLA_SOCKET){
        throw SocketError("No se pudo crear el socket peer");
    }
    return std::move(Socket(file_descriptor));
}

void Socket::bine_and_listen(const char* host, const char* service){
    bool no_pude_binear = true;
    struct addrinfo hints;
    struct addrinfo *resultados, *aux;
    inicializar_struct_hints(&hints,AF_INET, SOCK_STREAM, AI_PASSIVE);

    if (getaddrinfo(host, service, &hints, &resultados) != EXITO_GET_ADD_INFO){
        throw SocketError("Falla de getaddrinfo");
    }
    aux = resultados;
    while (aux != NULL && no_pude_binear){
        int file_descriptor = socket(aux->ai_family, aux->ai_socktype,
                                      aux->ai_protocol);
        if (file_descriptor == FALLA_SOCKET){
            no_pude_binear = true;
        } else {
            if (bind(file_descriptor, aux->ai_addr, aux->ai_addrlen)
                  == FALLA_SOCKET){
                close(file_descriptor);
                no_pude_binear = true;
            } else {
                no_pude_binear = false;
                this->file_descriptor = file_descriptor;
            }
        }
        aux = aux->ai_next;
    }
    freeaddrinfo(resultados);
    int val = 1;
    int s = setsockopt(this->file_descriptor, SOL_SOCKET, SO_REUSEADDR, &val,
                        sizeof(val));
    if (s == -1) {
      close(this->file_descriptor);
      freeaddrinfo(aux);
      return;
    }
    if (listen(this->file_descriptor, ESCUCHA) == FALLA_SOCKET){
        throw SocketError("falla de listen");
    }
    if (no_pude_binear){
        throw SocketError("No se pudo binear");
    }
}
Socket& Socket::operator=(Socket&& other) {
    this->file_descriptor = std::move(other.file_descriptor);
    other.file_descriptor = -1;
    return *this;
}

void Socket::conectar(const char* host, const char* service){
    bool no_pude_conectar = true;
    struct addrinfo hints;
    struct addrinfo *resultados, *aux;
    inicializar_struct_hints(&hints,AF_INET, SOCK_STREAM, 0);
    if (getaddrinfo(host, service, &hints, &resultados) != EXITO_GET_ADD_INFO){
        throw SocketError("Falla de getaddrinfo");
    }
    aux = resultados;
    while (aux != NULL && no_pude_conectar){
        int file_descriptor = socket(aux->ai_family, aux->ai_socktype,
                                      aux->ai_protocol);
        if (file_descriptor == FALLA_SOCKET){
            no_pude_conectar = true;
        } else {
            if (::connect(file_descriptor, aux->ai_addr, aux->ai_addrlen)
                  == FALLA_SOCKET){
                close(file_descriptor);
                no_pude_conectar = true;
            } else {
                no_pude_conectar = false;
                this->file_descriptor = file_descriptor;
            }
        }
        aux = aux->ai_next;
    }
    freeaddrinfo(resultados);
    if (no_pude_conectar){
        throw SocketError("No se pudo conectar en socket");
    }
}
void Socket::enviar(const char* mensaje, const size_t& tamanio) const {
    size_t bytes_enviados = 0;
    while (bytes_enviados < tamanio) {
        int verificacion = send(this->file_descriptor, &mensaje[bytes_enviados],
                              (tamanio - bytes_enviados), MSG_NOSIGNAL);
        if (verificacion > 0) {
            bytes_enviados += verificacion;
        } else {
            throw SocketError("no se pudo enviar el mensaje");
        }
    }
}
int Socket::recibir(char* mensaje, const size_t& tamanio) const{
    int cant_recibidos = 0;
    int verificacion = recv(this->file_descriptor, &mensaje[cant_recibidos],
                              (tamanio - cant_recibidos), 0);
    return verificacion;
}
