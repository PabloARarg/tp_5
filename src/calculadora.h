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
/**
 * @file delcara los tipos y las fuciones
 * @version 1.0.0
 * @date 14/4/2023
 * @author Pablo Rivas
 * @brief Calculadora simple que pude añadirse operaciones desde un programa externo
 * \see
 */
#ifndef TEMPLATE_H
#define TEMPLATE_H

/* === Headers files inclusions ================================================================ */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public variable declarations ============================================================ */
/**
 * @brief **Define tipo de variable a un puntero (puntero opaco)**
 *
 * Permite la creacion de una estructura sin conocer conocer su implementacion desde un programa externo
 *
 */
typedef struct calculadora_s * calculadora_t;

/**
 * @brief **Define un tipo de  variable (funcion de callback)**
 *
 * Permite crear variables que señalan a una funcion con estructura definida y definicion indefinida
 *
 */
typedef int (*funcion_t)(int, int);

/* === Public function declarations ============================================================ */

/**
 * @brief **Constructor del objeto calculadora**
 *
 * @return calculadora_t Retorna un puntero que identifica la calculadora
 */
calculadora_t CrearCalculadora();

/**
 * @brief **Crea una operacion, envia el puntero de la calculadora, el simbolo que define la operacion**
 *
 * @param calculadora Puntero del objeto calculadora
 * @param operador Caracter que identifica la operacion
 * @param funcion Funcion que define la operacion
 * @return true Se agrego con exito la operacion
 * @return false No se agrego la operacion por falta de memoria
 */
bool AgregarOperacionCalculadora(calculadora_t calculadora, char operador, funcion_t funcion);

/**
 * @brief **Realiza la operacion**
 *
 * @param calculadora Puntero que identifica la calculadora
 * @param cadena Se envia una cadena con dos numeros separado por un operador
 * @return int Debuelve el valor de la operacion si esta definida
 */
int Calcular(calculadora_t calculadora, char * cadena);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* TEMPLATE_H */