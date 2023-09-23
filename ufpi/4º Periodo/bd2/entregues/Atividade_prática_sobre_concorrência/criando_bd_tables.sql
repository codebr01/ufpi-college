-- MySQL Script generated by MySQL Workbench
-- Tue Aug  1 20:10:43 2023
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `db_conc` DEFAULT CHARACTER SET utf8 ;
USE `db_conc` ;

-- -----------------------------------------------------
-- Table `mydb`.`user`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `db_conc`.`user` ;

CREATE TABLE IF NOT EXISTS `db_conc`.`user` (
  `id_user` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `user_name` VARCHAR(100) NOT NULL,
  PRIMARY KEY (`id_user`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`itens`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `db_conc`.`itens` ;

CREATE TABLE IF NOT EXISTS `db_conc`.`itens` (
  `id_item` INT NOT NULL AUTO_INCREMENT,
  `nome_item` VARCHAR(100) NOT NULL,
  `preco_un` FLOAT NOT NULL,
  `qtd_item` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`id_item`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`vendas`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `db_conc`.`vendas` ;

CREATE TABLE IF NOT EXISTS `db_conc`.`vendas` (
  `id_venda` INT NOT NULL AUTO_INCREMENT,
  `itens_id_item` INT NOT NULL,
  `user_id_user` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`id_venda`),
  INDEX `fk_vendas_itens_idx` (`itens_id_item` ASC) VISIBLE,
  INDEX `fk_vendas_user1_idx` (`user_id_user` ASC) VISIBLE,
  CONSTRAINT `fk_vendas_itens`
    FOREIGN KEY (`itens_id_item`)
    REFERENCES `db_conc`.`itens` (`id_item`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_vendas_user1`
    FOREIGN KEY (`user_id_user`)
    REFERENCES `db_conc`.`user` (`id_user`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
