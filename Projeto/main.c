#include <stdio.h>
#include <stdlib.h>
#define ESCOLAS 5
#define QUESTIONARIOS 1000
void inserir_idade(int idade);
void inserir_genero(char sexo);
void inserir_residencia( char residencia);
void inserir_tipo_participante();
void inserir_dias();
void inserir_sintomas();
void inserir_doencas();



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
struct contagio_baixo
{
    int id_escola;
    int id;
    int horas;
    int minutos;
    int segundos;
    char risco_de_contagio[30];
    int idade;
    char genero[10];
    char cidade[20];
    char tipo_de_participante[30];
    float temp;
    char contacto_com_pessoa_infetada[3];
    char sintomas[30];
    char sem_doenca[30];

};
struct contagio_alto
{

};

int main()
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

    return 0;
}



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
void inserir_genero();
{


    do
    {
        int sexo;
        printf("Introduza o seu genero");
        scanf("%c", &sexo);
        switch(sexo)
        case 'F':
        break;
    case 'M'
            break;
    case 'D'
            break;
    }
    while(sexo != 'F' &&  sexo !='M' && sexo  != 'F' );

}
