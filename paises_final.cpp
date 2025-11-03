#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <locale.h>
#define n 10
using namespace std;

struct pais {
    int id;
    char nome[30];
    int populacao;
    char idioma[30];
    float PIB;
    float percapita;
};

struct pais lst[n] = { 
                       {1, "Brasil", 212, "Portugues", 2179, 15.27},
                       {2, "Espanha", 49, "Espanhol", 1723, 35.16},
				       {3, "Japao", 124, "Japones", 4026, 32.46},
				       {4, "Alemanha", 83, "Alemao", 4660, 56.14},
				       {5, "Australia", 27, "Ingles", 1752, 64.88}
					};
pais p, decres[n];
int id, aux, i, k, tamanho = 5, opcao=99;
char conf;
string nome;
bool encontrado;

void imprimir(){
	system("cls");
    for (i = 0; i < tamanho; i++){
        cout <<"ID:"<< lst[i].id<< "\nPais: "<< lst[i].nome<< "\nPopulação :" << lst[i].populacao <<
		" milhões\nIdioma: "<< lst[i].idioma<<"\nPIB: R$"<<lst[i].PIB<<" milhões\nPIB percapita: R$"<<
		lst[i].percapita<<" \n"<< endl;
    }
    system("pause");
}

void inserirnofinal(){
	system("cls");
    if(tamanho<n){
        cout << "Digite o ID do pais: ";
        cin >> p.id;
        cout << "\nDigite o nome do pais: ";
        cin >> p.nome;
        cout << "\nDigite a população do pais: ";
        cin >> p.populacao;
        cout << "\nDigite o idioma do pais: ";
        cin >> p.idioma;
        cout << "\nDigite o PIB do pais: ";
        cin >> p.PIB;
        p.percapita = p.PIB/p.populacao;
        cout << "\nConfirme a inserção na lista (S/N): ";
        cin >> conf;
		conf = toupper(conf);
		if(conf == 'S'){
			lst[tamanho] = p;
			cout<<"\nPaís adicionado ao final da lista.\n\n";
			tamanho++;
			system("Pause");
		}
		else{
			cout<<"\n\tConfirmação negada\n\n\tVoltando ao menu\n\n";
			system("pause");
		}	
	}
	else{
	    cout<<"\nLista cheia\n\n";
	    system("pause");
	}	
}

void inserirnaposicaok(){
	system("cls");
	cout << "Digite a posição em que será inserida: ";
    cin >> k;
    if (tamanho >= n){
        cout << "Lista cheia.\n";
        return;
    }
    if (k < 0 || k > tamanho){
        cout << "Posição invalida.\n";
        return;
    }
    else{
        cout << "\nDigite o ID do pais: ";
        cin >> p.id;
        cout << "\nDigite o nome do pais: ";
        cin >> p.nome;
        cout << "\nDigite a população do pais (em milhões): ";
        cin >> p.populacao;
        cout << "\nDigite o idioma do pais: ";
        cin >> p.idioma;
        cout << "\nDigite o PIB do pais (em milhões): ";
        cin >> p.PIB;
        p.percapita = p.PIB/p.populacao;
        cout << "\nConfirme a inserção na lista(S/N): ";
        cin >> conf;
        conf = toupper(conf);
        if (conf == 'S'){
            for (i = tamanho; i > k; i--){
                lst[i] = lst[i - 1];
            }
            lst[k] = p;
            tamanho++;
            cout << "\nConfirmado.\n\n";
            system("pause");
        }
        else{
            cout << "Confirmação negada.\n";
            system("pause");
        }
    }
}
int procurarnome(){
    for (i = 0; i < tamanho; i++){
        if (lst[i].nome == nome){
            return i;
        }
    }
    return -1;
}

void inseriraposnome(){
	system("cls");
	cout << "Digite o nome do país para inserir após:\n";
    cin >> nome;
    aux = procurarnome();
    if (aux != -1){
        cout << "\nConfirmar adição após " << lst[aux].nome << " com ID " << lst[aux].id << " ?\n";
        cin >> conf;
        conf = toupper(conf);
        if (conf == 'S'){
        	 cout << "\nDigite o ID do pais: ";
            cin >> p.id;
            cout << "\nDigite o nome do pais: ";
            cin >> p.nome;
            cout << "\nDigite a população do pais (em milhões): ";
            cin >> p.populacao;
            cout << "\nDigite o idioma do pais: ";
            cin >> p.idioma;
            cout << "\nDigite o PIB do pais (em milhões): ";
            cin >> p.PIB;
            p.percapita = p.PIB/p.populacao;
            k = aux + 1;
            for (i = tamanho; i > k; i--){
                lst[i] = lst[i - 1];
            }
            lst[k] = p;
            tamanho++;
            cout << "\nConfirmado.\n\n";
            system("pause");
        }
        else{
            cout << "\nAdição não confirmada.\n";
            system("pause");
        }
    }
    else{
        cout << "País não encontrado.\n\n";
        system("pause");
    }
}

void excluirpornome(){
	system("cls");
	cout << "\nDigite o nome do país a ser removido: ";
    cin >> nome;
    aux = procurarnome();
    if (aux != -1){
        cout << "\nDeseja confirmar a remoção de: " << lst[aux].nome<<" (S/N)?  ";
        cin >> conf;
        conf = toupper(conf);
        if (conf == 'S'){
            for (i = aux; i < tamanho - 1; i++){
                lst[i] = lst[i + 1];
            }
            tamanho--;
            cout << "\nPaís removido\n.";
            system("pause");
        }
        else{
            cout << "\nConfirmação negada.";
            system("pause");
        }
    }
    else{
        cout << "\nPaís não encontrado.";
        system("pause");
    }
}

void alterarporID(){
	system("cls");
	cout << "\nDigite o ID a ser alterado:\n";
    cin >> id;
    encontrado = false;
    for (i = 0; i < tamanho; i++){
        if (lst[i].id == id){
        	encontrado = true;
            cout << "\nConfirmar alteração do país: " << lst[i].nome << ", de ID " << lst[i].id << " (S/N)?:  ";
            cin >> conf;
            conf = toupper(conf);
            if (conf == 'S'){
                cout << "\nNovo nome: ";
                cin >> p.nome;
                cout << "\nNova população: ";
                cin >> p.populacao;
                cout << "\nNovo idioma: ";
                cin >> p.idioma;
                cout << "\nNovo PIB: ";
                cin >> p.PIB;
                p.percapita = p.PIB/p.populacao;
                cout << "\nConfirmar novos dados (S/N)? ";
                cin >> conf;
                conf = toupper(conf);
                if(conf == 'S'){
                	lst[i] = p;
                	cout << "\nDados atualizados.\n\n";
                	system("pause");
				}
                else{
                    cout << "\nAtualização cancelada.\n\n";
                    system("pause");
                }
            }
            else{
            	cout << "\nAtualização cancelada.\n";
            	system("pause");
			}
        }
    }
    if (encontrado == false){
        cout << "ID não encontrado.\n";
        system("pause");
    }
}

void percapita2500e1500(){
	system("cls");
    encontrado = false;
    for (i = 0; i < tamanho; i++){
        if (lst[i].percapita*1000 <= 25000 && lst[i].percapita*1000 >= 15000){
            cout << "\n" << lst[i].nome<< ", com uma renda per capita de: R$" << lst[i].percapita <<"(mil)\n";
            encontrado = true;
        }
    }
    if (encontrado == true){
    	system("pause");
    }
    else{
	    cout << "\nNão há paises com renda per capita entre 25000 e 15000 na lista.\n";
        system("pause");
    }	
}

void ordemPIB(){
	system("cls");
	for (i = 0; i < tamanho; i++)
    decres[i] = lst[i];
    for (i = 0; i < tamanho - 1; i++){
        for (aux = i + 1; aux < tamanho; aux++){
            if (decres[i].PIB < decres[aux].PIB){
                p = decres[i];
                decres[i] = decres[aux];
                decres[aux] = p;
            }
        }
    }
    cout << "\nAqui está a lista em ordem decrescente do PIB:\n\n";
    for (i = 0; i < tamanho; i++){
        cout << decres[i].nome<< ", com a ID: "<< decres[i].id<< " e PIB: R$" << decres[i].PIB << " milhões.\n\n";
    }
    system("pause");
}

int main() {
	setlocale(LC_ALL,"Portuguese");
    while (opcao != 0) {
    	system("cls");
        cout << "\n\tEscolha uma opção:";
        cout << "\n\t1 - Imprimir a lista";
        cout << "\n\t2 - Inserir no final";
        cout << "\n\t3 - Inserir na posição K";
        cout << "\n\t4 - Procurar por nome e inserir após o país encontrado";
        cout << "\n\t5 - Procurar por nome e remover país";
        cout << "\n\t6 - Procurar por ID e alterar conteudo";
        cout << "\n\t7 - Imprimir países com renda per capita entre 1500 e 2500";
        cout << "\n\t8 - Imprimir lista classificada por PIB (decrescente)";
        cout << "\n\t0 - Sair\n";
        if (!(cin >> opcao)) {
        cin.clear();                
        cin.ignore(1000, '\n');     
        opcao = -1;                 
        }

        switch (opcao){
        case 1: imprimir(); break;
        case 2: inserirnofinal(); break;
        case 3: inserirnaposicaok(); break;
        case 4: inseriraposnome(); break;
        case 5: excluirpornome(); break;
        case 6: alterarporID(); break;
        case 7: percapita2500e1500(); break;
        case 8: ordemPIB(); break;
        case 0:
            cout << "\nSaindo...\n"; break;
        default:
            cout << "\nOpção inválida.\n\n";
            system("pause"); break;
        }
    }
    return 0;
}
