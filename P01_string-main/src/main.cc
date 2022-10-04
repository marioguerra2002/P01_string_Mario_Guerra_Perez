// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 04/10/2022
// Archivo ClienteChain.cc
// Contiene la función main del programa, la cual se encarga de leer el archivo de entrada 
// y de llamar a las funciones de la clase Chain
// Referencias:
// Enlaces de interés
#include "symbol.h"
#include "alphabet.h"
#include "chain.h"
#include <sstream>
int main(int argc, char* argv[]) {
  int opcode{std::stoi(argv[3])};
  std::ifstream inputfile(argv[1]);
  std::ofstream outputfile(argv[2]);
  std::string aux;
  if (inputfile.is_open()) {
    while (getline(inputfile, aux)) {
      std::string input;
      for (unsigned int i{0}; i < aux.size(); ++i) {
        input += aux[i];  // meto en input cada caracter de aux
      }
      Chain chain(input);
      // problema de aquí para abajo
      switch (opcode) {
        case 1:
        chain.Size();
        break;
        case 2:
        chain.Inverse();
        break;
        case 3:
        chain.Prefixes();
        break;
        case 4:
        chain.Sufixes();
        break;
        case 5:
        chain.SubChain();
        break;
        default:
        std::cerr << "Por favor, introduzca un valor válido" << std::endl;
      }
    }
  }
}