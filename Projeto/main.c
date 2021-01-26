#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define TOTALQUESTIONARIOS 1000
#define QUESTIONARIOSESCOLA 200
#define MAX_TEXTO 50
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
    //guardar nivel de contagio
    int id_questionario;
    int id_escola;
    t_horario data_hora;
    int idade;
    char genero;
    char local_residencia;
    char tipo_participante;         //SE ï¿½ (DOCENTE,ESTUDANTE,FUNCIONï¿½RIO OU INVESTIGADOR)
    char contacto_com_pessoa;            //SE A PRESSOA TEVE EM CONTACTO COM ALGUEM COM COVID (SIM/NAO/DESCONHECIDO)
    char sintomas[MAX_TEXTO];       //QUE SINTOMAS A PESSOA A SER QUESTIONADA TEM (DIFICULDADE RESPIRATORIA,,DOR MUSCULAR,FADIGA,FALTA DE PALADAR,Nï¿½USEAS e TOSSE)
    char doencas[MAX_TEXTO];  //DOENï¿½AS DE RISCO (AUTOIMUNE,CANCRO,CARDIOVASCULAR,DIABETES,HIPERTENSï¿½O,OBESIDADE,OBESIDADE,RENAL,RESPIRATï¿½RIA)
    int temperatura;
} t_questionario;

// struct data e hora



typedef struct escola
{
    int idescola;
    char nomeescola;   //ESCOLAS (ESECS,ESTG,ESAD,ESTM,ESS)
    char localidade;
} t_escola;


int main()
{
    int contador_ESECS=0;
    int contador_ESTG=0;
    int contador_ESAD=0;
    int contador_ESTM=0;
    int contador_ESS=0;
    int contador_questionario=0;
    t_questionario questionarios[TOTALQUESTIONARIOS];
    t_escola escolas[TOTALESCOLAS];

/**LIMPAR CONSOLA E BUFFER**/
void limpar_consola(void);

/**FUNCAO SAIR DO PROGRAMA**/
void Sair(void);

/**LER STRING**/
void ler_string();

/**LER INTEIRO**/
int ler_numero();

/**COMECO DOS MENUS**/
int menu_principal(int contador_ESECS,int contador_ESTG,int contador_ESAD,int contador_ESTM,int contador_ESS);
void menu_inquerito_idade(void);
void menu_escolas(void);
int menu_escolas_opcao(t_escola escolas[], int contadoridescola);
int menu_inserir_consultar_idade(void);
int menu_idade(t_questionario idade[]);
char menu_genero(void);
char menu_opcao_genero(void);
int menu_inserir_consultar_genero(void);
int menu_tipo_de_participante(void);
int menu_opcao_tipo_de_participante(void);
int menu_inserir_consultar_tipo_de_participante(void);
char menu_contacto_com_pessoa_infetada(void);
char  menu_opcao_contacto_com_pessoa_infetada(void);
int menu_sintomas(void);
int  menu_inserir_consultar_sintomas(void);
int menu_doencas(void);
int menu_inserir_consultar_doencas(void);
int menu_inserir_consultar_local_residencia(void);
int  menu_inserir_consultar_escolas(void);
void menu_questionario(void);
/**FIM MENUS**/





/**INICO INSERIR**/
int inserir_escola(t_escola escola[],int contadoridescola);
int inserir_idade(t_questionario questionarios[]);
int Introduzir_Questionario(t_questionario questionario);

/**FIM INSERIR**/


/**CONSULTAR/LISTAR**/
void Consultar_escola(t_escola escola[]);
void Listar_escolas(t_escola escola[]);

/**FIM CONSULTAR**/
int questionario(t_questionario questionarios[],int contador_questionario);


//CONNTADOR ID ESCOLA
int main()
{
    int contador_ESECS=0;
    int contador_ESTG=0;
    int contador_ESAD=0;
    int contador_ESTM=0;
    int contador_ESS=0;
    int contador_questionario=0;
    t_questionario questionarios[TOTALQUESTIONARIOS];
    t_escola escolas[TOTALESCOLAS];
    int idade;

        int contadoridescola=0,escola, opcao,  op_escola;
    do
        {
        switch(opcao)
        {
        case 1:
            menu_escolas_opcao(escolas,contadoridescola);
        break;
        case 2:
            questionario(questionarios,contador_questionario);
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
   }while(opcao!=1 || opcao!=2 || opcao!=3 || opcao!=4 || opcao!=5 || opcao!=6);

    return 0;
}


/**COMEïCO DOS MENUS**/
int menu_principal(int contador_ESECS,int contador_ESTG,int contador_ESAD,int contador_ESTM,int contador_ESS)
{
    int opcao;
    do{
    // 1-menu principal 2-menu inserir e consultar
    printf("1 - Registar e Consultar os dados das Escolas\n");
    printf("2 - Registar e Consultar os dados dos Questionarios\n\n");
    printf("Estatisticas:\n");
    printf("Total de inqueritos Respondido pos escolas:\n\n");
    printf("\tESECS:%d/200 \n",contador_ESECS);
    printf("\tESTG:%d/200 \n",contador_ESTG);
    printf("\tESAD:%d/200 \n",contador_ESAD);
    printf("\tESTM:%d/200 \n",contador_ESTM);
    printf("\tESS:%d/200 \n\n",contador_ESS);
    printf("3 - Total de inqueritos por genero e idade\n"); //FAIXA ETARIA (18-23; 24-30; 31-40; 41-50; 51-65; +66)
    printf("4 - Percentagem de inqueritos por nivel de risco de contagio\n");
    printf("5 - Guardar ou Ler dados de ficheiro binario\n");
    printf("6 - Sair\n");
    printf("Introduza  uma opcao ->");
    scanf("%d",&opcao);
    }while(opcao!=1 || opcao!=2 || opcao!=3 || opcao!=4 || opcao!=5 || opcao!=6);
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


void menu_escolas(void)
{
    printf("1 - Introduzir 1 nova escola\n");
    printf("2 - Consultar escolas por id\n");
    printf("3 - Listar escolas\n");
    printf("Introduza 1 opcao ->");

}

int menu_escolas_opcao(t_escola escolas[], int contadoridescola )
{
    int opcao, intro_aux_escola;
    menu_escolas();
    do
    {
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao)
        {
        case 1:
            contadoridescola=inserir_escola(escolas,contadoridescola);

            break;
        case 2:
            Consultar_escola(escolas);
            break;
        case 3:
            Listar_escolas(escolas);
        default:
            printf("Opcao Invalida!\n");
        }
    }
    while(opcao<1 || opcao>3);
    return opcao;
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

        if(opcao_idade<=0 || opcao_idade>2)
        {
            printf("Opcao Invalida\n");
        }
    }
    while (opcao_idade <= 0 || opcao_idade > 2);

    return opcao_idade;
}


int menu_idade(t_questionario idade[])
{
    int opcao_idade ;
    do
    {
        opcao_idade = menu_inserir_consultar_idade();

        switch(opcao_idade)
        {
        case 1:
            inserir_idade(idade);
            //inserir++;
            break;
        case 2:
            //consultar_idade();
            break;
        }
    }
    while (opcao_idade <= 0 ||opcao_idade >2 );
    return opcao_idade;
}


char menu_genero(void)
{
    char opcao_genero;
    do

    {
        opcao_genero = menu_inserir_consultar_genero();
        printf("(M)asculino\n");
        printf("(F)emenino\n");
        printf("Introduza uma opcao\n");
        fflush(stdin);
        scanf("%c", &opcao_genero);
        menu_opcao_genero();
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
        scanf("%d", &opcao_genero);
        if(opcao_genero<=0 || opcao_genero>2)
        {
            printf("Opcao invalida\n");
        }
    }
    while(opcao_genero <= 0 || opcao_genero > 2 );
    return opcao_genero;
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
        if(opcao_tipo_participante<=0 || opcao_tipo_participante>2)
        {
            printf("Opcao invalida\n");
        }
    }
    while (opcao_tipo_participante < 0 || opcao_tipo_participante > 2 );
    {
        printf("Opcao invalida\n");
    }
    return opcao_tipo_participante;
}


char menu_contacto_com_pessoa_infetada(void)
{
    printf("(S)im\n");
    printf("(N)ao\n");
    printf("(D)esconhecido\n");
    printf("Introduza uma opcao\n");
    fflush(stdin);
}



char  menu_opcao_contacto_com_pessoa_infetada(void) //AQUI ï¿½ INT
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
        printf("Opcao invï¿½lida\n");
    }
    return opcao;
}


int menu_sintomas(void)
{
    int opcao_sintomas;

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
    return opcao_sintomas;

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
        if(opcao_sintomas<=0 || opcao_sintomas>2)
        {
            printf("Opcao invalida\n");
        }
    }
    while(opcao_sintomas < 0 || opcao_sintomas > 2);
    {
        printf("Opcao invalida");
    }

    return opcao_sintomas;

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
        printf("5.Hipertensï¿½o\n");
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
    int opcao_doencas;
    do
    {
        printf("1.Inserir doencas\n");
        printf("2.Consultar doencas\n");
        printf("\nOpcao-> ");
        fflush(stdin);
    }
    while(opcao_doencas < 0 || opcao_doencas > 2);
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

int  menu_inserir_consultar_escolas(void)
{
    int opcao_escolas;
    do
    {
        printf("1 Inserir escola\n");
        printf("2 Consultar escola\n");
        printf("Introduza uma opcao->\n");
        fflush(stdin);
        scanf("%d", &opcao_escolas);
        if(opcao_escolas<=0 || opcao_escolas>2)
        {
            printf("Opcao invalida\n");
        }
    }
    while(opcao_escolas < 0 || opcao_escolas > 2);
    {
        printf("Opcao invalida");
    }
    return opcao_escolas;
}


void menu_questionario(void)
{
    printf("1.Idade do Participante\n");
    printf("2.Genero\n");
    printf("3.Local de Residencia\n");
    printf("4.Tipo de Participante\n");
    printf("5.Nos ï¿½ltimos 15 dias esteve em contacto com pessoa infetada com COVID-19\n");
    printf("6.Que sintomas sente \n");
    printf("7.Que doenï¿½as tem\n");
    printf("0 para terminar\n");
    /* printf("Introduza um numero\n");
     fflush(stdin);*/

}

/** FIM DOS MENUS**/
int questionario(t_questionario questionarios[],int contador_questionario)
{
    int opcao;
    do
    {
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
           menu_idade(questionarios);
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

/** FUNCOES INSERIR**/
int inserir_escola(t_escola escola[],int contadoridescola)
{
    int i=0;
    //TODO: VALIDAï¿½ï¿½ES e fazer debug
    escola[contadoridescola].idescola=contadoridescola;//TEM BUG
   // ler_string("Introduza as iniciais da escola (ESECS,ESTG,ESAD,ESTM,ESS)\n",escola[contadoridescola].nomeescola,MAX_TEXTO);

      printf("\nId da escoal: %d",escola[contadoridescola].idescola);//TEM BUG
      ler_string("Introduza as Iniciais da escola\n",escola[contadoridescola].nomeescola,MAX_TEXTO);
      gets(escola[contadoridescola].nomeescola);
      printf("\nNome Inserido: %s",escola[contadoridescola].nomeescola);

      ler_string("Introduza a localidade da escola\n",escola[contadoridescola].localidade,MAX_TEXTO);
        printf("\nNome Inserido: %s",escola[contadoridescola].localidade);
    contadoridescola++;
    printf("%d",&i );
    return contadoridescola;
}

int inserir_idade(t_questionario questionarios[])
{
    do
    {
        printf("Introduza a sua idade\n");
        fflush(stdin);
        scanf("%d", &questionarios.idade[1]);
        if(questionarios.idade[1] <18){
            printf("Tem que ter idade igual ou superior a 18 anos\n");
        }

    }
    while(idade < 18);

return idade;
}
/** FIM FUNCOES INSERIR**/

/**FUNCOES CONSULTAR/LISTAR**/
void Consultar_escola(t_escola escola[])//FALTA TESTAR
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
/**FIM FUNCOES CONSULTAR/LISTAR**/


int Introduzir_Questionario(t_questionario questionario)
{
    //TODO: FAZER FUNï¿½ï¿½ES PARA ESTAS CENAS
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
    printf("Doenï¿½as\n");

}

void limpar_consola()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    fflush(stdin);
}

//FUNCAO LER STRING
void ler_string(char txt[], char str[], int max_len)
{
    printf("%s",txt);
    fflush(stdin);
    fgets(str, max_len, stdin);
    limpar_consola();
}

//FUNCAO LER NUMERO
int ler_numero(char text[])
{
    int numero;

    printf("%s: ", text);
    scanf("%d", &numero);
    return numero;
}


//FUNCAO SAIR
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
