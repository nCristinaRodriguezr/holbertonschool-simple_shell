#ifndef MAIN_H
#define MAIN_H
int main(void);
void exec_token(char **args, char *full_path);
void strtrim(char *input);
void tokenizeInput(char *input, char **args, char *delimiter);
char *get_full_path(const char *command);
#endif
