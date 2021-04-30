#ifndef SHARED_HELLO_H_
#define SHARED_HELLO_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>
#include <stdint.h>
#include <commons/log.h>
#include <commons/string.h>
#include <commons/config.h>
#include <commons/collections/list.h>
#include <commons/collections/queue.h>
#include <readline/readline.h>
#include "buffer.h"
#include "msgtypes.h"
#include "paquete.h"
#include "protocolo.h"
#include "sockets.h"

t_log* iniciar_logger(char*, char*);
int contar_elementos_array(char**);
int son_iguales(char*, char*);
int chequear_argumentos_del_mensaje(char**, int);
int existe_en_array(char**, char*);
void helloWorld(void);

#endif
