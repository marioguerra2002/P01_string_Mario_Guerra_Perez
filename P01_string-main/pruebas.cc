#include <vector>
#include <string>
#include <iostream>
#include <set>

int main() {
  std::vector<std::string> vect_auxiliar;
  std::string auxiliar;

  std::vector<std::string> chain;
  std::set<std::string> alphabet;
  const char SPACE{' '};

  std::string input = "ab bc cd abcda";
  for (int i{0}; i < input.size(); ++i) {
    if (input[i] != SPACE) {
      auxiliar += input[i];
    } else {
      vect_auxiliar.push_back(auxiliar);
      auxiliar = "";
    }
  }
  vect_auxiliar.push_back(auxiliar);  // meto el último símbolo (cadena)
  auxiliar = "";  // vacío auxiliar
  for (int i{0}; i < vect_auxiliar.size(); ++i) {
    std::cout << i << ": " << vect_auxiliar[i] << std::endl;
  }
  std::cout << "Vector de string auxiliar creado\n" << std::endl;
  //hasta aqui bien
  //Voy a hacer alfabeto
  for (int i{0}; i < vect_auxiliar.size() - 1; ++i) {
    alphabet.insert(vect_auxiliar[i]);
  }
  std::cout << "Alfabeto: " << std::endl;
  for (auto it = alphabet.begin(); it != alphabet.end(); ++it) {
    std::cout << *it << std::endl;
  }
  std::cout << "Alfabeto creado\n" << std::endl;
  //hasta aqui bien (alfabeto)
  for (int i{0}; i < vect_auxiliar[vect_auxiliar.size() - 1].size(); ++i) {
    //vamos a recorrer el último elemento del vector, que es el símbolo final (chain)
    auxiliar += vect_auxiliar[vect_auxiliar.size() - 1][i];
    for (auto it = alphabet.begin(); it != alphabet.end(); ++it) {
      if (auxiliar == *it) {
        chain.push_back(*it);
        auxiliar = "";
      }
    }
  }
  if (auxiliar != "") {
    chain.push_back(auxiliar);
    std::cout << "Error: cadena no válida" << std::endl;
  }
  // en caso de que auxiliar no esté vacío, es que no se ha encontrado el símbolo, por lo que no es una cadena válida
  // en este punto deberíamos tener la cadena en chain_ separada en símbolos
  std::cout << "Cadena: " << std::endl;
  for (int i{0}; i < chain.size(); ++i) {
    std::cout << chain[i];
  }
  std::cout << std::endl;

}
// int main() {
//   std::string prueba = "hola";
//   int prueba_valor{0};
//   for (int i{0}; i < prueba.size(); ++i) {
//     prueba_valor += (int)prueba[i];
//   }
//   std::cout << prueba_valor << std::endl;
// }
