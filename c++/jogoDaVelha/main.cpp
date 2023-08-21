#include <iostream>
#include <string>
#include <random>
using namespace std;

int status = 0;
string tabela[9] = {"0", "1", "2", "3", "4", "5", "6", "7", "8"};



void jogar(){

  int jogada;
  int terminar = 1;
  
  cout << "Faça sua jogada: ";

  while(terminar == 1) {
      cin >> jogada;
    if(tabela[jogada] != "o" && tabela[jogada] != "x" && jogada >= 0 && jogada < 9) {
      tabela[jogada] = "x";
      terminar = 0;
    
    } else{
        cout << "Faça outra jogada!" << endl;
      
    }
  }
}



void jogarPc() {
  int jogada;
  int terminar = 1;

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dist(0,8);
      
  while(terminar == 1) {

    jogada = dist(gen);
    
    if(tabela[jogada] != "x" && tabela[jogada] != "o" && jogada >= 0 && jogada < 9) {
      tabela[jogada] = "o";
      terminar = 0;
    }

    cout << "O computador escolheu a posição " << jogada << "\n";
    
  }
}



void verificar() {
  if ((tabela[0] == "x" && tabela[1] == "x" && tabela[2] == "x") ||
      (tabela[3] == "x" && tabela[4] == "x" && tabela[5] == "x") ||
      (tabela[6] == "x" && tabela[7] == "x" && tabela[8] == "x") ||
      (tabela[0] == "x" && tabela[3] == "x" && tabela[6] == "x") ||
      (tabela[1] == "x" && tabela[4] == "x" && tabela[7] == "x") ||
      (tabela[2] == "x" && tabela[5] == "x" && tabela[8] == "x") ||
      (tabela[0] == "x" && tabela[4] == "x" && tabela[8] == "x") ||
      (tabela[2] == "x" && tabela[4] == "x" && tabela[6] == "x")) {
    status = 1;
  } else if ((tabela[0] == "o" && tabela[1] == "o" && tabela[2] == "o") ||
             (tabela[3] == "o" && tabela[4] == "o" && tabela[5] == "o") ||
             (tabela[6] == "o" && tabela[7] == "o" && tabela[8] == "o") ||
             (tabela[0] == "o" && tabela[3] == "o" && tabela[6] == "o") ||
             (tabela[1] == "o" && tabela[4] == "o" && tabela[7] == "o") ||
             (tabela[2] == "o" && tabela[5] == "o" && tabela[8] == "o") ||
             (tabela[0] == "o" && tabela[4] == "o" && tabela[8] == "o") ||
             (tabela[2] == "o" && tabela[4] == "o" && tabela[6] == "o")) {
    status = 2;
  }
}



int main() {
  cout << "Jogo da Velha" << endl;

  while(status == 0) {
    
    cout << tabela[0] + " | " << tabela[1] + " | " << tabela[2] << "\n" << tabela[3] + " | " << tabela[4] + " | " << tabela[5] << "\n" << tabela[6] + " | " << tabela[7] + " | " << tabela[8] << "\n";

    verificar();
    jogar();
    jogarPc();

  }

  if(status == 1) {
    cout << "Você ganhou!" << endl;
  } else if(status == 2) {
    cout << "Você perdeu!" << endl;
  }
}