% FATOS %

come(joao,pizza).
come(joao,lasanha).
come(jamile,hamburguer).
come(jamile,sushi).
come(jamile,pao).
come(jamile,biscoito).
come(clistenes,empada).
come(clistenes,sushi).
come(clistenes,lasanha).
come(clistenes,pao).
come(clistenes,biscoito).

% REGRAS %

compra(X,Y) :- come(X,K),come(Y,K), !.

