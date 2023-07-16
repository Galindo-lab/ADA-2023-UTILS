/**********************************************************************
 * AUTOR: Luis Eduardo Galindo Amaya                 DATE: 15-07-2023 *
 *                                                                    *
 * En este archivo se almacenan todos los métodos para controlar una  *
 * fila simple.                                                       *
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

#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef List Queue;

/**
 * @brief 
 * 
 */
#define QUEUE_INIT(QUEUE) ListInit(STACK);

/**
 * @brief 
 * 
 */
#define QUEUE_ENQUEUE(QUEUE, DATA) LIST_PUSH(QUEUE, DATA)

/**
 * @brief 
 * 
 */
#define QUEUE_DEQUEUE(TYPE, QUEUE) \
    LIST_GET(TYPE, QUEUE, 0);      \
    ListRemove(QUEUE, 0)

/**
 * @brief 
 * 
 */
#define QUEUE_EMPTY(QUEUE) LIST_EMPTY(QUEUE)

/**
 * @brief 
 * 
 */
#define QUEUE_SIZE(QUEUE) LIST_LEN(QUEUE)

/**
 * @brief 
 * 
 */
#define QUEUE_FRONT(TYPE, QUEUE) LIST_GET(TYPE, QUEUE, 0)

/**
 * @brief 
 * 
 */
#define QUEUE_REAR(TYPE, QUEUE) \
    LIST_GET(TYPE, QUEUE, LIST_LEN(QUEUE) - 1)

/**
 * @brief 
 * 
 */
#define QUEUE_FREE(QUEUE) ListFree(QUEUE);

#endif