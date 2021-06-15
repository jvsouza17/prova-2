#include <stdio.h> // comandos de entrada e sa�da
#include <locale.h> // aceitar acentua��o
#include <string.h> // comando strcmp
#include <stdlib.h> // comando system
// cores do 'R', 'C' e 'D'
#define RED    "\x1b[31m"
#define GREEN  "\x1b[0;32m"
#define BLUE  "\x1B[34m"
#define WHITE  "\x1b[0m"

#define Desconto "50%"
// struct para a reserva
struct tReserva{
    int id;
    char passageiro[40];
    int fileira;
    int cadeira;
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    // Definir vari�veis
    char destino[25], nome[40];
    float valorPassagem, valorTotal;
    int idade, menu, id, senha, menuStatus, pergunta1, pergunta2, pergunta3,fileiras, totalCadeiras , i, j, cadeiras;
    int fileira,cadeira,idReserva = 0;
    int totalAssentoDisponivel = 0;
    int totalAssentoReservado = 0;
    int totalAssentoConfimado = 0;
    
    // Boas vindas e configura��o do voo
    printf("=======================================\n");
    printf("Seja bem vindo a Salumar Linhas A�reas!\n");
    printf("=======================================\n");
    printf("Primeiramente, vamos configurar o voo.\n");
    system("pause");
    system("cls");
    
    do{
        printf("\n1-Digite o destino: \n");
        gets(destino);
        fflush(stdin);
    } while(strlen(destino)==0);
    

    do {
        printf("2-Quantidade de fileiras: ");
        scanf("%d",&fileiras);
        printf("3-Quantidade de cadeiras por Fileiras: ");
        scanf("%d",&cadeiras);
        totalCadeiras = fileiras * cadeiras;
        if(totalCadeiras < 90 || totalCadeiras > 200)
              printf("\nN�mero inv�lido!\n");
    } while(totalCadeiras < 90  || totalCadeiras > 200);
    
    totalAssentoDisponivel = totalCadeiras;
    // Definindo o struct
    struct tReserva reserva[totalCadeiras];

    char assentos[fileiras][cadeiras];
 	// coloquei o mapa do avi�o aqui sen�o dar erro depois
    for(i = 0;i<fileiras;i++){
        for( j = 0;j<cadeiras;j++){
            assentos[i][j] = 'D';
             
        }
    }
              
    printf("\n4-Valor da passagem: \n");
    scanf("%f", &valorPassagem);
    fflush(stdin);
    system("cls");
    
    // informa��es do voo
    printf("=============================");
    printf("\n-Destino: %s", destino);
    printf("\n-N�mero de assentos: %d", totalCadeiras);
    printf("\n-Valor da passagem: R$ %.2f", valorPassagem);
    printf("\n=============================\n");
    system("pause");
    system("cls");
    
	// menu principal do sistema
    do{
        system("cls");
        printf("======================== MENU ========================\n");
        printf("|1|Mapa do avi�o.\n");
        printf("|2|Confirme uma reserva.\n");
        printf("|3|Fa�a uma reserva.\n");
        printf("|4|Cancele uma reserva.\n");
        printf("|5|Status do avi�o.\n");
        printf("|6|Avalie a Salumar (Caso j� tenha viajado conosco).\n");
        printf("|0|Sair.\n");
        printf("-Agora, o que voc� deseja fazer?\n");
        scanf("%d", &menu);
        fflush(stdin);
        printf("======================== MENU ========================\n");
        
        // visualizar o mapa do avi�o
        switch(menu)  {
            case 1:
                menu=1;
                system("cls");
                printf("================================================================\n");
                printf("Voo para %s, com %d assentos e com passagem no valor de R$ %.2f.\n", destino, totalCadeiras, valorPassagem);
                printf("================================================================\n\n");
                printf("========================= MAPA DO AVI�O =========================\n\n");
                for(i = 0;i<fileiras;i++){ // mapa do avi�o feito com fileiras e cadeiras
                    for( j = 0;j<cadeiras;j++){
                        if (j%10 == 0) {
                            printf("\n");
                        }
                        if(assentos[i][j] == 'D'){ // defini��o de cores para cada letra
                            printf(GREEN"\t%c"WHITE, assentos[i][j]);
                        }else if(assentos[i][j] == 'R'){
                            printf(RED"\t%c"WHITE, assentos[i][j]);
                        } else{
                            printf(BLUE"\t%c"WHITE, assentos[i][j]);
                        }
                        
                        
                    }
                }
                printf("\n========================= MAPA DO AVI�O =========================\n");
                system("pause");
                system("cls");
                break;
            case 2: // confirmar uma reserva que j� foi realizada
                menu=2;
                system("cls");
                    do {
                        printf("Digite sua id: \n");
                        scanf("%d", &id);
                        fflush(stdin);
                    } while(id<=0);
                
                    printf("Digite sua idade: \n");
                    scanf("%d", &idade);
                    fflush(stdin);
                    
                    if(idade<=5) { 
                        printf("Devido a idade ser� descontado %s do valor da passagem!\n", Desconto); // desconto para passageiros com menos de 6 anos
                        system("cls");
                        valorPassagem = valorPassagem/2;
                        printf("Novo valor: R$ %.2f\n", valorPassagem); 
                    }
                    if(reserva[id - 1].id == id) { // realiza a reserva usando o struct e altera o status do assento
                        assentos[reserva[id - 1].fileira][reserva[id - 1].cadeira] ='C'; 
                        printf("==================================\n");
                        printf("A reserva do id %d foi confirmada!\n", id);
                        printf("==================================\n");
                        totalAssentoReservado--;
                        totalAssentoConfimado++;
                    } else{
                        printf("==================================\n");
                        printf("A reserva n�o foi encontrada!\n");
                        printf("==================================\n");
                    }
                system("pause");
                break;
                
            case 3: // realizar uma reserva
                menu=3;
                system("cls");
                printf("Digite seu nome: \n"); 
                gets(nome);
                fflush(stdin);                
                
                for(i = 0;i<fileiras;i++){ // mapa do avi�o
                    printf("\n");
                    for( j = 0;j<cadeiras;j++){
                        if (j%10 == 0) {
                            printf("\n");
                        }
                        if(assentos[i][j] == 'D'){
                            printf(GREEN"\t%c"WHITE, assentos[i][j]);
                        }else if(assentos[i][j] == 'R'){
                            printf(RED"\t%c"WHITE, assentos[i][j]);
                        } else{
                            printf(BLUE"\t%c"WHITE, assentos[i][j]);
                        }
                    }
                }
                do{
                    printf("\nSolicite a fileira:");
                    scanf("%d",&fileira);
                    printf("\nSolicite a cadeira:");
                    scanf("%d",&cadeira);
                }while((fileira < 1 || fileira > fileiras) || (cadeira < 1 || cadeira > cadeiras)); 
                
                if(assentos[fileira - 1][cadeira - 1] == 'D') {
                    
                    idReserva++;
                    assentos[fileira - 1][cadeira - 1] = 'R';
                    printf("==================================\n");
                    printf("A reserva do id %d foi solicitada!\n", idReserva); // o n�mero da reserva � o mesmo da id
                    printf("==================================\n");
                    // sem essa parte o id n�o � reconhecido na hora de confirmar
                    strcpy(reserva[idReserva - 1].passageiro,nome);
                    reserva[idReserva - 1].id = idReserva;
                    reserva[idReserva - 1].fileira = fileira - 1;
                    reserva[idReserva - 1].cadeira = cadeira - 1;
                    totalAssentoDisponivel--;
                    totalAssentoReservado++;
                    // mapa do avi�o
					for( j = 0;j<cadeiras;j++){
                        if (j%10 == 0) {
                            printf("\n");
                        }
                        if(assentos[i][j] == 'D'){
                            printf(GREEN"\t%c"WHITE, assentos[i][j]);
                        }else if(assentos[i][j] == 'R'){
                            printf(RED"\t%c"WHITE, assentos[i][j]);
                        } else{
                            printf(BLUE"\t%c"WHITE, assentos[i][j]);
                        }
                    }
                    system("pause");
                }else{
                    printf("Cadeira ocupada!");
                    system("pause");
                }
                break;
            case 4://Esse case d� erro se for compilado no Dev-C++(sim, eu descobri um bug), para rodar corretamente deve ser compilado num mac ou no site replit
                menu=4;
                 	system("cls");
					do {
                        printf("Digite sua id: \n"); // depois dessa pergunta ele volta para o menu 
						scanf("%d", &id);
 						fflush(stdin); 
                    } while(id<=0); 

                    if(reserva[id - 1].id == id) { 
                        assentos[reserva[id - 1].fileira][reserva[id - 1].cadeira] ='D';
                        printf("==================================\n");
                        printf("A reserva do id %d foi cancelada!\n", id);
                        printf("==================================\n");
                        totalAssentoDisponivel++;
                        totalAssentoReservado--;
                    } else{
                        printf("==================================\n");
                        printf("A reserva n�o foi encontrada!\n");
                        printf("==================================\n");
                    }
                break;
            case 5: // status do avi�o, precisa de uma senha para ter acesso
                menu=5;
                do {
                    system("cls");
                    printf("===================================================\n");
                    printf("Acesso somente para funcion�rios e administradores!\n");
                    printf("===================================================\n");
                    printf("Digite a senha para ter acesso: \n");
                    scanf("%d", &senha);
                    fflush(stdin);
                }while(senha!=123);
                
                printf("================\n");
                printf("Acesso liberado!\n");
                printf("================\n");
                printf("1-Assentos reservados.\n");
                printf("2-Assentos confirmados e valor total.\n");
                printf("3-Assentos dispon�veis.\nEscolha: ");
                scanf("%d", &menuStatus);
                switch(menuStatus) { // o usu�rio escolhe o que ele deseja ter acesso
                    case 1:
                        printf("Existem %d assento(s) reservado(s).\n", totalAssentoReservado);
                        system("pause");
                        break;
                    case 2:
                        printf("Existem %d assento(s) confirmado(s).\n", totalAssentoConfimado);
                        valorTotal = valorPassagem * totalAssentoConfimado;
                        printf("O valor total do(s) confirmado(s) �: R$ %.2f", valorTotal);
                        system("pause");
                    break;
                    case 3:
                        printf("Existem %d assentos dispon�veis.\n", totalAssentoDisponivel);
                        system("pause");
                        break;
                    }
                break;
                    
            case 6: // decidi fazer uma parte para o usu�rio dar um feedback na empresa
                menu=6;
                system("cls");
                printf("1- De 1 a 10 quanto voc� gostou do atendimento dos funcion�rios? \n");
                scanf("%d", &pergunta1);
                fflush(stdin);
                printf("2- De 1 a 10 quanto voc� avalia o conforto dos avi�es? \n");
                scanf("%d", &pergunta2);
                fflush(stdin);
                printf("3- De 1 a 10 quanto voc� avalia a nossa empresa? \n");
                scanf("%d", &pergunta3);
                fflush(stdin);
                system("cls");
                printf("===========================\n");
                printf("1- %d pontos\n", pergunta1);
                printf("2- %d pontos\n", pergunta2);
                printf("3- %d pontos\n", pergunta3);
                printf("Obrigado pelo seu feedback!\n");
                printf("===========================");
                system("pause");
                    break;
    
            case 0: // essa op��o finaliza o c�digo
                menu = 0;
                system("cls");
                printf("================================================");
                printf("\nMuito obrigado por usar esse software, at� logo!");
                printf("\n================================================");
                break;
        }
    }while(menu!=0);
    return 0;
}
