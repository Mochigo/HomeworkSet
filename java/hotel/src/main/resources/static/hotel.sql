DROP DATABASE IF EXISTS `hotel`;

CREATE DATABASE `hotel`;

USE `hotel`;

CREATE TABLE `user`
(
    `id`       INT UNSIGNED NOT NULL AUTO_INCREMENT,
    `name`     VARCHAR(25)  NOT NULL,
    `password` VARCHAR(255) NOT NULL,

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `room`
(
    `id`     INT UNSIGNED NOT NULL AUTO_INCREMENT,
    `name`   VARCHAR(25) NOT NULL,
    `type`   VARCHAR(10) NOT NULL,
    `price`  DOUBLE      NOT NULL,
    `status` VARCHAR(10) NOT NULL,

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `customer`
(
    `id`        INT UNSIGNED NOT NULL AUTO_INCREMENT,
    `name`      VARCHAR(25) NOT NULL,
    `telephone` VARCHAR(25) NOT NULL,

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `commodity`
(
    `id`    INT UNSIGNED NOT NULL AUTO_INCREMENT,
    `name`  VARCHAR(25) NOT NULL,
    `price` DOUBLE      NOT NULL,

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `commodity_customer`
(
    `id`           INT UNSIGNED NOT NULL AUTO_INCREMENT,
    `customer_id`  INT UNSIGNED NOT NULL COMMENT "购买者id",
    `commodity_id` INT UNSIGNED NOT NULL COMMENT "商品id",
    `quantity`     INT UNSIGNED NOT NULL COMMENT "购买数量",
    `date`         DATETIME NOT NULL COMMENT "购买时间",

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `room_customer`
(
    `id`          INT UNSIGNED NOT NULL AUTO_INCREMENT,
    `customer_id` INT UNSIGNED NOT NULL COMMENT "会员id",
    `room_id`     INT UNSIGNED NOT NULL COMMENT "商品id",
    `date`        DATETIME NOT NULL COMMENT "开房时间",
    `last`        INT UNSIGNED NOT NULL COMMENT "持续时间",

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;