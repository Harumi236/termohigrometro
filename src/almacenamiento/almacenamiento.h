
#ifndef ALMACENAMIENTO_H
#define ALMACENAMIENTO_H

#include "medicion.h"

// Inicializar almacenamiento
void InicializarAlmacenamiento();

// Guardar una medicion
void AlmacenarDatos(const Medicion &medicion);

// Consultar cantidad de registros
int CantidadRegistros();

// Mostrar todos los registros
void MostrarRegistros();

#endif
