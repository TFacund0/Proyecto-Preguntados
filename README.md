# 🧠 Proyecto Preguntados (Console Edition)

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Course](https://img.shields.io/badge/Course-Algoritmos%20y%20Estructuras%20de%20Datos%20II-orange.svg)](https://en.wikipedia.org/wiki/Algorithms_and_Data_Structures)
[![Year](https://img.shields.io/badge/Year-2023-green.svg)](https://github.com/TuUsuario)

## 🌟 Descripción General

Este proyecto es un juego de trivia tipo **"Preguntados"** desarrollado íntegramente en **C** para la terminal. Fue desarrollado en 2023 como proyecto integrador de la materia **Algoritmos y Estructuras de Datos II**.

<p align="center">
  <img src="screenshots/Pantalla%20Inicial.png" width="80%" alt="Pantalla Inicial" />
</p>

A diferencia de proyectos modernos que dependen de motores gráficos o APIs externas, este sistema fue construido desde cero utilizando **estructuras de datos dinámicas** y lógica pura de programación, demostrando una sólida base en los fundamentos de las ciencias de la computación.

---

## 🎮 Galería del Juego

### 🏠 Inicio y Reglas
El juego comienza con una bienvenida y la explicación de las reglas, estableciendo el ambiente para los jugadores.

<p align="center">
  <img src="screenshots/Reglas%20de%20Juego.png" width="45%" alt="Reglas" />
  <img src="screenshots/Ingreso%20de%20Jugadores.png" width="45%" alt="Registro" />
</p>

### 🕹️ Jugabilidad
Incluye una ruleta aleatoria de categorías y una interfaz de preguntas dinámica que cambia según la categoría seleccionada.

<p align="center">
  <img src="screenshots/Ruleta%20de%20preguntas.png" width="45%" alt="Ruleta" />
  <img src="screenshots/Preguntas%20del%20juego.png" width="45%" alt="Pregunta" />
</p>

### 🏆 Resultados y Puntuaciones
Al finalizar el turno o la partida, el sistema procesa la cola de jugadores y muestra las posiciones finales.

<p align="center">
  <img src="screenshots/Puntuaciones%20de%20juego.png" width="45%" alt="Puntaje" />
  <img src="screenshots/Puntuaciones%20finales%20entre%20jugadores.png" width="45%" alt="Tabla Final" />
</p>

---

---

## 🚀 Desafíos Técnicos y Arquitectura

El proyecto destaca por implementar conceptos avanzados de gestión de datos y memoria:

### 1. Gestión de Jugadores (TDA Cola)
-   Implementación de un **Tipo de Dato Abstracto (TDA)** de tipo **Cola (Queue)** con nodos enlazados.
-   Gestión dinámica de memoria (`malloc` y `free`) para permitir un número variable de jugadores.
-   Lógica de turnos Round-Robin procesando la cola de jugadores.

### 2. Persistencia y Gestión de Datos
-   Uso de **Archivos Binarios (.dat)** para el almacenamiento de preguntas y categorías.
-   Acceso aleatorio a registros mediante `fseek` y `fread` para optimizar la lectura de preguntas sin cargar todo el archivo en memoria.
-   **Tooling**: Incluye un programa auxiliar (`clasificarPreguntas.c`) para la ingesta y clasificación de preguntas en el formato binario propietario.

### 3. Mecánicas de Juego
-   **Sistema de Ruleta**: Generación de categorías aleatorias con feedback visual en terminal.
-   **Gestión de Estados**: Control de vidas, intentos y puntuaciones por cada nodo de jugador.
-   **Interfaz de Usuario Terminal**: Diseño de UI mediante manipulación de colores de consola, centrado de texto y manejo de entradas de teclado en tiempo real (`getch`).

---

## 📂 Estructura del Proyecto

-   `juegoPreguntados.c`: Punto de entrada principal y orquestador del loop de juego.
-   `Librerias/`: Módulos especializados para cada componente:
    -   `preguntados.h`: Lógica central del juego y manejo de archivos.
    -   `Jugador/`: Implementación del TDA Cola y ordenación.
    -   `Actividad del Juego/`: Gestión de vidas, intentos y puntajes.
    -   `Visualizacion Juego/`: Funciones para renderizado en terminal.
-   `Categorias/`: Archivos de datos binarios y herramienta de clasificación.

---

## 🛠️ Instalación y Ejecución

1.  **Requisitos**: Compilador de C (GCC recomendado).
2.  **Compilación**:
    ```bash
    gcc juegoPreguntados.c -o juegoPreguntados
    ```
3.  **Ejecución**:
    ```bash
    ./juegoPreguntados
    ```

---

## 💡 Reflexión: El Valor de la Lógica Pura

Este proyecto fue desarrollado **sin el uso de asistentes de IA**, lo que requirió un profundo entendimiento de:
-   Aritmética de punteros.
-   Ciclos de vida de la memoria dinámica.
-   Manejo de buffers de entrada/salida.
-   Algoritmos de búsqueda y ordenamiento.

Representa el momento en que los fundamentos de la programación se convirtieron en herramientas para crear una aplicación interactiva y compleja.

---
*Desarrollado con pasión por el aprendizaje de los fundamentos del software en 2023.*
