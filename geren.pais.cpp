#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <locale.h>

using namespace std;

struct pais
{
    int id;
    string nome;
    int populacao;
    string idioma;
    float PIB;
    float percapita;
};

const int n = 10;
struct pais lst[n] = { {1,"Brasil",212,"Portugues",2.179},
                       {2,"Espanha",49,"Espanhol",1.723},
				       {3,"Japao",124,"Japones",4.026},
				       {4,"Alemanha",83,"Alemao",4.660},
				       {5,"Australia",27,"Ingles",1.752} };
pais j;
int id, aux, k, i, tamanho = 0, opcao;
char conf;
string nome;
bool encontrado;

void inicializacao()
{
    if (tamanho >= n)
    {
        cout << "Lista cheia.\n";
        return;
    }

    pais p;
    cout << "digite o ID do pais:\n";
    cin >> p.id;
    cout << "digite o nome do pais:\n";
    cin >> p.nome;
    cout << "digite a população do pais:\n";
    cin >> p.populacao;
    cout << "digite o idioma do pais:\n";
    cin >> p.idioma;
    cout << "digite o PIB do pais:\n";
    cin >> p.PIB;
    cout << "digite a renda percapita do pais:\n";
    cin >> p.percapita;
    cout << "deseja confirmar a inserção na lista:\n";
    cin >> conf;

    if (conf == 's')
    {
        lst[tamanho] = p;
        tamanho++;
    }
    else
    {
        cout << "confirmação negada.\n";
    }
}

void inserirnaposicaok()
{
    if (tamanho >= n)
    {
        cout << "Lista cheia.\n";
        return;
    }
    if (k < 0 || k > tamanho)
    {
        cout << "Posição invalida.\n";
        return;
    }

    pais p;
    cout << "digite o ID do pais:\n";
    cin >> p.id;
    cout << "digite o nome do pais:\n";
    cin >> p.nome;
    cout << "digite a população do pais:\n";
    cin >> p.populacao;
    cout << "digite o idioma do pais:\n";
    cin >> p.idioma;
    cout << "digite o PIB do pais:\n";
    cin >> p.PIB;
    cout << "digite a renda percapita do pais:\n";
    cin >> p.percapita;
    cout << "confirme a inserção na lista:\n";
    cin >> conf;

    if (conf == 's')
    {
        for (i = tamanho; i > k; i--)
        {
            lst[i] = lst[i - 1];
        }
        lst[k] = p;
        tamanho++;
    }
    else
    {
        cout << "confirmação negada.\n";
    }
}

int procurarnome()
{
    for (i = 0; i < tamanho; i++)
    {
        if (lst[i].nome == nome)
        {
            return i;
        }
    }
    return -1;
}

void inseriraposnome()
{
    aux = procurarnome();
    if (aux != -1)
    {
        cout << "confirmar adição após " << lst[aux].nome << " de ID " << lst[aux].id << " ?\n";
        cin >> conf;
        if (conf == 's')
        {
            k = aux + 1;
            inserirnaposicaok();
        }
        else
        {
            cout << "adição não confirmada.\n";
        }
    }
    else
    {
        cout << "país não encontrado.\n";
    }
}

void excluirnopornome()
{
    aux = procurarnome();
    if (aux != -1)
    {
        cout << "deseja confirmar a remoção de " << lst[aux].nome;
        cin >> conf;
        if (conf == 's')
        {
            for (i = aux; i < tamanho - 1; i++)
            {
                lst[i] = lst[i + 1];
            }
            tamanho--;
            cout << "pais removido.\n";
        }
        else
        {
            cout << "confirmação negada.\n";
        }
    }
    else
    {
        cout << "país não encontrado.\n";
    }
}

void alterarporID()
{
    encontrado = false;
    for (i = 0; i < tamanho; i++)
    {
        if (lst[i].id == id)
        {
            cout << "confirmar alteração do " << lst[i].nome << " de ID " << lst[i].id << " ?\n";
            cin >> conf;
            encontrado = true;
            if (conf == 's')
            {
                cout << "novo nome:\n";
                cin >> lst[i].nome;
                cout << "nova população:\n";
                cin >> lst[i].populacao;
                cout << "novo idioma:\n";
                cin >> lst[i].idioma;
                cout << "novo PIB:\n";
                cin >> lst[i].PIB;
                cout << "nova renda percapita:\n";
                cin >> lst[i].percapita;
            }
            else
            {
                cout << "confirmação negada:\n";
            }
        }
    }
    if (!encontrado)
    {
        cout << "ID não encontrado.\n";
    }
}

void percapita2500e1500()
{
    encontrado = false;
    cout << "os países são:\n";
    for (i = 0; i < tamanho; i++)
    {
        if (lst[i].percapita <= 2500 && lst[i].percapita >= 1500)
        {
            cout << "Nome:"
                 << lst[i].nome
                 << ", ID:"
                 << lst[i].id
                 << ", renda per capita: " << lst[i].percapita << endl;
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        cout << "não há pais com renda per capita entre 2500 e 1500 na lista.\n";
    }
}

void ordemPIB()
{
    for (i = 0; i < tamanho - 1; i++)
    {
        for (aux = i + 1; aux < tamanho; aux++)
        {
            if (lst[i].PIB < lst[aux].PIB)
            {
                j = lst[i];
                lst[i] = lst[aux];
                lst[aux] = j;
            }
        }
    }
    cout << "aqui esta a lista ordenada por PIB:\n";
    for (i = 0; i < tamanho; i++)
    {
        cout << "nome:"
             << lst[i].nome
             << ", ID:"
             << lst[i].id
             << ", PIB:" << lst[i].PIB << endl;
    }
}

int main()
{
    while (true)
    {
        cout << "Escolha uma opção:\n";
        cout << "1. insira o primeiro país\n";
        cout << "2. Inserir no final\n";
        cout << "3. Inserir na posição K\n";
        cout << "4. Procurar por nome e inserir após o país encontrado\n";
        cout << "5. Procurar por nome e remover país\n";
        cout << "6. Procurar por ID e alterar conteudo\n";
        cout << "7. Imprimir países com renda per capita entre 1500 e 2500\n";
        cout << "8. Imprimir lista classificada por PIB (decrescente)\n";
        cout << "0. Sair\n";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            inicializacao();
            break;
        case 2:
            inicializacao();
            break;
        case 3:
            cout << "Digite a posição a ser inserida:\n";
            cin >> k;
            inserirnaposicaok();
            break;
        case 4:
            cout << "Digite o nome do país para inserir após:\n";
            cin >> nome;
            inseriraposnome();
            break;
        case 5:
            cout << "Digite o nome do país a ser removido:\n";
            cin >> nome;
            excluirnopornome();
            break;
        case 6:
            cout << "Digite o ID a ser alterado:\n";
            cin >> id;
            alterarporID();
            break;
        case 7:
            percapita2500e1500();
            break;
        case 8:
            ordemPIB();
            break;
        case 0:
            cout << "saindo...\n";
            return 0;
        default:
            cout << "Opção inválida.";
        }
    }

    return 0;
}
