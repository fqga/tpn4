/* Copyright 2022, Laboratorio de Microprocesadores 
 * Facultad de Ciencias Exactas y Tecnología 
 * Universidad Nacional de Tucuman
 * http://www.microprocesadores.unt.edu.ar/
 * Copyright 2022, Facundo Quiroga <facundoqga@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DIGITAL_H   /*! @cond    */
#define DIGITAL_H   /*! @endcond */

/** @file digital.h
 **
 ** @brief Gestion de las GPIO
 **
 ** Contiene las declaraciones de las funciones necesarias para:
 ** Asignar la funcion de entrada o salida a cierto pin del microcontrolador
 ** Para Activar, Desactivar o Cambiar el estado del pin.
 ** 
 ** | RV | YYYY.MM.DD | Autor       | Descripción de los cambios              |
 ** |----|------------|-------------|-----------------------------------------|
 ** |  1 | 2022.10.13 | fquiroga    | Version inicial del archivo             |
 ** 
 ** @defgroup GPIO
 ** @brief Gestion de GPIOs independientemente de la HAL del fabricante
 ** @{ 
 */

/* === Inclusiones de archivos externos ==================================== */

/* === Cabecera C++ ======================================================== */
#ifdef __cplusplus
extern "C" {
#endif

/* === Definicion y Macros publicos ======================================== */
#include <stdint.h>
#include <stdbool.h>
/* == Declaraciones de tipos de datos publicos ============================= */

typedef struct digital_output_s * digital_output_t;
typedef struct digital_input_s  * digital_input_t;

/* === Declaraciones de variables publicas ================================= */

/* === Declaraciones de funciones publicas ================================= */

digital_output_t DigitalOutputCreate(uint8_t gpio, uint8_t bit);
void DigitalOutputActivate(digital_output_t output);
void DigitalOutputDeactivate(digital_output_t output);
void DigitalOutputToggle(digital_output_t output);

digital_input_t DigitalInputCreate(uint8_t gpio, uint8_t bit, bool inverted);
bool DigitalInputGetState(digital_input_t input);
bool DigitalInputHasChanged(digital_input_t input);
bool DigitalInputHasActivated(digital_input_t input);
bool DigitalInputHasDeactivated(digital_input_t input);

/* === Ciere de documentacion ============================================== */
#ifdef __cplusplus
}
#endif

/** @} Final de la definición del modulo para doxygen */

#endif   /* DIGITAL_H */
