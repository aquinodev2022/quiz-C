#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>

// Declara��o das constantes
#define max_perguntas 19
#define max_tam_pergunta 150
#define max_tam_opcoes 250

// Declara��o da fun��o limparEntrada
void limparEntrada();

// Recebe o tema, perguntas, op��es, resposta e n�mero total de perguntas 
void iniciarQuiz(char tema[], char perguntas[][max_tam_pergunta], char opcoes[][max_tam_opcoes], char respostas[], int numPerguntas) {
    int questoesAcertadas = 0;
    int pulos = 3; 

  // Exibe o tema que o usu�rio escolheu
  printf("\n-------------------------\n");
  printf("     %s\n", tema);
  printf("-------------------------\n");


  // Loop para percorrer as perguntas e op��es do quiz
    int i;
    for (i = 0; i < numPerguntas; ++i) {
        printf("\n%s\n", perguntas[i]);
        printf("%s", opcoes[i]);
        printf("\nVoc� tem pulos restantes: %d\n", pulos);

    // Declara��o de uma vari�vel para armazenar a resposta do usu�rio
    char respostaUsuario;
    printf("\nEscolha uma op��o: ");
    scanf(" %c", &respostaUsuario);

    // Converte a resposta do usu�rio para mai�sculas
    char respostaUsuarioUpperCase = toupper(respostaUsuario);

    // Converte a resposta correta para mai�sculas
    char respostaCorretaUpperCase = toupper(respostas[i]);

      // Verifica��o se a op��o escolhida � v�lida
      while (respostaUsuarioUpperCase < 'A' || (respostaUsuarioUpperCase > 'E' && respostaUsuarioUpperCase != '\n')) {
          printf("Op��o inv�lida! Digite uma op��o v�lida (A, B, C, D ou E):\n");

          // Limpar a entrada at� encontrar a quebra de linha
          while (getchar() != '\n');

          // Digitar uma op��o novamente
          printf("Escolha uma op��o: ");
          scanf(" %c", &respostaUsuario);

          // Converte a resposta do usu�rio para mai�sculas
          respostaUsuarioUpperCase = toupper(respostaUsuario);
      }

      // Limpar o console ap�s o usu�rio responder
      system("cls");

    // Se a resposta do usu�rio for igual � resposta correta
        if (respostaUsuarioUpperCase == respostaCorretaUpperCase) {
            // Resposta correta
            printf("Resposta correta!\n");
            questoesAcertadas++;   

    // Usu�rio apertou na tecla E		         
        } else if (respostaUsuarioUpperCase == 'E') {

      // Usu�rio escolheu pular        
            if (pulos > 0) {
                printf("Voc� pulou a quest�o %d.\n", i + 1);
                pulos--;		
	
          // Usu�rio n�o tem mais pulos dispon�veis     
          } else {
              printf("Voc� n�o tem mais pulos dispon�veis. Digite uma op��o v�lida (A, B, C ou D):\n");

              // Limpar a entrada at� encontrar a quebra de linha
              limparEntrada();

              // Declara��o de uma vari�vel para armazenar a resposta do usu�rio
              char opcaoValida;
              scanf(" %c", &opcaoValida);

              // Converte a op��o do usu�rio para mai�sculas
              char opcaoValidaUpperCase = toupper(opcaoValida);

              // Verifica��o se a op��o escolhida � v�lida
              while (opcaoValidaUpperCase < 'A' || opcaoValidaUpperCase > 'D') {
                  printf("\nOp��o inv�lida! Digite uma op��o v�lida (A, B, C ou D):\n");

                  // Limpar a entrada at� encontrar a quebra de linha
                  limparEntrada();

                  // Digitar uma op��o novamente
                  scanf(" %c", &opcaoValida);

                  // Converte a op��o do usu�rio para mai�sculas
                  opcaoValidaUpperCase = toupper(opcaoValida);
              }

              // Se a op��o digitada ap�s zerar os pulos for igual � resposta correta 
              if (opcaoValidaUpperCase == respostaCorretaUpperCase) {
                  printf("Op��o correta!\n");
                  questoesAcertadas++;
              } else {
                  printf("Op��o incorreta. A resposta correta era %c.\n", respostas[i]);
                  break;
              }
          }
            
        } else {
            // Resposta incorreta
            printf("Resposta incorreta. A resposta correta era %c.\n", respostas[i]);
            break;
        }

        // Limpar o entrada 
        limparEntrada();

        // Verifica se o usu�rio atingiu o m�nimo de acertos
        if (questoesAcertadas >= 16) {
            printf("\nParab�ns! Voc� conseguiu acertar 16 quest�es!\n");
            printf("\n");
            return;
        }
    }

    // usu�rio n�o atingiu o m�nimo de acertos
    printf("\nVoc� n�o atingiu a meta de acertos. Pontua��o: %d/16\n", questoesAcertadas);
    printf("\n--------------------------\n\n");
}

// Implementa��o da fun��o para descartar dados indesejados
void limparEntrada() {
int ch;
while ((ch = getchar()) != '\n' && ch != EOF);
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int escolha;

  // Loop que continuar� at� o usu�rio escolher sair
    do {
      printf("Bem-vindo(a) ao quiz!\n");
        printf("\n----- Menu Principal -----\n");
        printf("\n1. Geografia\n");
        printf("2. Hist�ria\n");
        printf("3. Ci�ncias\n");
        printf("4. Filmes e s�ries\n");
        printf("5. Sair do quiz\n");
        printf("\nEscolha uma op��o: ");
        
    // Verifica��o se ele � inteiro o valor digitado 
        if (scanf("%d", &escolha) != 1) {
            printf("\nop��o inv�lida! Tente novamente.\n");
            printf("\n");
            limparEntrada();
            continue;
        }

      system("cls");
      
        switch (escolha) {
            case 1: {
                char perguntas[max_perguntas][max_tam_pergunta] = {
                    "1. Qual foi a segunda capital do Brasil?\n",
                    "2. Qual � o pa�s mais extenso do mundo?\n",
                    "3. Qual � o deserto mais quente do mundo?\n",
                    "4. Qual � o pa�s com a menor �rea territorial?\n",
                    "5. Qual � o ponto mais alto do planeta terra?\n",
                    "6. Qual � a capital do Canad�?\n",
                    "7. Qual � o maior pa�s da Am�rica do Sul?\n",
                    "8. Qual � o pa�s mais populoso do mundo (2023)?\n",
                    "9. Qual desses pa�ses � cortado pela linha do Equador?\n",
                    "10. Qual � a cordilheira mais longa do mundo?\n",
                    "11. Qual � o maior arquip�lago do mundo com cerca de 14 mil ilhas\n",
                    "12. Qual � o canal que liga o Oceano Atl�ntico ao Oceano Pac�fico?\n",
                    "13. Qual � o pa�s mais populoso da �frica?\n",
                    "14. Qual � o nome da fronteira natural entre a Europa e a �sia\n",
                    "15. Qual � a capital da Austr�lia?\n",
                    "16. Em que oceano est� localizado o Mar de Coral?\n",
                    "17. Onde est� localizado o Tri�ngulo das Bermudas?\n",
                    "18. Qual � o pa�s mais densamente povoado do mundo?\n",
                    "19. Qual � a cidade mais populosa do mundo?\n"
                };

                char opcoes[max_perguntas][max_tam_opcoes] = {
                    "a) Salvador\nb) Recife\nc) Bras�lia\nd) Rio de Janeiro\ne) Pular Quest�o\n",
                    "a) Estados Unidos\nb) R�ssia\nc) Brasil\nd) China\ne) Pular Quest�o\n",
                    "a) Saara\nb) Gobi\nc) Atacama\nd) Kalahari\ne) Pular Quest�o\n",
                    "a) M�naco\nb) L�bia\nc) Vaticano\nd) Israel\ne) Pular Quest�o\n",
                    "a) Monte Everest\nb) Makalu\nc) Monte Fuji\nd) Kanchenjunga\ne) Pular Quest�o\n",
                    "a) Toronto\nb) Vancouver\nc) Ottawa\nd) Montreal\ne) Pular Quest�o\n",
                    "a) Argentina\nb) Brasil\nc) Chile\nd) Peru\n",
                    "a) �ndia\nb) China\nc) Estados Unidos\nd) Paquist�o\ne) Pular Quest�o\n",
                    "a) L�bia\nb) Argentina\nc) Col�mbia\nd) Peru\ne) Pular Quest�o\n",
                    "a) Montanhas Urais\nb) Cordilheira dos Andes\nc) Cordilheira do Himalaia\nd) Grande Escarpa\ne) Pular Quest�o\n",
                    "a) Jap�o\nb) jalap�o\nc) Indon�sia\nd) Laos\ne) Pular Quest�o\n",
                    "a) Canal do Panam�\nb) Canal de Suez\nc) Canal da Mancha\nd) Estreito de Gibraltar\ne) Pular Quest�o\ne) Pular Quest�o\n",
                    "a) Nig�ria\nb) Eti�pia\nc) Egito\nd) �frica do Sul\ne) Pular Quest�o\n",
                    "a) Rio Dan�bio\nb) Rio Volga\nc) Rio Reno\nd) Montes Urais\ne) Pular Quest�o\n",
                    "a) Sydney\nb) Melbourne\nc) Canberra\nd) Brisbane\ne) Pular Quest�o\n",
                    "a) Miami (Fl�rida), Bermuda e San Juan (Porto Rico)\nb) Miami (Fl�rida), Havana (Cuba) e San Juan (Porto Rico)\nc) Londres, Bermuda e San Juan (Porto Rico).\nd) Miami (Fl�rida), Bermudas e Sydney (Austr�lia)\ne) Pular Quest�o\n",
                    "a) Brasil\nb) Argentina\nc) M�xico\nd) Canad�\ne) Pular Quest�o\n",
                    "a) China\nb) M�naco\nc) Brasil\nd) �ndia\ne) Pular Quest�o\n",
                    "a) T�quio\nb) Pequim\nc) Xangai\nd) Deli\ne) Pular Quest�o\n"
                };

                char respostas[max_perguntas] = {'D', 'B', 'A', 'C', 'A', 'C', 'B', 'A', 'C', 'B', 'C', 'A', 'A', 'D', 'C', 'B', 'A', 'B', 'A'};

                iniciarQuiz("Geografia", perguntas, opcoes, respostas, max_perguntas);
                break;
            }
            case 2: {
                char perguntas[max_perguntas][max_tam_pergunta] = {
                    "1. Quem foi o segundo presidente do Brasil?\n",
                    "2. Em que ano come�ou a Primeira Guerra Mundial?\n",
                    "3. Quem foi o l�der da Revolu��o Cubana em 1959?\n",
                    "4. Quem foi o l�der do movimento pelos direitos civis nos Estados Unidos na d�cada de 1960?\n",
                    "5. Qual foi o estopim da Primeira Guerra Mundial?\n",
                    "6. Quem foi Joana d'Arc?\n",
                    "7. Quem foi o primeiro presidente dos Estados Unidos?\n",
                    "8. Quem foi o l�der do movimento pelos direitos civis na �ndia, conhecido por sua filosofia de n�o viol�ncia?\n",
                    "9. Em que ano ocorreu a Revolu��o Francesa?\n",
                    "10. Quem foi Cle�patra?\n",
                    "11. Qual foi o evento que marcou o in�cio da Segunda Guerra Mundial?\n",
                    "12. Quem foi Francisco Franco?\n",
                    "13. Em que ano come�ou a Segunda Guerra Mundial?\n",
                    "14. Qual foi o evento que marcou o fim da Guerra Fria??\n",
                    "15. Qual � a civiliza��o mais antiga do mundo?\n",
                    "16. Quem foi Nelson Mandela?\n",
                    "17. Qual foi a principal causa da Guerra Civil Americana?\n",
                    "18. Quem foi o l�der da Revolu��o Russa de 1917?\n",
                    "19. A civiliza��o asteca se originou de qual pa�s?\n"
                };

                char opcoes[max_perguntas][max_tam_opcoes] = {
                    "a) Prudente Moraes\nb) Marechal Deodoro da Fonseca\nc) Floriano Peixoto\nd) Campos Sales\ne) Pular Quest�o\n",
                    "a) 1914\nb) 1918\ncf) 1922\nd) 1939\ne) Pular Quest�o\n",
                    "a) Che Guevara\nb) Fidel Castro\nc) Batista\nd) Hugo Ch�vez\ne) Pular Quest�o\n",
                    "a) Martin Luther King Jr.\nb) Abraham Lincoln\nc) Malcolm X\nd) John F. Kennedy\ne) Pular Quest�o\n",
                    "a) Imperialismo\nb) Assassinato do Arquiduque Francisco Ferdinando\nc) Nacionalismo\nd) Revolu��o Industrial\ne) Pular Quest�o\n",
                    "a) Rainha da Inglaterra\nb) Hero�na francesa da guerra dos Cem anos\nc) Navegadora portuguesa\nd) Escritora italiana\ne) Pular Quest�o\n",
                    "a) James Madison\nb) John Adams\nc) Thomas Jefferson\nd) George Washington\ne) Pular Quest�o\n",
                    "a) Jawaharlal Nehru\nb) Subhas Chandra Bose\nc) Mahatma Gandhi\nd) Indira Gandhi\ne) Pular Quest�o\n",
                    "a) 1766\nb) 1789\nc) 1824\nd) 1860\ne) Pular Quest�o\n",
                    "a) Rainha do Egito\nb) Imperatriz Romana\nc) Pol�tica grega\nd) Escritora grega\ne) Pular Quest�o\n",
                    "a) Tratado de Versalhes\nb) Ataque a Hiroshima\nc) Bombardeio de Pearl Harbor\nd) Invas�o da Pol�nia pela Alemanha\ne) Pular Quest�o\n",
                    "a) Ditador espanhol\nb) Presidente dos Estados Unidos\nc) Primeiro-ministro brit�nico\nd) Jogador argentino\ne) Pular Quest�o\n",
                    "a) 1914\nb) 1939\nc) 1945\nd) 1950\ne) Pular Quest�o\n",
                    "a) Revolu��o Cubana\nb) Queda do Muro de Berlim\nc) Guerra do Afeganist�o\nd) Guerra do Vietn�\ne) Pular Quest�o\n",
                    "a) Gr�cia\nb) Egito\nc) Mesopot�mia\nd) �rabe\ne) Pular Quest�o\n",
                    "a) Pol�tico sul-africano\nb) L�der chin�s\nc) Fil�sofo franc�s\nd) Ativista indiano\ne) Pular Quest�o\n",
                    "a) Disputas territoriais\nb) Quest�es econ�micas\nc) Desigualdades sociais\nd) Aboli��o da escravid�o\ne) Pular Quest�o\n",
                    "a) Vladimir Lenin\nb) Joseph Stalin\nc) Leon Trotsky\nd) Mikhail Gorbachev\ne) Pular Quest�o\n",
                    "a) Bol�via\nb) Chile\nc) Peru\nd) M�xico\ne) Pular Quest�o\n"
                };

                char respostas[max_perguntas] = {'C', 'A', 'B', 'A', 'B', 'B', 'D', 'C', 'B', 'A', 'D', 'A', 'B', 'B', 'C', 'A', 'D', 'A', 'D'};

                iniciarQuiz("Hist�ria", perguntas, opcoes, respostas, max_perguntas);
                break;
            }
            case 3: {
                char perguntas[max_perguntas][max_tam_pergunta] = {
                    "1. Qual � o tipo de sangue mais raro?\n",
                    "2. Qual � a principal fun��o do sistema nervoso?\n",
                    "3. Quantos cora��es um polvo tem?\n",
                    "4. Os menores ossos do corpo est�o localizados onde?\n",
                    "5. Qual � o �rg�o respons�vel pela produ��o de insulina no corpo humano?\n",
                    "6. O que � a fotoss�ntese?\n",
                    "7. Quantos ossos os tubar�es t�m em seus corpos?\n",
                    "8. Qual � a principal fun��o dos rins no corpo humano?\n",
                    "9. O que s�o os �cidos nucleicos?\n",
                    "10. Qual � a subst�ncia natural mais dura da natureza?\n",
                    "11. Qual a f�rmula qu�mica do di�xido de carbono?\n",
                    "12. Qual � o segundo planeta mais pr�ximo do sol?\n",
                    "13. Quantas patas tem uma aranha?\n",
                    "14. Qual elemento qu�mico � representado pela sigla Ag na tabela peri�dica?\n",
                    "15. Qual parte da planta � respons�vel pela fotoss�ntese?\n",
                    "16. Qual � a fun��o dos leuc�citos no corpo humano?\n",
                    "17. Qual subst�ncia n�o se mistura com a �gua?\n",
                    "18. Qual � o maior �rg�o do corpo humano?\n",
                    "19. Quem foi o cientista que desenvolveu a teoria da evolu��o?\n"
                    };

            char opcoes[max_perguntas][max_tam_opcoes] = {
                  "a) AB+\nb) AB-\nc) O+\nd) A-\ne) Pular Quest�o\n",
                  "a) Digest�o\nb) Circula��o\nc) Respira��o\nd) controlar as a��es volunt�rias e involunt�rias\ne) Pular Quest�o\n",
                  "a) 2 cora��es\nb) 1 cora��o\nc) 3 cora��es\nd) 5 cora��es\ne) Pular Quest�o\n",
                  "a) Orelha\nb) Nariz\nc) Bra�o\nd) Perna\ne) Pular Quest�o\n",
                  "a) F�gado\nb) P�ncreas\nc) Rim\nd) Cora��o\ne) Pular Quest�o\n",
                  "a) Produ��o de energia a partir de nutrientes\nb) Produ��o de oxig�nio a partir da luz solar\nc) Produ��o de glicose a partir de di�xido de carbono\nd) Produ��o de clorofila a partir de nutrientes\ne) Pular Quest�o\n",
                  "a) 0 ossos\nb) 500 ossos\nc) 150 ossos\nd) 457 ossos\ne) Pular Quest�o\n",
                  "a) Digest�o\nc) Respira��o\nb) Filtrar o sangue\nd) Controle da temperatura corporal\ne) Pular Quest�o\n",
                  "a) Subst�ncias respons�veis pelo odor do corpo\nb) Mol�culas que armazenam informa��es gen�ticas\nc) Enzimas que auxiliam na digest�o\nd) Estruturas que protegem os �rg�os internos\ne) Pular Quest�o\n",
                  "a) Ouro\nb) Rocha\nc) Diamante\nd) Rubi\ne) Pular Quest�o\n",
                  "a) (CO2)\nb) (NaCL)\nc) (O3)\nd) (HCL)\ne) Pular Quest�o\n",
                  "a) Merc�rio\nc) V�nus\nb) Terra\nd) Marte\ne) Pular Quest�o\n",
                  "a) 12 patas\nb) 10 patas\nc) 8 patas\nd) 14 patas\ne) Pular Quest�o\n",
                  "a) Ouro\nb) prata\nc) R�dio\nd) Plut�nio\ne) Pular Quest�o\n",
                  "a) Processo de divis�o celular\nb) Processo de reprodu��o sexuada\nc) Processo de s�ntese de prote�nas\nd) Processo de produ��o de energia\ne) Pular Quest�o\n",
                  "a) Transporte de oxignio\nc) Produ��o de horm�nios\nb) Combate a infec��es\nd) Digest�o de alimentos\ne) Pular Quest�o\n",
                  "a) Azeite\nb) Gordura vegetal\nc) Petr�leo\nd) �leo\ne) Pular Quest�o\n",
                  "a) Cora��o\nb) F�gado\nc) Pele\nd) Pulm�es\ne) Pular Quest�o\n",
                  "a) Charles Darwin\nb) Gregor Mendel\nc) Alfred Wallace\nd) Jean-Baptiste Lamarck\ne) Pular Quest�o\n"
            };

            char respostas[max_perguntas] = {'B', 'D', 'C', 'A', 'B', 'C', 'A', 'C', 'B', 'C', 'A', 'B', 'C', 'B', 'A', 'C', 'D', 'C', 'A'};

            iniciarQuiz("Ci�ncias", perguntas, opcoes, respostas, max_perguntas);
            break;
        }

        case 4: {
                char perguntas[max_perguntas][max_tam_pergunta] = {
                    "1. Qual destes filmes da Disney foi lan�ado primeiro?\n",
                    "2. Quem interpretou o Coringa no filme de 2019?\n",
                    "3. Qual � o nome do protagonista da s�rie 'Breaking Bad'?\n",
                    "4. Em que ano foi lan�ado o primeiro epis�dio de 'Game of Thrones'?\n",
                    "5. Qual foi o primeiro filme de anima��o a ser indicado ao Oscar de Melhor Filme?\n",
                    "6. Qual o nome da namorada do Chuck?\n",
                    "7. Qual � o nome do planeta natal de Superman?\n",
                    "8. Quem interpretou Tony Stark (Homem de Ferro) nos filmes da Marvel?\n",
                    "9. Freddy Krueger come�a com quem de alvo?\n",
                    "10. De quem o Lucifer gosta na s�rie Lucifer?\n",
                    "11. Qual filme � baseado no livro de J.R.R. Tolkien e tem um anel como item central?\n",
                    "12. Quem � o protagonista da s�rie 'Sherlock' de 2010?\n",
                    "13. Qual o nome da cidade onde se passa o filme It - A Coisa?\n",
                    "14. Qual � a s�rie de televis�o sobre um grupo de sobreviventes em um apocalipse zumbi?\n",
                    "15. Qual � o maior inimigo do Aquaman?\n",
                    "16. Qual estado brasileiro se passa o filme Tropa de Elite?\n",
                    "17. Qual � o nome do personagem principal na s�rie de filmes Rambo?\n",
                    "18. Em que ano foi lan�ado o primeiro epis�dio de 'Stranger Things'?\n",
                    "19. Na s�rie Peaky Blinders, qual � o nome da fam�lia envolvida em atividades criminosas na Inglaterra p�s-Primeira Guerra Mundial??\n"
                };

                char opcoes[max_perguntas][max_tam_opcoes] = {
                    "a) O Rei Le�o\nb) Mulan\nc) Pocahontas\nd) Toy Story\ne) Pular Quest�o\n",
                    "a) Robert Pattinson\nb) Joaquin Phoenix\nc) Heath Ledger\nd) Christian Bale\ne) Pular Quest�o\n",
                    "a) Walter White\nb) Jesse Pinkman\nc) Saul Goodman\nd) Skyler White\ne) Pular Quest�o\n",
                    "a) 2010\nb) 2011\nc) 2012\nd) 2013\ne) Pular Quest�o\n",
                    "a) A Bela e a Fera\nb) A pequena Sereia\nc) Bambi\nd) Nemo\ne) Pular Quest�o\n",
                    "a) Tiffany\nb) Margarete\nc) Gwen\nd) P�mela\ne) Pular Quest�o\n",
                    "a) Krypton\nb) Asgard\nc) Tatooine\nd) Gotham\ne) Pular Quest�o\n",
                    "a) Chris Evans\nb) Eric Loomis\nc) Chris Hemsworth\nd) Robert Downey Jr.\ne) Pular Quest�o\n",
                    "a) Adolescentes\nb) Adultos\nc) Crian�as\nd) Idosos\ne) Pular Quest�o\n",
                    "a) Mazikeen\nb) Ella Lopez\nc) Eve\nd) Chloe Decker\ne) Pular Quest�o\n",
                    "a) O Senhor dos An�is\nb) Harry Potter\nc) Star Wars\nd) Matrix\ne) Pular Quest�o\n",
                    "a) John Watson\nb) Sherlock Holmes\nc) Moriarty\nd) Mycroft Holmes\ne) Pular Quest�o\n",
                    "a) Derry\nb) Herry\nc) Hollywodd\nd) Nova Iorque\ne) Pular Quest�o\n",
                    "a) The Walking Dead\nb) Fear the Walking Dead\nc) Z Nation\nd) iZombie\ne) Pular Quest�o\n",
                    "a) Arraia Negra\nb) Loki\nc) Arlequina\nd) Doutor Estranho\ne) Pular Quest�o\n",
                    "a) S�o paulo\nb) Rio de Janeiro\nc) Minas Gerais\nd) Cear�\ne) Pular Quest�o\n",
                    "a) Rocky Balboa\nb) Frank Castle\nc) John Rambo\nd) John McClane\ne) Pular Quest�o\n",
                    "a) 2014\nb) 2016\nc) 2010\nd) 2022\ne) Pular Quest�o\n",
                    "a) Campbell\nb) O'Connor\nc) Shelby\nd) Murphy\ne) Pular Quest�o\n"
                };

                char respostas[max_perguntas] = {'A', 'B', 'A', 'B', 'A', 'A', 'D', 'B', 'A', 'D', 'A', 'B', 'A', 'A', 'A', 'B', 'C', 'B', 'C'};

                iniciarQuiz("Filmes e s�ries", perguntas, opcoes, respostas, max_perguntas);
                break;
            }

        case 5:
            printf("Saindo do programa... Obrigado por jogar!\n");
            break;
        default:
            printf("\nOp��o n�o encontrada! Tente novamente.\n");
            printf("\n");
    }
} while (escolha != 5); // O loop continua executando enquanto a escolha do usu�rio for diferente de 5.

return 0;

}