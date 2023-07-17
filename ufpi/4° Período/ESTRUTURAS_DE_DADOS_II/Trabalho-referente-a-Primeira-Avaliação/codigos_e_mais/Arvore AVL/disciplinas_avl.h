typedef struct disciplinas Disciplinas;

void insertDisciplina(Disciplinas **root,int bloco);
void insertTreeDiscipline(Disciplinas **root, Disciplinas *node);
void printInOrdemDiscipline(Disciplinas *root);
void printDiscipline(Disciplinas *root, int cod_discipline);
void printDisciplinaInBlock(Disciplinas *root, int bloco);
void printDisciplinaWorkload(Disciplinas *root, int workload);
void removerTodasDisciplinas(Disciplinas **root);
void rotacaoEsquerdaDisciplina(Disciplinas **node);
void rotacaoDireitaDisciplina(Disciplinas **node);
void atualizarAlturaDisciplina(Disciplinas *node);
void deletarDisciplinas(Disciplinas **root);

Disciplinas *searchNodeDiscipline(Disciplinas *root, int cod);
Disciplinas *createNodeDiscipline(int bloco);
Disciplinas* ehFolha(Disciplinas *no);  
Disciplinas* umFilho(Disciplinas *no);
Disciplinas* doisFilho(Disciplinas *no);
Disciplinas* buscaMaiorEsq(Disciplinas *no);

int removeDiscipline(Disciplinas **root, int id);
int ehFolhaInt(Disciplinas *no);
int umFilhoInt(Disciplinas *no);
int doisFilhoInt(Disciplinas *no);
int alturaDisciplina(Disciplinas *no);
int fatorBalanceamentoDisciplina(Disciplinas *no);
