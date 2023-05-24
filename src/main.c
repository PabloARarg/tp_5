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

/** \brief define e implementa las funciones de call-back y los pasa como parametro de llamada
 **
 ** \addtogroup 
 ** \brief 
  ** @see 
 ** @{ */

/* === Headers files inclusions =============================================================== */
#include"calculadora.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

int suma(int a,int b){

    return a+b;
}

int resta(int a,int b){

    return a-b;
}

int prducto(int a,int b){

    return a*b;
}

void main(void){
    char a[]="12+13";

    calculadora_t calculadora = CrearCalculadora();//crea la calculadora

    AgregarOperacionCalculadora(calculadora,'+',suma);//añade una operacion a la calculadora
    AgregarOperacionCalculadora(calculadora,'-',resta);
    AgregarOperacionCalculadora(calculadora,'*',prducto);

    int resulatado=Calcular(calculadora,a);//calcula el valor de la operacion

    printf("\nResultado-> %i\r\n",resulatado);//muestra el resultado de la operacion

}

/* === Public function implementation ========================================================== */

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
