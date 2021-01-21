#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define TOTALQUESTIONARIOS 1000
#define QUESTIONARIOSESCOLA 200
#define MAX_TEXTO 50
#define TOTALESCOLAS 5

typedef struct questionario  //ESTRUTURA LIMITE DE 1000 QUESTIONARIOS 200 POR ESCOLA
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
    char contacto_covidcontacto_covid[TOTALQUESTIONARIOS];            //SE A PRESSOA TEVE EM CONTACTO COM ALGUEM COM COVID (SIM/NAO/DESCONHECIDO)
    char sintomas[TOTALQUESTIONARIOS][MAX_TEXTO];       //QUE SINTOMAS A PESSOA A SER QUESTIONADA TEM (DIFICULDADE RESPIRATORIA,,DOR MUSCULAR,FADIGA,FALTA DE PALADAR,NÁUSEAS e TOSSE)
    char doenca_risco[TOTALQUESTIONARIOS][MAX_TEXTO];  //DOENÇAS DE RISCO (AUTOIMUNE,CANCRO,CARDIOVASCULAR,DIABETES,HIPERTENSÃO,OBESIDADE,OBESIDADE,RENAL,RESPIRATÓRIA)
    int temperatura[TOTALQUESTIONARIOS];
} t_questionario;





typedef struct escola
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
char opcao_genero(void);

int menu_escolas(void); //MENU ESCOLAS OPCAO 1 NO MENU PRINCIPAL
void menu_questionarios(void); //MENU QUESTIONARIOS OPCAO 2 NO MENU PRINCIPAL




void menu_principal_opcao(void);

void menu_inquerito_idade(void); //MENU
int menu_doencas(void);


int menu_gravar_ficheiros(void);
//FIM MENUS


int inserir_escola(t_escola escola[],int contadoridescola);
void Consultar_escola(t_escola escola[]);






//LER DADOS
void ler_string();
int ler_numero();
//FIM LER DADOS

int opcao_tipo_de_participante(void);
int menu_inserir_consultar_contacto_com_pessoa_infetada(void);

char local_residencia[TOTALQUESTIONARIOS];
char tipo_participante[TOTALQUESTIONARIOS];         //SE È (DOCENTE,ESTUDANTE,FUNCIONÁRIO OU INVESTIGADOR)
char contacto_covid[TOTALQUESTIONARIOS];




void menu_inquerito_idade(void);


int inserir_idade();
void consultar_idade(t_questionario idade[]);
int menu_opcao_idade();
int menu_idade();
int menu_inserir_consultar_idade();
void gravar_idade_em_ficheiros(t_questionario idade[], int  gravar_ficheiro_idade);
int ler_idade_em_ficheiros(t_questionario idade[]);




char inserir_genero(t_questionario genero );
char menu_genero(void);
void gravar_genero_em_ficheiros(t_questionario genero[], int gravar_ficheiro_genero);
int ler_genero_em_ficheiros(t_questionario genero[]);
char menu_opcao_genero(void);
void consultr_genero(void);
int menu_inserir_consultar_genero(void);





int opcao_sintomas(void);
int menu_inserir_consultar_sintomas(void);
int menu_inserir_sintomas();
void consultar_sintomas(void);
void listar_sintomas();
void gravar_sintomas_em_ficheiro(t_questionario sintomas[], int gravar_ficheiro_sintomas);
int ler_sintomas_em_ficheiro(t_questionario sintomas[]);


int menu_opcao_doencas(void);
int inserir_doencas();
void consultar_doencas(void);







void menu_ficheiros(void);




int menu_tipo_de_participante(void);
void gravar_tipo_participante_em_ficheiros(t_questionario tipo_participante[], int gravar_ficheiro_tipo_de_participante);
int ler_tipo_participante_em_ficheiros(t_questionario tipo_participante[]);
int menu_inserir_consultar_tipo_de_participante(void);



char menu_opcao_contacto_com_pessoa_infetada(void);
char menu_contacto_com_pessoa_infetada();
void gravar_contacto_com_pessoa_infetada_em_ficheiros(t_questionario pessoa[], int gravar_ficheiro_tipo_de_participante);
int ler_tipo_participante_em_ficheiros(t_questionario tipo_participante[]);



int menu_inserir_consultar_local_residencia(void);
int menu_doencas(void);





int questionario1(void);





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
    int idade;
    menu_principal(contador_ESECS,contador_ESTG,contador_ESAD,contador_ESTM,contador_ESS);
    menu_principal_opcao();
    return 0;
}
void menu_principal(int contador_ESECS,int contador_ESTG,int contador_ESAD,int contador_ESTM,int contador_ESS)
{
    int opcao;
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
    printf("Introduza  uma opcao ->");
    fflush(stdin);
    scanf("%d", &opcao);
}
void ler_string(char txt[], char str[], int max_len)
{
    printf("%s",txt);
    fflush(stdin);
    fgets(str, max_len, stdin);
    limpar_consola();
}

int ler_numero(char text[])
{
    int numero;

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
    int contadoridescola,escola, opcao,  op_escola;
    do
    {
        switch(opcao)
        {
        case 1:
            menu_escolas_opcao();
        case 2:
            questionario();
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            Sair();
            break;
        }
    }
    while(opcao!=1 || opcao!=2 || opcao!=3 || opcao!=4 || opcao!=5 || opcao!=6);
    return;
}
int questionario(void)
{
    int opcao;
    do
    {
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            menu_idade();
            break;
        case 2:
            menu_genero();
            break;
        case 3:

            break;
        case 4:
            menu_tipo_de_participante();
            break;
        case 5:
            menu_sintomas();
            break;
        case 6:
            menu_doencas();
        }
    }
    while(opcao != 0);
    return opcao;
}
void menu_inquerito_idade(void)
{
    printf("********Faixa Etaria********\n");
    printf("Idade entre 18 - 23\n");
    printf("Idade entre 24 - 30\n");
    printf("Idade entre 31 - 40\n");
    printf("Idade entre 41 - 50\n");
    printf("Idade entre 51 - 65\n");
    printf("Idade +66\n");
}


int menu_escolas_opcao(t_escola escola[], int contadoridescola[] )
{
    int opcao, intro_aux_escola;
    menu_escolas();
    do
    {
        printf("Introduza uma opcao->\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao)
        {
        case 1:
            intro_aux_escola=inserir_escola(escola, intro_aux_escola);
            contadoridescola++;
            break;
        case 2:
            Consultar_escola(escola);
            break;
        default:
            printf("Opcao Invalida!\n");
        }
    }
    while(opcao<1 || opcao>2);
    return opcao;

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


int Introduzir_Questionario(t_questionario questionario)
{
    //TODO: FAZER FUNÇÔES PARA ESTAS CENAS
    printf("ID:\n");
    printf("ID ESCOLA:\n");
    printf("DATA:");
    printf("HORA:\n");
    printf("NIVEL CONTAGIO\n");
    printf("IDADE:\n");
    printf("Genero:\n");
    printf("Local de residencia:\n");
    printf("Tipo de participante\n");
    printf("Temperatura\n");
    printf("Esteve em contacto com alguem com covid-19?\n");
    printf("Sintomas\n");
    printf("Doenças\n");

}
int inserir_escola(t_escola escola[],int contadoridescola)
{
    int i=0;
    //TODO: VALIDAÇÕES e fazer debug
    //escola[i].idescola=contadoridescola;
    ler_string("Introduza as iniciais da escola (ESECS,ESTG,ESAD,ESTM,ESS)\n",escola[contadoridescola].nomeescola,MAX_TEXTO);

    ler_string("Introduza a localidade da escola\n",escola[contadoridescola].localidade,MAX_TEXTO);

    contadoridescola++;
    printf("%d",&i );
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
    for(i=1; i<6; i++)
    {
        printf("ID:%d\n",escola[i].idescola);
        printf("Nome da escola:%c\n",escola[i].nomeescola);
        printf("Localidade da escola:%c\n",escola[i].localidade);
    }

}

int menu_inserir_consultar_idade()
{
    int opcao_idade;
    do
    {
        printf("1.Inserir Idade\n");
        printf("2.Consultar Idade\n");
        printf("Introduza uma opcao\n");
        fflush(stdin);
        scanf("%d", &opcao_idade);
    }
    while (opcao_idade > 0 && opcao_idade <= 2);
    {
        printf("Opcao Invalida\n");
    }
return opcao_idade;
}
int menu_idade()
{
    int opcao ;
    do

    {
        opcao = menu_inserir_consultar_idade();

        switch(opcao)
        {
        case 1:
            printf("1eee");
            inserir_idade();
            //inserir++;
            break;
        case 2:
            //consultar_idade();
            break;
        }
    }
    while (opcao < 0 ||opcao >= 2 );
    {
        printf("Opcao sssinvalida");
    }
return opcao;
}
void gravar_idade_em_ficheiros(t_questionario idade[], int  gravar_ficheiro_idade)
{
    FILE * ficheiro_idade_gravar;
    ficheiro_idade_gravar = fopen ("idade.dat", "wb");

    if(ficheiro_idade_gravar = NULL)
    {
        printf("Impossivel criar ficheiro");
    }
    else
    {
        fwrite(&gravar_ficheiro_idade, sizeof(int),1, ficheiro_idade_gravar);
        fwrite(idade,sizeof(t_questionario),200, ficheiro_idade_gravar);
        fclose(ficheiro_idade_gravar);
    }
}
int ler_idade_em_ficheiros(t_questionario idade[])
{
    int ler_idade;
    FILE * ficheiro_idade_ler;
    ficheiro_idade_ler = fopen("idade.dat", "rb");
    if(ficheiro_idade_ler == NULL)
    {
        printf("Impossível ler ficheiros");
    }
    else
    {
        fwrite(&ler_idade, sizeof(int),1, ficheiro_idade_ler);
        fread(idade, sizeof(t_questionario), ler_idade, ficheiro_idade_ler);
        fclose(ficheiro_idade_ler);
    }
    return ler_idade;
}
int inserir_idade()
{
    int idade;
    do
    {
        printf("Introduza a sua idade\n");
        fflush(stdin);
        scanf("%d", &idade);
    }
    while(idade <= 18);


    printf("A sua idade e igual ou superior a 18\n");
return idade;
}
void consultar_idade();

char menu_genero(void)
{
    char opcao_genero;
    do
    {
        printf("(M)asculino\n");
        printf("(F)emenino\n");
        printf("Introduza uma opcao\n");
        fflush(stdin);
        scanf("%c", &opcao_genero);
    }
    while(opcao_genero != 0);
    {
        printf("Opcao invalida\n");
    }
    return opcao_genero;
}
char menu_opcao_genero(void)
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
    return sexo;
}

int menu_inserir_consultar_genero(void)
{
    int opcao_genero;
    do
    {
        printf("1.Inserir genero\n");
        printf("2.Consultar genero\n");
        printf("\nOpcao-> ");
        fflush(stdin);
    }
    while(opcao_genero );
}

void gravar_genero_em_ficheiros(t_questionario genero[], int gravar_ficheiro_genero)
{
    FILE * ficheiro_genero_gravar;
    ficheiro_genero_gravar = fopen("genero.dat", "wb");

    if(ficheiro_genero_gravar == NULL)
    {
        printf("Impossivel criar ficheiro\n");
    }
    else
    {
        fwrite(&gravar_ficheiro_genero, sizeof(int ),1, ficheiro_genero_gravar);
        fwrite(genero, sizeof(int),200, ficheiro_genero_gravar);
        fclose(ficheiro_genero_gravar);
    }
}
int ler_genero_em_ficheiros(t_questionario genero[])
{
    int ler_genero;
    FILE * ficheiro_genero_ler;

    if(ficheiro_genero_ler == NULL)
    {
        printf("Impossivel ler ficheiro\n");

    }
    else
    {
        fwrite(&ler_genero, sizeof(int),1, ficheiro_genero_ler);
        fread(genero,sizeof(t_questionario), ler_genero,ficheiro_genero_ler);
        fclose(ficheiro_genero_ler);
    }
    return ler_genero;
}

int menu_tipo_de_participante(void)
{
    int opcao_tipo_de_participante;
    do
    {
        printf("1.Docente\n");
        printf("2.Estudante\n");
        printf("3.Funcionario\n");
        printf("4.Investigador\n");
        printf("Opcao->\n");
        fflush(stdin);
        scanf("%d", &opcao_tipo_de_participante);
    }
    while(opcao_tipo_de_participante < 0 || opcao_tipo_de_participante >4);
    {
        printf("Opcao invalida\n");
    }
    return opcao_tipo_de_participante;
}

int menu_opcao_tipo_de_participante(void)
{
    int tipo_de_participante;
    do
    {
        switch(tipo_de_participante)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            printf("Opcao invalida");
        }
    }
    while(tipo_de_participante!=1 || tipo_de_participante!=2 || tipo_de_participante!=3 || tipo_de_participante!=4);
    return tipo_de_participante;
}

int menu_inserir_consultar_tipo_de_participante(void)
{
    int opcao_tipo_participante;
    do
    {
        printf("1.Inserir tipo de participante\n");
        printf("2.Consultar tipo de participante\n");
        printf("\nOpcao-> ");
        fflush(stdin);
        scanf("%d", &opcao_tipo_participante);
    }
    while (opcao_tipo_participante < 0 || opcao_tipo_participante > 2 );
    {
        printf("Opcao invalida\n");
    }
}

void gravar_tipo_participante_em_ficheiros(t_questionario tipo_participante[], int gravar_ficheiro_tipo_de_participante)
{
    FILE * ficheiro_tipo_participante_gravar;
    ficheiro_tipo_participante_gravar = fopen("tipo participante.dat", "wb");
    if(ficheiro_tipo_participante_gravar == NULL)
    {
        printf("Impossivel criar ficheiro\n");
    }
    else
    {
        fwrite(&gravar_ficheiro_tipo_de_participante, sizeof(int),1, ficheiro_tipo_participante_gravar);
        fwrite(tipo_participante, sizeof(t_questionario),200,ficheiro_tipo_participante_gravar);
        fclose(ficheiro_tipo_participante_gravar);
    }
}

int ler_tipo_participante_em_ficheiros(t_questionario tipo_participante[])
{
    int ler_tipo_participante;
    FILE * ficheiro_tipo_participante_ler;
    ficheiro_tipo_participante_ler = fopen("tipo participante", "rb");
    if(ficheiro_tipo_participante_ler == NULL)
    {
        printf("Impossivel ler ficheiro\n");
    }
    else
    {
        fwrite(&ler_tipo_participante, sizeof(int),1, ficheiro_tipo_participante_ler);
        fread(tipo_participante,sizeof(t_questionario), ler_tipo_participante,ficheiro_tipo_participante_ler);
        fclose(ficheiro_tipo_participante_ler);
    }
    return ler_tipo_participante;
}

char menu_contacto_com_pessoa_infetada(void)
{
    printf("(S)im\n");
    printf("(N)ao\n");
    printf("(D)esconhecido\n");
    printf("Introduza uma opcao\n");
    fflush(stdin);
}

char  menu_opcao_contacto_com_pessoa_infetada(void) //AQUI È INT
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
    {


        printf("Opcao inválida\n");
    }
    return opcao;
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
    printf("\nOpcao-> ");
    fflush(stdin);
}

int  menu_inserir_consultar_sintomas(void)
{
    int opcao_sintomas;
    do
    {
        printf("1.Inserir sintomas\n");
        printf("2.Consultar sintomas\n");
        printf("\nOpcao-> ");
        fflush(stdin);
        scanf("%d", &opcao_sintomas);
    }
    while(opcao_sintomas < 0 || opcao_sintomas > 2);
    {
        printf("Opcao invalida\n");
    }
}
int menu_doencas(void)
{
    int opcao_doencas;
    do
    {
        printf("1.Autoimune\n");
        printf("2.Cancro\n");
        printf("3.Cardiovascular\n");
        printf("4.Diabetes\n");
        printf("5.Hipertensão\n");
        printf("6.Obesidade\n");
        printf("7.Renal\n");
        printf("8.Respiratoria\n");
        printf("0.Sair\n");
        printf("\nOpcao-> ");
        fflush(stdin);
        scanf("%d", &opcao_doencas);
    }
    while(opcao_doencas < 0 || opcao_doencas >8);
    return opcao_doencas;
}

int menu_inserir_consultar_doencas(void)
{
    printf("1.Inserir doencas\n");
    printf("2.Consultar doencas\n");
    printf("\nOpcao-> ");
    fflush(stdin);
}
void gravar_sintomas_em_ficheiro(t_questionario sintomas[], int gravar_sintomas_em_ficheiro)
{
    FILE * ficheiro_sintomas_gravar;
    ficheiro_sintomas_gravar = fopen("sintomas.dat", "wb");
    if(ficheiro_sintomas_gravar == NULL)
    {
        printf("Impossivel criar ficheiro");
    }
    else
    {
        fwrite(&gravar_sintomas_em_ficheiro, sizeof(int),1, ficheiro_sintomas_gravar);
        fwrite(sintomas, sizeof(t_questionario),200,ficheiro_sintomas_gravar);
        fclose(ficheiro_sintomas_gravar);
    }
}
int ler_sintomas_em_ficheiro(t_questionario sintomas[])
{

    int ler_sintomas;
    FILE * ficheiro_sintomas_ler;
    ficheiro_sintomas_ler = fopen("sintomas.dat", "rb");
    if(ficheiro_sintomas_ler == NULL)
    {
        printf("Impossivel ler ficheiro");
    }
    else
    {
        fwrite(&ler_sintomas,sizeof(int),1,ficheiro_sintomas_ler);
        fread(sintomas,sizeof(t_questionario),200,ficheiro_sintomas_ler);
        fclose(ficheiro_sintomas_ler);
    }
}
int menu_inserir_consultar_local_residencia(void)
{
    int opcao_loca_de_residencia;
    do
    {
        printf("1.Inserir Local de Residencia\n");
        printf("2.Consultar Local de Residencia\n");
        printf("\nOpcao-> ");
        fflush(stdin);
    }
    while(opcao_loca_de_residencia != 0);
    {
        printf("Opcao invalida\n");
    }
    return opcao_loca_de_residencia;
}

int  menu_inserir_consultar_escolas()
{
    int opcao;
    printf("1 Inserir escola\n");
    printf("2 Consultar escola\n");
    return opcao;
}

void menu_inserir_consultar_ficheiros()
{
    printf("1.Gravar Ficheiros\n");
    printf("2.Ler Ficheiros\n");
    /* printf("Introduza uma opcao\n");
     fflush(stdin);*/
}

void menu_questionario(void)
{
    printf("1.Idade do Participante\n");
    printf("2.Genero\n");
    printf("3.Local de Residencia\n");
    printf("4.Tipo de Participante\n");
    printf("5.Nos últimos 15 dias esteve em contacto com pessoa infetada com COVID-19\n");
    printf("6.Que sintomas sente \n");
    printf("7.Que doenças tem\n");
    printf("0 para terminar\n");
    /* printf("Introduza um numero\n");
     fflush(stdin);*/

}
int menu_gravar_ficheiros()
{
    int opcao;
    do
    {
        switch(opcao)
        {
        case 2:
            break;
        }
    }
    while(opcao != 0);
}



int menu_escolas(void)
{

}
