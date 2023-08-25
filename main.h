#ifndef MAIN_H
#define MAIN_H
int main(void);
int execute_func(void);
void strtrim(char *input);
void tokenizeInput(char *input, char **args, char *delimiter);
int get_full_path(const char *command, char *full_path);
extern char **environ;
#endif
