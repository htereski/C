#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX_LIVROS 5

typedef struct{
    char *Titulo;
    char **Autor;
    char *Idioma;
    char *Editora;
    char **Assunto;
    int Quantidade_autor;
    int Quantidade_assunto;
    int Numero_paginas;
    int Ano_edicao;
}Livro;

Livro *_biblioteca;
int _quantidade_livros = 0;

int verificarString(char str[]);
void menuIncluirEditarExcluir(char str[]);
void perguntasUsuario(char frase[]);
void incluirLivro();
void listar();
void listarLivro();
void mostrarLivrosEditar();
void editar();
void editarLivroMenu();
void editarTitulo(int qual_livro);
void editarAutor(int qual_livro);
void editarAnoEdicao(int qual_livro);
void editarAssunto(int qual_livro);
void editarPaginas(int qual_livro);
void editarIdioma(int qual_livro);
void excluirLivro();
void desejaMesmoExcluir(char palavra[]);
void mensagemErro(int opcao);
void salvarArquivo(char arq[]);
void lerArquivo(char arq[]);
void menuListar();
void menu();

int main(){
    setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}

int verificarString(char str[]){
    int i;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] != ' ')
            return 1;
    }
    return 0;
}

void menuIncluirEditarExcluir(char str[]){
    system("cls");
    printf("****************************************\n\n");
    printf("***   Editar\n\n");
    printf("*** - (1) Incluir %s\n\n", str);
    printf("*** - (2) Editar %s\n\n", str);
    printf("*** - (3) Excluir %s\n\n", str);
    printf("*** - (4) Voltar p/ Opcao anterior\n\n");
    printf("****************************************\n\n");
    printf(" -  Digite sua opcao que deseja alterar: ");
    fflush(stdin);
}

void perguntasUsuario(char frase[]){
    system("cls");
    printf("%s", frase);
    fflush(stdin);
}

void incluirLivro(){
    int i, j;
    char aux_string[100];

    if(_quantidade_livros == 0)
        _biblioteca = malloc((_quantidade_livros+1) * sizeof(Livro));
    else
        _biblioteca = realloc(_biblioteca, (_quantidade_livros+1) * sizeof(Livro));

    do{
        perguntasUsuario("Digite o Titulo do livro: ");
        gets(aux_string);
        if(verificarString(aux_string) == 0)
            mensagemErro(1);
    }while(verificarString(aux_string) == 0);
    _biblioteca[_quantidade_livros].Titulo = malloc(strlen(aux_string) * sizeof(char));
    strcpy(_biblioteca[_quantidade_livros].Titulo, aux_string);

    do{    
        perguntasUsuario("Quantos Autores o Livro tem? ");
        while(scanf("%d", &_biblioteca[_quantidade_livros].Quantidade_autor) != 1){
            mensagemErro(1);
            perguntasUsuario("Quantos Autores o Livro tem? ");
        }
        if(_biblioteca[_quantidade_livros].Quantidade_autor < 1)
            mensagemErro(1);
    }while(_biblioteca[_quantidade_livros].Quantidade_autor < 1);
    _biblioteca[_quantidade_livros].Autor = malloc(_biblioteca[_quantidade_livros].Quantidade_autor * sizeof(char*));
    if(_biblioteca[_quantidade_livros].Quantidade_autor > 1){
        for(i = 0; i < _biblioteca[_quantidade_livros].Quantidade_autor; i++){
            do{
                system("cls");
                printf("Digite o nome do(a) %d Autor(a): ", i+1);
                fflush(stdin);
                gets(aux_string);
                if(verificarString(aux_string) == 0)
                    mensagemErro(1);
            }while(verificarString(aux_string) == 0);
            _biblioteca[_quantidade_livros].Autor[i] = malloc(strlen(aux_string) * sizeof(char));
            strcpy(_biblioteca[_quantidade_livros].Autor[i], aux_string);
        }
    }
    else{
        do{
            perguntasUsuario("Digite o nome do(a) Autor(a): ");
            gets(aux_string);
            if(verificarString(aux_string) == 0)
                mensagemErro(1);
        }while(verificarString(aux_string) == 0);
        _biblioteca[_quantidade_livros].Autor[0] = malloc(strlen(aux_string) * sizeof(char));
        strcpy(_biblioteca[_quantidade_livros].Autor[0], aux_string);
    }

    do{
        perguntasUsuario("Quantos Assuntos o Livro tem? ");
        while(scanf("%d", &_biblioteca[_quantidade_livros].Quantidade_assunto) != 1){
            mensagemErro(1);
            perguntasUsuario("Quantos Assuntos o Livro tem? ");
        }
        if(_biblioteca[_quantidade_livros].Quantidade_assunto < 1)
            mensagemErro(1);
    }while(_biblioteca[_quantidade_livros].Quantidade_assunto < 1);
    _biblioteca[_quantidade_livros].Assunto = malloc(_biblioteca[_quantidade_livros].Quantidade_assunto * sizeof(char*));

    if(_biblioteca[_quantidade_livros].Quantidade_assunto > 1){
        for(i = 0; i < _biblioteca[_quantidade_livros].Quantidade_assunto; i++){
            do{
                system("cls");
                printf("Digite o Assunto %d: ", i+1);
                fflush(stdin);
                gets(aux_string);
                if(verificarString(aux_string) == 0)
                    mensagemErro(1);
            }while(verificarString(aux_string) == 0);
            _biblioteca[_quantidade_livros].Assunto[i] = malloc(strlen(aux_string) * sizeof(char));
            strcpy(_biblioteca[_quantidade_livros].Assunto[i], aux_string);
        }
    }
    else{
        do{
            perguntasUsuario("Digite o Assunto: ");
            gets(aux_string);
            if(verificarString(aux_string) == 0)
                mensagemErro(1);
        }while(verificarString(aux_string) == 0);
        _biblioteca[_quantidade_livros].Assunto[0] = malloc(strlen(aux_string) * sizeof(char));
        strcpy(_biblioteca[_quantidade_livros].Assunto[0], aux_string);
    }

    do{ 
        perguntasUsuario("Digite o nome da Editora: ");
        gets(aux_string);
        if(verificarString(aux_string) == 0)
            mensagemErro(1);
    }while(verificarString(aux_string) == 0);
    _biblioteca[_quantidade_livros].Editora = malloc(strlen(aux_string) * sizeof(char));
    strcpy(_biblioteca[_quantidade_livros].Editora, aux_string);

    do{
        perguntasUsuario("Digite o Idioma: ");
        gets(aux_string);
        if(verificarString(aux_string) == 0)
            mensagemErro(1);
    }while(verificarString(aux_string) == 0);
    _biblioteca[_quantidade_livros].Idioma = malloc(strlen(aux_string) * sizeof(char));
    strcpy(_biblioteca[_quantidade_livros].Idioma, aux_string);

    do{
        perguntasUsuario("Digite o Ano de Edicao: ");
        scanf("%d", &_biblioteca[_quantidade_livros].Ano_edicao);
        if(_biblioteca[_quantidade_livros].Ano_edicao < 1 || _biblioteca[_quantidade_livros].Ano_edicao > 2023)
            mensagemErro(1);
    }while(_biblioteca[_quantidade_livros].Ano_edicao < 1 || _biblioteca[_quantidade_livros].Ano_edicao > 2023);

    do{
        perguntasUsuario("Digite a quantidade de Paginas: ");
        scanf("%d", &_biblioteca[_quantidade_livros].Numero_paginas);
        if(_biblioteca[_quantidade_livros].Numero_paginas < 1)
            mensagemErro(1);
    }while(_biblioteca[_quantidade_livros].Numero_paginas < 1);
    _quantidade_livros++;
    system("cls");
    printf("Livro ADICIONADO com SUCESSO!\n\n");
    system("pause");
}

void listarLivro(){
    system("cls");
    printf("*******************************************\n\n");
    printf("***         Listar Livro(s)             ***\n\n");
    printf("*** - (0) Voltar p/ Opcao Anterior      ***\n\n");
    printf("*** - (1) Listar Todos                  ***\n\n");
    printf("*** - (2) Listar Livro                  ***\n\n");
    printf("*******************************************\n\n");
    printf("- Digite sua opcao que deseja: ");
    fflush(stdin);
}

void listar(){
    int i, j;
    int opc1;
    char aux_string[100];

    do{
        do{
            listarLivro();
            while(scanf("%d", &opc1) != 1){
                mensagemErro(1);
                listarLivro();
            }
            if(opc1 < 0 || opc1 > 2){
                mensagemErro(1);
            }
        }while(opc1 < 0 || opc1 > 2);

        if(opc1 == 0)
            return;

        if(opc1 == 1){
            system("cls");
            printf("*******************************************\n");
            printf("***              Livro(s)               ***\n");
            printf("*******************************************\n\n");
            for(i = 0; i < _quantidade_livros; i++){
                printf("*******************************************\n");
                printf("*** - Titulo: %s\n\n", _biblioteca[i].Titulo);
                for(j = 0; j < _biblioteca[i].Quantidade_autor; j++){
                    printf("*** - Autor(a): %s\n\n", _biblioteca[i].Autor[j]);
                }
                for(j = 0; j < _biblioteca[i].Quantidade_assunto; j++){
                    printf("*** - Assunto: %s\n\n", _biblioteca[i].Assunto[j]);
                }
                printf("*** - Editora: %s\n\n", _biblioteca[i].Editora);
                printf("*** - Idioma: %s\n\n", _biblioteca[i].Idioma);
                printf("*** - Paginas: %d\n\n", _biblioteca[i].Numero_paginas);
                printf("*** - Ano Edicao: %d\n", _biblioteca[i].Ano_edicao);
                printf("*******************************************\n\n");
            }
            system("pause");
            opc1 = 0;
        }
        else{
            do{
                system("cls");
                printf("Digite o Titulo do livro: ");
                fflush(stdin);
                gets(aux_string);
                if(verificarString(aux_string) == 0){
                    mensagemErro(1);
                }
            }while(verificarString(aux_string) == 0);

            for(i = 0; i < _quantidade_livros; i++){
                opc1 = strcmp(aux_string, _biblioteca[i].Titulo);
                if(opc1 == 0)
                    break;
            }

            if(opc1 == 0){
                system("cls");
                printf("*******************************************\n");
                printf("***              Livro                  ***\n");
                printf("*******************************************\n\n");
                printf("*******************************************\n");
                printf("*** - Titulo: %s\n\n", _biblioteca[i].Titulo);
                for(j = 0; j < _biblioteca[i].Quantidade_autor; j++){
                    printf("*** - Autor(a): %s\n\n", _biblioteca[i].Autor[j]);
                }
                for(j = 0; j < _biblioteca[i].Quantidade_assunto; j++){
                    printf("*** - Assunto: %s\n\n", _biblioteca[i].Assunto[j]);
                }
                printf("*** - Editora: %s\n\n", _biblioteca[i].Editora);
                printf("*** - Idioma: %s\n\n", _biblioteca[i].Idioma);
                printf("*** - Paginas: %d\n\n", _biblioteca[i].Numero_paginas);
                printf("*** - Ano Edicao: %d\n", _biblioteca[i].Ano_edicao);
                printf("*******************************************\n\n");
                system("pause");
            }
            else{
                system("cls");
                printf("Titulo nao encontrado!\n\n");
                system("pause");
                opc1 = 0;
            }
        }
    }while(opc1 != -1);
}
void editarLivroMenu(){
    system("cls");
    printf("****************************************\n\n");
    printf("***   Editar Livro                   ***\n\n");
    printf("*** - (1) Titulo                     ***\n\n");
    printf("*** - (2) Autor(es)                  ***\n\n");
    printf("*** - (3) Editora                    ***\n\n");
    printf("*** - (4) Numero de Paginas          ***\n\n");
    printf("*** - (5) Ano de Edicao              ***\n\n");
    printf("*** - (6) Idioma                     ***\n\n");
    printf("*** - (7) Assunto(s)                 ***\n\n");
    printf("*** - (8) Voltar p/ Opcao Anterior   ***\n\n");
    printf("****************************************\n\n");
    printf("- Digite sua opcao que deseje alterar: ");
    fflush(stdin);
}

void editarTitulo(int qual_livro){
    char aux_string[100];
    do{
        system("cls");
        printf("Digite o Novo Titulo: ");
        fflush(stdin);
        gets(aux_string);
        if(verificarString(aux_string) == 0)
            mensagemErro(1);
    }while(verificarString(aux_string) == 0);
    _biblioteca[qual_livro].Titulo = realloc(NULL, strlen(aux_string) * sizeof(char));
    strcpy(_biblioteca[qual_livro].Titulo, aux_string);
    printf("Titulo Editado com SUCESSO!\n\n");
    system("pause");
}

void editarAutor(int qual_livro){
    int i, aux;
    int opc1;
    int opc2;
    int opc3 = - 1;
    char aux_string[100];
    while(opc3 == -1){
        do{
            menuIncluirEditarExcluir("Autor");
            while(scanf("%d", &opc1) != 1){
                mensagemErro(1);
                menuIncluirEditarExcluir("Autor");
            }
            if(opc1 < 1 || opc1 > 4)
                mensagemErro(1);
        }while(opc1 < 1 || opc1 > 4);
        
        if(opc1 == 4){
            return;
        }

        switch(opc1){
            case 1:
                do{
                    system("cls");
                    printf("Inclua o Nome do Autor: ");
                    fflush(stdin);
                    gets(aux_string);
                    if(verificarString(aux_string) == 0)
                        mensagemErro(1);
                }while(verificarString(aux_string) == 0);
                aux = _biblioteca[qual_livro].Quantidade_autor;
                _biblioteca[qual_livro].Quantidade_autor++;
                _biblioteca[qual_livro].Autor = realloc(_biblioteca[qual_livro].Autor, (aux+1) * sizeof(char*));
                _biblioteca[qual_livro].Autor[aux] = malloc(strlen(aux_string) * sizeof(char));
                strcpy(_biblioteca[qual_livro].Autor[aux], aux_string);
                printf("Autor Adicionado com SUCESSO!\n\n");
                system("pause");
                opc3 = -1;
            break;

            case 2:
                do{
                    system("cls");
                    printf("Autores\n\n");
                    printf(" - (0) Voltar p/ Opcao Anterior\n\n");
                    for(i = 0; i < _biblioteca[qual_livro].Quantidade_autor; i++){
                        printf(" - (%d) %s\n\n", i+1, _biblioteca[qual_livro].Autor[i]);
                    }
                    printf("Quem voce deseja Editar: ");
                    fflush(stdin);
                    while(scanf("%d", &opc1) != 1){
                        mensagemErro(1);
                        system("cls");
                        printf("Autores\n\n");
                        printf(" - (0) Voltar p/ Opcao Anterior\n\n");
                        for(i = 0; i < _biblioteca[qual_livro].Quantidade_autor; i++){
                            printf(" - (%d) %s\n\n", i+1, _biblioteca[qual_livro].Autor[i]);
                        }
                        printf("Quem voce deseja Editar: ");
                        fflush(stdin);
                    }
                    if(opc1 < 0 || opc1 > _biblioteca[qual_livro].Quantidade_autor)
                        mensagemErro(1);
                }while(opc1 < 0 || opc1 > _biblioteca[qual_livro].Quantidade_autor);

                opc1--;

                if(opc1 == -1){
                    opc3 = -1;
                    break;
                }

                do{
                    system("cls");
                    printf("Digite o Nome do Autor: ");
                    fflush(stdin);
                    gets(aux_string);
                    if(verificarString(aux_string) == 0)
                        mensagemErro(1);
                }while(verificarString(aux_string) == 0);
                _biblioteca[qual_livro].Autor[opc1] = realloc(NULL, strlen(aux_string) * sizeof(char));
                strcpy(_biblioteca[qual_livro].Autor[opc1], aux_string);
                printf("Autor Editado com SUCESSO!\n\n");
                system("pause");
                opc3 = -1;
            break;   

            default:
                if(_biblioteca[qual_livro].Quantidade_autor == 1){
                    opc3 = -1;
                    system("cls");
                    printf("Voce tem apenas um Autor, se quiser excluir, por favor, adicione outro!\n\n");
                    system("pause");
                }
                else{
                    do{
                        system("cls");
                        printf("Autores\n\n");
                        printf(" - (0) Voltar p/ Opcao Anterior\n\n");
                        for(i = 0; i < _biblioteca[qual_livro].Quantidade_autor; i++){
                            printf(" - (%d) %s\n\n", i+1, _biblioteca[qual_livro].Autor[i]);
                        }
                        printf("Quem voce deseja EXCLUIR: ");
                        fflush(stdin);
                        while(scanf("%d", &opc1) != 1){
                            mensagemErro(1);
                            system("cls");
                            printf("Autores\n\n");
                            for(i = 0; i < _biblioteca[qual_livro].Quantidade_autor; i++){
                                printf(" - (%d) %s\n\n", i+1, _biblioteca[qual_livro].Autor[i]);
                            }
                            printf("Quem voce deseja EXCLUIR: ");
                            fflush(stdin);
                        }
                        if(opc1 < 0 || opc1 > _biblioteca[qual_livro].Quantidade_autor)
                            mensagemErro(1);
                    }while(opc1 < 0 || opc1 > _biblioteca[qual_livro].Quantidade_autor);
                    
                    opc1--;

                    if(opc1 == -1){
                        opc3 = -1;
                        break;
                    }

                    do{
                        desejaMesmoExcluir(_biblioteca[qual_livro].Autor[opc1]);
                        printf("\n\n-> ");
                        while(scanf("%d", &opc2) != 1){
                            mensagemErro(1);
                            desejaMesmoExcluir(_biblioteca[qual_livro].Autor[opc1]);
                            printf("\n\n-> ");
                        }
                        if(opc2 < 1 || opc2 > 2)
                            mensagemErro(1);
                    }while(opc2 < 1 || opc2 > 2);
                    if(opc2 == 1){
                        for(opc1; opc1 < _biblioteca[qual_livro].Quantidade_autor; opc1++){
                            _biblioteca[qual_livro].Autor[opc1] = _biblioteca[qual_livro].Autor[opc1+1];
                        }
                        _biblioteca[qual_livro].Quantidade_autor--;
                        free(_biblioteca[qual_livro].Autor[opc1-1]);
                        printf("EXCLUIDO COM SUCESSO!!\n\n");
                        system("pause");
                    }
                    opc3 = -1;
                }
            break;
        }
    }
}

void editarEditora(int qual_livro){
    char aux_string[100];
    do{
        system("cls");
        printf("Digite o Nome da Editora: ");
        fflush(stdin);
        gets(aux_string);
        if(verificarString(aux_string) == 0)
            mensagemErro(1);
    }while(verificarString(aux_string) == 0);
    _biblioteca[qual_livro].Editora = realloc(NULL, strlen(aux_string) * sizeof(char));
    strcpy(_biblioteca[qual_livro].Editora, aux_string);
    printf("Editora Alterado com SUCESSO!\n\n");
    system("pause");
}

void editarPaginas(int qual_livro){
    do{
        system("cls");
        printf("Digite a quantidade de Paginas: ");
        fflush(stdin);
        while(scanf("%d", &_biblioteca[qual_livro].Numero_paginas) != 1){
            mensagemErro(1);
            system("cls");
            printf("Digite a quantidade de Paginas: ");
            fflush(stdin);
        }
        if(_biblioteca[qual_livro].Numero_paginas < 1)
            mensagemErro(1);
    }while(_biblioteca[qual_livro].Numero_paginas < 1);
    printf("Numero de Paginas Alterado com SUCESSO!\n\n");
    system("pause");
}

void editarAnoEdicao(int qual_livro){
    do{
        system("cls");
        printf("Digite o Ano de Edicao: ");
        fflush(stdin);
        while(scanf("%d", &_biblioteca[qual_livro].Ano_edicao) != 1){
            mensagemErro(1);
            system("cls");
            printf("Digite o Ano de Edicao: ");
            fflush(stdin);
        }
        if(_biblioteca[qual_livro].Ano_edicao < 1 || _biblioteca[qual_livro].Ano_edicao > 2023)
            mensagemErro(1);
    }while(_biblioteca[qual_livro].Ano_edicao < 1 || _biblioteca[qual_livro].Ano_edicao > 2023);
    printf("Ano Editado com SUCESSO!\n\n");
    system("pause");
}

void editarIdioma(int qual_livro){
    char aux_string[100];
    do{
        system("cls");
        printf("Digite o Idioma: ");
        fflush(stdin);
        gets(aux_string);
        if(verificarString(aux_string) == 0)
            mensagemErro(1);
    }while(verificarString(aux_string) == 0);
    _biblioteca[qual_livro].Idioma = realloc(NULL, strlen(aux_string) * sizeof(char));
    strcpy(_biblioteca[qual_livro].Idioma, aux_string);
    printf("Idioma Editado com SUCESSO!\n\n");
    system("pause");
}

void editarAssunto(int qual_livro){
    int i, aux;
    int opc1;
    int opc2;
    int opc3 = -1;
    char aux_string[100];
    while(opc3 == -1){
        do{
            menuIncluirEditarExcluir("Assunto");
            while(scanf("%d", &opc1) != 1){
                mensagemErro(1);
                menuIncluirEditarExcluir("Assunto");
            }
            if(opc1 < 1 || opc1 > 4)
                mensagemErro(1);
        }while(opc1 < 1 || opc1 > 4);

        if(opc1 == 4)
            return;

        switch(opc1){
            case 1:
                do{
                    system("cls");
                    printf("Inclua o Nome do Assunto: ");
                    fflush(stdin);
                    gets(aux_string);
                    if(verificarString(aux_string) == 0)
                        mensagemErro(1);
                }while(verificarString(aux_string) == 0);

                aux = _biblioteca[qual_livro].Quantidade_assunto;
                _biblioteca[qual_livro].Quantidade_assunto++;
                _biblioteca[qual_livro].Assunto = realloc(_biblioteca[qual_livro].Assunto, (aux+1) * sizeof(char*));
                _biblioteca[qual_livro].Assunto[aux] = malloc(strlen(aux_string) * sizeof(char));
                strcpy(_biblioteca[qual_livro].Assunto[aux], aux_string);
                printf("Assunto Incluido com SUCESSO!\n\n");
                system("pause");
                opc3 = -1;
            break;

            case 2:
                do{
                    system("cls");
                    printf("Assuntos\n\n");
                    printf(" - (0) Voltar p/ Opcao Anterior\n\n");
                    for(i = 0; i < _biblioteca[qual_livro].Quantidade_assunto; i++){
                        printf(" - (%d) %s\n\n", i+1, _biblioteca[qual_livro].Assunto[i]);
                    }
                    printf("Qual Assunto voce deseja Editar: ");
                    fflush(stdin);
                    while(scanf("%d", &opc1) != 1){
                        mensagemErro(1);
                        system("cls");
                        printf("Autores\n\n");
                        printf(" - (0) Voltar p/ Opcao Anterior\n\n");
                        for(i = 0; i < _biblioteca[qual_livro].Quantidade_assunto; i++){
                            printf(" - (%d) %s\n\n", i+1, _biblioteca[qual_livro].Assunto[i]);
                        }
                        printf("Qual Assunto voce deseja Editar: ");
                        fflush(stdin);
                    }
                    if(opc1 < 0 || opc1 > _biblioteca[qual_livro].Quantidade_assunto)
                        mensagemErro(1);
                }while(opc1 < 0 || opc1 > _biblioteca[qual_livro].Quantidade_assunto);

                opc1--;

                if(opc1 == -1){
                    opc3 = -1;
                    break;
                }

                do{
                    system("cls");
                    printf("Digite o Nome do Assunto: ");
                    fflush(stdin);
                    gets(aux_string);
                    if(verificarString(aux_string) == 0)
                        mensagemErro(1);
                }while(verificarString(aux_string) == 0);
                _biblioteca[qual_livro].Assunto[opc1] = realloc(NULL, strlen(aux_string) * sizeof(char));
                strcpy(_biblioteca[qual_livro].Assunto[opc1], aux_string);
                printf("Assunto Editado com SUCESSO!\n\n");
                system("pause");
                opc3 = -1;
            break;

            default:
                if(_biblioteca[qual_livro].Quantidade_assunto == 1){
                    system("cls");
                    printf("Voce tem apenas um Assunto, se quiser excluir, por favor, adicione outro!\n\n");
                    system("pause");
                    opc3 = -1;
                }
                else{
                    do{
                        system("cls");
                        printf("Assuntos\n\n");
                        printf(" - (0) Voltar p/ Opcao Anterior\n\n");
                        for(i = 0; i < _biblioteca[qual_livro].Quantidade_assunto; i++){
                            printf(" - (%d) %s\n\n", i+1, _biblioteca[qual_livro].Assunto[i]);
                        }
                        printf("Qual assunto deseja EXCLUIR: ");
                        fflush(stdin);
                        while(scanf("%d", &opc1) != 1){
                            mensagemErro(1);
                            system("cls");
                            printf("Assuntos\n\n");
                            for(i = 0; i < _biblioteca[qual_livro].Quantidade_assunto; i++){
                                printf(" - (%d) %s\n\n", i+1, _biblioteca[qual_livro].Assunto[i]);
                            }
                            printf("Qual assunto voce deseja EXCLUIR: ");
                            fflush(stdin);
                        }
                        if(opc1 < 0 || opc1 > _biblioteca[qual_livro].Quantidade_assunto)
                            mensagemErro(1);
                    }while(opc1 < 0 || opc1 > _biblioteca[qual_livro].Quantidade_assunto);
                    
                    opc1--;

                    if(opc1 == -1){
                        opc3 = -1;
                        break;
                    }

                    do{
                        desejaMesmoExcluir(_biblioteca[qual_livro].Assunto[opc1]);
                        printf("\n\n-> ");
                        while(scanf("%d", &opc2) != 1){
                            mensagemErro(1);
                            desejaMesmoExcluir(_biblioteca[qual_livro].Assunto[opc1]);
                            printf("\n\n-> ");
                        }
                        if(opc2 < 1 || opc2 > 2)
                            mensagemErro(1);
                    }while(opc2 < 1 || opc2 > 2);
                    if(opc2 == 1){
                        for(opc1; opc1 < _biblioteca[qual_livro].Quantidade_assunto; opc1++){
                            _biblioteca[qual_livro].Assunto[opc1] = _biblioteca[qual_livro].Assunto[opc1+1];
                        }
                        _biblioteca[qual_livro].Quantidade_assunto--;
                        free(_biblioteca[qual_livro].Assunto[opc1-1]);
                        printf("EXCLUIDO COM SUCESSO!!\n\n");
                        system("pause");
                    }
                    opc3 = -1;
                }
            break;
        }
    };
}

void mostrarLivrosEditar(){
    int i;
    system("cls");
    printf("***************************************\n\n");
    printf("***          Editar Livro(s)        ***\n\n\n");
    printf("*** - (0) Voltar p/ Opcao Anterior\n\n");
    for(i = 0; i < _quantidade_livros; i++){
        printf("*** - (%d) Titulo: %s\n\n", i+1, _biblioteca[i].Titulo);
    }
    printf("************************************\n\n");
    printf("- Digite sua opcao que deseje alterar: ");
    fflush(stdin);
}

void editar(){
    int opc1 = 8;
    int opc2 = -1;
    int opc3;
    int qual_livro;

    while(opc1 == 8){
        do{
            mostrarLivrosEditar();
            while(scanf("%d", &qual_livro) != 1){
                mensagemErro(1);
                mostrarLivrosEditar();
            }
            qual_livro--;
            if(qual_livro < -1 || qual_livro >= _quantidade_livros)
                mensagemErro(1);
        }while(qual_livro < -1 || qual_livro >= _quantidade_livros);

        if(qual_livro == -1)
            return;
        
        while(opc2 == -1){
            do{
                editarLivroMenu();
                while(scanf("%d", &opc1) != 1){
                    mensagemErro(1);
                    editarLivroMenu();
                }
                if(opc1 < 1 || opc1 > 8)
                    mensagemErro(1);
            }while(opc1 < 1 || opc1 > 8);

            if(opc1 == 8)
                opc2 = 0;

            if(opc1 != 8){
                switch(opc1){
                    case 1:
                        editarTitulo(qual_livro);
                        opc2 = -1;
                    break;
                    case 2:
                        editarAutor(qual_livro);
                        opc2 = -1;
                    break;
                    case 3:
                        editarEditora(qual_livro);
                        opc2 = -1;
                    break;
                    case 4:
                        editarPaginas(qual_livro);
                        opc2 = -1;
                    break;
                    case 5:
                        editarAnoEdicao(qual_livro);
                        opc2 = -1;
                    break;
                    case 6:
                        editarIdioma(qual_livro);
                        opc2 = -1;
                    break;
                    default:
                        editarAssunto(qual_livro);
                    break;
                }
            }
        }
    }
}

void mostrarExcluir(){
    int i;
    system("cls");
    printf("****************************************\n\n");
    printf("***   Qual Livro deseja EXCLUIR?\n\n");
    printf("*** - (0) Voltar p/ Opcao Anterior\n\n");
    for(i = 0; i < _quantidade_livros; i++){
        printf("*** - (%d) Livro: %s\n\n", i+1, _biblioteca[i].Titulo);
    }
    printf("- Digite sua opcao que deseja EXCLUIR: ");
    fflush(stdin);
}

void desejaMesmoExcluir(char palavra[]){
    system("cls");
    printf("Tem certeza que deseja EXCLUIR [%s] ? (1 - Sim / 2 - Nao)", palavra);
    fflush(stdin);
}

void excluirLivro(){
    int quem;
    int opcao = 2;

    while(opcao == 2){
        do{
            mostrarExcluir();
            while(scanf("%d", &quem) != 1){
                mensagemErro(1);
                mostrarExcluir();
            }
            quem--;
            if(quem < -1 || quem >= _quantidade_livros)
                mensagemErro(1);
        }while(quem < -1 || quem >= _quantidade_livros);

        if(quem == -1)
            return;

        do{
            desejaMesmoExcluir(_biblioteca[quem].Titulo);
            printf("\n\n-> ");
            scanf("%d", &opcao);
            if(opcao < 1 || opcao > 2)
                mensagemErro(1);
        }while(opcao < 1 || opcao > 2);
    }

    for(quem; quem < _quantidade_livros; quem++){
        _biblioteca[quem] = _biblioteca[quem+1];
    }
    _quantidade_livros--;
    _biblioteca = realloc(_biblioteca, _quantidade_livros * sizeof(Livro));
    system("cls");
    printf("EXCLUIDO COM SUCESSO!\n\n");
    system("pause");
}

void mensagemErro(int opcao){
    switch(opcao){
        case 1:
            system("cls");
            printf("[ERRO] Entrada Invalida!\n\n");
            system("pause");
        break;
        case 2:
            system("cls");
            printf("Lista Cheia!\n\n");
            system("pause");
        break;
        case 3:
            system("cls");
            printf("Lista vazia!\n\n");
            system("pause");
        break;
    }
}

void salvarArquivo(char arq[]){
    FILE *file = fopen(arq, "w");
    int i, j;

    if(file){
        for(i = 0; i < _quantidade_livros; i++){
            fprintf(file, "%s;", _biblioteca[i].Titulo);
            fprintf(file, "%s;", _biblioteca[i].Idioma);
            fprintf(file, "%s;", _biblioteca[i].Editora);
            fprintf(file, "%d;", _biblioteca[i].Numero_paginas);
            fprintf(file, "%d;", _biblioteca[i].Ano_edicao);
            for(j = 0; j < _biblioteca[i].Quantidade_autor; j++){
                fprintf(file, "%s:", _biblioteca[i].Autor[j]);
            }
            for(j = 0; j < _biblioteca[i].Quantidade_assunto; j++){
                fprintf(file, "%s*", _biblioteca[i].Assunto[j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else{
        printf("[ERRO] Nao foi possivel escrever no arquivo!\n\n");
        system("pause");
    }    
}

void lerArquivo(char arq[]){
    FILE *file = fopen(arq, "r");
    int i = 0;
    int j = 0;
    int k = 0;
    int tam = 0;
    int cont = 0;
    char aux = 'a';// atribui esse valor apenas para entrar no laço de repetição
    char aux_string[100];

    if(file){
        while(aux != EOF){
            aux = fgetc(file);
            if(aux != '\n' && aux != ':' && aux != ';' && aux != '*' && aux != EOF)
                aux_string[i++] = aux;
            else{
                aux_string[i] = '\0';
                i = 0;
                if(j == 0 && tam == 0)
                    _biblioteca = malloc(sizeof(Livro));
                else if(tam > 0 && aux != EOF)
                    _biblioteca = realloc(_biblioteca, (j+1) * sizeof(Livro));
                if(aux == ';'){
                    if(cont == 0){
                        _biblioteca[j].Titulo = malloc(strlen(aux_string) * sizeof(char));
                        strcpy(_biblioteca[j].Titulo, aux_string);
                        _biblioteca[j].Quantidade_autor = 0;
                        _biblioteca[j].Quantidade_assunto = 0;
                        cont++;
                        tam = -1;
                    }
                    else if(cont == 1){
                        _biblioteca[j].Idioma = malloc(strlen(aux_string) * sizeof(char));
                        strcpy(_biblioteca[j].Idioma, aux_string);
                        cont++;
                    }
                    else if(cont == 2){
                        _biblioteca[j].Editora = malloc(strlen(aux_string) * sizeof(char));
                        strcpy(_biblioteca[j].Editora, aux_string);
                        cont++;
                    }
                    else if(cont == 3){
                        _biblioteca[j].Numero_paginas = atoi(aux_string);
                        cont++;
                    }
                    else{
                        _biblioteca[j].Ano_edicao = atoi(aux_string);
                        cont = -1;
                    }
                }
                else if(aux == ':'){
                    if(cont == -1){
                        _biblioteca[j].Autor = malloc(sizeof(char*));
                        _biblioteca[j].Autor[k] = malloc(strlen(aux_string) * sizeof(char));
                        strcpy(_biblioteca[j].Autor[k], aux_string);
                        k++;
                        _biblioteca[j].Quantidade_autor = k;
                        cont--;
                    }
                    else{
                        _biblioteca[j].Autor = realloc(_biblioteca[j].Autor, (k+1) * sizeof(char*));
                        _biblioteca[j].Autor[k] = malloc(strlen(aux_string) * sizeof(char));
                        strcpy(_biblioteca[j].Autor[k], aux_string);
                        k++;
                        _biblioteca[j].Quantidade_autor = k;
                    }
                }
                else if(aux == '*'){
                    if(cont < 0){
                        k = 0;
                        _biblioteca[j].Assunto = malloc(sizeof(char*));
                        _biblioteca[j].Assunto[k] = malloc(strlen(aux_string) * sizeof(char));
                        strcpy(_biblioteca[j].Assunto[k], aux_string);
                        k++;
                        _biblioteca[j].Quantidade_assunto = k;
                        cont = 1;
                    }
                    else{
                        _biblioteca[j].Assunto = realloc(_biblioteca[j].Assunto, (k+1) * sizeof(char*));
                        _biblioteca[j].Assunto[k] = malloc(strlen(aux_string) * sizeof(char));
                        strcpy(_biblioteca[j].Assunto[k], aux_string);
                        k++;
                        _biblioteca[j].Quantidade_assunto = k;
                    }
                }
                else{
                    if(aux == '\n'){
                        j++;
                        k = 0;
                        tam = 1;
                        cont = 0;
                    }
                }
            }
        };
        _quantidade_livros = j;
        fclose(file);
    }
    else{
        printf("[ERRO] Nao foi possivel ler o arquivo!\n\n");
        system("pause");
    }
}

void menuListar(){
    system("cls");
    printf("************************************\n\n");
    printf("*** - (1) Incluir Livro          ***\n\n");
    printf("*** - (2) Editar Livro           ***\n\n");
    printf("*** - (3) Excluir Livro          ***\n\n");
    printf("*** - (4) Listar Livro(s)        ***\n\n");
    printf("*** - (5) Encerrar Programa      ***\n\n");
    printf("************************************\n\n");
    printf("-> ");
    fflush(stdin);
}

void menu(){
    int opcao = 0;
    char arquivo_txt[] = {"test.txt"};
    lerArquivo(arquivo_txt);

    while(opcao != 5){
        do{
            menuListar();
            while(scanf("%d", &opcao) != 1){
                mensagemErro(1);
                menuListar();
            }
            if(opcao < 1 || opcao > 5)
                mensagemErro(1);
        }while(opcao < 1 || opcao > 5);

        if(opcao != 5){
            switch(opcao){
                case 1:
                    if(_quantidade_livros < MAX_LIVROS)
                        incluirLivro();
                    else
                        mensagemErro(2);
                break;
                case 2:
                    if(_quantidade_livros > 0)
                        editar();
                    else
                        mensagemErro(3);
                break;
                case 3:
                    if(_quantidade_livros > 0)
                        excluirLivro();
                    else
                        mensagemErro(3);
                break;
                default:
                    if(_quantidade_livros > 0)
                        listar();
                    else
                        mensagemErro(3);
                break;
            }
        }
    };
    salvarArquivo(arquivo_txt);
    free(_biblioteca);
}