#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // Para system("clear") ou system("cls")

using namespace std;

// Struct para clientes
struct Cliente {
    string nome;
    string cpf;
    string rg;
    string email;
    string whatsapp;
    
    // Construtor no padrão C++98
    Cliente() : nome(""), cpf(""), rg(""), email(""), whatsapp("") {}
    
    Cliente(string n, string c, string r, string e, string w) : 
        nome(n), cpf(c), rg(r), email(e), whatsapp(w) {}
};

// Struct para produtos
struct Produto {
    int codigo;
    string nome;
    double preco;
    int quantidade;
    
    // Construtor no padrão C++98
    Produto() : codigo(0), nome(""), preco(0.0), quantidade(0) {}
    
    Produto(int c, string n, double p, int q) : 
        codigo(c), nome(n), preco(p), quantidade(q) {}
};

// Função para limpar a tela (multiplataforma)
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Função para pausar a execução
void pausar() {
    cout << "\nPressione Enter para continuar...";
    cin.ignore();
    cin.get();
}

// Função para login
bool fazerLogin() {
    const string usuarioCorreto = "admin";
    const string senhaCorreta = "1234";
    
    string usuario, senha;
    int tentativas = 0;
    
    while (tentativas < 3) {
        limparTela();
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
            pausar();
            tentativas++;
        }
    }
    
    cout << "\nNumero maximo de tentativas alcancado. Encerrando programa.\n";
    return false;
}

// Função para cadastrar cliente
void cadastrarCliente(vector<Cliente>& clientes) {
    limparTela();
    cout << "=== CADASTRO DE CLIENTE ===\n";
    
    Cliente novo;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, novo.nome);
    cout << "CPF: ";
    getline(cin, novo.cpf);
    cout << "RG: ";
    getline(cin, novo.rg);
    cout << "Email: ";
    getline(cin, novo.email);
    cout << "WhatsApp: ";
    getline(cin, novo.whatsapp);
    
    clientes.push_back(novo);
    cout << "\nCliente cadastrado com sucesso!\n";
    pausar();
}

// Função para listar clientes
void listarClientes(const vector<Cliente>& clientes) {
    limparTela();
    cout << "=== LISTA DE CLIENTES ===\n";
    
    if (clientes.empty()) {
        cout << "Nenhum cliente cadastrado.\n";
    } else {
        for (size_t i = 0; i < clientes.size(); ++i) {
            cout << "Cliente #" << (i+1) << ":\n";
            cout << "Nome: " << clientes[i].nome << endl;
            cout << "CPF: " << clientes[i].cpf << endl;
            cout << "RG: " << clientes[i].rg << endl;
            cout << "Email: " << clientes[i].email << endl;
            cout << "WhatsApp: " << clientes[i].whatsapp << endl;
            cout << "------------------------\n";
        }
    }
    pausar();
}

// Função para remover cliente
void removerCliente(vector<Cliente>& clientes) {
    limparTela();
    cout << "=== REMOVER CLIENTE ===\n";
    
    if (clientes.empty()) {
        cout << "Nenhum cliente cadastrado para remover.\n";
        pausar();
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
    
    pausar();
}

// Função para gerenciar clientes
void gerenciarClientes(vector<Cliente>& clientes) {
    int opcao;
    do {
        limparTela();
        cout << "=== GERENCIAMENTO DE CLIENTES ===\n";
        cout << "1. Cadastrar novo cliente\n";
        cout << "2. Listar clientes cadastrados\n";
        cout << "3. Remover cliente\n";
        cout << "0. Voltar ao menu principal\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
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
                pausar();
        }
    } while (opcao != 0);
}

// Função para listar produtos
void listarProdutos(const vector<Produto>& produtos) {
    limparTela();
    cout << "=== LISTA DE PRODUTOS ===\n";
    
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado.\n";
    } else {
        for (size_t i = 0; i < produtos.size(); ++i) {
            cout << "Codigo: " << produtos[i].codigo << " | ";
            cout << "Nome: " << produtos[i].nome << " | ";
            cout << "Preco: R$ " << produtos[i].preco << " | ";
            cout << "Quantidade: " << produtos[i].quantidade << endl;
            cout << "--------------------------------------------\n";
        }
    }
    pausar();
}

// Função para adicionar produto
void adicionarProduto(vector<Produto>& produtos) {
    limparTela();
    cout << "=== ADICIONAR PRODUTO ===\n";
    
    Produto novo;
    cout << "Codigo: ";
    cin >> novo.codigo;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, novo.nome);
    cout << "Preco: ";
    cin >> novo.preco;
    cout << "Quantidade: ";
    cin >> novo.quantidade;
    
    produtos.push_back(novo);
    cout << "\nProduto adicionado com sucesso!\n";
    pausar();
}

// Função para editar produto
void editarProduto(vector<Produto>& produtos) {
    limparTela();
    cout << "=== EDITAR PRODUTO ===\n";
    
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado para editar.\n";
        pausar();
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
            cout << "Novo nome (" << produtos[i].nome << "): ";
            cin.ignore();
            getline(cin, produtos[i].nome);
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
    
    pausar();
}

// Função para remover produto
void removerProduto(vector<Produto>& produtos) {
    limparTela();
    cout << "=== REMOVER PRODUTO ===\n";
    
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado para remover.\n";
        pausar();
        return;
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
    
    pausar();
}

// Função para gerenciar estoque
void gerenciarEstoque(vector<Produto>& produtos) {
    int opcao;
    do {
        limparTela();
        cout << "=== GERENCIAMENTO DE ESTOQUE ===\n";
        cout << "1. Listar produtos\n";
        cout << "2. Editar produto\n";
        cout << "3. Adicionar produto\n";
        cout << "4. Remover produto\n";
        cout << "0. Voltar ao menu principal\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
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
                pausar();
        }
    } while (opcao != 0);
}

// Função para vender produtos
void venderProdutos(vector<Produto>& produtos, const vector<Cliente>& clientes) {
    limparTela();
    cout << "=== VENDA DE PRODUTOS ===\n";
    
    if (clientes.empty()) {
        cout << "Nenhum cliente cadastrado. Cadastre um cliente primeiro.\n";
        pausar();
        return;
    }
    
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado. Cadastre produtos primeiro.\n";
        pausar();
        return;
    }
    
    // Selecionar cliente
    listarClientes(clientes);
    int clienteIdx;
    cout << "\nDigite o numero do cliente que esta comprando (0 para cancelar): ";
    cin >> clienteIdx;
    
    if (clienteIdx == 0) {
        return;
    } else if (clienteIdx < 1 || clienteIdx > static_cast<int>(clientes.size())) {
        cout << "Cliente invalido!\n";
        pausar();
        return;
    }
    
    const Cliente& cliente = clientes[clienteIdx - 1];
    
    // Processar venda
    vector<Produto> carrinho;
    vector<int> quantidades;
    double total = 0.0;
    
    int opcao;
    do {
        limparTela();
        cout << "=== CARRINHO DE COMPRAS ===\n";
        cout << "Cliente: " << cliente.nome << endl;
        cout << "Itens no carrinho: " << carrinho.size() << endl;
        cout << "Total: R$ " << total << endl;
        cout << "---------------------------\n";
        cout << "1. Adicionar produto\n";
        cout << "2. Finalizar compra\n";
        cout << "0. Cancelar venda\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
        if (opcao == 1) {
            limparTela();
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
                        pausar();
                        break;
                    }
                    
                    if (quantidade > produtos[i].quantidade) {
                        cout << "Quantidade indisponivel em estoque!\n";
                        pausar();
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
                    pausar();
                    break;
                }
            }
            
            if (!encontrado) {
                cout << "Produto nao encontrado!\n";
                pausar();
            }
        } else if (opcao == 2) {
            if (carrinho.empty()) {
                cout << "Carrinho vazio! Adicione produtos primeiro.\n";
                pausar();
                continue;
            }
            
            // Emitir nota fiscal
            limparTela();
            cout << "=== NOTA FISCAL ===\n";
            cout << "Cliente: " << cliente.nome << endl;
            cout << "CPF: " << cliente.cpf << endl;
            cout << "--------------------------------\n";
            cout << "ITENS:\n";
            
            for (size_t i = 0; i < carrinho.size(); ++i) {
                cout << carrinho[i].nome << " - ";
                cout << quantidades[i] << " x R$ " << carrinho[i].preco << " = ";
                cout << "R$ " << (carrinho[i].preco * quantidades[i]) << endl;
            }
            
            cout << "--------------------------------\n";
            cout << "TOTAL: R$ " << total << endl;
            cout << "--------------------------------\n";
            cout << "Obrigado pela preferencia!\n";
            
            pausar();
            break;
        } else if (opcao != 0) {
            cout << "Opcao invalida!\n";
            pausar();
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
        pausar();
    }
}

int main() {
    vector<Cliente> clientes;
    vector<Produto> produtos;
    
    // Adicionar alguns produtos iniciais
    produtos.push_back(Produto(1, "Arroz 5kg", 25.90, 50));
    produtos.push_back(Produto(2, "Feijao 1kg", 8.50, 40));
    produtos.push_back(Produto(3, "Oleo 900ml", 7.90, 30));
    produtos.push_back(Produto(4, "Acucar 5kg", 15.50, 35));
    produtos.push_back(Produto(5, "Sal 1kg", 2.90, 60));
    
    if (!fazerLogin()) {
        return 0;
    }
    
    int opcao;
    do {
        limparTela();
        cout << "=== MENU PRINCIPAL ===\n";
        cout << "1. Gerenciar clientes\n";
        cout << "2. Gerenciar estoque\n";
        cout << "3. Vender produtos\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
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
                pausar();
        }
    } while (opcao != 0);
    
    return 0;
}
