#include "sockets.h"

int iniciar_servidor(t_log* logger, char* ip, char* puerto)
{
	int socket_servidor;
    struct addrinfo hints, *servinfo;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(ip, puerto, &hints, &servinfo);

    if ((socket_servidor = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol)) == -1){
		log_info(logger, "No se pudo crear el server correctamente. Levante el modulo nuevamente. Gracias, vuelvas prontos.");
		exit(-1);
	}

//    for (struct addrinfo *p = servinfo; p != NULL; p = p->ai_next)
//    {
//        socket_servidor = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
//        if (socket_servidor == -1)
//            continue;

        if (bind(socket_servidor, servinfo->ai_addr, servinfo->ai_addrlen) < 0) {
        	log_info(logger, "No se pudo crear el server correctamente. Levante el modulo nuevamente. Gracias, vuelvas prontos.");
        	exit(-1);
        }

//        if (bind(socket_servidor, p->ai_addr, p->ai_addrlen) == -1) {
//            close(socket_servidor);
//            continue;
//        }
//        break;
//    }

    if(listen(socket_servidor, SOMAXCONN)){
    		log_info(logger, "No se pudo crear el server correctamente. Levante el modulo nuevamente. Gracias, vuelvas prontos.");
    		exit(-1);
    }

    freeaddrinfo(servinfo);

    log_trace(logger, "Listo para escuchar a mi cliente");

    return socket_servidor;
}

int esperar_cliente(t_log* logger, int socket_servidor)
{
	struct sockaddr_in dir_cliente;
	socklen_t tam_direccion = sizeof(struct sockaddr_in);

	int socket_cliente = accept(socket_servidor, (void*) &dir_cliente, &tam_direccion);

	log_info(logger, "Se conecto un cliente!");

	return socket_cliente;
}
uint32_t conectar(t_log* logger, char* ip, char* puerto){
	uint32_t socket_conexion = crear_conexion(logger,ip, puerto);
	if (socket_conexion == -1) {
		log_error(logger, "No me pude conectar");
	} else {
		log_info(logger, "Me conecte exitosamente");
	}

	return socket_conexion;
}

int crear_conexion(t_log* logger, char* ip, char* puerto)
{
	struct addrinfo hints;
	struct addrinfo *server_info;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(ip, puerto, &hints, &server_info);

	int socket_cliente = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);

	if(connect(socket_cliente, server_info->ai_addr, server_info->ai_addrlen) == -1)
		log_error(logger, "Error al conectar");

	freeaddrinfo(server_info);

	return socket_cliente;
}

void liberar_conexion(uint32_t* socket_cliente)
{
	close(*socket_cliente);
    *socket_cliente = -1;
}
