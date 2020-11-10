#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <exception>
#include <string>

class SocketError : public std::exception{
			public:
					explicit SocketError(const std::string& error);
          ~SocketError();
					std::string get_error() const;

			private:
					std::string error;
};

class ArchivoError : public std::exception{
    public:
          explicit ArchivoError(const std::string& error);
          ~ArchivoError();
          std::string get_error() const;
    private:
          std::string error;
};

#endif
