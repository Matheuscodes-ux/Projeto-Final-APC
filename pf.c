#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

float gastoenergiaM(char sex, float weight, int age)
{
    sex = toupper(sex);
    float ge = 0;
    if ((sex == 'M') && (age >= 0) && (age <= 3))
    {
        ge = (59.512 * weight) - 30.4;
    }
    else if ((sex == 'M') && (age > 3) && (age <= 10))
    {
        ge = (22.706 * weight) + 504.3;
    }
    else if ((sex == 'M') && (age > 10) && (age <= 18))
    {
        ge = (17.686 * weight) + 658.2;
    }
    else if ((sex == 'M') && (age > 18) && (age <= 30))
    {
        ge = (15.057 * weight) + 692.2;
    }
    else if ((sex == 'M') && (age > 30) && (age <= 60))
    {
        ge = (11.472 * weight) + 873.1;
    }
    else if ((sex == 'M') && (age > 60))
    {
        ge = (11.711 * weight) + 587.7;
    }
    else if ((sex == 'F') && (age > 0) && (age <= 3))
    {
        ge = (58.317 * weight) - 31.1;
    }
    else if ((sex == 'F') && (age > 3) && (age <= 10))
    {
        ge = (20.315 * weight) + 485.9;
    }
    else if ((sex == 'F') && (age > 10) && (age <= 18))
    {
        ge = (13.384 * weight) + 692.6;
    }
    else if ((sex == 'F') && (age > 18) && (age <= 30))
    {
        ge = (14.818 * weight) + 486.6;
    }
    else if ((sex == 'F') && (age > 30) && (age <= 60))
    {
        ge = (8.126 * weight) + 845.6;
    }
    else if ((sex == 'F') && (age > 60))
    {
        ge = (9.082 * weight) + 658.5;
    }
    return ge;
}
float consumoKcal(float ge, float fator)
{
    return ge * fator;
}
float reducaopeso(float kgperder, int tempo, float gasto)
{
    float kcalEmagrecer = kgperder * 7700; // calorias necessária para emagrecerm, vai pegar qts kgs a pessoa quer perder e multiplicar por 7700
    float defcitdiario = kcalEmagrecer / tempo;
    float resultado = gasto - defcitdiario;
    return resultado;
}

float aumentopeso(float kgganhar, int tempo, float calorias)
{
    float kcalAumentar = kgganhar * 7700;
    float superavitD = kcalAumentar / tempo;
    float resultado = calorias + superavitD;
    return resultado;
}

float imc(float alt, float peso)
{
    float resultado = peso / (alt * alt);

    return resultado;
}
int main()
{
    char sexo, exefis, maiusculo, sexoM;
    char massa[20];
    int idade, escolha, opcao, temp, obesidade;
    float peso, kcal, fatoratv, energia, reducao, aumento, CR, PA, altura, IMC;
    setlocale(LC_ALL, "portuguese");

    printf("====================================");
    printf("\n            MAIS VIDA              ");
    printf("\n====================================");

    do
    {

        printf("\n<------------------------------------------->");
        printf("\n[1]- Inserir dados");
        printf("\n[2]- Saber mais sobre o programa");
        printf("\n[0]- Sair\n");
        scanf("%d", &escolha);
        switch (escolha)

        {

            break;

        case 1:
            limparTela();
            printf("\n================================================");
            printf("\n==== Vamos digitar alguns dados               ====");
            printf("\n**** Digite seu sexo:                         ****\n");
            scanf(" %c", &sexo);
            sexoM = toupper(sexo);

            printf("**** Digite sua idade:                          ****\n");
            scanf("%d", &idade);

            printf("**** Digite seu peso:                           ****\n");
            scanf("%f", &peso);
            gastoenergiaM(sexo, idade, peso);

            printf("**** Digite sua altura:                         ****\n");
            scanf("%f", &altura);

            break;
        case 2:
            limparTela();
            printf("\n================================================");
            printf("\nO objetivo do contador de calorias é ajudar a entender a quantidade de calorias diárias necessária para emagrecer, engordar ou manter seu peso");
            printf("\nO cálculo de calorias diária funciona com base no gasto energético multiplicado pelo fator atividade");
            printf("\n[I]- Gasto energético = valor que muda conforme a idade x kg +/- valor que muda conforme a idade");
            printf("\n[II]- Fator atividade é calculado de acordo com a quantidade de atividades físicas praticádas pelo indivíduo");
            printf("\n[III]- Também será calculado o IMC, ou seja, o índice de massa corpórea.");
            break;

        default:
            printf("Digite uma opção válida para prosseguir com o programa");
            break;
        }

        limparTela();
        if (escolha == 1)
        {
            if ((sexoM != 'M') && (sexoM != 'F'))
            {
                printf("Digite um sexo válido");
            }
            else if (idade < 0)
            {
                printf("Digite uma idade válida");
            }
            else if (peso < 0)
            {
                printf("Digite um peso válido");
            }
            else if (altura < 0)
            {
                printf("Digite uma altura válida");
            }
            else
            {

                printf("\n================================================");
                printf("\nAgora vamos calcular o fator energético");
                printf("\n[A]- 1 hora de esforço físico semanal");
                printf("\n[B]- 2 horas de esforço físico semanal");
                printf("\n[C]- 5 horas de esforço físico semanal");
                printf("\n[D]- 7 horas ou mais de esforço físico semanal\n");
                scanf(" %c", &exefis);
                maiusculo = toupper(exefis);
                limparTela();

                printf("\n================================================");
                switch (maiusculo)
                {
                case 'A':
                    fatoratv = 1.55;
                    break;
                case 'B':
                    fatoratv = 1.55;
                    break;
                case 'C':
                    fatoratv = 1.84;
                    break;
                case 'D':
                    fatoratv = 2.2;
                    break;
                default:
                    printf("Insira um caracter válido");
                }
                limparTela();
                printf("\n================================================");
                energia = gastoenergiaM(sexo, peso, idade);
                kcal = energia * fatoratv; // calorias que deverão ser ingeridas diariamente
                printf("\nVocê deseja?");
                printf("\n[1]- Manter seu peso");
                printf("\n[2]- Diminuir seu peso");
                printf("\n[3]- Aumentar seu peso");
                printf("\n[4]- Calcular seu Índice de massa Corpórea(IMC)\n");
                scanf("%d", &opcao);
                switch (opcao)
                {
                case 1:
                    limparTela();
                    printf("\n================================================");
                    printf("\nVocê deseja mantar seu peso");
                    printf("\n-------------------------------------->");
                    printf("\n %.2f é quantidade de calorias que você deve ingerir diariamente para manter seu peso", kcal);
                    break;
                case 2:
                    limparTela();
                    printf("\n================================================");
                    printf("\nQuantos kg você deseja perder?\n");
                    scanf("%f", &reducao);
                    if (reducao < 0)
                    {
                        printf("Digite um valor positivo");
                    }
                    else
                    {
                        printf("Digite em quanto tempo você deseja obter esse resultado\n");
                        scanf("%d", &temp);
                        if (temp < 0)
                        {
                            printf("Digite um valor positivo");
                        }
                        else
                        {

                            CR = reducaopeso(reducao, temp, kcal);
                            limparTela();
                            printf("\n================================================");
                            printf("\n%.2f é a quantidade de kcal por dia que você deve ingerir para perder %.2fkg em %d dias", CR, reducao, temp);
                            if (sexo == 'F' && CR < 1200)
                            {
                                printf("\nEssa qtd de kcal/dia não é recomendada, busque um médico");
                            }
                            else if (sexo == 'M' && CR < 1500)
                            {
                                printf("\nEssa qtd de kcal/dia não é recomendada, busque um médico");
                            }
                        }
                    }
                    break;
                case 3:
                    limparTela();
                    printf("\n================================================");
                    printf("\nDigite quantos kg você deseja ganhar\n");
                    scanf("%f", &aumento);
                    if (aumento < 0)
                    {
                        printf("Digite uma quantidade positiva");
                    }
                    else
                    {
                        printf("Digite em quantos dias você deseja obter esse resultado\n");
                        scanf("%d", &temp);

                        PA = aumentopeso(aumento, temp, kcal);
                        printf("\n================================================");
                        printf("\n%.2f é a quantidade de kcal por dia que você deve ingerir para ganhar %.2fkg em %d dias", PA, reducao, temp);
                    }
                    break;
                case 4:
                    limparTela();
                    printf("\n================================================");
                    IMC = imc(altura, peso);
                    if (IMC < 18.5)
                    {
                        printf("\nSeu IMC foi dado como: Magreza...");
                        printf("\nBusque auxílio médico para subir seu peso");
                    }
                    else if ((IMC >= 18.5) && (IMC < 25))
                    {
                        printf("\nSeu IMC foi dado como: Normal");
                    }
                    else if ((IMC >= 25) & (IMC < 30))
                    {
                        printf("\nSeu IMC foi dado como: Sobrepeso...");
                        printf("\nBusque auxílio médico para diminuir seu peso");
                    }
                    else if ((IMC >= 30) & (IMC < 40))
                    {
                        printf("\nSeu IMC foi dado como: Obeso...");
                        printf("\nBusque auxílio médico para diminuir seu peso");
                    }
                    else
                    {
                        printf("\nSeu IMC foi dado como: Obesidade grave");
                        printf("\nBusque auxílio médico urgentemente para diminuir seu peso");
                    }
                default:
                    break;
                }
            }
        }
    } while (escolha != 0);
    limparTela();
    printf("\n=====================================================");
    printf("\nObrigado por testar o programa!!!");
    exibirLogoBloco();
}
