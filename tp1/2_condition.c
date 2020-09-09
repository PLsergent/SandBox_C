#include <stdio.h>

int main() {
    int answer;

    printf("Lorsqu'un pancake prend l'avion à destination de Toronto \net qu'il fait une escale technique à St Claude, on dit:\n");
    printf("=====================================================||=============================================\n");
    printf("1. Qu'il n'est pas arrivé à Toronto                  || 2. Qu'il était supposé arriver à Toronto    \n");
    printf("=====================================================||=============================================\n");
    printf("3. Qu'est ce qu'il fout ce maudit pancake tabernable || 4. La réponse D                             \n");
    printf("=====================================================||=============================================\n");
    scanf("%d", &answer);

    switch (answer)
    {
    case 1:
        printf("C'est une mauvaise réponse.");
        break;
    case 2:
        printf("C'est une mauvaise réponse.");
        break;
    case 3:
        printf("Bravo.");
        break;
    case 4:
        printf("C'est une mauvaise réponse.");
        break;
    
    default:
        printf("Veuillez choisir entre 1 et 4.");
        break;
    }
    return 0;
}