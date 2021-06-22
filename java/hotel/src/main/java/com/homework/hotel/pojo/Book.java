package com.homework.hotel.pojo;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Book {
    private int ID;
    private int CustomerID;
    private int RoomID;
    private String Date;
    private int last;

    public Book() {
    }

    public Book(int ID, int customerID, int roomID, int last) {
        this.ID = ID;
        CustomerID = customerID;
        RoomID = roomID;
        this.last = last;
        SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");//设置日期格式
        this.Date = df.format(new Date());
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
        return last;
    }

    public void setLast(int last) {
        this.last = last;
    }

    public String getDate() {
        return Date;
    }

    public void setDate(String date) {
        Date = date;
    }
}
