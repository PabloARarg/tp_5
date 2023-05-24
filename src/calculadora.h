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
 * @brief 
 * \see 
*/
#ifndef TEMPLATE_H
#define TEMPLATE_H

/* === Headers files inclusions ================================================================ */
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public variable declarations ============================================================ */
typedef struct calculadora_s *calculadora_t;

typedef int(*funcion_t)(int,int);

/* === Public function declarations ============================================================ */

//crea una calculadora
calculadora_t CrearCalculadora();

//crea una operacion, envia el puntero de la calculadora, el simbolo que define la operacion
//y la funcion asociada a ese simbolo
bool AgregarOperacionCalculadora(calculadora_t calculadora,char operador,funcion_t funcion);

//calcula la operacion
int Calcular(calculadora_t calculadora,char *cadena);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* TEMPLATE_H */