#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct notaFiscal {
  int NF;
  int ocorrencia;
  string produto;
  notaFiscal *proximo = nullptr;
};

void adicionar(int &notafiscal, notaFiscal *&ponteiro, notaFiscal *&ultimo);
bool consultar(int &notafiscal, notaFiscal *&aux, notaFiscal *&inicioLista, notaFiscal *&antigoULtimo);
void pausarSistema();
void limparTela();

int main() {
  notaFiscal *ponteiro = nullptr, *inicioLista = nullptr, *ultimo = nullptr, *aux = nullptr, *antigoUltimo = nullptr;
  int opcao, notafiscal;
  bool resposta = true, primeiraVez = true, existe = false;

  do {
    cout << "\n===== MENU =====" << endl;
    cout << "1. Adicionar NotaFiscal" << endl;
    cout << "2. Consultar NotaFiscal" << endl;
    cout << "3. Atualizar NotaFiscal" << endl;
    cout << "4. Excluir NotaFiscal" << endl;
    cout << "5. Sair" << endl;
    cout << "Digite uma opcao: ";
    cin >> opcao;

    switch (opcao) {
        case 1: // adicionar
        cout << "\n\t--INCLUINDO NF--";
        cout << "\n\tDigite o codigo da NF: ";
        cin >> notafiscal;

        if (primeiraVez) {
          inicioLista = new notaFiscal;
          inicioLista->NF = notafiscal;
          cout << " \n\tDigite o codigo da Ocorrencia: ";
          cin >> inicioLista->ocorrencia;
          cin.ignore();
          cout << "\n\tDigite o nome do produdo: ";
          getline(cin, inicioLista->produto);

          inicioLista->proximo = nullptr;
          ultimo = inicioLista;
          primeiraVez = false;
          cout << "\n\tNF cadastrada!" << endl;
          pausarSistema();
        } else {

          existe = consultar(notafiscal, aux, inicioLista, antigoUltimo);

          if (existe) {
            cout << "\n\tNF ja cadastrada" << endl;
          } else {
            adicionar(notafiscal, ponteiro, ultimo);
            cout << endl;
          }
          pausarSistema();
        }
        break;

        case 2: // consultar
        cout << "\n\t--Consultar NF--";
        cout << "\n\tDigite o codigo da NF: ";
        cin >> notafiscal;

        existe = consultar(notafiscal, aux, inicioLista, antigoUltimo);

        if (existe) {
          cout << "\n\t-- NF Cadastrada --";
          cout << "\n\tCodigo NF: ";
          cout << aux->NF;
          cout << "\n\tCodigo da Ocorrencia: ";
          cout << aux->ocorrencia;
          cout << "\n\tNome do Produto: ";
          cout << aux->produto << endl;
          pausarSistema();
        } else {
          cout << "\n\tNF nao cadastrada" << endl;
          pausarSistema();
        }
        break;

        case 3 : // atualizar
        cout << "\n\t--Atualizar NF--";
        cout << "\n\tDigite o codigo da NF: ";
        cin >> notafiscal;

        existe = consultar(notafiscal, aux, inicioLista, antigoUltimo);

        if(existe){
          cout << " \n\tAtualize o codigo da Ocorrencia: ";
          cin >> aux->ocorrencia;
          cin.ignore();
          cout << "\n\tDigite o nome do produdo: ";
          getline(cin, aux->produto);
          cout << "\n\tNF cadstrada com sucesso!" << endl;
          pausarSistema();
        }else{
          cout << "\n\tNF nao cadastrada" << endl;
          pausarSistema();
        }
        break;

        case 4: // deletar
        cout << "\n\t--Deletar NF--";
        cout << "\n\tDigite o codigo da NF: ";
        cin >> notafiscal;

        existe = consultar(notafiscal, aux, inicioLista, antigoUltimo);

          if(existe){
            antigoUltimo ->proximo = aux ->proximo;
            delete(aux);
            cout << "\n\tNF deletada com sucesso!" << endl;
            pausarSistema();
          }else{
            cout << "\n\tNF nao cadastrada" << endl;
            pausarSistema();
          }
        break;

        default: // Sair do programa
        cout << "\n\tFim de Programa" << endl;
        resposta = false;
        pausarSistema();
        break;
    }
    limparTela();

  } while (resposta);

  return 0;
}

void adicionar(int &notafiscal, notaFiscal *&ponteiro, notaFiscal *&ultimo) {

  ponteiro = new notaFiscal;

  ponteiro->NF = notafiscal;
  cout << " \n\tDigite o codigo da Ocorrencia: ";
  cin >> ponteiro->ocorrencia;
  cin.ignore();
  cout << "\n\tDigite o nome do produdo: ";
  getline(cin, ponteiro->produto);

  ponteiro->proximo = nullptr;
  ultimo->proximo = ponteiro;
  ultimo = ponteiro;
  cout << "\n\tNF cadastrada com sucesso! ";
}

bool consultar(int &notafiscal, notaFiscal *&aux, notaFiscal *&inicioLista, notaFiscal *&antigoUltimo) {
  if(inicioLista == nullptr){
    inicioLista = new notaFiscal;
  }
  
  aux = inicioLista;
  antigoUltimo = inicioLista;

  if (aux ->NF == notafiscal) {
    return true;
  }
  aux = inicioLista ->proximo;

  while( aux != nullptr){
    if( aux ->NF == notafiscal ) {
      return true;
    }
    antigoUltimo = aux;
    aux = aux ->proximo;
  }
  
  return false;
}

void pausarSistema() {
  cout << "\n\tPressione Enter para continuar";
  cin.ignore();
  getchar();
}

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}