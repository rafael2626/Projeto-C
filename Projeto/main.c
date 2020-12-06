#include <stdio.h>
#include <stdlib.h>
#define TOTALQUESTIONARIOS 1000
#define QUESTIONARIOSESCOLA 200
#define MAX_TEXTO 50

typedef struct  //ESTRUTURA LIMITE DE 1000 QUESTIONARIOS 200 POR ESCOLA
{
    int id_questionario[TOTALQUESTIONARIOS];
    int idade[TOTALQUESTIONARIOS];
    char genero[TOTALQUESTIONARIOS];
    char local_residencia[TOTALQUESTIONARIOS];
    char tipo_participante[TOTALQUESTIONARIOS];         //SE È (DOCENTE,ESTUDANTE,FUNCIONÁRIO OU INVESTIGADOR)
    char contacto_covid[TOTALQUESTIONARIOS];            //SE A PRESSOA TEVE EM CONTACTO COM ALGUEM COM COVID (SIM/NAO/DESCONHECIDO)
    char sintomas[TOTALQUESTIONARIOS][MAX_TEXTO];       //QUE SINTOMAS A PESSOA A SER QUESTIONADA TEM (DIFICULDADE RESPIRATORIA,,DOR MUSCULAR,FADIGA,FALTA DE PALADAR,NÁUSEAS e TOSSE)
    char doença_risco[TOTALQUESTIONARIOS][MAX_TEXTO];//DOENÇAS DE RISCO (AUTOIMUNE,CANCRO,CARDIOVASCULAR,DIABETES,HIPERTENSÃO,OBESIDADE,OBESIDADE,RENAL,RESPIRATÓRIA)
    int temperatura[TOTALQUESTIONARIOS];
} t_questionario;





typedef struct
{
    int idescola[];
    char nomeescola[];   //ESCOLAS (ESECS,ESTG,ESAD,ESTM,ESS)
    char localidade[];
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
    t_baixo
};

t_questionario criar_idade(int idade_existentes);
int inserir_idade(int idade_existente, t_questionario/**/ [] );
void consultar_idade(int idade_existentes,  t_questionario idade[]);
void gravar_idade_em_ficherio(t_questionario[], int idades_existentes, char nome[]);
int ler_idade_de_ficheiro(t_questionario[], char nome_ficheiro[]);


t_questionario criar_genero(char genero_existentes);
int inserir_idade(char idade_existente, t_questionario [] );
void consultar_genero(char  generos_existentes,  t_questionario genero[]);
void gravar_genero_em_ficherio(t_questionario[], char generos_existentes, char nome[]);
int ler_idade_de_ficheiro(t_questionario[], char nome_ficheiro[]);


t_questionario criar local_de_residencia(char local_de_residencia_existentes);
int inserir_local_de_residencia(char local_de_residencia_)


int menu_principal(void);
int menu_genero(void);
int menu_tipo_de_participante(void);
int menu_contacto_com_pessoa_infetada(void);
int menu_sintomas(void);
int menu_doencas(void);

char local_residencia[TOTALQUESTIONARIOS];
char tipo_participante[TOTALQUESTIONARIOS];         //SE È (DOCENTE,ESTUDANTE,FUNCIONÁRIO OU INVESTIGADOR)
char contacto_covid[TOTALQUESTIONARIOS];


Conta_t criar_conta(int contas_existentes);
int inserir_conta(int contas_existentes, Conta_t contas[]);
void consultar_contas(int contas_existentes, Conta_t contas[]);
void gravar_contas_em_ficheiro(Conta_t contas[], int contas_existentes, char nome_ficheiro[]);
int ler_contas_de_ficheiro(Conta_t contas[], char nome_ficheiro[]);













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


int main()
{
    int opcao;
    do
    {
        opcao=menu_principal();
        switch(opcao);
    case 1:
        do
        {
          // meter funcao dentro de uma funcao
        }
        break;
    }
    while
    return 0;
}

void Escola
{

}
int menu_principal(void);
{

    // 1-menu principal 2-menu inserir e consultar
    printf("1- Idade do Participante:\n");
    printf("2- Genero do Participante:\n");
    printf("3- Local de Residencia:\n");
    printf("4- Tipo de Participante:\n");
    printf("5- Nos ultimos 15 dias esteve em contacto com pessoa infetada com COVID-19?\n");
    printf("6- Que sintomas sente\n");
    printf("7-Que doencas tem?\n");
}
int menu_genero(void);
{
    printf("(M)asculino\n");
    printf("(F)emenino\n");
}
int menu_tipo_de_participante(void);
{
    printf("1.Docente\n");
    printf("2.Estudante\n");
    printf("3.Funcionario\n");
    printf("4.Investigador\n");

}
int menu_contacto_com_pessoa_infetada(void);
{
    printf("(S)im\n");
    printf("(N)ao\n");
    printf("(D)esconhecido\n");
}
int menu_sintomas(void);
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
