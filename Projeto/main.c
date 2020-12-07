#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define TOTALQUESTIONARIOS 1000
#define QUESTIONARIOSESCOLA 200
#define MAX_TEXTO 50

typedef struct  //ESTRUTURA LIMITE DE 1000 QUESTIONARIOS 200 POR ESCOLA
{
    int id_questionario[TOTALQUESTIONARIOS];
    int id_escola[TOTALQUESTIONARIOS];
    int dia[TOTALQUESTIONARIOS];
    int mes[TOTALQUESTIONARIOS];
    int ano[TOTALQUESTIONARIOS];
    int hora[TOTALQUESTIONARIOS];
    int minutos[TOTALQUESTIONARIOS];
    int idade[TOTALQUESTIONARIOS];
    char genero[TOTALQUESTIONARIOS];
    char local_residencia[TOTALQUESTIONARIOS];
    char tipo_participante[TOTALQUESTIONARIOS];         //SE È (DOCENTE,ESTUDANTE,FUNCIONÁRIO OU INVESTIGADOR)
    char contacto_covid[TOTALQUESTIONARIOS];            //SE A PRESSOA TEVE EM CONTACTO COM ALGUEM COM COVID (SIM/NAO/DESCONHECIDO)
    char sintomas[TOTALQUESTIONARIOS][MAX_TEXTO];       //QUE SINTOMAS A PESSOA A SER QUESTIONADA TEM (DIFICULDADE RESPIRATORIA,,DOR MUSCULAR,FADIGA,FALTA DE PALADAR,NÁUSEAS e TOSSE)
    char doenca_risco[TOTALQUESTIONARIOS][MAX_TEXTO];  //DOENÇAS DE RISCO (AUTOIMUNE,CANCRO,CARDIOVASCULAR,DIABETES,HIPERTENSÃO,OBESIDADE,OBESIDADE,RENAL,RESPIRATÓRIA)
    int temperatura[TOTALQUESTIONARIOS];
} t_questionario;





typedef struct
{
    int idescola[TOTALQUESTIONARIOS];
    char nomeescola[TOTALQUESTIONARIOS];   //ESCOLAS (ESECS,ESTG,ESAD,ESTM,ESS)
    char localidade[TOTALQUESTIONARIOS];
} t_escola;




typedef struct contagio_baixo
{
    int id_escola;
    int id;
    int horas;
    int minutos;
    int segundos;
    char risco_de_contagio[MAX_TEXTO];
    int idade;
    char genero[MAX_TEXTO];
    char cidade[MAX_TEXTO];
    char tipo_de_participante[MAX_TEXTO];
    float temp;
    char contacto_com_pessoa_infetada[MAX_TEXTO];
    char sintomas[MAX_TEXTO];
    char sem_doenca[MAX_TEXTO];
}   t_baixo;

//LIMPA A CONSOLA E BUFFER
void limpar_consola(void);
//FUNCAO QUE FAZ SAIR DO PROGRAMA
void Sair(void);

void menu_principal(int contador_ESECS,int contador_ESTG,int contador_ESAD,int contador_ESTM,int contador_ESS);
int menu_genero(void);
int menu_tipo_de_participante(void);
int menu_contacto_com_pessoa_infetada(void);
int menu_sintomas(void);
int menu_doencas(void);
void menu_principal_opcao(void);

char local_residencia[TOTALQUESTIONARIOS];
char tipo_participante[TOTALQUESTIONARIOS];         //SE È (DOCENTE,ESTUDANTE,FUNCIONÁRIO OU INVESTIGADOR)
char contacto_covid[TOTALQUESTIONARIOS];


//ESTAS VARIAVEIS SERVEM PARA CONTAR OS TESTES DE CADA ESCOLA;
int contador_ESECS=0;
int contador_ESTG=0;
int contador_ESAD=0;
int contador_ESTM=0;
int contador_ESS=0;

//FUNCAO QUE LIMPA A CONSOLA E BUFFER
void limpar_consola()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    fflush(stdin);
}
                //FUNCAO MAIN
int main()
{
    menu_principal(contador_ESECS,contador_ESTG,contador_ESAD,contador_ESTM,contador_ESS);
    menu_principal_opcao();
    return 0;
}



/*
void quetionario();
{
    char ESCOLAS;
    int perguntas;
    do
    {
        switch(perguntas)
        case 1:
        break;
    case 1:
        break;
    case 1:
        break;
    case 1:
        break;
    case 1:
        break;
    case 1:
        break;
    case 1:
        break;
    case 1:
        break;
        {
        }
        while(perguntas <=1 || perguntas < 9);

        printf("Introduza a sua escola\n");
        scanf("c%",&ESCOLAS);
        /*switch(ESCOLAS)
        {
        case 'ESTG':
        break;
        case 'ESECES':
        break;
        case 'ESTM':
        break;
        case 'ESAD.CR';
        break;
        case 'ESSLEI';
        break;
        }default printf("Escola invalida");

    }
}
*/



/**
void Escola
{

}**/
void menu_principal(int contador_ESECS,int contador_ESTG,int contador_ESAD,int contador_ESTM,int contador_ESS)
{

    // 1-menu principal 2-menu inserir e consultar
    printf("1- Registar e Consultar os dados das Escolas\n");
    printf("2- Registar e Consultar os dados dos Questionarios\n\n");
    printf("Estatisticas:\n");
    printf("Total de inqueritos Respondido pos escolas:\n\n");
    printf("\tESECS:%d/200 \n",contador_ESECS);
    printf("\tESTG:%d/200 \n",contador_ESTG);
    printf("\tESAD:%d/200 \n",contador_ESAD);
    printf("\tESTM:%d/200 \n",contador_ESTM);
    printf("\tESS:%d/200 \n\n",contador_ESS);
    printf("3- Total de inqueritos por genero e idade\n"); //FAIXA ETARIA (18-23; 24-30; 31-40; 41-50; 51-65; +66)
    printf("4 - Percentagem de inqueritos por nivel de risco de contagio\n");
    printf("5 - Guardar ou Ler dados de ficheiro binario\n");
    printf("6 - Sair\n");

    return;
}

void menu_principal_opcao(void){
int opcao;
do{
    scanf("%d",&opcao);

    switch(opcao)
    {
        case 1://MENU REGISTAR E CONSULTAR OS DADOS DAS ESCOLAS
        break;

        case 2://MENU REGISTAR E CONSULTAR OS DADOS DOS QUESTIONARIOS
        break;

        case 3://MENU TOTAL DE INQUERITOS POR GENERO E IDADE
        break;

        case 4://MENU?? PERCENTAGEM DE INQUERITOS POR NIVEL DE RISCO DE CONTAGIO
        break;

        case 5://MENU GUARDAR OU LER DADOS DE FICHEIROS BINARIOS
        break;

        case 6:
             Sair();
         break;

        default:
            printf("Opção invalida!");
        break;
    }
    }while(opcao!=1 || opcao!=2 || opcao!=3 || opcao!=4 || opcao!=5 || opcao!=6);
    return;
}

void Sair(void)
{
    char confirmacao;
do{
        printf("Tem a certeza que pretende sair? (S/N)\n");
        fflush(stdin);
        scanf("%c",&confirmacao);
        confirmacao=toupper(confirmacao);

        if(confirmacao=='S'){
            exit(0);
        }

        else if(confirmacao=='N'){
             menu_principal(contador_ESECS,contador_ESTG,contador_ESAD,contador_ESTM,contador_ESS);
             limpar_consola();
             return;
        }

        else if(confirmacao!='S' ||confirmacao!='N'){
                printf("Opcao Invalida so pode escolher S/N");
        }
}while(confirmacao!='S' || confirmacao!='N');
return;
}

int menu_genero(void)
{
    printf("(M)asculino\n");
    printf("(F)emenino\n");
}
int menu_tipo_de_participante(void)
{
    printf("1.Docente\n");
    printf("2.Estudante\n");
    printf("3.Funcionario\n");
    printf("4.Investigador\n");

}

int menu_contacto_com_pessoa_infetada(void)
{
    printf("(S)im\n");
    printf("(N)ao\n");
    printf("(D)esconhecido\n");
}

int menu_sintomas(void)
{
    printf("1.Dificuldade respiratoria\n");
    printf("2.Dor Muscular\n");
    printf("3.Fadiga\n");
    printf("4.Falta de Paladar\n");
    printf("5.Nauseas\n");
    printf("6.Febre\n");
    printf("7.Tosse\n");
    printf("0.Sair\n");
}
int menu_doencas(void)
{
    printf("1.Autoimune\n");
    printf("2.Cancro\n");
    printf("3.Cardiovascular\n");
    printf("4.Diabetes\n");
    printf("5.Hipertensão\n");
    printf("6.Obesidade\n");
    printf("7.Renal\n");
    printf("8.Respiratoria\n");
    printf("0.Sair");
}
/*inserir e consultar menus*/







/*
void inserir_idade(void);
{
    do
    {
        printf("Introduza a sua idade\n");
        scanf("%d", &idade);
    }
    while(idade < 18 && idade <= 0);
    printf("A sua idade e igual ou superior a 18\n");

}
void inserir_genero(void);
{


    do
    {
        char sexo;
        printf("Introduza o seu genero");
        scanf("%c", );
        switch(sexo)
        {
        case 'F':
            break;
        case 'M':
            break;
        default:
            printf("Opcao invalida");
        }
        while(sexo != 'F' &&  sexo !='M');

    }
}
void menu_opcoes(void);
{
    int perguntas;
    do
    {
        switch(perguntas)
        {
        case  1 :
            inserir_idade();
            break;
        case 2 :
            inserir_genero();
            break;
        case 3 :
            inserir_residencia();
            break;
        case 4 :
            inserir_tipo_participante();
            break;
        case 5 :
            inserir_dias();
            break;
        case 6 :
            inserir_sintomas();
            break;
        case 7 :
            break;
        default:
            printf("Opcao Inválida");
        }
    }
    while(perguntas > 0 && perguntas < 9);
    printf("Opcao invalida");
}
void inserir_residencia(void);
{
    char residencia[30];
    printf("Introduza a sua residencia");
    scanf("%c", &residencia);
}
void inser
*/
