package com.homework.hotel.exception;

public class MailException extends Exception{
    public MailException() {
        super("这是一个不合法的邮件地址");
    }
}
