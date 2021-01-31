#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define TOTALQUESTIONARIOS 1000
#define QUESTIONARIOSESCOLA 200
#define MAX_TEXTO 50
#define HUGE_TEXTO 100
#define TOTALESCOLAS 5

typedef struct
{
    int dia;
    int mes;
    int ano;
    int hora;
    int minutos;
} t_horario;

typedef struct   //ESTRUTURA LIMITE DE 1000 QUESTIONARIOS 200 POR ESCOLA
{
    int id_questionario;
    int id_escola;
    t_horario data_hora;
    int idade;
    char genero[MAX_TEXTO];
    char local_residencia[MAX_TEXTO];
    char tipo_participante[MAX_TEXTO];         //SE ï¿½ (DOCENTE,ESTUDANTE,FUNCIONï¿½RIO OU INVESTIGADOR)
    char contacto_com_pessoa[MAX_TEXTO];            //SE A PRESSOA TEVE EM CONTACTO COM ALGUEM COM COVID (SIM/NAO/DESCONHECIDO)
    char sintomas[MAX_TEXTO];       //QUE SINTOMAS A PESSOA A SER QUESTIONADA TEM (DIFICULDADE RESPIRATORIA,,DOR MUSCULAR,FADIGA,FALTA DE PALADAR,Nï¿½USEAS e TOSSE)
    char doencas[MAX_TEXTO];  //DOENï¿½AS DE RISCO (AUTOIMUNE,CANCRO,CARDIOVASCULAR,DIABETES,HIPERTENSï¿½O,OBESIDADE,OBESIDADE,RENAL,RESPIRATï¿½RIA)
    char nivel_contagio[MAX_TEXTO];
    float temperatura;
} t_questionario;

// struct data e hora

typedef struct escola
{
    int idescola;
    char nomeescola[MAX_TEXTO];   //ESCOLAS (ESECS,ESTG,ESAD,ESTM,ESS)
    char localidade[MAX_TEXTO];
} t_escola;

/**LER DADOS**/
void ler_string(char txt[], char str[], int max_len);
int ler_numero(char text[]);
float ler_float(char text[]);
/**FIM LER DADOS**/

/**FUNCOES INSERIR**/
int inserir_escola(t_escola escolas[],int contadorEscolas,int esecsContador,int estgContador,int esadContador,int estmContador,int essContadorcal);
int inserir_questionario(t_questionario questionarios[],int contadorQuestionarios,t_escola escolas[],int contadorEscolas);
int inserir_idade(void);
void inserir_genero(t_questionario questionarios[],int contadorQuestionarios);
void tipo_participante(t_questionario questionarios[],int contadorQuestionarios);
void inserir_covid(t_questionario questionarios[],int contadorQuestionarios);
void inserirdata_dia(t_questionario questionarios[],int contadorQuestionario);
void inserirdata_hora(t_questionario questionarios[],int contadorQuestionarios);
void menu_inserir_sintomas();
void inserir_sintomas(t_questionario questionarios[],int contadorQuestionarios);
void menu_inserir_doenca_risco();
void inserir_doenca_risco(t_questionario questionarios[],int contadorQuestionarios);
void inserir_doenca_risco_switch(t_questionario questionarios[],int contadorQuestionarios,int opcao);
void calcular_nivel_risco(t_questionario questionarios[],int contadorQuestionarios);
/**FIM DE INSERIR**/

/**FUNCOES LISTAR**/
void listar_escolas(t_escola escolas[],int contadorEscola);
void listar_questionarios(t_questionario questionarios[],int contadorQuestionario);
int faixaetaria18_23(t_questionario questionarios[],int contadorQuestionarios);
int faixaetaria24_30(t_questionario questionarios[],int contadorQuestionarios);
int faixaetaria31_40(t_questionario questionarios[],int contadorQuestionarios);
int faixaetaria41_50(t_questionario questionarios[],int contadorQuestionarios);
int faixaetaria51_65(t_questionario questionarios[],int contadorQuestionarios);
int faixaetariamaior66(t_questionario questionarios[],int contadorQuestionarios);
int consultargeneromasculino(t_questionario questionarios[],int contadorQuestionarios);
int consultargenerofemenino(t_questionario questionarios[],int contadorQuestionarios);
int nivelderiscobaixo(t_questionario questionarios[],int contadorQuestionarios);
int nivelderiscomedio(t_questionario questionarios[],int contadorQuestionarios);
int nivelderiscoalto(t_questionario questionarios[],int contadorQuestionarios);
/**FIM FUNCOES LISTAR**/

/**FUNCOES FICHEIROS**/
void Guardar_escolas(t_escola escolas[],int contadorEscolas);
int Ler_escolas(t_escola escolas[]);
void Guardar_questionarios(t_questionario questionarios[], int contadorQuestionarios);
int Ler_questionarios(t_questionario questionarios[]);
/**FIM FUNCOES FICHEIROS**/

/**FUNÇOES DE AJUDA**/
void ajudacontadores(t_escola escolas[],int *esecsContador,int *estgContador,int *esadContador,int *estmContador,int *essContador);
void limpar_consola();
/**FIM FUNCOES DE AJUDA**/

int main()
{
    printf("Trabalho Realizado por: Carlos Vinagre - 2180687\n");
    t_questionario questionarios[TOTALQUESTIONARIOS-1];
    t_escola escolas[TOTALESCOLAS-1];
    int i,opcao,totalInqueritosResp,inqueritosRealizados[TOTALESCOLAS-1],contadorEscolas=0,contadorQuestionarios=0,idade1823=0,idade2430=0,idade3140=0,idade4150=0,idade5165=0,idademais66=0,masculino=0,femenino=0;
    int esecsContador=0,estgContador,esadContador,estmContador,essContador;
    float baixo,medio,alto;



    contadorEscolas=Ler_escolas(escolas);
    printf("\n");
    contadorQuestionarios=Ler_questionarios(questionarios);

    do
    {
        idade1823=faixaetaria18_23(questionarios,contadorQuestionarios);
        idade2430=faixaetaria24_30(questionarios,contadorQuestionarios);
        idade3140=faixaetaria31_40(questionarios,contadorQuestionarios);
        idade4150=faixaetaria41_50(questionarios,contadorQuestionarios);
        idade5165=faixaetaria51_65(questionarios,contadorQuestionarios);
        idademais66=faixaetariamaior66(questionarios,contadorQuestionarios);
        masculino=consultargeneromasculino(questionarios,contadorQuestionarios);
        femenino=consultargenerofemenino(questionarios,contadorQuestionarios);
        baixo=nivelderiscobaixo(questionarios,contadorQuestionarios);
        medio=nivelderiscomedio(questionarios,contadorQuestionarios);
        alto=nivelderiscoalto(questionarios,contadorQuestionarios);

        printf("---------  Menu Principal  --------- \n\n");
        printf("Numero de escolas inseridas: %d\n\n",contadorEscolas);
        printf("1 - Registar Escola \n");
        printf("2 - Consultar Escolas\n");
        printf("3 - Registar Questionario\n");
        printf("4 - Consultar Questionarios\n");
        printf("5 - Estatisticas\n");
        printf("\t\tTotal de Questionarios respondidos:%d\n",contadorQuestionarios);
        //printf("%d\n\n\n",esecsContador);

        printf("\t\t =============ESTATISTICA IDADE=============\n");
        printf("\t\tQuestionarios Faixa etaria entre 18 - 23:%d\n",idade1823);
        printf("\t\tQuestionarios Faixa etaria entre 24 - 30:%d\n",idade2430);
        printf("\t\tQuestionarios Faixa etaria entre 31 - 40:%d\n",idade3140);
        printf("\t\tQuestionarios Faixa etaria entre 41 - 50:%d\n",idade4150);
        printf("\t\tQuestionarios Faixa etaria entre 51 - 65:%d\n",idade5165);
        printf("\t\tQuestionarios Faixa etaria +66:%d\n\n",idademais66);
        printf("\t\t =============ESTATISTICA GENERO=============\n");
        printf("\t\tExistem %d participantes do genero masculino\n",masculino);
        printf("\t\tExistem %d participantes do genero femenino\n\n",femenino);
        printf("\t\t =============ESTATISTICA NIVEL CONTAGIO=============\n");
        printf("\t\tExistem %0.2f participantes com nivel de risco baixo\n",baixo);
        printf("\t\tExistem %0.2f participantes com nivel de risco medio\n",medio);
        printf("\t\tExistem %0.2f participantes com nivel de risco alto\n",alto);

        //printf("ESECS %d\n",esecsContador);

        printf("6 - Sair\n");
        printf("Opcao escolhida --->");
        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
            contadorEscolas=inserir_escola(escolas,contadorEscolas,esecsContador,estgContador,esadContador,estmContador,essContador);
            break;
        case 2:
            listar_escolas(escolas,contadorEscolas);
            break;
        case 3:
            contadorQuestionarios=inserir_questionario(questionarios,contadorQuestionarios,escolas,contadorEscolas);

            break;
        case 4:
          listar_questionarios(questionarios,contadorQuestionarios);
            break;
        case 5:

        case 6:

            break;
        default:
            printf("\nOpcao errada escolha uma entre 1-6\n");
        }
        Guardar_escolas(escolas,contadorEscolas);
        Guardar_questionarios(questionarios,contadorQuestionarios);
    }
    while(opcao!=6);
    printf("\nO utilizador decidiu sair\n");
}

/**FUNCOES INSERIR**/
int inserir_escola(t_escola escolas[],int contadorEscolas,int esecsContador,int estgContador,int esadContador,int estmContador,int essContador)
{
    int i;
    char aux[MAX_TEXTO];
    escolas[contadorEscolas].idescola=contadorEscolas+1;
    printf("\nId da escola: %d\n",escolas[contadorEscolas].idescola);
    do
    {
        if(i==1)
        {
            printf("Escola ja existe\n\n");
        }
        ler_string("Introduza o nome da escola\n",aux,MAX_TEXTO);
        printf("Nome Inserido: %s\n",aux);
        i=consultar_escolas_nome(escolas,aux,contadorEscolas);
    }
    while(i!=-1);
    strcpy(escolas[contadorEscolas].nomeescola, aux);
    ler_string("Introduza a localidade da escola\n",escolas[contadorEscolas].localidade,MAX_TEXTO);
    //ajudacontadores(escolas,*esecsContador,*estgContador,*esadContador,*estmContador,*essContador);
    printf("\nLocalidade Inserido: %s",escolas[contadorEscolas].localidade);
    contadorEscolas++;
    return contadorEscolas;
}

int inserir_questionario(t_questionario questionarios[],int contadorQuestionarios,t_escola escolas[],int contadorEscolas)
{
    char aux[MAX_TEXTO];
    int i;
    ler_string("\nIntroduza o nome da escola:\n",aux,MAX_TEXTO);
    i=consultar_escolas_nome(escolas,aux,contadorEscolas);
    if(i==-1)
        printf("A escola nao existe\n");
    else
    {
        questionarios[contadorQuestionarios].id_questionario=contadorQuestionarios+1;
        questionarios[contadorQuestionarios].id_escola=i;
        inserirdata_dia(questionarios,contadorQuestionarios);
        inserirdata_hora(questionarios,contadorQuestionarios);
        questionarios[contadorQuestionarios].idade=inserir_idade();
        inserir_genero(questionarios,contadorQuestionarios);
        ler_string("Insira o local de residencia:\n",questionarios[contadorQuestionarios].local_residencia,MAX_TEXTO);
        tipo_participante(questionarios,contadorQuestionarios);
        questionarios[contadorQuestionarios].temperatura=ler_float("Insira a temperatura");
        inserir_covid(questionarios,contadorQuestionarios);
        inserir_sintomas(questionarios,contadorQuestionarios);
        inserir_doenca_risco(questionarios,contadorQuestionarios);
        calcular_nivel_risco(questionarios,contadorQuestionarios);
    }
    return ++contadorQuestionarios;
}
void ajudacontadores(t_escola escolas[],int *esecsContador,int *estgContador,int *esadContador,int *estmContador,int *essContador)
{
    int i;
    for(i=0;i<TOTALESCOLAS;i++){
    if (strcasecmp(escolas[i].nomeescola,"esecs")==0)
    *esecsContador++;
    if (strcasecmp(escolas[i].nomeescola,"estg")==0)
   *estgContador++;
    if (strcasecmp(escolas[i].nomeescola,"esad")==0)
    *esadContador++;
    if (strcasecmp(escolas[i].nomeescola,"estm")==0)
    *estmContador++;
    if (strcasecmp(escolas[i].nomeescola,"ess")==0)
    *essContador++;
    }
}

int inserir_idade()
{
    int idade=0;
    do
    {
        idade=ler_numero("Insira a sua idade\n");
    }
    while(idade<18 && idade>100);
    return idade;
}

void inserir_genero(t_questionario questionarios[],int contadorQuestionarios)
{
    char genero[MAX_TEXTO];
    int opcao;
    do
    {
        printf("1 - Masculino\n");
        printf("2 - Femenino\n");
        opcao=ler_numero("insira o numero conforme o genero:\n");
        switch(opcao)
        {
            case 1:strcpy(questionarios[contadorQuestionarios].genero,"Masculino");
            break;
            case 2:strcpy(questionarios[contadorQuestionarios].genero,"Femenino");
            break;
            default:"Numero invalido!\n";
        }
    }while(opcao<1 && opcao>2);
}

void tipo_participante(t_questionario questionarios[],int contadorQuestionarios)
{
    int opcao;
    do
    {
        printf("1 - docente\n2 - estudante\n3 - funcionario\n4 - investigador\n");
        opcao=ler_numero("Insira o numero conforme o tipo de participante\n");
        switch(opcao)
        {
        case 1:strcpy(questionarios[contadorQuestionarios].tipo_participante,"docente");
            break;
        case 2:strcpy(questionarios[contadorQuestionarios].tipo_participante,"estudante");
            break;
        case 3:strcpy(questionarios[contadorQuestionarios].tipo_participante,"funcionario");
            break;
        case 4:strcpy(questionarios[contadorQuestionarios].tipo_participante,"investigador");
            break;
        default:
        printf("Opcao Invalida! Tem que inserir um numero entre 1 e 4\n");
        }
    }
    while(opcao<1 && opcao>4);
}

void inserir_covid(t_questionario questionarios[],int contadorQuestionarios)
{
   int opcao;
    do
    {
        printf("1 - Sim\n2 - Nao\n3 - Desconhecido\n");
        opcao=ler_numero("Insira o numero conforme Se teve com 1 pessoa com covid\n");
        switch(opcao)
        {
        case 1:strcpy(questionarios[contadorQuestionarios].contacto_com_pessoa,"Sim");
            break;
        case 2:strcpy(questionarios[contadorQuestionarios].contacto_com_pessoa,"Nao");
            break;
        case 3:strcpy(questionarios[contadorQuestionarios].contacto_com_pessoa,"Desconhecido");
            break;
        default:printf("Opcao Invalida! Tem que inserir um numero entre 1 e 3");
        break;
        }
    }
    while(opcao<1 && opcao>3);
}


void inserirdata_dia(t_questionario questionarios[],int contadorQuestionario)
{
    do{
        printf("\nIntroduza o ano: \n O ano tem que ser entre 2000 e 2999\n ");
        scanf("%d",&questionarios[contadorQuestionario].data_hora.ano);

    }while(!(questionarios[contadorQuestionario].data_hora.ano>=2000 && questionarios[contadorQuestionario].data_hora.ano<3000));
    do{
        printf("Introduzir o Mes: \n O mes tem que ser entre 1 e 12\n ");
        scanf("%d",&questionarios[contadorQuestionario].data_hora.mes);
    }while(!(questionarios[contadorQuestionario].data_hora.mes>=1 && questionarios[contadorQuestionario].data_hora.mes<=12));
    do{
        printf("Introduzir o dia: \n O dia tem que ser entre 1 e 31\n");
        scanf("%d",&questionarios[contadorQuestionario].data_hora.dia);
    }while(!(questionarios[contadorQuestionario].data_hora.dia>=1 &&questionarios[contadorQuestionario].data_hora.dia<=31));
}

void inserirdata_hora(t_questionario questionarios[],int contadorQuestionarios)
{
    do
    {
        printf("\nIntroduza a hora: \n A hora tem que ser entre 0 e 23 ");
        scanf("%d",&questionarios[contadorQuestionarios].data_hora.hora);
    }
    while(!(questionarios[contadorQuestionarios].data_hora.hora>=0 && questionarios[contadorQuestionarios].data_hora.hora<=23));
    do
    {
        printf("Introduzir os Minutos: \n Os minutos tem que ser entre 0 e 59    ");
        scanf("%d",&questionarios[contadorQuestionarios].data_hora.minutos);
    }
    while(!(questionarios[contadorQuestionarios].data_hora.minutos>=0 && questionarios[contadorQuestionarios].data_hora.minutos<=59));

}
void menu_inserir_sintomas()
{
        printf("Introduza os sintomas:\n");
        printf("1 - Dificuldade em Respirar\n");
        printf("2 - Dor Muscular\n");
        printf("3 - Fadiga\n");
        printf("4 - Falta de paladar\n");
        printf("5 - Nauseas\n");
        printf("6 - Tosse\n");
        printf("0 - Terminar\n");
}

void inserir_sintomas(t_questionario questionarios[],int contadorQuestionarios)
{
    int opcao;
    do{
            menu_inserir_sintomas();
        scanf("%d",&opcao);
        switch(opcao)
        {
        case 1:strcat(questionarios[contadorQuestionarios].sintomas,"Dificuldade em Respirar, ");
            break;
        case 2:strcat(questionarios[contadorQuestionarios].sintomas,"Dor Muscular, ");
            break;
        case 3:strcat(questionarios[contadorQuestionarios].sintomas,"Fadiga, ");
            break;
        case 4:strcat(questionarios[contadorQuestionarios].sintomas,"Falta de Paladar, ");
            break;
        case 5:strcat(questionarios[contadorQuestionarios].sintomas,"Nauseas, ");
            break;
        case 6:strcat(questionarios[contadorQuestionarios].sintomas,"Tosse, ");
            break;
        default:printf("Opcao Invalida!");
        case 0:
            break;
        }
    }while(opcao!=0);
}

void menu_inserir_doenca_risco()
{
        printf("Introduza as doencas de risco:\n");
        printf("1 - Autoimune\n");
        printf("2 - Cancro\n");
        printf("3 - Cardiovascular\n");
        printf("4 - Diabetes\n");
        printf("5 - Hipertensao\n");
        printf("6 - Obesidade\n");
        printf("7 - Renal\n");
        printf("8 - Respiratoria\n");
        printf("0 - Terminar\n");
}

void inserir_doenca_risco(t_questionario questionarios[],int contadorQuestionarios)
{
        int opcao;
    do{
        menu_inserir_doenca_risco();
         scanf("%d",&opcao);
        inserir_doenca_risco_switch(questionarios,contadorQuestionarios,opcao);
    }while(opcao!=0);
}

void inserir_doenca_risco_switch(t_questionario questionarios[],int contadorQuestionarios,int opcao)
{
    switch(opcao)
        {
        case 1:strcat(questionarios[contadorQuestionarios].doencas,"Autoimune, ");
            break;
        case 2:strcat(questionarios[contadorQuestionarios].doencas,"Cancro, ");
            break;
        case 3:strcat(questionarios[contadorQuestionarios].doencas,"Cardiovascular, ");
            break;
        case 4:strcat(questionarios[contadorQuestionarios].doencas,"Diabetes, ");
            break;
        case 5:strcat(questionarios[contadorQuestionarios].doencas,"Hipertensao, ");
            break;
        case 6:strcat(questionarios[contadorQuestionarios].doencas,"Obesidade, ");
            break;
        case 7:strcat(questionarios[contadorQuestionarios].doencas,"Renal,");
            break;
        case 8:strcat(questionarios[contadorQuestionarios].doencas,"Respiratorio,");
            break;
        default:printf("Opcao Invalida!");
        case 0:
            break;
        }
}

void calcular_nivel_risco(t_questionario questionarios[],int contadorQuestionarios)
{
    if(strcmp(questionarios[contadorQuestionarios].contacto_com_pessoa,"Sim")==0)
        strcpy(questionarios[contadorQuestionarios].nivel_contagio,"Alto");
    if(strcmp(questionarios[contadorQuestionarios].contacto_com_pessoa,"Nao")==0)
        strcpy(questionarios[contadorQuestionarios].contacto_com_pessoa,"Baixo");
    if(strcmp(questionarios[contadorQuestionarios].contacto_com_pessoa,"Desconhecido")==0);
        strcpy(questionarios[contadorQuestionarios].contacto_com_pessoa,"Medio");
}
/**FIM FUNCOES INSEIR**/


/**FUNCOES CONSULTAR**/
int consultar_escolas_nome(t_escola escolas[],char nome[],int contadorEscolas)
{
    int i,j=-1;

    for(i=0; i<=contadorEscolas; i++)
    {
        if(strcasecmp(escolas[i].nomeescola,nome)==0)
        {
            j=i;
        }

    }
    return j;
}


void listar_escolas(t_escola escola[],int contadorEscolas)
{
    int i;
    printf("\nListar Escolas:\n");
    for(i=0; i<contadorEscolas; i++)
    {
        printf("\n\nID: %d\n",escola[i].idescola);
        printf("Nome: %s\n",escola[i].nomeescola);
        printf("Localidade: %s\n",escola[i].localidade);
    }
    printf("\n");
}

void listar_questionarios(t_questionario questionarios[],int contadorQuestionarios)
{
    int i;
    printf("\n Listar Questionarios:\n\n");
    //printf("%dcontadorquestionarios",contadorQuestionarios);
    for(i=0; i<=contadorQuestionarios-1; i++)
    {
       printf("ID:%d\n",questionarios[i].id_questionario);
       printf("ID ESCOLA:%d\n",questionarios[i].id_escola);
       printf("DATA:%d-%d-%d %d:%d\n",questionarios[i].data_hora.ano,questionarios[i].data_hora.mes,questionarios[i].data_hora.dia,questionarios[i].data_hora.hora,questionarios[i].data_hora.minutos);
       printf("NIVEL CONTAGIO:%s\n",questionarios[i].nivel_contagio);
       printf("IDADE:%d\n",questionarios[i].idade);
       printf("GENERO:%s\n",questionarios[i].genero);
       printf("RESIDENCIA:%s\n",questionarios[i].local_residencia);
       printf("TIPO PATICIPANTE:%s\n",questionarios[i].tipo_participante);
       printf("TEMPERATURA:%0.1f\n",questionarios[i].temperatura);
       printf("CONTACTO COM PESSOA:%s\n",questionarios[i].contacto_com_pessoa);
       printf("SINTOMAS:{%s}\n",questionarios[i].sintomas);
       printf("DOENCAS:{%s}\n\n\n",questionarios[i].doencas);
    }
}

int faixaetaria18_23(t_questionario questionarios[],int contadorQuestionarios){
    int i,contador=0;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(questionarios[i].idade>=18 && questionarios[i].idade<=23)
        {
            contador++;
        }
    }
    return contador;
}

int faixaetaria24_30(t_questionario questionarios[],int contadorQuestionarios){
    int i,contador=0;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(questionarios[i].idade>=24 && questionarios[i].idade<=30)
        {
            contador++;
        }
    }
    return contador;
}

int faixaetaria31_40(t_questionario questionarios[],int contadorQuestionarios){
    int i,contador=0;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(questionarios[i].idade>=31 && questionarios[i].idade<=40)
        {
            contador++;
        }
    }
    return contador;
}

int faixaetaria41_50(t_questionario questionarios[],int contadorQuestionarios){
    int i,contador=0;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(questionarios[i].idade>=41 && questionarios[i].idade<=50)
        {
            contador++;
        }
    }
    return contador;
}

int faixaetaria51_65(t_questionario questionarios[],int contadorQuestionarios){
    int i,contador=0;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(questionarios[i].idade>=51 && questionarios[i].idade<=65)
        {
            contador++;
        }
    }
    return contador;
}

int faixaetariamaior66(t_questionario questionarios[],int contadorQuestionarios){
    int i,contador=0;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(questionarios[i].idade>=66)
        {
            contador++;
        }
    }
    return contador;
}

int consultargeneromasculino(t_questionario questionarios[],int contadorQuestionarios){
    int i,contador=0;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(strcasecmp(questionarios[i].genero,"masculino")==0)
        {
            contador++;
        }
    }
    return contador;
}

int consultargenerofemenino(t_questionario questionarios[],int contadorQuestionarios){
    int i,contador=0;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(strcasecmp(questionarios[i].genero,"femenino")==0)
        {
            contador++;
        }
    }
    return contador;
}

/**NAO FUNCIONAM MAS O CODIGO È MAIS OU MENOS ISTO ACHO EU**/
int contaesecs(t_questionario questionarios[],int contadorQuestionarios)
{
    int i=0,contador=0;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(strcasecmp(questionarios[i].id_escola,"0"))
        {
            contador++;
        }
    }
    return contador;
}

int contaestg(t_questionario questionarios[],int contadorQuestionarios)
{
    int i=0,contador=0;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(strcasecmp(questionarios[i].id_escola,"1"))
        {
            contador++;
        }
    }
    return contador;
}

int contaesad(t_questionario questionarios[],int contadorQuestionarios)
{
    int i=0,contador=0;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(strcasecmp(questionarios[i].id_escola,"2"))
        {
            contador++;
        }
    }
    return contador;
}

int contaestm(t_questionario questionarios[],int contadorQuestionarios)
{
    int i=0,contador=0;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(strcasecmp(questionarios[i].id_escola,"3"))
        {
            contador++;
        }
    }
    return contador;
}

int contaess(t_questionario questionarios[],int contadorQuestionarios)
{
    int i=0,contador=0;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(strcasecmp(questionarios[i].id_escola,"4"))
        {
            contador++;
        }
    }
    return contador;
}
/**FIM DOS CONTADORES DE ESCOLA**/
int nivelderiscobaixo(t_questionario questionarios[],int contadorQuestionarios){
    int i,contador=0;
    float resultado;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(strcasecmp(questionarios[i].nivel_contagio,"Baixo")==0)
        {
            contador++;
        }
           resultado=(contador*contadorQuestionarios)/TOTALQUESTIONARIOS;

    }
    return resultado;
}

int nivelderiscomedio(t_questionario questionarios[],int contadorQuestionarios){
    int i,contador=0;
    float resultado;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(strcasecmp(questionarios[i].nivel_contagio,"Desconhecido")==0)
        {
            contador++;
        }
           resultado=(contador*contadorQuestionarios)/TOTALQUESTIONARIOS;

    }
    return resultado;
}

int nivelderiscoalto(t_questionario questionarios[],int contadorQuestionarios){
    int i,contador=0;
    float resultado;
    for(i=0;i<contadorQuestionarios;i++)
    {
        if(strcasecmp(questionarios[i].nivel_contagio,"Alto")==0)
        {
            contador++;
        }
           resultado=(contador*contadorQuestionarios)/TOTALQUESTIONARIOS;

    }
    return resultado;
}
/**FIM FUNCOES CONSULTAR**/

/**FICHEIROS**/
void Guardar_escolas(t_escola escolas[],int contadorEscolas)
{
    int i;
    FILE *file;
    file=fopen("escolas.dat","wb");
    i=fwrite(&escolas,sizeof(t_escola),TOTALESCOLAS,file);
    //printf("Numero de elementos escritos: %d",i);
    i=fwrite(&contadorEscolas,sizeof(int),1,file);
    //printf("Numero de contadorEscolas: %d",contadorEscolas);
    fclose(file);

}

int Ler_escolas(t_escola escolas[])
{
    int i,contadorEscolas=0;
    FILE *file;
    file=fopen("escolas.dat","rb");
    if(file==NULL)
    {
        printf("Ficheiro nao existe!!\n");
    }
    i=fread(&escolas,sizeof(t_escola),TOTALESCOLAS,file);
    //printf("Numero de elementos Lidos: %d",i);
    i=fread(&contadorEscolas,sizeof(int),1,file);
    //printf("Numero de ContadorEscolas Lidos: %d",i);
    fclose(file);
    return contadorEscolas;
}

void Guardar_questionarios(t_questionario questionarios[], int contadorQuestionarios)
{
int i;
    FILE *file;
    file=fopen("questionarios.dat","wb");
    i=fwrite(&questionarios,sizeof(t_questionario),TOTALQUESTIONARIOS,file);
   // printf("Numero de elementos escritos: %d\n",i);
    i=fwrite(&contadorQuestionarios,sizeof(int),1,file);
   // printf("Numero de Questionarios: %d\n",contadorQuestionarios);
    fclose(file);
}

int Ler_questionarios(t_questionario questionarios[])
{
    int i,contadorQuestionarios=0;
    FILE *file;
    file=fopen("questionarios.dat","rb");
    if(file==NULL)
    {
        printf("Ficheiro nao existe!!\n");
    }
    i=fread(&questionarios,sizeof(t_questionario),TOTALQUESTIONARIOS,file);
    //printf("Numero de elementos Lidos: %d\n",i);
    i=fread(&contadorQuestionarios,sizeof(int),1,file);
    //printf("Numero de ContadorQuestionarios Lidos: %d\n",i);
    fclose(file);
    return contadorQuestionarios;
}

/**FIM FICHEIROS**/


/**FUNCOES DE AJUDA**/
void ler_string(char txt[], char str[], int max_len)
{
    printf("%s",txt);
    fflush(stdin);
    fgets(str, max_len, stdin);
    strtok(str, "\n"); /**TIRAR \N dos ficheiros**/
}

int ler_numero(char text[])
{
    int numero;

    printf("%s: ", text);
    scanf("%d", &numero);
    return numero;
}

float ler_float(char text[])
{
    float numero;

    printf("%s: ", text);
    scanf("%f", &numero);
    return numero;
}

void limpar_consola()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    fflush(stdin);
}
