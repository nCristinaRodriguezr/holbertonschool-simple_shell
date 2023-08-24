#ifndef MAIN_H
#define MAIN_H
int main(void);
void exec_token(char **args, char *full_path);
void strtrim(char *input);
void tokenizeInput(char *input, char **args, char *delimiter);
void get_full_path(const char *command, char *full_path);
#endif
