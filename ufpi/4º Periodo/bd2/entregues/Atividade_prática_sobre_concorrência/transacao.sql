-- Inserindo dados na tabela de itens

insert into itens (nome_item,preco_un,qtd_item) values ('Baralho', 5.25,10);-- id 1
insert into itens (nome_item,preco_un,qtd_item) values ('Uno', 5.25,10);-- id 2
insert into itens (nome_item,preco_un,qtd_item) values ('Pista da Hotwheels', 25.00,10);-- id 3
insert into itens (nome_item,preco_un,qtd_item) values ('Kit Nerf', 50.70,10);-- id 4
insert into itens (nome_item,preco_un,qtd_item) values ('Colecao de Cartas de Magic', 31.99,10);-- id 5

-- Inserindo usuarios na tabela de user
insert into user (user_name) values ('João Neto');-- id 1
insert into user (user_name) values ('Maria do Rosario');-- id 2
insert into user (user_name) values ('Carlos Silva');-- id 3

-- Fazendo uma venda
START TRANSACTION;

-- Selecione o item para venda com bloqueio exclusivo (FOR UPDATE)
SELECT qtd_item FROM itens WHERE id_item = 15 FOR UPDATE;

-- Inserindo venda
INSERT INTO vendas (itens_id_item,user_id_user) VALUES (15,5);

-- Realize a venda do item e atualize a quantidade disponível
UPDATE itens SET qtd_item = qtd_item - 1 WHERE id_item = 15;

COMMIT;
ROLLBACK;

-- Selects das tabelas
select * from itens;

select * from user;

select * from vendas;

select user_name, nome_item from user join vendas join itens where id_user = user_id_user and id_item = itens_id_item;
select * from user join vendas join itens where id_user = user_id_user and id_item = itens_id_item;




