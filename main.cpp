#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // Para system("clear") ou system("cls")

using namespace std;


#define INVALID_INPUT -99

int id_codigo = 0;

struct Cliente {
int codigo;
    string nomeCliente;
    string cpf;
    string email;
    string whatsapp;

Cliente(string nomeCliente, string cpf, string email, string whatsapp) :
        nomeCliente(nomeCliente), cpf(cpf), email(email), whatsapp(whatsapp) {
id_codigo++;
  codigo = id_codigo;
}
   
    Cliente() : nomeCliente(""), cpf(""), email(""), whatsapp("") {
id_codigo++;
  codigo = id_codigo;
}
   
};



struct Produto {
    int codigo;
    string nomeProduto;
    double preco;
    int quantidade;
   
    Produto(string nomeProduto, double preco, int quantidade) :
        nomeProduto(nomeProduto), preco(preco), quantidade(quantidade) {
  id_codigo++;
  codigo = id_codigo;
}

    Produto() : nomeProduto(""), preco(0.0), quantidade(0.0) {
id_codigo++;
  codigo = id_codigo;
}

};

bool fazerLogin() {
    const string usuarioCorreto = "admin";
    const string senhaCorreta = "1234";
   
    string usuario, senha;
    int tentativas = 0;
   
    while (tentativas < 3) {
        system("cls");
        cout << "=== LOGIN DO OPERADOR ===\n";
        cout << "Usuario: ";
        cin >> usuario;
        cout << "Senha: ";
        cin >> senha;
       
        if (usuario == usuarioCorreto && senha == senhaCorreta) {
            return true;
        } else {
            cout << "\nUsuario ou senha incorretos! Tentativas restantes: "
                 << (2 - tentativas) << endl;
            cin.ignore();
    cin.get();
tentativas++;
        }
    }
   
    cout << "\nNumero maximo de tentativas alcancado. Encerrando programa.\n";
    return false;
}

void cadastrarCliente(vector<Cliente>& clientes) {
    system("cls");
    cout << "=== CADASTRO DE CLIENTE ===\n";
   
    Cliente novo;
   
    id_codigo++;
    novo.codigo = id_codigo;
   
    cout << "Nome: ";
    cin.ignore();
    getline(cin, novo.nomeCliente);
    cout << "CPF: ";
    getline(cin, novo.cpf);
    cout << "Email: ";
    getline(cin, novo.email);
    cout << "WhatsApp: ";
    getline(cin, novo.whatsapp);
   
    clientes.push_back(novo);
    cout << "\nCliente cadastrado com sucesso!\n";

cin.ignore();
    cin.get();
}

// Função para listar clientes
void listarClientes(const vector<Cliente>& clientes) {
    system("cls");
    cout << "=== LISTA DE CLIENTES ===\n";
   
    if (clientes.empty()) {
        cout << "Nenhum cliente cadastrado.\n";
    } else {
        for (size_t i = 0; i < clientes.size(); ++i) {
            cout << "Cliente #" << (i+1) << ":\n";
            cout << "Nome: " << clientes[i].nomeCliente << endl;
            cout << "CPF: " << clientes[i].cpf << endl;
            cout << "Email: " << clientes[i].email << endl;
            cout << "WhatsApp: " << clientes[i].whatsapp << endl;
            cout << "------------------------\n";
        }
    }

cin.ignore();
    cin.get();
}

// Função para remover cliente
void removerCliente(vector<Cliente>& clientes) {
    system("cls");
    cout << "=== REMOVER CLIENTE ===\n";
   
    if (clientes.empty()) {
        cout << "Nenhum cliente cadastrado para remover.\n";

cin.ignore();
    cin.get();
        return;
    }
   
    listarClientes(clientes);
   
    int indice;
    cout << "\nDigite o numero do cliente que deseja remover (0 para cancelar): ";
    cin >> indice;
   
    if (indice == 0) {
        return;
    } else if (indice > 0 && indice <= static_cast<int>(clientes.size())) {
        clientes.erase(clientes.begin() + (indice - 1));
        cout << "Cliente removido com sucesso!\n";
    } else {
        cout << "Indice invalido!\n";
    }
   
cin.ignore();
    cin.get();
}

// Função para gerenciar clientes
void gerenciarClientes(vector<Cliente>& clientes) {
    int opcao;
    do {
        system("cls");
        cout << "=== GERENCIAMENTO DE CLIENTES ===\n";
        cout << "1. Cadastrar novo cliente\n";
        cout << "2. Listar clientes cadastrados\n";
        cout << "3. Remover cliente\n";
        cout << "0. Voltar ao menu principal\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
       
        if (cin.fail()) {
cin.clear();
cin.ignore();

opcao = INVALID_INPUT;
}
       
        switch (opcao) {
            case 1:
                cadastrarCliente(clientes);
                break;
            case 2:
                listarClientes(clientes);
                break;
            case 3:
                removerCliente(clientes);
                break;
            case 0:
                break;
            default:
                cout << "Opcao invalida!\n";
               
cin.ignore();
    cin.get();
        }
    } while (opcao != 0);
}

// Função para listar produtos
void listarProdutos(const vector<Produto>& produtos) {
    system("cls");
    cout << "=== LISTA DE PRODUTOS ===\n";
   
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado.\n";
    } else {
        for (size_t i = 0; i < produtos.size(); ++i) {
            cout << "Codigo: " << produtos[i].codigo << " | ";
            cout << "Nome: " << produtos[i].nomeProduto << " | ";
            cout << "Preco: R$ " << produtos[i].preco << " | ";
            cout << "Quantidade: " << produtos[i].quantidade << endl;
            cout << "--------------------------------------------\n";
        }
    }

cin.ignore();
    cin.get();
}

// Função para adicionar produto
void adicionarProduto(vector<Produto>& produtos) {
    system("cls");
    cout << "=== ADICIONAR PRODUTO ===\n";
   
    Produto novo;
   

id_codigo++;
novo.codigo = id_codigo;
cout << "Nome: ";
    cin.ignore();
    getline(cin, novo.nomeProduto);
    cout << "Preco: ";
    cin >> novo.preco;
    cout << "Quantidade: ";
    cin >> novo.quantidade;
   
    produtos.push_back(novo);
    cout << "\nProduto adicionado com sucesso!\n";
   
cin.ignore();
    cin.get();
}

// Função para editar produto
void editarProduto(vector<Produto>& produtos) {
    system("cls");
    cout << "=== EDITAR PRODUTO ===\n";
   
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado para editar.\n";
       
cin.ignore();
    cin.get();
        return;
    }
   
    listarProdutos(produtos);
   
    int codigo;
    cout << "\nDigite o codigo do produto que deseja editar (0 para cancelar): ";
    cin >> codigo;
   
    if (codigo == 0) {
        return;
    }
   
    bool encontrado = false;
    for (size_t i = 0; i < produtos.size(); ++i) {
        if (produtos[i].codigo == codigo) {
            cout << "Novo nome (" << produtos[i].nomeProduto << "): ";
            cin.ignore();
            getline(cin, produtos[i].nomeProduto);
            cout << "Novo preco (" << produtos[i].preco << "): ";
            cin >> produtos[i].preco;
            cout << "Nova quantidade (" << produtos[i].quantidade << "): ";
            cin >> produtos[i].quantidade;
           
            cout << "Produto atualizado com sucesso!\n";
            encontrado = true;
            break;
        }
    }
   
    if (!encontrado) {
        cout << "Produto com codigo " << codigo << " nao encontrado!\n";
    }
   
cin.ignore();
    cin.get();
}

// Função para remover produto
void removerProduto(vector<Produto>& produtos) {
    system("cls");
    cout << "=== REMOVER PRODUTO ===\n";
   
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado para remover.\n";
}      
   
    listarProdutos(produtos);
   
    int codigo;
    cout << "\nDigite o codigo do produto que deseja remover (0 para cancelar): ";
    cin >> codigo;
   
    if (codigo == 0) {
        return;
    }
   
    bool encontrado = false;
    for (size_t i = 0; i < produtos.size(); ++i) {
        if (produtos[i].codigo == codigo) {
            produtos.erase(produtos.begin() + i);
            cout << "Produto removido com sucesso!\n";
            encontrado = true;
            break;
        }
    }
   
    if (!encontrado) {
        cout << "Produto com codigo " << codigo << " nao encontrado!\n";
    }
   
            cin.ignore();
    cin.get();
}

// Função para gerenciar estoque
void gerenciarEstoque(vector<Produto>& produtos) {
    int opcao;
    do {
        system("cls");
        cout << "=== GERENCIAMENTO DE ESTOQUE ===\n";
        cout << "1. Listar produtos\n";
        cout << "2. Editar produto\n";
        cout << "3. Adicionar produto\n";
        cout << "4. Remover produto\n";
        cout << "0. Voltar ao menu principal\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
       
        if (cin.fail()) {
cin.clear();
cin.ignore();

opcao = INVALID_INPUT;
}
       
       
       
        switch (opcao) {
            case 1:
                listarProdutos(produtos);
                break;
            case 2:
                editarProduto(produtos);
                break;
            case 3:
                adicionarProduto(produtos);
                break;
            case 4:
                removerProduto(produtos);
                break;
            case 0:
                break;
            default:
                cout << "Opcao invalida!\n";
cin.ignore();
    cin.get();
        }
    } while (opcao != 0);
}


void venderProdutos(vector<Produto>& produtos, const vector<Cliente>& clientes) {
    system("cls");
    cout << "=== VENDA DE PRODUTOS ===\n";
   
    if (clientes.empty()) {
        cout << "Nenhum cliente cadastrado. Cadastre um cliente primeiro.\n";
cin.ignore();
    cin.get();
        return;
    }
   
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado. Cadastre produtos primeiro.\n";
cin.ignore();
    cin.get();
        return;
    }
   
    // Selecionar cliente
    listarClientes(clientes);
    int clienteIdx;
    cout << "\nDigite o numero do cliente que esta comprando (0 para cancelar): ";
    cin >> clienteIdx;
   
    if (cin.fail()) {
cin.clear();
cin.ignore();

clienteIdx = INVALID_INPUT;
}
   
    if (clienteIdx == 0) {
        return;
    } else if (clienteIdx < 1 || clienteIdx > static_cast<int>(clientes.size())) {
        cout << "Cliente invalido!\n";
cin.ignore();
    cin.get();
        return;
    }
   
    const Cliente& cliente = clientes[clienteIdx - 1];
   
    // Processar venda
    vector<Produto> carrinho;
    vector<int> quantidades;
    double total = 0.0;
   
    int opcao;
    do {
        system("cls");
        cout << "=== CARRINHO DE COMPRAS ===\n";
        cout << "Cliente: " << cliente.nomeCliente << endl;
        cout << "Itens no carrinho: " << carrinho.size() << endl;
        cout << "Total: R$ " << total << endl;
        cout << "---------------------------\n";
        cout << "1. Adicionar produto\n";
        cout << "2. Finalizar compra\n";
        cout << "0. Cancelar venda\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
       
        if (opcao == 1) {
            system("cls");
            listarProdutos(produtos);
           
            int codigo, quantidade;
            cout << "\nDigite o codigo do produto (0 para voltar): ";
            cin >> codigo;
           
            if (codigo == 0) continue;
           
            bool encontrado = false;
            for (size_t i = 0; i < produtos.size(); ++i) {
                if (produtos[i].codigo == codigo) {
                    cout << "Quantidade (disponivel: " << produtos[i].quantidade << "): ";
                    cin >> quantidade;
                   
                    if (quantidade <= 0) {
                        cout << "Quantidade invalida!\n";
					cin.ignore();
    				cin.get();
                        break;
                    }
                   
                    if (quantidade > produtos[i].quantidade) {
                        cout << "Quantidade indisponivel em estoque!\n";
					cin.ignore();
    				cin.get();
                        break;
                    }
                   
                    // Adicionar ao carrinho
                    carrinho.push_back(produtos[i]);
                    quantidades.push_back(quantidade);
                    total += produtos[i].preco * quantidade;
                   
                    // Atualizar estoque
                    produtos[i].quantidade -= quantidade;
                   
                    cout << "Produto adicionado ao carrinho!\n";
                    encontrado = true;
				cin.ignore();
        		cin.get();
                    break;
                }
            }
           
            if (!encontrado) {
                cout << "Produto nao encontrado!\n";
			cin.ignore();
    		cin.get();
            }
        } else if (opcao == 2) {
            if (carrinho.empty()) {
                cout << "Carrinho vazio! Adicione produtos primeiro.\n";
			cin.ignore();
    		cin.get();
                continue;
            }
           
            // Emitir nota fiscal
            
		cin.ignore();
    	cin.get();
   
            break;
        } else if (opcao != 0) {
            cout << "Opcao invalida!\n";
           
		cin.ignore();
    	cin.get();
        }
    } while (opcao != 0);
   
    // Se cancelou a venda, devolver produtos ao estoque
    if (opcao == 0 && !carrinho.empty()) {
        for (size_t i = 0; i < carrinho.size(); ++i) {
            for (size_t j = 0; j < produtos.size(); ++j) {
                if (produtos[j].codigo == carrinho[i].codigo) {
                    produtos[j].quantidade += quantidades[i];
                    break;
                }
            }
        }
        cout << "Venda cancelada. Produtos devolvidos ao estoque.\n";
		cin.ignore();
    	cin.get();
    }
}

int main() {
    vector<Cliente> clientes;
    vector<Produto> produtos;
   
    // Adicionar alguns produtos iniciais
    produtos.push_back(Produto("Chapéu de Cowboy", 120.90, 50));
    produtos.push_back(Produto("Botas texana de couro", 360.60, 40));
    produtos.push_back(Produto("Calças de gado", 240.59, 30));
    produtos.push_back(Produto("Camisa de flanela", 80.50, 35));
    produtos.push_back(Produto("Cintos de couro", 150.70, 60));
    produtos.push_back(Produto("Esporas de cavalo", 90.2, 60));
    produtos.push_back(Produto("Luvas de couro", 60.40, 60));
    produtos.push_back(Produto("Bandanas exportadas", 20.39, 60));
    produtos.push_back(Produto("Sacos de dormir", 250.30, 60));
    produtos.push_back(Produto("Mochilas de couro", 200.20, 60));
    produtos.push_back(Produto("Água de colônia", 30.50, 60));
    produtos.push_back(Produto("Sabonetes artesanais", 7.50, 60));
    produtos.push_back(Produto("Perfumes de polvora", 230.85, 60));
    produtos.push_back(Produto("Lanternas a óleo", 100.00, 60));
    produtos.push_back(Produto("Uísque Jack Daniel's Honey", 160.50, 60));
    produtos.push_back(Produto("Chopp Bresser Ipa (1,5 L)", 25.60 , 60));
    produtos.push_back(Produto("Vinho Tinto", 30.90, 60));
    produtos.push_back(Produto("Sela de cavalo (todas as raças)", 450.69, 60));
    produtos.push_back(Produto("Ferradura de Metal (todas as raças)", 63.50, 60));
    produtos.push_back(Produto("Manta de couro de ovelha", 190.40, 60));
   
    if (!fazerLogin()) {
        return 0;
    }
   
    int opcao;
    do {
        system("cls");
        cout << "=== MENU PRINCIPAL ===\n";
        cout << "1. Gerenciar clientes\n";
        cout << "2. Gerenciar estoque\n";
        cout << "3. Vender produtos\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
       
        if (cin.fail()) {
		cin.clear();
		cin.ignore();

		opcao = INVALID_INPUT;
		}
       
        switch (opcao) {
            case 1:
                gerenciarClientes(clientes);
                break;
            case 2:
                gerenciarEstoque(produtos);
                break;
            case 3:
                venderProdutos(produtos, clientes);
                break;
            case 0:
                cout << "Encerrando programa...\n";
                break;
            default:
                cout << "Opcao invalida!\n";

		cin.ignore();
    	cin.get();
        }
    } while (opcao != 0);
   
    return 0;
}
