#ifndef I_MONGO_STORE_SRC_FILESYSTEM_H_
#define I_MONGO_STORE_SRC_FILESYSTEM_H_
#include "utils_mongo.h"

void inicializar_paths_aux();
void leer_superbloque(FILE* archivo);
void obtener_superbloque();
void inicializar_bloques();
bool directorio_existe(char* path);

#endif /* I_MONGO_STORE_SRC_FILESYSTEM_H_ */
