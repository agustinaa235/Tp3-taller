#ifndef LOCK_H
#define LOCK_H

#include <mutex>
class Lock {
			public:
							/*
								* inicializara al lock y lo dejara valido para uso
							*/
							explicit Lock(std::mutex& mutex);
							/*
								* liberara al lock con sus recursos
							*/
							~Lock();
			private:
							std::mutex& mutex;
};

#endif
