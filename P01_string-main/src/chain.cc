// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 04/10/2022
// Archivo chain.cc
// Contiene las declaraciones de los métodos de la clase Chain
// Referencias:
// Enlaces de interés
#include "chain.h"
Chain::Chain(std::string input) {
  std::string auxiliar;
  std::vector<std::string> vect_auxiliar;
  for (unsigned int i{0}; i < input.size(); ++i) {
    if (input[i] != kSpace) {
      auxiliar += input[i];
    } else {
      vect_auxiliar.push_back(auxiliar);
      auxiliar = "";
    }
  }
  vect_auxiliar.push_back(auxiliar);  // meto el último símbolo (cadena)
  auxiliar = "";  // vacío auxiliar
  alphabet_ = Alphabet(vect_auxiliar);  // Aquí se crea el alfabeto
  for (unsigned int i{0}; i < vect_auxiliar[vect_auxiliar.size() - 1].size(); ++i) {
    //vamos a recorrer el último elemento del vector, que es el símbolo final (chain)
    auxiliar += vect_auxiliar[vect_auxiliar.size() - 1][i];
    for (auto& symbol : alphabet_.GetSet()) {
      if (auxiliar == symbol.GetSymbol()) {
        chain_.push_back(symbol);
        auxiliar = "";
      }
    }
  }
  if (auxiliar != "") {
    chain_.push_back(Symbol(auxiliar));
    std::cout << "Error: cadena no válida" << std::endl;
  }
  // en caso de que auxiliar no esté vacío, es que no se ha encontrado el símbolo, por lo que no es una cadena válida
  // en este punto deberíamos tener la cadena en chain_ separada en símbolos
}
Chain Chain::GetChain() {
  return *this;
}
std::ostream &operator<<(std::ostream &os, const Chain &chain) {
  for (auto& symbol : chain.chain_) {
    os << symbol.GetSymbol();
  }
  os << std::endl;
  return os;
}
std::ostream &operator<<(std::ostream &os, const std::vector<Symbol> &vector) {
  for (auto& symbol : vector) {
    os << symbol.GetSymbol();
  }
  os << std::endl;
  return os;
}
std::istream &operator>>(std::istream &is, Chain &chain) {
  std::string input;
  is >> input;
  chain = Chain(input);
  return is;
}
void Chain::Size() {
  std::stringstream output;
  output << std::endl;
  std::ofstream outputtext("output_file.txt");
  output << chain_.size();
  outputtext << output.str();
}
void Chain::Inverse() {
  std::vector<Symbol> inverse;
  std::stringstream output;
  // recorro vector al revés
  for (long unsigned int i{chain_.size() - 1}; i >= 0 && i != chain_.empty(); --i) {
    // usamos el empty() para que no se salga del vector (me estaba dando error)
    inverse.push_back(chain_[i]);
  }
  inverse.push_back(chain_[0]);
  output << std::endl;
  std::ofstream outputtext("output_file.txt");

  for (auto& symbol : inverse) {
    output << symbol.GetSymbol();
  }
  outputtext << output.str();
}
void Chain::Prefixes() {
  std::vector<Symbol> prefixes;
  std::string auxiliar;
  std::stringstream output;
  output << std::endl;
  prefixes.push_back(Symbol(kEpsilon));
  for (unsigned int i{0}; i < chain_.size(); ++i) {
    // cojo símbolo a símbolo de la cadena empezando por el primero
    // luego cojo el siguiente símbolo y lo concateno al anterior
    auxiliar += chain_[i].GetSymbol();
    prefixes.push_back(Symbol(auxiliar));
  }
  std::ofstream outputtext("output_file.txt");
  for (auto& symbol : prefixes) {
    output << symbol.GetSymbol() << " ";
  }
  outputtext.write(output.str().c_str(), output.str().size());
  //outputtext << output.str();
}
void Chain::Sufixes() {
  std::vector<Symbol> suffixes;
  std::string auxiliar;
  std::stringstream output;
  output << std::endl;
  suffixes.push_back(Symbol(kEpsilon));
  // igual que en Prefixes, pero empezando por el final
  // y recorriendo el vector al revés
  for (long unsigned int i{chain_.size() - 1}; i >= 0 && i != chain_.empty(); --i) {
    // usamos el empty() para que no se salga del vector (me estaba dando error)
    auxiliar = chain_[i].GetSymbol() + auxiliar;
    suffixes.push_back(Symbol(auxiliar));
  }
  std::ofstream outputtext("output_file.txt");
  for (auto& symbol : suffixes) {
    output << symbol.GetSymbol() << " ";
  }
  outputtext << output.str();
}
void Chain::SubChain() {
  std::vector<Symbol> subchain;
  std::string auxiliar;
  std::stringstream output;
  output << std::endl;
  subchain.push_back(Symbol(kEpsilon));
  //subchain.push_back(Symbol(kSpace_b));
  for (unsigned int i{0}; i < chain_.size(); ++i) {
    for (unsigned int j{i}; j < chain_.size(); ++j) {
      //a partir del primero, cojo símbolo a símbolo siguientes
      auxiliar += chain_[j].GetSymbol();
      subchain.push_back(Symbol(auxiliar));
    }
    auxiliar = "";
  }
  std::ofstream outputtext("output_file.txt");
  for (auto& symbol : subchain) {
    output << symbol.GetSymbol() << " ";
  }
  outputtext << output.str();
}