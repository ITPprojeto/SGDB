FILE  *open(const char *name, const char *operation);
char *createTable(char *table_name);
void showTable(int new_line, int qdt_colun, char ***table, int max, int space);
void insertItems(char **table);
void createFile(int new_line, int qdt_colun, char ***table, int max, int space, char *nome);
int maxSizeStr(int new_line, int qdt_colun, char ***table, int maior);
void search(int new_line, int qdt_colun, char ***table);
