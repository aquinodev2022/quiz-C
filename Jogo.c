#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>

// Declaração das constantes
#define max_perguntas 19
#define max_tam_pergunta 150
#define max_tam_opcoes 250

// Declaração da função limparEntrada
void limparEntrada();

// Recebe o tema, perguntas, opções, resposta e número total de perguntas 
void iniciarQuiz(char tema[], char perguntas[][max_tam_pergunta], char opcoes[][max_tam_opcoes], char respostas[], int numPerguntas) {
    int questoesAcertadas = 0;
    int pulos = 3; 

  // Exibe o tema que o usuário escolheu
  printf("\n-------------------------\n");
  printf("     %s\n", tema);
  printf("-------------------------\n");


  // Loop para percorrer as perguntas e opções do quiz
    int i;
    for (i = 0; i < numPerguntas; ++i) {
        printf("\n%s\n", perguntas[i]);
        printf("%s", opcoes[i]);
        printf("\nVocê tem pulos restantes: %d\n", pulos);

    // Declaração de uma variável para armazenar a resposta do usuário
    char respostaUsuario;
    printf("\nEscolha uma opção: ");
    scanf(" %c", &respostaUsuario);

    // Converte a resposta do usuário para maiúsculas
    char respostaUsuarioUpperCase = toupper(respostaUsuario);

    // Converte a resposta correta para maiúsculas
    char respostaCorretaUpperCase = toupper(respostas[i]);

      // Verificação se a opção escolhida é válida
      while (respostaUsuarioUpperCase < 'A' || (respostaUsuarioUpperCase > 'E' && respostaUsuarioUpperCase != '\n')) {
          printf("Opção inválida! Digite uma opção válida (A, B, C, D ou E):\n");

          // Limpar a entrada até encontrar a quebra de linha
          while (getchar() != '\n');

          // Digitar uma opção novamente
          printf("Escolha uma opção: ");
          scanf(" %c", &respostaUsuario);

          // Converte a resposta do usuário para maiúsculas
          respostaUsuarioUpperCase = toupper(respostaUsuario);
      }

      // Limpar o console após o usuário responder
      system("cls");

    // Se a resposta do usuário for igual à resposta correta
        if (respostaUsuarioUpperCase == respostaCorretaUpperCase) {
            // Resposta correta
            printf("Resposta correta!\n");
            questoesAcertadas++;   

    // Usuário apertou na tecla E		         
        } else if (respostaUsuarioUpperCase == 'E') {

      // Usuário escolheu pular        
            if (pulos > 0) {
                printf("Você pulou a questão %d.\n", i + 1);
                pulos--;		
	
          // Usuário não tem mais pulos disponíveis     
          } else {
              printf("Você não tem mais pulos disponíveis. Digite uma opção válida (A, B, C ou D):\n");

              // Limpar a entrada até encontrar a quebra de linha
              limparEntrada();

              // Declaração de uma variável para armazenar a resposta do usuário
              char opcaoValida;
              scanf(" %c", &opcaoValida);

              // Converte a opção do usuário para maiúsculas
              char opcaoValidaUpperCase = toupper(opcaoValida);

              // Verificação se a opção escolhida é válida
              while (opcaoValidaUpperCase < 'A' || opcaoValidaUpperCase > 'D') {
                  printf("\nOpção inválida! Digite uma opção válida (A, B, C ou D):\n");

                  // Limpar a entrada até encontrar a quebra de linha
                  limparEntrada();

                  // Digitar uma opção novamente
                  scanf(" %c", &opcaoValida);

                  // Converte a opção do usuário para maiúsculas
                  opcaoValidaUpperCase = toupper(opcaoValida);
              }

              // Se a opção digitada após zerar os pulos for igual à resposta correta 
              if (opcaoValidaUpperCase == respostaCorretaUpperCase) {
                  printf("Opção correta!\n");
                  questoesAcertadas++;
              } else {
                  printf("Opção incorreta. A resposta correta era %c.\n", respostas[i]);
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

        // Verifica se o usuário atingiu o mínimo de acertos
        if (questoesAcertadas >= 16) {
            printf("\nParabêns! Você conseguiu acertar 16 questões!\n");
            printf("\n");
            return;
        }
    }

    // usuário não atingiu o mínimo de acertos
    printf("\nVocê não atingiu a meta de acertos. Pontuação: %d/16\n", questoesAcertadas);
    printf("\n--------------------------\n\n");
}

// Implementação da função para descartar dados indesejados
void limparEntrada() {
int ch;
while ((ch = getchar()) != '\n' && ch != EOF);
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int escolha;

  // Loop que continuará até o usuário escolher sair
    do {
      printf("Bem-vindo(a) ao quiz!\n");
        printf("\n----- Menu Principal -----\n");
        printf("\n1. Geografia\n");
        printf("2. História\n");
        printf("3. Ciências\n");
        printf("4. Filmes e séries\n");
        printf("5. Sair do quiz\n");
        printf("\nEscolha uma opção: ");
        
    // Verificação se ele é inteiro o valor digitado 
        if (scanf("%d", &escolha) != 1) {
            printf("\nopção inválida! Tente novamente.\n");
            printf("\n");
            limparEntrada();
            continue;
        }

      system("cls");
      
        switch (escolha) {
            case 1: {
                char perguntas[max_perguntas][max_tam_pergunta] = {
                    "1. Qual foi a segunda capital do Brasil?\n",
                    "2. Qual é o país mais extenso do mundo?\n",
                    "3. Qual é o deserto mais quente do mundo?\n",
                    "4. Qual é o país com a menor área territorial?\n",
                    "5. Qual é o ponto mais alto do planeta terra?\n",
                    "6. Qual é a capital do Canadá?\n",
                    "7. Qual é o maior país da América do Sul?\n",
                    "8. Qual é o país mais populoso do mundo (2023)?\n",
                    "9. Qual desses países é cortado pela linha do Equador?\n",
                    "10. Qual é a cordilheira mais longa do mundo?\n",
                    "11. Qual é o maior arquipélago do mundo com cerca de 14 mil ilhas\n",
                    "12. Qual é o canal que liga o Oceano Atlântico ao Oceano Pacífico?\n",
                    "13. Qual é o país mais populoso da África?\n",
                    "14. Qual é o nome da fronteira natural entre a Europa e a Ásia\n",
                    "15. Qual é a capital da Austrália?\n",
                    "16. Em que oceano está localizado o Mar de Coral?\n",
                    "17. Onde está localizado o Triângulo das Bermudas?\n",
                    "18. Qual é o país mais densamente povoado do mundo?\n",
                    "19. Qual é a cidade mais populosa do mundo?\n"
                };

                char opcoes[max_perguntas][max_tam_opcoes] = {
                    "a) Salvador\nb) Recife\nc) Brasília\nd) Rio de Janeiro\ne) Pular Questão\n",
                    "a) Estados Unidos\nb) Rússia\nc) Brasil\nd) China\ne) Pular Questão\n",
                    "a) Saara\nb) Gobi\nc) Atacama\nd) Kalahari\ne) Pular Questão\n",
                    "a) Mônaco\nb) Líbia\nc) Vaticano\nd) Israel\ne) Pular Questão\n",
                    "a) Monte Everest\nb) Makalu\nc) Monte Fuji\nd) Kanchenjunga\ne) Pular Questão\n",
                    "a) Toronto\nb) Vancouver\nc) Ottawa\nd) Montreal\ne) Pular Questão\n",
                    "a) Argentina\nb) Brasil\nc) Chile\nd) Peru\n",
                    "a) Índia\nb) China\nc) Estados Unidos\nd) Paquistão\ne) Pular Questão\n",
                    "a) Líbia\nb) Argentina\nc) Colômbia\nd) Peru\ne) Pular Questão\n",
                    "a) Montanhas Urais\nb) Cordilheira dos Andes\nc) Cordilheira do Himalaia\nd) Grande Escarpa\ne) Pular Questão\n",
                    "a) Japão\nb) jalapão\nc) Indonésia\nd) Laos\ne) Pular Questão\n",
                    "a) Canal do Panamá\nb) Canal de Suez\nc) Canal da Mancha\nd) Estreito de Gibraltar\ne) Pular Questão\ne) Pular Questão\n",
                    "a) Nigéria\nb) Etiópia\nc) Egito\nd) África do Sul\ne) Pular Questão\n",
                    "a) Rio Danúbio\nb) Rio Volga\nc) Rio Reno\nd) Montes Urais\ne) Pular Questão\n",
                    "a) Sydney\nb) Melbourne\nc) Canberra\nd) Brisbane\ne) Pular Questão\n",
                    "a) Miami (Flórida), Bermuda e San Juan (Porto Rico)\nb) Miami (Flórida), Havana (Cuba) e San Juan (Porto Rico)\nc) Londres, Bermuda e San Juan (Porto Rico).\nd) Miami (Flórida), Bermudas e Sydney (Austrália)\ne) Pular Questão\n",
                    "a) Brasil\nb) Argentina\nc) México\nd) Canadá\ne) Pular Questão\n",
                    "a) China\nb) Mônaco\nc) Brasil\nd) Índia\ne) Pular Questão\n",
                    "a) Tóquio\nb) Pequim\nc) Xangai\nd) Deli\ne) Pular Questão\n"
                };

                char respostas[max_perguntas] = {'D', 'B', 'A', 'C', 'A', 'C', 'B', 'A', 'C', 'B', 'C', 'A', 'A', 'D', 'C', 'B', 'A', 'B', 'A'};

                iniciarQuiz("Geografia", perguntas, opcoes, respostas, max_perguntas);
                break;
            }
            case 2: {
                char perguntas[max_perguntas][max_tam_pergunta] = {
                    "1. Quem foi o segundo presidente do Brasil?\n",
                    "2. Em que ano começou a Primeira Guerra Mundial?\n",
                    "3. Quem foi o líder da Revolução Cubana em 1959?\n",
                    "4. Quem foi o líder do movimento pelos direitos civis nos Estados Unidos na década de 1960?\n",
                    "5. Qual foi o estopim da Primeira Guerra Mundial?\n",
                    "6. Quem foi Joana d'Arc?\n",
                    "7. Quem foi o primeiro presidente dos Estados Unidos?\n",
                    "8. Quem foi o líder do movimento pelos direitos civis na Índia, conhecido por sua filosofia de não violência?\n",
                    "9. Em que ano ocorreu a Revolução Francesa?\n",
                    "10. Quem foi Cleópatra?\n",
                    "11. Qual foi o evento que marcou o início da Segunda Guerra Mundial?\n",
                    "12. Quem foi Francisco Franco?\n",
                    "13. Em que ano começou a Segunda Guerra Mundial?\n",
                    "14. Qual foi o evento que marcou o fim da Guerra Fria??\n",
                    "15. Qual é a civilização mais antiga do mundo?\n",
                    "16. Quem foi Nelson Mandela?\n",
                    "17. Qual foi a principal causa da Guerra Civil Americana?\n",
                    "18. Quem foi o líder da Revolução Russa de 1917?\n",
                    "19. A civilização asteca se originou de qual país?\n"
                };

                char opcoes[max_perguntas][max_tam_opcoes] = {
                    "a) Prudente Moraes\nb) Marechal Deodoro da Fonseca\nc) Floriano Peixoto\nd) Campos Sales\ne) Pular Questão\n",
                    "a) 1914\nb) 1918\ncf) 1922\nd) 1939\ne) Pular Questão\n",
                    "a) Che Guevara\nb) Fidel Castro\nc) Batista\nd) Hugo Chávez\ne) Pular Questão\n",
                    "a) Martin Luther King Jr.\nb) Abraham Lincoln\nc) Malcolm X\nd) John F. Kennedy\ne) Pular Questão\n",
                    "a) Imperialismo\nb) Assassinato do Arquiduque Francisco Ferdinando\nc) Nacionalismo\nd) Revolução Industrial\ne) Pular Questão\n",
                    "a) Rainha da Inglaterra\nb) Heroína francesa da guerra dos Cem anos\nc) Navegadora portuguesa\nd) Escritora italiana\ne) Pular Questão\n",
                    "a) James Madison\nb) John Adams\nc) Thomas Jefferson\nd) George Washington\ne) Pular Questão\n",
                    "a) Jawaharlal Nehru\nb) Subhas Chandra Bose\nc) Mahatma Gandhi\nd) Indira Gandhi\ne) Pular Questão\n",
                    "a) 1766\nb) 1789\nc) 1824\nd) 1860\ne) Pular Questão\n",
                    "a) Rainha do Egito\nb) Imperatriz Romana\nc) Política grega\nd) Escritora grega\ne) Pular Questão\n",
                    "a) Tratado de Versalhes\nb) Ataque a Hiroshima\nc) Bombardeio de Pearl Harbor\nd) Invasão da Polônia pela Alemanha\ne) Pular Questão\n",
                    "a) Ditador espanhol\nb) Presidente dos Estados Unidos\nc) Primeiro-ministro britânico\nd) Jogador argentino\ne) Pular Questão\n",
                    "a) 1914\nb) 1939\nc) 1945\nd) 1950\ne) Pular Questão\n",
                    "a) Revolução Cubana\nb) Queda do Muro de Berlim\nc) Guerra do Afeganistão\nd) Guerra do Vietnã\ne) Pular Questão\n",
                    "a) Grécia\nb) Egito\nc) Mesopotâmia\nd) Árabe\ne) Pular Questão\n",
                    "a) Político sul-africano\nb) Líder chinês\nc) Filósofo francês\nd) Ativista indiano\ne) Pular Questão\n",
                    "a) Disputas territoriais\nb) Questões econômicas\nc) Desigualdades sociais\nd) Abolição da escravidão\ne) Pular Questão\n",
                    "a) Vladimir Lenin\nb) Joseph Stalin\nc) Leon Trotsky\nd) Mikhail Gorbachev\ne) Pular Questão\n",
                    "a) Bolívia\nb) Chile\nc) Peru\nd) México\ne) Pular Questão\n"
                };

                char respostas[max_perguntas] = {'C', 'A', 'B', 'A', 'B', 'B', 'D', 'C', 'B', 'A', 'D', 'A', 'B', 'B', 'C', 'A', 'D', 'A', 'D'};

                iniciarQuiz("História", perguntas, opcoes, respostas, max_perguntas);
                break;
            }
            case 3: {
                char perguntas[max_perguntas][max_tam_pergunta] = {
                    "1. Qual é o tipo de sangue mais raro?\n",
                    "2. Qual é a principal função do sistema nervoso?\n",
                    "3. Quantos corações um polvo tem?\n",
                    "4. Os menores ossos do corpo estão localizados onde?\n",
                    "5. Qual é o órgão responsável pela produção de insulina no corpo humano?\n",
                    "6. O que é a fotossíntese?\n",
                    "7. Quantos ossos os tubarões têm em seus corpos?\n",
                    "8. Qual é a principal função dos rins no corpo humano?\n",
                    "9. O que são os ácidos nucleicos?\n",
                    "10. Qual é a substância natural mais dura da natureza?\n",
                    "11. Qual a fórmula química do dióxido de carbono?\n",
                    "12. Qual é o segundo planeta mais próximo do sol?\n",
                    "13. Quantas patas tem uma aranha?\n",
                    "14. Qual elemento químico é representado pela sigla Ag na tabela periódica?\n",
                    "15. Qual parte da planta é responsável pela fotossíntese?\n",
                    "16. Qual é a função dos leucócitos no corpo humano?\n",
                    "17. Qual substância não se mistura com a água?\n",
                    "18. Qual é o maior órgão do corpo humano?\n",
                    "19. Quem foi o cientista que desenvolveu a teoria da evolução?\n"
                    };

            char opcoes[max_perguntas][max_tam_opcoes] = {
                  "a) AB+\nb) AB-\nc) O+\nd) A-\ne) Pular Questão\n",
                  "a) Digestão\nb) Circulação\nc) Respiração\nd) controlar as ações voluntárias e involuntárias\ne) Pular Questão\n",
                  "a) 2 corações\nb) 1 coração\nc) 3 corações\nd) 5 corações\ne) Pular Questão\n",
                  "a) Orelha\nb) Nariz\nc) Braço\nd) Perna\ne) Pular Questão\n",
                  "a) Fígado\nb) Pâncreas\nc) Rim\nd) Coração\ne) Pular Questão\n",
                  "a) Produção de energia a partir de nutrientes\nb) Produção de oxigênio a partir da luz solar\nc) Produção de glicose a partir de dióxido de carbono\nd) Produção de clorofila a partir de nutrientes\ne) Pular Questão\n",
                  "a) 0 ossos\nb) 500 ossos\nc) 150 ossos\nd) 457 ossos\ne) Pular Questão\n",
                  "a) Digestão\nc) Respiração\nb) Filtrar o sangue\nd) Controle da temperatura corporal\ne) Pular Questão\n",
                  "a) Substâncias responsáveis pelo odor do corpo\nb) Moléculas que armazenam informações genéticas\nc) Enzimas que auxiliam na digestão\nd) Estruturas que protegem os órgãos internos\ne) Pular Questão\n",
                  "a) Ouro\nb) Rocha\nc) Diamante\nd) Rubi\ne) Pular Questão\n",
                  "a) (CO2)\nb) (NaCL)\nc) (O3)\nd) (HCL)\ne) Pular Questão\n",
                  "a) Mercúrio\nc) Vênus\nb) Terra\nd) Marte\ne) Pular Questão\n",
                  "a) 12 patas\nb) 10 patas\nc) 8 patas\nd) 14 patas\ne) Pular Questão\n",
                  "a) Ouro\nb) prata\nc) Rádio\nd) Plutônio\ne) Pular Questão\n",
                  "a) Processo de divisão celular\nb) Processo de reprodução sexuada\nc) Processo de síntese de proteínas\nd) Processo de produção de energia\ne) Pular Questão\n",
                  "a) Transporte de oxignio\nc) Produção de hormônios\nb) Combate a infecções\nd) Digestão de alimentos\ne) Pular Questão\n",
                  "a) Azeite\nb) Gordura vegetal\nc) Petróleo\nd) Óleo\ne) Pular Questão\n",
                  "a) Coração\nb) Fígado\nc) Pele\nd) Pulmões\ne) Pular Questão\n",
                  "a) Charles Darwin\nb) Gregor Mendel\nc) Alfred Wallace\nd) Jean-Baptiste Lamarck\ne) Pular Questão\n"
            };

            char respostas[max_perguntas] = {'B', 'D', 'C', 'A', 'B', 'C', 'A', 'C', 'B', 'C', 'A', 'B', 'C', 'B', 'A', 'C', 'D', 'C', 'A'};

            iniciarQuiz("Ciências", perguntas, opcoes, respostas, max_perguntas);
            break;
        }

        case 4: {
                char perguntas[max_perguntas][max_tam_pergunta] = {
                    "1. Qual destes filmes da Disney foi lançado primeiro?\n",
                    "2. Quem interpretou o Coringa no filme de 2019?\n",
                    "3. Qual é o nome do protagonista da série 'Breaking Bad'?\n",
                    "4. Em que ano foi lançado o primeiro episódio de 'Game of Thrones'?\n",
                    "5. Qual foi o primeiro filme de animação a ser indicado ao Oscar de Melhor Filme?\n",
                    "6. Qual o nome da namorada do Chuck?\n",
                    "7. Qual é o nome do planeta natal de Superman?\n",
                    "8. Quem interpretou Tony Stark (Homem de Ferro) nos filmes da Marvel?\n",
                    "9. Freddy Krueger começa com quem de alvo?\n",
                    "10. De quem o Lucifer gosta na série Lucifer?\n",
                    "11. Qual filme é baseado no livro de J.R.R. Tolkien e tem um anel como item central?\n",
                    "12. Quem é o protagonista da série 'Sherlock' de 2010?\n",
                    "13. Qual o nome da cidade onde se passa o filme It - A Coisa?\n",
                    "14. Qual é a série de televisão sobre um grupo de sobreviventes em um apocalipse zumbi?\n",
                    "15. Qual é o maior inimigo do Aquaman?\n",
                    "16. Qual estado brasileiro se passa o filme Tropa de Elite?\n",
                    "17. Qual é o nome do personagem principal na série de filmes Rambo?\n",
                    "18. Em que ano foi lançado o primeiro episódio de 'Stranger Things'?\n",
                    "19. Na série Peaky Blinders, qual é o nome da família envolvida em atividades criminosas na Inglaterra pós-Primeira Guerra Mundial??\n"
                };

                char opcoes[max_perguntas][max_tam_opcoes] = {
                    "a) O Rei Leão\nb) Mulan\nc) Pocahontas\nd) Toy Story\ne) Pular Questão\n",
                    "a) Robert Pattinson\nb) Joaquin Phoenix\nc) Heath Ledger\nd) Christian Bale\ne) Pular Questão\n",
                    "a) Walter White\nb) Jesse Pinkman\nc) Saul Goodman\nd) Skyler White\ne) Pular Questão\n",
                    "a) 2010\nb) 2011\nc) 2012\nd) 2013\ne) Pular Questão\n",
                    "a) A Bela e a Fera\nb) A pequena Sereia\nc) Bambi\nd) Nemo\ne) Pular Questão\n",
                    "a) Tiffany\nb) Margarete\nc) Gwen\nd) Pâmela\ne) Pular Questão\n",
                    "a) Krypton\nb) Asgard\nc) Tatooine\nd) Gotham\ne) Pular Questão\n",
                    "a) Chris Evans\nb) Eric Loomis\nc) Chris Hemsworth\nd) Robert Downey Jr.\ne) Pular Questão\n",
                    "a) Adolescentes\nb) Adultos\nc) Crianças\nd) Idosos\ne) Pular Questão\n",
                    "a) Mazikeen\nb) Ella Lopez\nc) Eve\nd) Chloe Decker\ne) Pular Questão\n",
                    "a) O Senhor dos Anéis\nb) Harry Potter\nc) Star Wars\nd) Matrix\ne) Pular Questão\n",
                    "a) John Watson\nb) Sherlock Holmes\nc) Moriarty\nd) Mycroft Holmes\ne) Pular Questão\n",
                    "a) Derry\nb) Herry\nc) Hollywodd\nd) Nova Iorque\ne) Pular Questão\n",
                    "a) The Walking Dead\nb) Fear the Walking Dead\nc) Z Nation\nd) iZombie\ne) Pular Questão\n",
                    "a) Arraia Negra\nb) Loki\nc) Arlequina\nd) Doutor Estranho\ne) Pular Questão\n",
                    "a) São paulo\nb) Rio de Janeiro\nc) Minas Gerais\nd) Ceará\ne) Pular Questão\n",
                    "a) Rocky Balboa\nb) Frank Castle\nc) John Rambo\nd) John McClane\ne) Pular Questão\n",
                    "a) 2014\nb) 2016\nc) 2010\nd) 2022\ne) Pular Questão\n",
                    "a) Campbell\nb) O'Connor\nc) Shelby\nd) Murphy\ne) Pular Questão\n"
                };

                char respostas[max_perguntas] = {'A', 'B', 'A', 'B', 'A', 'A', 'D', 'B', 'A', 'D', 'A', 'B', 'A', 'A', 'A', 'B', 'C', 'B', 'C'};

                iniciarQuiz("Filmes e séries", perguntas, opcoes, respostas, max_perguntas);
                break;
            }

        case 5:
            printf("Saindo do programa... Obrigado por jogar!\n");
            break;
        default:
            printf("\nOpção não encontrada! Tente novamente.\n");
            printf("\n");
    }
} while (escolha != 5); // O loop continua executando enquanto a escolha do usuário for diferente de 5.

return 0;

}