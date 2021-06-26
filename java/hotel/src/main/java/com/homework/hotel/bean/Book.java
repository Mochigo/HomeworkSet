package com.homework.hotel.bean;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Book {
    private int ID;
    private int CustomerID;
    private int RoomID;
    private String Date;
    private int Last;

    public Book() {
    }

    public Book(int customerID, int roomID, int last) {
        CustomerID = customerID;
        RoomID = roomID;
        this.Last = last;
        SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");//设置日期格式
        this.Date = df.format(new Date());
    }

    public Book(int customerID, int roomID, String date, int last) {
        CustomerID = customerID;
        RoomID = roomID;
        Date = date;
        Last = last;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public int getCustomerID() {
        return CustomerID;
    }

    public void setCustomerID(int customerID) {
        CustomerID = customerID;
    }

    public int getRoomID() {
        return RoomID;
    }

    public void setRoomID(int roomID) {
        RoomID = roomID;
    }

    public int getLast() {
        return Last;
    }

    public void setLast(int last) {
        this.Last = last;
    }

    public String getDate() {
        return Date;
    }

    public void setDate(String date) {
        Date = date;
    }
}
