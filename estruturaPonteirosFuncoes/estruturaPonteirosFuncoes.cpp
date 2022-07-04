#include <iostream>
#include <string>

struct desempenho {
    int av[3];
};

struct aluno {
    char nome[20];
    struct desempenho avaliacao;
}aluno[3];

void inserirDados() {
    for (int i = 0; i < 3; i += 1) {
        fflush(stdin);
        std::cout << "nome: ";
        std::cin.getline((aluno + i)->nome, 30);
        for (int j = 0; j < 3; j += 1) {
            std::cout << "nota: " << j+1 << std::endl;
            std::cin >> (aluno + i)->avaliacao.av[j];
        }
    }
}

void processarNota(struct aluno* ptr) {
    struct aluno aluno_maior_nota;
    int media = 0;
    int maior_media = 0;

    for (int i = 0; i < 3; i += 1) {
        media = 0;
        for (int j = 0; j < 3; j += 1) {
            media += (ptr + i)->avaliacao.av[j];
            //std::cout << (ptr + i)->avaliacao.av[j] << std::endl;
            if (media > maior_media) {
                maior_media = media;
                strcpy(aluno_maior_nota.nome, (ptr + i)->nome);
            }
        }
    }
    std::cout << "maior media foi: " << aluno_maior_nota.nome;
}

int main() {
    inserirDados();
    processarNota(aluno);
    return 0;
}