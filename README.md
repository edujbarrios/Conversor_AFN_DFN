# Proyecto de Conversión NFA a DFA 🔄

Bienvenido al repositorio del proyecto de conversión de Autómatas Finitos No Deterministas (NFA) a Autómatas Finitos Deterministas (DFA).

Este proyecto ha sido desarrollado por Eduardo J. Barrios García. El objetivo principal es proporcionar una herramienta que facilite la conversión entre estos dos tipos de autómatas.

## Características 🌟

- Conversión rápida y eficiente de NFA a DFA.
- Interfaz de línea de comandos fácil de usar.
- Generación de archivos de salida en formato `.dfa`.

## Requisitos 📋

- Sistema operativo basado en Unix (Linux, macOS).
- Compilador GCC instalado.
- Herramienta `make` disponible.

## Compilación y Uso 💻

1. Clona el repositorio en tu máquina local.
2. Navega hasta el directorio del proyecto.
3. Ejecuta el comando `make` para compilar el proyecto.
4. Luego de la compilación, ejecuta el programa con el comando `./ejecutable archivo.nfa output.dfa`.

## Ejemplos de Uso 📖

Supongamos que tienes un archivo llamado `miAutomata.nfa` y quieres convertirlo a DFA. Simplemente ejecuta:

```bash
./ejecutable miAutomata.nfa miAutomataDFA.dfa
