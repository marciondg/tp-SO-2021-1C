#ifndef I_MONGO_STORE_SRC_CONSOLA_MONGO_H_
#define I_MONGO_STORE_SRC_CONSOLA_MONGO_H_

#include "utils_mongo.h"
#include "msg_Mongo.h"

void verificar_sabotaje(void);
void procesar_mensajes_en_consola_mongo(char** palabras_del_mensaje);
void procesar_nuevo_sabotaje(int signal);
bool hay_sabotajes(void);

#endif /* I_MONGO_STORE_SRC_CONSOLA_MONGO_H_ */
