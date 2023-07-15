/**********************************************************************
 * AUTOR: Luis Eduardo Galindo Amaya                 DATE: 15-07-2023 *
 *                                                                    *
 * En este archivo se almacenan todos los métodos para controlar una  *
 * pila simple.                                                       *
 **********************************************************************/

//  This program is free software: you can redistribute it and/or
//  modify it under the terms of the GNU General Public License as
//  published by the Free Software Foundation, either version 3 of the
//  License, or (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
//  along with this program.
//  If not, see <https://www.gnu.org/licenses/>.

#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef List Stack;

/**
 * @brief Macro para inicializar un Stack
 * 
 * @param STACK Puntero a el stack
 */
#define STACK_INIT(STACK) ListInit(STACK);

/**
 * @brief Macro para insertar un elemento en el stack
 *
 * @param STACK Puntero a el stack.
 * @param DATA Puntero a los datos a insertar.
 */
#define STACK_PUSH(STACK, DATA) LIST_PUSH(STACK, DATA)

/**
 * @brief Macro para extraer el último elemento de el stack.

 * @param TYPE Tipo al que se desea convertir el valor.
 * @param STACK Puntero a el stack.
 * @return El valor convertido al tipo especificado.
 */
#define STACK_POP(TYPE, STACK) LIST_POP(TYPE, STACK)

/**
 * @brief Macro para examinar el primer elemento del stack
 *
 * @param TYPE Tipo al que se desea convertir el valor.
 * @param STACK Puntero a el stack.
 * @return El valor del primer elemento del stack
 */
#define STACK_TOP(TYPE, STACK) LIST_GET(TYPE, STACK, 0)

/**
 * @brief Macro para verificar si el stack está vacío.
 *
 * @param STACK Puntero a el stack.
 * @return 1 si el stack está vacía, 0 en caso contrario.
 */
#define STACK_EMPTY(STACK) LIST_EMPTY(STACK)

/**
 * @brief Macro para obtener la cantidad de elementos en el stack
 * 
 * @param STACK Puntero a el stack.
 * @return La longitud de el stack.
 */
#define STACK_SIZE(STACK) LIST_LEN(STACK)


/**
 * @brief Macro para liberar la memoria del stack
 * 
 */
#define STACK_FREE(STACK) ListFree(STACK); 

#endif