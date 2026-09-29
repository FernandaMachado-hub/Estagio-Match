#include <stdio.h>

int main() {

    // Cadastro das empresas
    char empresa[15][50] = {
        "CodeCraft", "DevSolutions", "SoftPlus Tecnologia",
        "QualityTech", "TestLab Sistemas", "CodeCheck",
        "CloudTech", "InfraCloud", "NextOps",
        "DataPlus", "DataCore", "InfoData",
        "SecureTech", "CyberGuard", "ShieldNet"
    };

    // Código das áreas de cada vaga
    int area[15] = {
        1, 1, 1,
        2, 2, 2,
        3, 3, 3,
        4, 4, 4,
        5, 5, 5
    };

    // Modalidade de cada vaga
    char modalidade[15][20] = {
        "Hibrido", "Remoto", "Presencial",
        "Hibrido", "Remoto", "Presencial",
        "Hibrido", "Remoto", "Presencial",
        "Hibrido", "Presencial", "Remoto",
        "Hibrido", "Presencial", "Remoto"
    };

    // Valor da bolsa de cada vaga
    float bolsa[15] = {
        1500, 1650, 1400,
        1350, 1500, 1250,
        1700, 1800, 1550,
        1450, 1350, 1600,
        1600, 1500, 1750
    };

    // Guarda as posições das vagas encontradas
    int vagasEncontradas[3];

    // Variáveis de controle do sistema
    int opcaoArea;
    int continuar = 1;

    // Repete o sistema enquanto o usuário desejar continuar
    do {
        printf("Bem-vindo ao EstagioMatch!\n");
        printf("Aqui voce encontra vagas de estagio de\n");
        printf("acordo com a sua area de interesse.\n");

        // Apresenta o menu de áreas
        printf("Escolha uma area de interesse:\n\n");
        printf("1 - Desenvolvimento de Software\n");
        printf("2 - QA e Testes\n");
        printf("3 - DevOps\n");
        printf("4 - Banco de Dados\n");
        printf("5 - Seguranca da Informacao\n");
        printf("0 - Sair\n\n");
        printf("Opcao: ");
        scanf("%d", &opcaoArea);

        // Verifica se o usuário escolheu sair
        if (opcaoArea == 0) {
            printf("\nObrigado por usar o EstagioMatch. Ate a proxima!\n");
            continuar = 0;

        // Verifica se a opção informada é inválida
        } else if (opcaoArea < 1 || opcaoArea > 5) {
            printf("\nOpcao invalida! Tente novamente.\n");

        // Converte o código da área para o nome correspondente
        } else {

            char nomeArea[30];

            if (opcaoArea == 1) {
                sprintf(nomeArea, "Desenvolvimento de Software");
            } else if (opcaoArea == 2) {
                sprintf(nomeArea, "QA e Testes");
            } else if (opcaoArea == 3) {
                sprintf(nomeArea, "DevOps");
            } else if (opcaoArea == 4) {
                sprintf(nomeArea, "Banco de Dados");
            } else {
                sprintf(nomeArea, "Seguranca da Informacao");
            }

            // Variáveis utilizadas no processamento das vagas
            int quantidade = 0;
            float soma = 0;
            float maior = 0;
            float menor = 0;
            int i;

            // Percorre as 15 vagas procurando a área escolhida
            for (i = 0; i < 15; i++) {

                if (area[i] == opcaoArea) {

                    // Guarda a posição da vaga encontrada
                    vagasEncontradas[quantidade] = i;

                    // Soma os valores das bolsas
                    soma = soma + bolsa[i];

                    // Identifica a maior e a menor bolsa
                    if (quantidade == 0) {
                        maior = bolsa[i];
                        menor = bolsa[i];

                    } else {

                        if (bolsa[i] > maior) {
                            maior = bolsa[i];
                        }

                        if (bolsa[i] < menor) {
                            menor = bolsa[i];
                        }
                    }

                    // Conta a quantidade de vagas encontradas
                    quantidade = quantidade + 1;
                }
            }

            // Exibe as vagas encontradas
            printf("\nVagas encontradas para: %s\n\n", nomeArea);

            for (i = 0; i < quantidade; i++) {

                // Recupera a posição da vaga encontrada
                int indice = vagasEncontradas[i];

                printf("               VAGA %d\n", i + 1);
                printf("Empresa    : %s\n", empresa[indice]);
                printf("Area       : %s\n", nomeArea);
                printf("Modalidade : %s\n", modalidade[indice]);
                printf("Bolsa      : R$ %.2f\n", bolsa[indice]);
            }

            // Calcula a média das bolsas encontradas
            float media = 0;

            if (quantidade > 0) {
                media = soma / quantidade;
            }

            // Exibe o resumo dos resultados
            printf("           RESUMO DAS VAGAS\n");
            printf("Quantidade de vagas : %d\n", quantidade);
            printf("Media das bolsas    : R$ %.2f\n", media);
            printf("Maior bolsa         : R$ %.2f\n", maior);
            printf("Menor bolsa         : R$ %.2f\n", menor);

            // Controla a escolha da vaga
            int escolhaValida = 0;

            while (escolhaValida == 0) {

                int opcaoVaga;

                printf("Qual vaga voce deseja escolher?\n");
                printf("1, 2 ou 3 - Escolher vaga\n");
                printf("0 - Voltar ao menu\n");
                printf("Opcao: ");
                scanf("%d", &opcaoVaga);

                // Permite voltar sem escolher uma vaga
                if (opcaoVaga == 0) {
                    escolhaValida = 1;

                // Verifica se a vaga escolhida existe
                } else if (opcaoVaga >= 1 && opcaoVaga <= quantidade) {

                    int indiceEscolhido = vagasEncontradas[opcaoVaga - 1];

                    printf("\nVoce escolheu a vaga da empresa %s.\n", empresa[indiceEscolhido]);

                    // Confirma a candidatura
                    int confirmacaoValida = 0;

                    while (confirmacaoValida == 0) {

                        char resposta;

                        printf("Deseja confirmar a candidatura? (s/n): ");
                        scanf(" %c", &resposta);

                        if (resposta == 's' || resposta == 'S') {
                            printf("CANDIDATURA REALIZADA!\n");
                            printf("Enviamos o link da vaga para o seu e-mail:\n");
                            printf("Boa sorte no processo seletivo!\n");
                            printf("Obrigado por usar o EstagioMatch!\n");
                            confirmacaoValida = 1;

                        } else if (resposta == 'n' || resposta == 'N') {
                            printf("\nCandidatura cancelada.\n\n");
                            confirmacaoValida = 1;

                        // Trata respostas diferentes de S ou N
                        } else {
                            printf("\nResposta invalida! Digite 's' ou 'n'.\n");
                        }
                    }

                    escolhaValida = 1;

                } else {
                    printf("\nOpcao invalida! Tente novamente.\n\n");
                }
            }

            // Verifica se o usuário deseja realizar uma nova busca
            int respostaValida = 0;

            while (respostaValida == 0) {

                char novaBusca;

                printf("Deseja realizar uma nova busca? (s/n): ");
                scanf(" %c", &novaBusca);

                if (novaBusca == 's' || novaBusca == 'S') {
                    respostaValida = 1;

                } else if (novaBusca == 'n' || novaBusca == 'N') {
                    printf("\nObrigado por usar o EstagioMatch. Ate a proxima!\n");
                    continuar = 0;
                    respostaValida = 1;

                // Trata respostas inválidas
                } else {
                    printf("\nResposta invalida! Digite 's' ou 'n'.\n");
                }
            }
        }

    } while (continuar == 1);

    return 0;
}
