% BASE DE CONHECIMENTO %
pneus(4).
portas(4).
motor(1).


carro(X,Y,Z):- X(4), Y(4), Z(1).

gerou(francisco,marcos).
gerou(joão,renato).
gerou(silvio,andré).
gerou(daniel,rogerio).

pai(X,Y):- gerou(X,Y).

pi(3,14).
raio(2).

pais(brasil, 9, 130).
pais(china, 12, 1800).
pais(eua, 9, 230).
pais(india, 3, 450).

gosta(maria, comida).
gosta(joão, vinho).

