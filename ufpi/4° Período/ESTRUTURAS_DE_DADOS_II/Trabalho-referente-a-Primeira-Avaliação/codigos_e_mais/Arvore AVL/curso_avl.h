typedef struct curso Curso;
typedef struct disciplina Disciplina;

void showBlocks(Curso *root, int qtdBlock);
void insertTree(Curso **root, Curso *node);  
void insertCourse(Curso **root, int idCurso);   
void searchCourse(Curso *root, int id);     
void printInOrdem(Curso *root);                  
void showCursoDisciplinaCod(Curso *root, int cod); 
void printCursoDisciplina(Curso *root, int cod_curso, int cod_discipline);
void printAllDiscipline(Curso *root, int block, int cod_curso);
void printCursoDisciplinaWorkload(Curso *root, int cod_curso,int workload);
void removeAvrCursoDisciplina(Curso **root, int idCurso);
void rotacaoEsquerda(Curso **node);
void rotacaoDireita(Curso **node);
void atualizarAltura(Curso **node);

Curso *create(); 
Curso *createNode(int id);
Curso *searchNode(Curso *root, int cod);
Curso *ehFolhaCurso(Curso *no);
Curso *umFilhoCurso(Curso *no);
Curso *doisFilhoCurso(Curso *no);
Curso *buscaMaiorEsqCurso(Curso *no);

int ehFolhaIntCurso(Curso *no);
int umFilhoIntCurso(Curso *no);
int doisFilhoIntCurso(Curso *no);
int altura(Curso *no);
int fatorBalanceamento(Curso *no);
int removerCursoDiscipline(Curso **root, int idCurso, int idDisciplina);
int removerCurso(Curso **root, int idCurso);
