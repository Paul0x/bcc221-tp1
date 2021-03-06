/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/


#include "SistemaClinica.h"
using namespace std;

/**
 * Construtor da classe, carrega as contas e consultas dos arquivos.
 * 
 */
SistemaClinica::SistemaClinica() {
    this->contas = this->fileHelper.buscarPagamentoConta();
    this->consultas = this->fileHelper.buscarPagamentoConsulta();
}

SistemaClinica::SistemaClinica(const SistemaClinica& orig) {
}

/**
 * Destrutor - salva as contas e consultas nos arquivos
 */
SistemaClinica::~SistemaClinica() {
    this->fileHelper.salvarPagamentoConta(this->contas);
    this->fileHelper.salvarPagamentoConsulta(this->consultas);
}

/**
 *  Função de inicialização do sistema, permitindo a escolha do login
 */
void SistemaClinica::initSistema() {
    int opcaoInicio;
    system("clear");
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "=============================================" << endl;
    cout << "Digite:" << endl << "1 - Fazer Login" << endl << "2 - Sair" << endl;
    cin >> opcaoInicio;
    switch (opcaoInicio) {
        case 1:
            this->initTelaLogin();
            break;
        case 2:
            exit(0);
            break;
        default:
            cout << "Opção inválida";
            this->initSistema();
    }

}

/**
 * Função de inicialização dos usuários, carregando os mesmos nos arquivos
 * OBS: Descomentar as linhas abaixo caso queira que o sistema grave os usuários padrão
 */
void SistemaClinica::initUsuarios() {
    //    Administrador admin = Administrador();
    //    admin.setCpf("000.000.000-99");
    //    admin.setEmail("admin@clinica.com");
    //    admin.setLogin("admin");
    //    admin.setSenha("admin");
    //    admin.setNome("Administrador");
    //    //this->usuarios.push_back(admin);
    //
    //    Especialista esp1 = Especialista();
    //    esp1.setCpf("000.000.000-98");
    //    esp1.setEmail("admin@clinica.com");
    //    esp1.setLogin("admin1");
    //    esp1.setSenha("admin1");
    //    esp1.setNome("Especialista 1");
    //    //this->usuarios.push_back(esp1);
    //
    //    Especialista esp2 = Especialista();
    //    esp2.setCpf("000.000.000-97");
    //    esp2.setEmail("admin@clinica.com");
    //    esp2.setLogin("admin2");
    //    esp2.setSenha("admin3");
    //    esp2.setNome("Especialista 2");
    //    //this->usuarios.push_back(esp2);
    //
    //    Especialista esp3 = Especialista();
    //    esp3.setCpf("000.000.000-96");
    //    esp3.setEmail("admin@clinica.com");
    //    esp3.setLogin("admin2");
    //    esp3.setSenha("admin3");
    //    esp3.setNome("Especialista 3");
    //    //this->usuarios.push_back(esp3);
    //    this->fileHelper.registrarUsuarioArquivo(admin);
    //    this->fileHelper.registrarUsuarioArquivo(esp1);
    //    this->fileHelper.registrarUsuarioArquivo(esp2);
    //    this->fileHelper.registrarUsuarioArquivo(esp3);
    cout << "Usuários inicializados com sucesso" << endl;

    this->usuarios = this->fileHelper.buscarUsuariosArquivo();


}

/**
 *  Tela de login e lógida de login
 */
void SistemaClinica::initTelaLogin() {
    system("clear");
    string usuario;
    string senha;
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "=============================================" << endl;
    cout << "Digite o login: ";
    cin >> usuario;
    system("clear");
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "=============================================" << endl;
    cout << "Digite a senha: ";
    cin >> senha;

    int loginFlag = 0;
    for (int i = 0; i < this->usuarios.size(); i++) {
        if (this->usuarios[i]->getLogin() == usuario) {
            if (this->usuarios[i]->getSenha() == senha) {
                loginFlag = 1;
                this->currentUsuario = this->usuarios[i];
            }
        }
    }

    if (loginFlag == 1) {
        cout << "Login realizado com sucesso." << endl;
        system("clear");
        this->executarAcaoMenu(this->currentUsuario->imprimirMenu());
    } else {
        cout << "Não foi possível fazer o login, usuario ou senha incorretos." << endl;
        cout << "Aperte enter para retornar.";
        int w;
        cin >> w;
        this->initSistema();
    }

}

/**
 * Executa uma ação de menu, recebe como argumento uma string que é enviada da classe Usuário
 * @param acao
 */
void SistemaClinica::executarAcaoMenu(string acao) {
    if (acao == "ag") {
        this->initAgendaScreen();
    } else if (acao == "rc") {
        this->initRecebimentoConsultasScreen();
    } else if (acao == "pc") {
        this->initPagamentoContasScreen();
    } else if (acao == "fp") {
        this->initFolhaPontoScreen();
    } else if (acao == "gu") {
        this->initGerenciamentoUsuariosScreen();
    } else {
        this->fileHelper.salvarPagamentoConta(this->contas);
        this->fileHelper.salvarPagamentoConsulta(this->consultas);
    }

}

/**
 * Carrega a tela da agenda
 */
void SistemaClinica::initAgendaScreen() {
    system("clear");
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "Usuário Logado: " << this->currentUsuario->getNome() << endl;
    cout << "=============================================" << endl;
    cout << "Módulo de Agenda" << endl;
    cout << "Selecione um especialista para visualizar sua agenda:" << endl;
    for (int i = 0; i < this->usuarios.size(); i++) {
        if (this->usuarios[i]->getNomeClasse() == "Especialista") {
            cout << i << " - " << this->usuarios[i]->getNome() << endl;
        }
    }
    int opcao;
    cin >> opcao;
    try {
        // Polimorfismo para tipo especialista
        shared_ptr<Especialista> esp = dynamic_pointer_cast<Especialista> (this->usuarios[opcao]);
        esp->setAgenda(this->fileHelper.buscarAgendaEspecialista(esp->getCodigo()));
        esp->mostrarAgenda();
        this->fileHelper.salvarAgendaEspecialista(esp->getAgenda(), esp->getCodigo());
    } catch (...) {
        cout << "Ocorreu um erro ao carregar a agenda do especialista selecionado.";
        cout << "Aperte enter para tentar novamente.";
        cin >> opcao;
        this->initAgendaScreen();
    }
    this->executarAcaoMenu(this->currentUsuario->imprimirMenu());
};

/**
 * Tela de recebimento de consultas
 */
void SistemaClinica::initRecebimentoConsultasScreen() {
    system("clear");
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "Usuário Logado: " << this->currentUsuario->getNome() << endl;
    cout << "=============================================" << endl;
    cout << "Módulo de Recebimento de Consultas" << endl;
    cout << "Insira uma opção:" << endl;
    cout << "1 - Receber nova consulta | 2 - Visualizar Extrato por Período  | 3 - Voltar" << endl;
    int opcao;
    cin >> opcao;
    switch (opcao) {
        case 1:
            this->inserirRecebimentoConsulta();
            break;
        case 2:
            this->listaConsultasRecebidas();
            break;
        case 3:
            this->executarAcaoMenu(this->currentUsuario->imprimirMenu());
            break;
    }
};

/**
 * Tela de pagamento de contas
 */
void SistemaClinica::initPagamentoContasScreen() {
    system("clear");
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "Usuário Logado: " << this->currentUsuario->getNome() << endl;
    cout << "=============================================" << endl;
    cout << "Módulo de Pagamento de Contas" << endl;
    cout << "Insira uma opção:" << endl;
    cout << "1 - Adicionar Nova Conta | 2 - Visualizar Contas Inseridas | 3 - Voltar" << endl;
    int opcao;
    cin >> opcao;
    switch (opcao) {
        case 1:
            this->inserirRecebimentoConta();
            break;
        case 2:
            this->listaContasInseridas();
            break;
        case 3:
            this->executarAcaoMenu(this->currentUsuario->imprimirMenu());
            break;
    }
};

/**
 * Tela para carregar a folha de ponto de algum funcionário
 */
void SistemaClinica::initFolhaPontoScreen() {
    system("clear");
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "Usuário Logado: " << this->currentUsuario->getNome() << endl;
    cout << "=============================================" << endl;
    cout << "Módulo de Folha de Ponto" << endl;
    cout << "Selecione um funcionário para visualizar sua folha de ponto:" << endl;
    for (int i = 0; i < this->usuarios.size(); i++) {
        if (this->usuarios[i]->getNomeClasse() == "Especialista" ||
                this->usuarios[i]->getNomeClasse() == "AssistenteAdministrativo"
                ) {
            cout << i << " - " << this->usuarios[i]->getNome() << endl;
        }
    }
    int opcao;
    cin >> opcao;
    shared_ptr<Funcionario> func;
    try {
        func = dynamic_pointer_cast<Funcionario> (this->usuarios[opcao]);
        func->setFolhaPonto(this->fileHelper.buscarPontoFuncionario(func->getCodigo()));
        func->mostrarFolhaPonto();
        this->fileHelper.salvarPontoFuncionario(func->getFolhaPonto(), func->getCodigo());
    } catch (...) {
        cout << "Ocorreu um erro ao carregar a folha de ponto do funcionário selecionado.";
        cout << "Aperte enter para tentar novamente.";
        cin >> opcao;
        this->initAgendaScreen();
    }
    this->executarAcaoMenu(this->currentUsuario->imprimirMenu());
};

/*
 * Tela para área de gerencimaento dos usuários
 */
void SistemaClinica::initGerenciamentoUsuariosScreen() {
    system("clear");
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "Usuário Logado: " << this->currentUsuario->getNome() << endl;
    cout << "=============================================" << endl;
    cout << "Módulo de Cadastro de Usuarios" << endl;
    cout << "=============================================" << endl;
    cout << "Escolha uma das opções: 1 - Adicionar Usuário | 2 - Remover Usuário | 3 - Voltar";
    int opcao;
    cin >> opcao;
    switch (opcao) {
        case 1:
            this->cadastrarUsuario();
            break;
        case 2:
            this->removerUsuario();
            break;
        default:
            this->executarAcaoMenu(this->currentUsuario->imprimirMenu());
    }
};

/*
 * Adiciona novo recebimento de consulta
 */
void SistemaClinica::inserirRecebimentoConsulta() {
    system("clear");
    RegistroPagamentoConsulta consulta;
    double valor;
    string nomeCliente;
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "Usuário Logado: " << this->currentUsuario->getNome() << endl;
    cout << "=============================================" << endl;
    cout << "Módulo de Recebimento de Consultas" << endl;
    cout << "Adicionar nova consulta" << endl;
    cout << "=============================================" << endl;
    cout << "Digite o valor da consulta: ";
    cin >> valor;
    cout << "Digite o nome do cliente: ";
    cin >> nomeCliente;

    consulta.setValor(valor);
    consulta.setNomeCliente(nomeCliente);
    consulta.setDataTimestamp(time(0));
    cout << "Data de registro: " << consulta.getData() << endl;
    cout << "Aperte 0 + enter para continuar.";
    int opcao;
    cin >> opcao;
    this->consultas.insert(make_pair(consulta.getDataTimestamp(), &consulta));
    this->initRecebimentoConsultasScreen();
};

/**
 *  Área de listagem das consultas recebidas
 */
void SistemaClinica::listaConsultasRecebidas() {
    system("clear");
    RegistroPagamentoConsulta consulta;
    string dtInicio;
    string dtFim;
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "Usuário Logado: " << this->currentUsuario->getNome() << endl;
    cout << "=============================================" << endl;
    cout << "Módulo de Recebimento de Consultas" << endl;
    cout << "Listar Consultas Recebidas" << endl;
    cout << "=============================================" << endl;
    cout << "Digite a data de início (0 -> mostra todos os registros) - formato: dd/mm/yyyy: ";
    cin >> dtInicio;
    if (dtInicio != "0") {
        cout << "Digite a data fim - formato: dd/mm/yyyy: ";
        cin >> dtFim;
    } else {
        dtFim = "01/01/1994";
    }
    time_t dtInicioTm;
    time_t dtFimTm;

    dtInicioTm = to_time_t(dtInicio, false, "%d/%m/%Y");
    dtFimTm = to_time_t(dtFim, false, "%d/%m/%Y");

    for (auto const& consulta : this->consultas) {
        if ((dtInicioTm <= consulta.first && dtFimTm >= consulta.first) || dtInicio == "0") {
            cout << "- Dt: " << consulta.second->getData()
                    << " | " << consulta.second->getNomeCliente() <<
                    " | R$" << consulta.second->getValor() << endl;
        }
    }

    cout << "================================" << endl
            << "Insira uma opção: " << endl <<
            " 1 - Fazer nova pesquisa | 2 - Voltar | 3 - Menu Principal: ";
    int opcao;
    cin >> opcao;
    switch (opcao) {
        case 1:
            this->listaConsultasRecebidas();
            break;
        case 2:
            this->initRecebimentoConsultasScreen();
            break;
        case 3:
            this->executarAcaoMenu(this->currentUsuario->imprimirMenu());
            break;
    }
};

/*
 *  Adiciona novas contas pagas
 */
void SistemaClinica::inserirRecebimentoConta() {
    system("clear");
    shared_ptr<RegistroPagamentoConta> conta = make_shared<RegistroPagamentoConta>();
    string descricao;
    string dtVencimento;
    string dtPagamento;
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "Usuário Logado: " << this->currentUsuario->getNome() << endl;
    cout << "=============================================" << endl;
    cout << "Módulo de Recebimento de Contas" << endl;
    cout << "Adicionar nova conta" << endl;
    cout << "=============================================" << endl;
    cout << "Digite a descrição da conta: ";
    cin >> descricao;
    cout << "Digite a data de vencimento da conta (dd/mm/yyyy): ";
    cin >> dtVencimento;
    cout << "Digite a data de pagamento da conta (dd/mm/yyyy): ";
    cin >> dtPagamento;
    conta->setDescricao(descricao);
    conta->setDtPagamento(dtPagamento);
    conta->setDtVencimento(dtVencimento);
    this->contas.push_back(conta);
    this->initPagamentoContasScreen();
};

/*
 * Lista as contas recebidas
 */
void SistemaClinica::listaContasInseridas() {
    system("clear");
    RegistroPagamentoConsulta consulta;
    string dtInicio;
    string dtFim;
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "Usuário Logado: " << this->currentUsuario->getNome() << endl;
    cout << "=============================================" << endl;
    cout << "Módulo de Recebimento de Consultas" << endl;
    cout << "Listar Contas Pagas" << endl;
    cout << "=============================================" << endl;

    for (int i = 0; i < this->contas.size(); i++) {
        cout << i << " - " << this->contas[i]->getDescricao() <<
                " | " << this->contas[i]->getDtVencimento() << " | " << this->contas[i]->getDtPagamento() << endl;
    }

    cout << "================================" << endl
            << "Insira uma opção: " << endl <<
            " 1 - Voltar | 2 - Menu Principal: ";
    int opcao;
    cin >> opcao;
    switch (opcao) {
        case 1:
            this->initPagamentoContasScreen();
            break;
        case 2:
            this->executarAcaoMenu(this->currentUsuario->imprimirMenu());
            break;
    }
};

/*
 * Cadastra novos usuários
 */
void SistemaClinica::cadastrarUsuario() {
    system("clear");
    string nome;
    string cpf;
    string email;
    string login;
    string senha;
    int tipo = 0;
    int codigo;
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "Usuário Logado: " << this->currentUsuario->getNome() << endl;
    cout << "=============================================" << endl;
    cout << "Adicionar novo usuário" << endl;
    cout << "=============================================" << endl;
    cout << "Digite o tipo de usuário -> 1 - Administrador | 2 - Assistente Administrativo | 3 - Especialista: ";
    do {
        cin >> tipo;
    } while (tipo <= 0 || tipo > 3);
    cout << "Digite o nome do usuário: ";
    cin >> nome;
    cout << "Digite o cpf do usuário: ";
    cin >> cpf;
    cout << "Digite o email do usuário: ";
    cin >> email;
    cout << "Digite o login do usuário: ";
    cin >> login;
    cout << "Digite a senha do usuário: ";
    cin >> senha;

    codigo = this->usuarios.size() + 1;
    shared_ptr<Usuario> usr;
    switch (tipo) {
        case 1:
            usr = make_shared<Administrador>();
            break;
        case 2:
            usr = make_shared<AssistenteAdministrativo>();
            break;
        case 3:
            usr = make_shared<Especialista>();
            break;
    }

    usr->setCodigo(codigo);
    usr->setCpf(cpf);
    usr->setEmail(email);
    usr->setNome(nome);
    usr->setSenha(senha);
    usr->setLogin(login);
    this->usuarios.push_back(usr);
    this->fileHelper.registrarUsuarioArquivo(*usr);
    this->usuarios = this->fileHelper.buscarUsuariosArquivo();
    this->initGerenciamentoUsuariosScreen();

};

/**
 * Remove usuários
 */
void SistemaClinica::removerUsuario() {

}