#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <set>

using namespace std;

#define INVALID_INPUT -99

int id_codigo = 0;

struct Cliente {
    int codigo;
    string nomeCliente;
    string cpf;
    string email;
    string whatsapp;

    Cliente(string nomeCliente = "", string cpf = "", string email = "", string whatsapp = "") 
        : nomeCliente(nomeCliente), cpf(cpf), email(email), whatsapp(whatsapp) {
        static int proximoCodigo = 1;
        codigo = proximoCodigo++;
    }
};

struct Produto {
    int codigo;
    string nomeProduto;
    double preco;
    int quantidade;
    int parte;
    int volume;
   
     Produto(string nomeProduto = "", double preco = 0.0, int quantidade = 0, int parte = 0, int volume = 0)
        : nomeProduto(nomeProduto), preco(preco), quantidade(quantidade), parte(parte), volume(volume) {
        static int proximoCodigo = 1;
        codigo = proximoCodigo++;
    }
};

struct ItemCarrinho {
    Produto produto;
    int quantidade;
};

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    cout << "\nPressione Enter para continuar...";
    cin.ignore();
    cin.get();
}

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

void cadastrarCliente(vector<Cliente>& clientes) {
    limparTela();
    cout << "=== CADASTRO DE CLIENTE ===\n";
   
    Cliente novo;
   
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
    pausar();
}

void listarClientes(const vector<Cliente>& clientes) {
    limparTela();
    cout << "=== LISTA DE CLIENTES ===\n";
   
    if (clientes.empty()) {
        cout << "Nenhum cliente cadastrado.\n";
    } else {
        for (size_t i = 0; i < clientes.size(); ++i) {
            cout << "Cliente #" << (i+1) << ":\n";
            cout << "Codigo: " << clientes[i].codigo << endl;
            cout << "Nome: " << clientes[i].nomeCliente << endl;
            cout << "CPF: " << clientes[i].cpf << endl;
            cout << "Email: " << clientes[i].email << endl;
            cout << "WhatsApp: " << clientes[i].whatsapp << endl;
            cout << "------------------------\n";
        }
    }
    pausar();
}

void removerCliente(vector<Cliente>& clientes) {
    limparTela();
    cout << "=== REMOVER CLIENTE ===\n";
   
    if (clientes.empty()) {
        cout << "Nenhum cliente cadastrado para remover.\n";
        pausar();
        return;
    }
   
    listarClientes(clientes);
   
    int codigo;
    cout << "\nDigite o codigo do cliente que deseja remover (0 para cancelar): ";
    cin >> codigo;
   
    if (codigo == 0) {
        return;
    }
   
    bool encontrado = false;
    for (size_t i = 0; i < clientes.size(); ++i) {
        if (clientes[i].codigo == codigo) {
            clientes.erase(clientes.begin() + i);
            cout << "Cliente removido com sucesso!\n";
            encontrado = true;
            break;
        }
    }
   
    if (!encontrado) {
        cout << "Cliente com codigo " << codigo << " nao encontrado!\n";
    }
   
    pausar();
}

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
                pausar();
        }
    } while (opcao != 0);
}

void listarProdutosPorParte(const vector<Produto>& produtos) {
    int opcao;
    do {
        limparTela();
        cout << "=== LISTAGEM DE PRODUTOS POR PARTE ===\n\n";
        cout << "1. Phantom Blood\n";
        cout << "2. Battle Tendency\n";
        cout << "3. Stardust Crusaders\n";
        cout << "4. Diamond is Unbreakable\n";
        cout << "5. Golden Wind\n";
        cout << "6. Stone Ocean\n";
        cout << "7. Steel Ball Run\n";
        cout << "8. JoJolion\n";
        cout << "9. Listar todos os produtos\n";
        cout << "\n0. Voltar ao menu anterior\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 0) {
            return;
        }

        if (opcao == 9) {
            // Listar todos os produtos (formato original)
            limparTela();
            cout << "=== LISTA COMPLETA DE PRODUTOS ===\n";
            cout << left << setw(8) << "Codigo" << setw(40) << "Nome"
                 << setw(10) << "Preco" << setw(10) << "Quant."
                 << setw(8) << "Parte" << setw(8) << "Vol." << endl;
            cout << string(80, '-') << endl;
           
            for (size_t i = 0; i < produtos.size(); ++i) {
                cout << left << setw(8) << produtos[i].codigo
                     << setw(40) << produtos[i].nomeProduto
                     << "R$ " << setw(7) << fixed << setprecision(2) << produtos[i].preco
                     << setw(10) << produtos[i].quantidade
                     << setw(8) << produtos[i].parte
                     << setw(8) << produtos[i].volume << endl;
            }
            pausar();
            continue;
        }

        if (opcao < 1 || opcao > 8) {
            cout << "Opcao invalida!\n";
            pausar();
            continue;
        }

        // Filtrar produtos da parte selecionada
        vector<const Produto*> produtosParte;
        for (size_t i = 0; i < produtos.size(); ++i) {
            if (produtos[i].parte == opcao) {
                produtosParte.push_back(&produtos[i]);
            }
        }

        if (produtosParte.empty()) {
            cout << "Nenhum produto cadastrado nesta parte.\n";
            pausar();
            continue;
        }

        // Exibir nome da parte
        string nomeParte;
        switch(opcao) {
            case 1: nomeParte = "PHANTOM BLOOD"; break;
            case 2: nomeParte = "BATTLE TENDENCY"; break;
            case 3: nomeParte = "STARDUST CRUSADERS"; break;
            case 4: nomeParte = "DIAMOND IS UNBREAKABLE"; break;
            case 5: nomeParte = "GOLDEN WIND"; break;
            case 6: nomeParte = "STONE OCEAN"; break;
            case 7: nomeParte = "STEEL BALL RUN"; break;
            case 8: nomeParte = "JOJOLION"; break;
        }

        limparTela();
        cout << "=== " << nomeParte << " ===\n";
        cout << left << setw(8) << "Codigo" << setw(5) << "Vol." << setw(35) << "Nome"
             << setw(10) << "Preco" << setw(10) << "Quant." << endl;
        cout << string(70, '-') << endl;

        // Ordenar por volume
        for (size_t i = 0; i < produtosParte.size(); ++i) {
            for (size_t j = i+1; j < produtosParte.size(); ++j) {
                if (produtosParte[j]->volume < produtosParte[i]->volume) {
                    const Produto* temp = produtosParte[i];
                    produtosParte[i] = produtosParte[j];
                    produtosParte[j] = temp;
                }
            }
        }

        // Exibir produtos
        for (size_t i = 0; i < produtosParte.size(); ++i) {
            cout << left << setw(8) << produtosParte[i]->codigo
                 << setw(5) << produtosParte[i]->volume
                 << setw(35) << produtosParte[i]->nomeProduto
                 << "R$ " << setw(7) << fixed << setprecision(2) << produtosParte[i]->preco
                 << setw(10) << produtosParte[i]->quantidade << endl;
        }

        pausar();

    } while (opcao != 0);
}

void adicionarProduto(vector<Produto>& produtos) {
    limparTela();
    cout << "=== ADICIONAR PRODUTO ===\n";
   
    Produto novo;
   
    cout << "Nome: ";
    cin.ignore();
    getline(cin, novo.nomeProduto);
    cout << "Preco: ";
    cin >> novo.preco;
    cout << "Quantidade: ";
    cin >> novo.quantidade;
    cout << "Parte (1-8): ";
    cin >> novo.parte;
    cout << "Volume: ";
    cin >> novo.volume;
   
    produtos.push_back(novo);
    cout << "\nProduto adicionado com sucesso!\n";
    pausar();
}

void editarProdutoPorParte(vector<Produto>& produtos) {
    int opcaoParte;
    do {
        limparTela();
        cout << "=== EDITAR PRODUTO - SELECIONE A PARTE ===\n\n";
        cout << "1. Phantom Blood\n";
        cout << "2. Battle Tendency\n";
        cout << "3. Stardust Crusaders\n";
        cout << "4. Diamond is Unbreakable\n";
        cout << "5. Golden Wind\n";
        cout << "6. Stone Ocean\n";
        cout << "7. Steel Ball Run\n";
        cout << "8. JoJolion\n";
        cout << "\n0. Voltar ao menu anterior\n";
        cout << "Escolha uma parte: ";
        cin >> opcaoParte;

        if (opcaoParte == 0) {
            return;
        }

        if (opcaoParte < 1 || opcaoParte > 8) {
            cout << "Parte invalida!\n";
            pausar();
            continue;
        }

        // Filtrar produtos da parte selecionada
        vector<Produto*> produtosParte;
        for (size_t i = 0; i < produtos.size(); ++i) {
            if (produtos[i].parte == opcaoParte) {
                produtosParte.push_back(&produtos[i]);
            }
        }

        if (produtosParte.empty()) {
            cout << "Nenhum produto cadastrado nesta parte.\n";
            pausar();
            continue;
        }

        // Menu de seleção de volume
        int opcaoVolume;
        do {
            limparTela();
            
            // Exibir nome da parte
            string nomeParte;
            switch(opcaoParte) {
                case 1: nomeParte = "PHANTOM BLOOD"; break;
                case 2: nomeParte = "BATTLE TENDENCY"; break;
                case 3: nomeParte = "STARDUST CRUSADERS"; break;
                case 4: nomeParte = "DIAMOND IS UNBREAKABLE"; break;
                case 5: nomeParte = "GOLDEN WIND"; break;
                case 6: nomeParte = "STONE OCEAN"; break;
                case 7: nomeParte = "STEEL BALL RUN"; break;
                case 8: nomeParte = "JOJOLION"; break;
            }
            
            cout << "=== " << nomeParte << " ===\n";
            cout << "Selecione o volume para editar:\n\n";
            
            // Exibir volumes disponíveis
            for (size_t i = 0; i < produtosParte.size(); ++i) {
                cout << produtosParte[i]->volume << ". " << produtosParte[i]->nomeProduto
                     << " - R$ " << fixed << setprecision(2) << produtosParte[i]->preco
                     << " (" << produtosParte[i]->quantidade << " disponíveis)\n";
            }
            
            cout << "\n0. Voltar para seleção de parte\n";
            cout << "Escolha um volume: ";
            cin >> opcaoVolume;
            
            if (opcaoVolume == 0) {
                break;
            }
            
            // Encontrar o produto selecionado
            Produto* produtoSelecionado = NULL;
            for (size_t i = 0; i < produtosParte.size(); ++i) {
                if (produtosParte[i]->volume == opcaoVolume) {
                    produtoSelecionado = produtosParte[i];
                    break;
                }
            }
            
            if (produtoSelecionado == NULL) {
                cout << "Volume inválido!\n";
                pausar();
                continue;
            }
            
            // Menu de edição do produto específico
            int opcaoEdicao;
            do {
                limparTela();
                cout << "=== EDITANDO: " << produtoSelecionado->nomeProduto << " ===\n\n";
                cout << "1. Nome: " << produtoSelecionado->nomeProduto << endl;
                cout << "2. Preço: R$ " << fixed << setprecision(2) << produtoSelecionado->preco << endl;
                cout << "3. Quantidade: " << produtoSelecionado->quantidade << endl;
                cout << "4. Volume: " << produtoSelecionado->volume << endl;
                
                cout << "\n0. Finalizar edição deste produto\n";
                cout << "00. Voltar para seleção de volume\n";
                cout << "Escolha o campo para editar: ";
                cin >> opcaoEdicao;
                
                if (opcaoEdicao == 0) {
                    break;
                } else if (opcaoEdicao == 00) {
                    opcaoVolume = -1; // Força voltar para seleção de volume
                    break;
                }
                
                string novoValor;
                double novoPreco;
                int novoInt;
                
                switch(opcaoEdicao) {
                    case 1:
                        cout << "\nNovo nome (atual: " << produtoSelecionado->nomeProduto << "): ";
                        cin.ignore();
                        getline(cin, novoValor);
                        if (!novoValor.empty()) {
                            produtoSelecionado->nomeProduto = novoValor;
                            cout << "Nome alterado com sucesso!\n";
                        }
                        break;
                    case 2:
                        cout << "\nNovo preço (atual: R$ " << fixed << setprecision(2) 
                             << produtoSelecionado->preco << "): ";
                        cin >> novoPreco;
                        if (novoPreco > 0) {
                            produtoSelecionado->preco = novoPreco;
                            cout << "Preço alterado com sucesso!\n";
                        }
                        break;
                    case 3:
                        cout << "\nNova quantidade (atual: " << produtoSelecionado->quantidade << "): ";
                        cin >> novoInt;
                        if (novoInt >= 0) {
                            produtoSelecionado->quantidade = novoInt;
                            cout << "Quantidade alterada com sucesso!\n";
                        }
                        break;
                    case 4:
                        cout << "\nNovo volume (atual: " << produtoSelecionado->volume << "): ";
                        cin >> novoInt;
                        if (novoInt > 0) {
                            // Verificar se já existe um produto com este volume na mesma parte
                            bool volumeExistente = false;
                            for (size_t i = 0; i < produtos.size(); ++i) {
                                if (produtos[i].parte == produtoSelecionado->parte && 
                                    produtos[i].volume == novoInt && 
                                    produtos[i].codigo != produtoSelecionado->codigo) {
                                    volumeExistente = true;
                                    break;
                                }
                            }
                            
                            if (!volumeExistente) {
                                produtoSelecionado->volume = novoInt;
                                cout << "Volume alterado com sucesso!\n";
                            } else {
                                cout << "Já existe um produto com este volume nesta parte!\n";
                            }
                        }
                        break;
                    default:
                        cout << "Opção inválida!\n";
                }
                
                if (opcaoEdicao >= 1 && opcaoEdicao <= 4) {
                    pausar();
                }
            } while (opcaoEdicao != 0 && opcaoEdicao != 00);
            
        } while (opcaoVolume != 0);
        
    } while (opcaoParte != 0);
}

void removerProduto(vector<Produto>& produtos) {
    limparTela();
    cout << "=== REMOVER PRODUTO ===\n";
   
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado para remover.\n";
        pausar();
        return;
    }
   
    listarProdutosPorParte(produtos);
   
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

void gerenciarEstoque(vector<Produto>& produtos) {
    int opcao;
    do {
        limparTela();
        cout << "=== GERENCIAMENTO DE ESTOQUE ===\n";
        cout << "1. Listar produtos (por parte)\n";
        cout << "2. Editar produto (por parte)\n";
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
                listarProdutosPorParte(produtos);
                break;
            case 2:
                editarProdutoPorParte(produtos);
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

void exibirCarrinho(const vector<ItemCarrinho>& carrinho, double total) {
    limparTela();
    cout << "=== SEU CARRINHO ===\n";
   
    if (carrinho.empty()) {
        cout << "Carrinho vazio.\n";
    } else {
        cout << left << setw(5) << "Qtd" << setw(40) << "Produto"
             << setw(10) << "Preco" << setw(10) << "Subtotal" << endl;
        cout << string(65, '-') << endl;
       
        for (size_t i = 0; i < carrinho.size(); ++i) {
            cout << left << setw(5) << carrinho[i].quantidade
                 << setw(40) << carrinho[i].produto.nomeProduto
                 << "R$ " << setw(7) << fixed << setprecision(2) << carrinho[i].produto.preco
                 << "R$ " << setw(7) << (carrinho[i].produto.preco * carrinho[i].quantidade) << endl;
        }
       
        cout << string(65, '-') << endl;
        cout << right << setw(55) << "TOTAL: R$ " << total << endl;
    }
    cout << "\n";
}

bool verificarDesconto(const vector<ItemCarrinho>& carrinho) {
    set<int> partes;
    
    for (size_t i = 0; i < carrinho.size(); ++i) {
        partes.insert(carrinho[i].produto.parte);
        if (partes.size() >= 3) {
            return true;
        }
    }
    
    return false;
}

void menuVolumesParte(int parte, const vector<Produto>& produtos, vector<ItemCarrinho>& carrinho, double& total) {
    vector<Produto> volumesParte;
    
    // Filtrar produtos da parte selecionada
    for (size_t i = 0; i < produtos.size(); ++i) {
        if (produtos[i].parte == parte && produtos[i].quantidade > 0) {
            volumesParte.push_back(produtos[i]);
        }
    }
    
    int opcao;
    do {
        limparTela();
        
        // Exibir cabeçalho com o nome da parte
        string nomeParte;
        switch(parte) {
            case 1: nomeParte = "PHANTOM BLOOD"; break;
            case 2: nomeParte = "BATTLE TENDENCY"; break;
            case 3: nomeParte = "STARDUST CRUSADERS"; break;
            case 4: nomeParte = "DIAMOND IS UNBREAKABLE"; break;
            case 5: nomeParte = "GOLDEN WIND"; break;
            case 6: nomeParte = "STONE OCEAN"; break;
            case 7: nomeParte = "STEEL BALL RUN"; break;
            case 8: nomeParte = "JOJOLION"; break;
        }
        
        cout << "=== " << nomeParte << " ===\n";
        cout << "Selecione um volume para adicionar ao carrinho:\n\n";
        
        if (volumesParte.empty()) {
            cout << "Nenhum volume disponivel nesta parte.\n";
        } else {
            // Exibir volumes disponíveis
            for (size_t i = 0; i < volumesParte.size(); ++i) {
                cout << volumesParte[i].volume << ". " << volumesParte[i].nomeProduto
                     << " - R$ " << fixed << setprecision(2) << volumesParte[i].preco
                     << " (" << volumesParte[i].quantidade << " disponiveis)\n";
            }
        }
        
        cout << "\n0. Voltar para selecao de partes\n";
        cout << "00. Ver carrinho\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
        if (opcao == 0) {
            return;
        } else if (opcao == 00) {
            exibirCarrinho(carrinho, total);
            if (!carrinho.empty()) {
                cout << "1. Finalizar compra\n";
                cout << "2. Continuar comprando\n";
                cout << "Escolha: ";
                int escolha;
                cin >> escolha;
                
                if (escolha == 1) {
                    opcao = 0;
                    return;
                }
            } else {
                pausar();
            }
        } else {
            // Verificar se o volume existe
            bool encontrado = false;
            for (size_t i = 0; i < volumesParte.size(); ++i) {
                if (volumesParte[i].volume == opcao) {
                    encontrado = true;
                    
                    // Perguntar quantidade
                    int quantidade;
                    cout << "Quantidade (disponivel: " << volumesParte[i].quantidade << "): ";
                    cin >> quantidade;
                    
                    if (quantidade <= 0 || quantidade > volumesParte[i].quantidade) {
                        cout << "Quantidade invalida!\n";
                        pausar();
                        break;
                    }
                    
                    // Adicionar ao carrinho
                    bool jaNoCarrinho = false;
                    for (size_t j = 0; j < carrinho.size(); ++j) {
                        if (carrinho[j].produto.codigo == volumesParte[i].codigo) {
                            carrinho[j].quantidade += quantidade;
                            jaNoCarrinho = true;
                            break;
                        }
                    }
                    
                    if (!jaNoCarrinho) {
                        ItemCarrinho novoItem;
                        novoItem.produto = volumesParte[i];
                        novoItem.quantidade = quantidade;
                        carrinho.push_back(novoItem);
                    }
                    
                    total += volumesParte[i].preco * quantidade;
                    cout << "Volume adicionado ao carrinho!\n";
                    pausar();
                    break;
                }
            }
            
            if (!encontrado) {
                cout << "Volume invalido!\n";
                pausar();
            }
        }
    } while (opcao != 0);
}

void menuPartes(const vector<Produto>& produtos, vector<ItemCarrinho>& carrinho, double& total) {
    int opcao;
    do {
        limparTela();
        cout << "=== LOJA DE MANGAS JOJO'S BIZARRE ADVENTURE ===\n";
        cout << "Selecione uma parte para ver os volumes:\n";
        cout << "1. Phantom Blood\n";
        cout << "2. Battle Tendency\n";
        cout << "3. Stardust Crusaders\n";
        cout << "4. Diamond is Unbreakable\n";
        cout << "5. Golden Wind\n";
        cout << "6. Stone Ocean\n";
        cout << "7. Steel Ball Run\n";
        cout << "8. JoJolion\n";
        cout << "\n0. Voltar ao menu principal\n";
        cout << "00. Ver carrinho (" << carrinho.size() << " itens)\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
        if (opcao >= 1 && opcao <= 8) {
            menuVolumesParte(opcao, produtos, carrinho, total);
        } else if (opcao == 00) {
            exibirCarrinho(carrinho, total);
            
            if (!carrinho.empty()) {
                cout << "1. Finalizar compra\n";
                cout << "2. Remover item\n";
                cout << "3. Continuar comprando\n";
                cout << "Escolha: ";
                int escolha;
                cin >> escolha;
                
                if (escolha == 1) {
                    return;
                } else if (escolha == 2) {
                    // Remover item
                    cout << "Digite o numero do item para remover: ";
                    int itemRemover;
                    cin >> itemRemover;
                    
                    if (itemRemover > 0 && itemRemover <= static_cast<int>(carrinho.size())) {
                        total -= carrinho[itemRemover-1].produto.preco * carrinho[itemRemover-1].quantidade;
                        carrinho.erase(carrinho.begin() + itemRemover - 1);
                        cout << "Item removido do carrinho!\n";
                    } else {
                        cout << "Item invalido!\n";
                    }
                    pausar();
                }
            } else {
                pausar();
            }
        } else if (opcao != 0) {
            cout << "Opcao invalida!\n";
            pausar();
        }
    } while (opcao != 0);
}
void gerarNotaFiscal(const Cliente& cliente, const vector<ItemCarrinho>& carrinho, double total, double desconto) {
    limparTela();
    cout << "=============================================\n";
    cout << "                NOTA FISCAL                  \n";
    cout << "=============================================\n";
    cout << "Cliente: " << cliente.nomeCliente << endl;
    cout << "CPF: " << cliente.cpf << endl;
    cout << "Data: " << __DATE__ << " " << __TIME__ << endl;
    cout << "---------------------------------------------\n";
    cout << "ITENS COMPRADOS:\n";
    cout << left << setw(5) << "Qtd" << setw(30) << "Produto" 
         << setw(10) << "Preco" << setw(10) << "Subtotal" << endl;
    cout << string(55, '-') << endl;
    
    for (size_t i = 0; i < carrinho.size(); ++i) {
        cout << left << setw(5) << carrinho[i].quantidade
             << setw(30) << carrinho[i].produto.nomeProduto
             << "R$ " << setw(7) << fixed << setprecision(2) << carrinho[i].produto.preco
             << "R$ " << setw(7) << (carrinho[i].produto.preco * carrinho[i].quantidade) << endl;
    }
    
    cout << "---------------------------------------------\n";
    if (desconto > 0) {
        cout << "Subtotal: R$ " << fixed << setprecision(2) << (total + desconto) << endl;
        cout << "Desconto (5%): R$ " << fixed << setprecision(2) << desconto << endl;
    }
    cout << "TOTAL: R$ " << fixed << setprecision(2) << total << endl;
    cout << "=============================================\n";
    cout << "Obrigado pela preferencia!\n";
    cout << "Volte sempre!\n";
    cout << "=============================================\n";
    pausar();
}


void venderProdutos(vector<Produto>& produtos, const vector<Cliente>& clientes) {
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
    cout << "\nDigite o codigo do cliente que esta comprando (0 para cancelar): ";
    cin >> clienteIdx;
    
    if (clienteIdx == 0) {
        return;
    }
    
    bool clienteEncontrado = false;
    Cliente clienteCompra;
    for (size_t i = 0; i < clientes.size(); ++i) {
        if (clientes[i].codigo == clienteIdx) {
            clienteCompra = clientes[i];
            clienteEncontrado = true;
            break;
        }
    }
    
    if (!clienteEncontrado) {
        cout << "Cliente nao encontrado!\n";
        pausar();
        return;
    }
    
    // Processar venda
    vector<ItemCarrinho> carrinho;
    double total = 0.0;
    
    limparTela();
    cout << "=== LOJA DE MANGAS JOJO'S BIZARRE ADVENTURE ===\n";
    cout << "Cliente: " << clienteCompra.nomeCliente << "\n\n";
    
    menuPartes(produtos, carrinho, total);
    
    // Se o carrinho não estiver vazio, finalizar compra
    if (!carrinho.empty()) {
        // Verificar desconto
        bool temDesconto = verificarDesconto(carrinho);
        double desconto = 0.0;
        
        if (temDesconto) {
            desconto = total * 0.05;
            total -= desconto;
            cout << "\nDESCONTO APLICADO: 5% (R$ " << fixed << setprecision(2) << desconto << ")\n";
        }
        
        // Finalizar compra
        limparTela();
        cout << "=== COMPRA FINALIZADA ===\n";
        cout << "Cliente: " << clienteCompra.nomeCliente << endl;
        cout << "CPF: " << clienteCompra.cpf << endl;
        cout << "Itens comprados:\n";
        
        for (size_t i = 0; i < carrinho.size(); ++i) {
            cout << carrinho[i].quantidade << "x " << carrinho[i].produto.nomeProduto
                 << " - R$ " << carrinho[i].produto.preco << " cada\n";
                 
            // Atualizar estoque
            for (size_t j = 0; j < produtos.size(); ++j) {
                if (produtos[j].codigo == carrinho[i].produto.codigo) {
                    produtos[j].quantidade -= carrinho[i].quantidade;
                    break;
                }
            }
        }
        
        if (temDesconto) {
            cout << "\nDESCONTO: R$ " << fixed << setprecision(2) << desconto << endl;
        }
        cout << "\nTOTAL: R$ " << fixed << setprecision(2) << total << endl;
        cout << "\nObrigado pela compra!\n";
        
        // Gerar nota fiscal
        gerarNotaFiscal(clienteCompra, carrinho, total, desconto);
    }
}

void popularMangasJojo(vector<Produto>& produtos) {
    // Parte 1: Phantom Blood (Volumes 1-5)
  	for(int i = 1; i <= 5; i++){
 		char buffer[100];
 		sprintf(buffer, "JoJo's Bizarre Adventure: Phantom Blood Vol. %d", i);
		produtos.push_back(Produto(buffer, 29.90, 10, 1, i));
	}
    // Parte 2: Battle Tendency (Volumes 6-12)
    for(int i = 1; i <= 7; i++){
 	   	char buffer[100];
    	sprintf(buffer, "JoJo's Bizarre Adventure: Battle Tendency Vol. %d", i);
		produtos.push_back(Produto(buffer, 34.90, 10, 2, i));
	}
   
    // Parte 3: Stardust Crusaders (Volumes 1-16)
    for (int i = 1; i <= 16; i++) {
        char buffer[100];
        sprintf(buffer, "JoJo's Bizarre Adventure: Stardust Crusaders Vol. %d", i);
        produtos.push_back(Produto(buffer, 39.90, 10, 3, i));
    }
   
    // Parte 4: Diamond is Unbreakable (Volumes 1-18)
    for (int i = 1; i <= 18; i++) {
        char buffer[100];
        sprintf(buffer, "JoJo's Bizarre Adventure: Diamond is Unbreakable Vol. %d", i);
        produtos.push_back(Produto(buffer, 39.90, 10, 4, i));
    }
   
    // Parte 5: Golden Wind (Volumes 1-17)
    for (int i = 1; i <= 17; i++) {
        char buffer[100];
        sprintf(buffer, "JoJo's Bizarre Adventure: Golden Wind Vol. %d", i);
        produtos.push_back(Produto(buffer, 42.90, 10, 5, i));
    }
   
    // Parte 6: Stone Ocean (Volumes 1-17)
    for (int i = 1; i <= 17; i++) {
        char buffer[100];
        sprintf(buffer, "JoJo's Bizarre Adventure: Stone Ocean Vol. %d", i);
        produtos.push_back(Produto(buffer, 42.90, 10, 6, i));
    }
   
    // Parte 7: Steel Ball Run (Volumes 1-24)
    for (int i = 1; i <= 24; i++) {
        char buffer[100];
        sprintf(buffer, "JoJo's Bizarre Adventure: Steel Ball Run Vol. %d", i);
        produtos.push_back(Produto(buffer, 44.90, 10, 7, i));
    }
   
    // Parte 8: JoJolion (Volumes 1-27)
    for (int i = 1; i <= 27; i++) {
        char buffer[100];
        sprintf(buffer, "JoJo's Bizarre Adventure: JoJolion Vol. %d", i);
        produtos.push_back(Produto(buffer, 44.90, 10, 8, i));
    }
}

int main() {
    vector<Cliente> clientes;
    vector<Produto> produtos;
   
    // Popular com os mangás de JoJo
    popularMangasJojo(produtos);
   
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
                pausar();
        }
    } while (opcao != 0);
   
    return 0;
}
