#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFF_SIZE 256




bool succes(char *answer, int len){
    for (int i = 0; i < len; i++){
        if (answer[i] != '+')
            return  false;
    }
return true;
}


char *check(char *password, int len, char *input){
    int input_len = 0;
    char *checked = (char*)malloc(BUFF_SIZE * sizeof(char));
    
    while (input[input_len] != '\0'){
        input_len++;
    }
    if (len != input_len){
        return "#";
    }
    for (int i = 0; i < len; i++){
        if (password[i] == input[i]){
            checked[i] = '+';
        }
        else{
            bool flag = false;
            for(int j = 0; j < len; j++){
                if (input[i] == password[j]){
                    flag = true;
                    break;
                }
            }
            if (flag)
                checked[i] = '!';
            else
                checked[i] = '.';
        }
    }

return checked;
}

int main(int argc, char **argv){
    char c;
    int num_try = 0, len = 0;
    char *file = (char*)malloc(BUFF_SIZE * sizeof(char));
    char *password = (char*)malloc(BUFF_SIZE * sizeof(char));
    char *input = (char*)malloc(BUFF_SIZE * sizeof(char));
    char *answer = (char*)malloc(BUFF_SIZE * sizeof(char));
    char quit[] = "!quit";

    if (argc < 2){
        fprintf(stderr, "Needs at least one argument\n");
        exit(1);
    }

    FILE *settings = fopen(argv[1], "r");
    if (settings == NULL){
        printf("Cannot open a file");
        exit(2);
    }

    c = fgetc(settings); 
    for (int i = 0; c != EOF; i++){
        file[i] = c;
        c = fgetc(settings);
    }
    fclose(settings);

    int i = 0;
    for (; file[i]!=32; i++)
        password[i] = file[i];
    
    for (; file[i]==32; i++)
        ;
    
    for (; file[i]>=48 && file[i]<=57; i++)
        len = 10*len + (file[i] - '0');
    
    for (; file[i]==32; i++)
        ;
    
    for (; file[i]>=48 && file[i]<=57; i++)
        num_try = 10*num_try + (file[i] - '0');
    free(file);

    printf("Welcome to Fallout 3 hacking minigame!\n");
    printf("The passphrase contains 4 letters.\n");
    while (num_try > 0){
        printf("\nyou have %d tries left: ", num_try);
        scanf("%s", input);
        
        bool quit_flag = true;
        for (int i = 0; i < 5; i++){
            if (input[i] != quit[i]){
                quit_flag = false;
                break;
            }
        }
        if (quit_flag){
            free(password);
            free(input);
            free(answer);
            exit(5);
        }
        
        answer = check(password, len, input);
        if (answer == "#"){
            printf("Wrong number of characters, try again");
            continue;
        }
        bool flag = succes(answer, len);
        if (flag)
            printf("correct, here's how you did:\n"); 
        else
            printf("incorrect, here's how you did:\n");
            
        for (int j = 0; j < len; j++){
            printf("%c", input[j]);
        }
        printf("\n");
        for (int j = 0; j < len; j++){
            printf("%c", answer[j]);
        }
        num_try--;
        
        if (flag){
            printf("\nyou win\n");
            free(password);
            free(input);
            free(answer);
            exit(3);
        }
        else if(num_try == 0){
            printf("\ngame over\n");
            free(password);
            free(input);
            free(answer);
            exit(4);
        }
        else{
            printf("\ntry again");
        }
    }

return 0;
}
