#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <exception>
#include <string>

class SocketError : public std::exception{
			public:
					/*
						* creara la clase socket error
					*/
					explicit SocketError(const std::string& error);
					/*
						* liberara la clase socket error con sus recursos
					*/
          ~SocketError();
					/*
						* devolvera el mensaje de error
					*/
					const char* what() const noexcept override;

			private:
					std::string error;
};

class Exception : public std::exception{
		public:
					/*
						* creara la clase Exception
					*/
					explicit Exception(const std::string& error);
					/*
						* liberara la clase exception con sus recursos
					*/
					~Exception();
					/*
						* devolvera el mensaje de error
					*/	
					const char* what() const noexcept override;

		private:
					std::string error;
};


#endif
