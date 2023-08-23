#ifndef MAIN_H
#define MAIN_H
int main(void);
void exec_token(char *input);
void strtrim(char *input);
void tokenizeInput(char *input, char **args, char *delimiter);
void builtin_env(void);
#endif
