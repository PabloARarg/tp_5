/************************************************************************************************
Copyright (c) 2023, Pablo Rivas

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** \brief implementa las funciones y la estructura
 **
 ** \addtogroup
 ** \brief
 ** @see
 ** @{ */

/* === Headers files inclusions =============================================================== */
#include "calculadora.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

//! **Define puntero a la estructura operaciones**
typedef struct operacion_s * operacion_t;

//! Define una estructura para almacenar las funciones de operaciones asociada el simbolo correspondiente
struct operacion_s {
    char operador;         //!< Almacena el operador que define la operacion
    funcion_t funcion;     //!< Almcacena la funcion que implementa la operacion(_puntero_)
    operacion_t siguiente; //!< Almacena la direccion de la siguiente operacion(_puntero_)
};

// define la estructura de una objeto calculadora con un grupo definido de slots para almacenar
// operaciones
struct calculadora_s {
    operacion_t operaciones; //!< Almacena la direccion de ultima operacion(_puntero_)
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

//! **Busca una operacion entre las almacenadas**
operacion_t BuscarOperacion(calculadora_t calculadora, char operador);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/** @brief Funcion interna para buscar la operacion mediante la coincidencia del operador*/
operacion_t BuscarOperacion(calculadora_t calculadora, char operador) {
    operacion_t result = NULL;
    // evita que se ejecute si calculadora es NULL->si calculadora es null ->
    // calculadora.operaciones=null
    if (calculadora) {
        // busca mediante enlaces por punteros
        for (operacion_t actual = calculadora->operaciones; actual->siguiente != NULL; actual = actual->siguiente) {
            if (actual->operador == operador) { // compara con un operador
                result = actual;                // almacena para la salida la direcion del * operacion
                break;
            }
        }
    }
    return result; // debuelve nul si no encontro operador valido o la direccion del operador
}

/* === Public function implementation ========================================================== */

// Crea el objeto calculadora
calculadora_t CrearCalculadora() {
    calculadora_t result = malloc(sizeof(struct calculadora_s));
    if (result)
        memset(result, 0, sizeof(struct calculadora_s));
    return result;
}

// agrega una operacion a la calculadora
bool AgregarOperacionCalculadora(calculadora_t calculadora, char operador, funcion_t funcion) {
    operacion_t operacion = malloc(sizeof(struct operacion_s));
    // al crear la calculadora se tiene operaciones=NULL
    if ((operacion) && calculadora->operaciones == NULL) {
        // si es la primera operacion se guada la direccion directamente
        operacion->operador = operador;
        operacion->funcion = funcion;
        operacion->siguiente = NULL;
        calculadora->operaciones = operacion;
    }

    else if ((operacion) && !BuscarOperacion(calculadora, operador)) {
        operacion->operador = operador;
        operacion->funcion = funcion;
        operacion->siguiente = calculadora->operaciones;
        calculadora->operaciones = operacion;
    }
    return (operacion != NULL);
}

// realiza la operacion y debuelve el resultado
int Calcular(calculadora_t calculadora, char * cadena) {
    int a, b;
    char operador;
    int result = 0;

    for (int indice = 0; indice < strlen(cadena); indice++) { // separa los operando y el operador
        // en ASCCI los operadores tienen valores menores a los char numeros y lo busca asi
        if (cadena[indice] < '0') {
            operador = cadena[indice];
            a = atoi(cadena);              // guada el primer numero de la cadena y lo corta el operador
            b = atoi(cadena + indice + 1); // guarda el segundo numero
            break;
        }
    }

    // busca si esta definido la operacion el la calculadora
    operacion_t operacion = BuscarOperacion(calculadora, operador);
    if (operacion) {
        result = operacion->funcion(a, b); // ejecuta la operacion
    }
    return result;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
