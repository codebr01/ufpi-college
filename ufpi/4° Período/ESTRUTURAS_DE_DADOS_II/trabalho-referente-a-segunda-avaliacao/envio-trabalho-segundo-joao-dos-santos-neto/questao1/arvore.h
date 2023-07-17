typedef struct avr Avr;

Avr* inicializa();
Avr* criaNo(char *palavra,int linha);
Avr* remove_NO(Avr *H, char *palavra);
Avr* removerMenor(Avr *H);
Avr* procuraMenor(Avr *atual);
Avr* move2EsqRED(Avr *H);
Avr* move2DirRED(Avr *H);
Avr* balancear(Avr *H);

int insereAvrRedBlack(Avr **raiz, char *palavra, int linha);
int insereNo(Avr **raiz, Avr *no, int linha);
int remove_AvrLLRB(Avr *raiz, char *palavra);
int consulta_AvrLLRB(Avr *raiz, char *palavra);

void mostrarNo(Avr *no);
void mostrarAvr(Avr *raiz);
void rotacionaEsquerda(Avr **no);
void rotacionaDireita(Avr **no);
void trocaCor(Avr **raiz);

char cor(Avr *no);