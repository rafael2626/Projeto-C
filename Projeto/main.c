#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define TOTALQUESTIONARIOS 1000
#define QUESTIONARIOSESCOLA 200
#define MAX_TEXTO 50
#define TOTALESCOLAS 5

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
    int idescola;
    char nomeescola[TOTALESCOLAS];   //ESCOLAS (ESECS,ESTG,ESAD,ESTM,ESS)
    char localidade[TOTALESCOLAS];
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

//MENUS
void menu_principal(int contador_ESECS,int contador_ESTG,int contador_ESAD,int contador_ESTM,int contador_ESS);
int menu_genero(void);
void menu_tipo_de_participante(void);
int menu_contacto_com_pessoa_infetada(void);
int menu_sintomas(void);
int menu_doencas(void);
void menu_principal_opcao(void);
int menu_idade(void);
void menu_escolas(void); //MENU ESCOLAS OPCAO 1 NO MENU PRINCIPAL
void menu_questionarios(void); //MENU QUESTIONARIOS OPCAO 2 NO MENU PRINCIPAL
void menu_inquerito_idade(void); //MENU
//FIM MENUS

//INTRODUZIR
int Introduzir_escola(t_escola escola[],int contadoridescola);
//FIM INTRODUZIR


//CONSULTAR
void Consultar_escola(t_escola escola[]);

//FIM CONSULTAR


//LER DADOS
void ler_string();
int ler_numero();
//FIM LER DADOS

char local_residencia[TOTALQUESTIONARIOS];
char tipo_participante[TOTALQUESTIONARIOS];         //SE È (DOCENTE,ESTUDANTE,FUNCIONÁRIO OU INVESTIGADOR)
char contacto_covid[TOTALQUESTIONARIOS];


//ESTAS VARIAVEIS SERVEM PARA CONTAR OS TESTES DE CADA ESCOLA NOS QUESTIONARIOS;
int contador_ESECS=0;
int contador_ESTG=0;
int contador_ESAD=0;
int contador_ESTM=0;
int contador_ESS=0;

//CONNTADOR ID ESCOLA
int contadoridescola=1;



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
        switch(ESCOLAS)
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
void ler_string(char txt[], char str[], int max_len) {


printf("%s",txt);
fflush(stdin);
fgets(str, max_len, stdin);

limpar_consola();

}

int ler_numero(char text[])
{
    int numero;
    fflush(stdin);
    printf("%s: ", text);
    scanf("%d", &numero);
    return numero;
}

int lerInteiro (char mensagem[], int limMin, int limMax)
{
    int num, resultado;

    do
    {
        printf("%s", mensagem);
        resultado = scanf("%d", &num);
        limpar_consola();
        if (resultado == 0)
        {
            printf("\n\nERRO: tem de inserir um valor numerico\n\n");
        }
        else
        {
            if (num < limMin || num > limMax)
            {
                printf("\nERRO: o valor nao pertence ao intervalo [%d, %d]\n\n",limMin, limMax);
            }
        }
    }
    while (resultado==0 || num < limMin || num > limMax);
    return num;
}


void menu_principal_opcao(void)
{
    int opcao;
    do
    {
        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
            menu_escolas();
            //MENU REGISTAR E CONSULTAR OS DADOS DAS ESCOLAS
            break;

        case 2:
            menu_questionarios();
            //MENU REGISTAR E CONSULTAR OS DADOS DOS QUESTIONARIOS
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
    }
    while(opcao!=1 || opcao!=2 || opcao!=3 || opcao!=4 || opcao!=5 || opcao!=6);
    return;
}
void menu_escolas(void)
{
    printf("1 - Inserir Escola\n");
    printf("2 - Consultar Escolas\n");
}

void menu_questionarios(void)
{
    printf("1 - Inserir Questionario\n");
    printf("2 - Consultas Questionarios\n");
}

void menu_inquerito_idade(void)
{
    printf("********Faixa Etaria********\n");
    printf("Idade enttre 18 - 23\n");
    printf("Idade entre 24 - 30\n");
    printf("Idade entre 31 - 40\n");
    printf("Idade entre 41 - 50\n");
    printf("Idade entre 51 - 65\n");
    printf("Idade +66\n");
}

char menu_genero_opcao(void)
{
    char opcao;
    do{
    printf("Introduza o genero");
    scanf("%c",&opcao);
    switch(opcao)
    {
        case 'M':
            break;

        case 'F':
            break;
        default:printf("Resposta invalida");
    }
    opcao=toupper(opcao);
    }while(opcao!='M' || opcao!='F');
}


int menu_escolas_opcao(t_escola escola[])
{
    int opcao;
    do
    {
        printf("Introduza a opcao ->");
        scanf("%d",&opcao);
        switch(opcao)
        {
        case 1:
            Introduzir_escola(escola,contadoridescola);
            break;

        case 2:
            Consultar_escola(escola);
            break;
        case 3:
            Listar_escolas(escola); //LISTAR CODIGO [EXTRA]
            break;
        default:
            printf("Opcao Invalida!");
        }
    }
    while(opcao<1 || opcao>3);


}

void Sair(void)
{
    char confirmacao;
    do
    {
        printf("Tem a certeza que pretende sair? (S/N)\n");
        fflush(stdin);
        scanf("%c",&confirmacao);
        confirmacao=toupper(confirmacao);

        if(confirmacao=='S')
        {
            exit(0);
        }

        else if(confirmacao=='N')
        {
            menu_principal(contador_ESECS,contador_ESTG,contador_ESAD,contador_ESTM,contador_ESS);
            limpar_consola();
            return;
        }

        else if(confirmacao!='S' ||confirmacao!='N')
        {
            printf("Opcao Invalida so pode escolher S/N");
        }
    }
    while(confirmacao!='S' || confirmacao!='N');
    return;
}
int questionario(void)
{
    printf("1.Idade do Participante\n");
    printf("2.Genero\n");
    printf("3.Local de Residencia\n");
    printf("4. Tipo de Participante\n");
    printf("5.Nos últimos 15 dias esteve em contacto com pessoa infetada com COVID-19\n");
    printf("6.Que sintomas sente (0 para terminar)\n");
    printf("7.Que doenças tem (0 para terminar)");

}
int menu_idade(void)
{
    printf("Idade do Participante\n");
}
int menu_genero(void)
{
    printf("(M)asculino\n");
    printf("(F)emenino\n");
}
void menu_tipo_de_participante(void)
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

int menu_inserir_registar_genero(void)
{
    printf("1.Inserir genero\n");
    printf("2.Consultar genero\n");
}
int menu_inserir_tipo_de_participante(void)
{
    printf("1.Inserir tipo de participante\n");
    printf("2.Consultar tipo de participante\n");
}
int  menu_inserir_sintomas(void)
{
    printf("1.Inserir sintomas\n");
    printf("2.Consultar sintomas\n");
}
int menu_inserir_doencas(void)
{
    printf("1.Inserir doencas\n");
    printf("2.Consultar coencas\n");
}



int inserir_idade(void)
{
    int idade;
    do
    {
        printf("Introduza a sua idade\n");
        scanf("%d", &idade);
    }
    while(idade < 18 && idade <= 0);
    printf("A sua idade e igual ou superior a 18\n");

    return idade;

}
void inserir_genero(void)
{
    char sexo;
    do
    {
        printf("Introduza o seu genero");
        scanf("%c",&sexo);
        fflush(stdin);
        switch(sexo)
        {
        case 'F':
            break;
        case 'M':
            break;
        default:
            printf("Opcao invalida");
        }
    }
    while(sexo != 'F' &&  sexo !='M');

    void menu_tipo_de_participante(void);
    {
        int tipo_de_participante;
        do
        {
            switch(tipo_de_participante)
            {
            case 1:
                printf("Docente\n");
                break;
            case 2:
                printf("Estudante\n");
                break;
            case 3:
                printf("Funcionario\n");
                break;
            case 4:
                printf("Investigador\n");

            default:
                printf("Opcao invalida");
            }
        }
        while(tipo_de_participante!=1 || tipo_de_participante!=2 || tipo_de_participante!=3 || tipo_de_participante!=4);


    }
    void menu_contacto_com_pessoa_infetada()
    {
        char opcao;
        do
        {
            switch(opcao)
            {

            case 'S':
                break;
            case 'N':
                break;
            case 'D':
                break;
            }

        }
        while(opcao!='S' || opcao!= 'N' || opcao!= 'D');
        printf("Opcao inválida");

    }

    int Introduzir_escola(t_escola escola[],int contadoridescola)
    {
        int i=0;


        //TODO: VALIDAÇÕES e fazer debug

        escola[i].idescola=contadoridescola;
        ler_string("Introduza as iniciais da escola (ESECS,ESTG,ESAD,ESTM,ESS\n",escola[contadoridescola].nomeescola,MAX_TEXTO);

        ler_string("Introduza a localidade da escola\n",escola[contadoridescola].localidade,MAX_TEXTO);

        contadoridescola++;
        return contadoridescola;


    }

    void Consultar_escola(t_escola escola[])
    {
        //TODO VER SE FUNCIONA
        int i;
        i = lerInteiro("Insira o id a pesquisar: ",1,strlen(escola));


        printf("ID:%d\n",escola[i].idescola);
        printf("Nome da escola:%s\n",escola[i].nomeescola);
        printf("Localidade da escola:%s\n",escola[i].localidade);


    }
    void Listar_escolas(t_escola escola[])
    {

        //TODO VER SE FUNCIONA
        int i;
        for(i=1;i<6;i++)
        {
            printf("ID:%d\n",escola[i].idescola);
            printf("Nome da escola:%c\n",escola[i].nomeescola);
            printf("Localidade da escola:%c\n",escola[i].localidade);
        }

    }

    int Introduzir_Questionario(t_questionario questionario)
    {
        //TODO: FAZER FUNÇÔES PARA ESTAS CENAS
    printf("ID:");
    printf("ID ESCOLA:");
    printf("DATA:");
    printf("HORA:");
    printf("NIVEL CONTAGIO");
    pritnf("IDADE:");
    printf("Genero:");
    printf("Local de residencia:");
    printf("Tipo de participante");
    printf("Temperatura");
    printf("Esteve em contacto com alguem com covid-19?");
    printf("Sintomas");
    printf("Doenças");

    }




}

//    void menu_opcoes(void);
/*
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
