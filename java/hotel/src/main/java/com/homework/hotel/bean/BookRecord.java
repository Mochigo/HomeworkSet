package com.homework.hotel.bean;

public class BookRecord {
    private String CustomerName;
    private String RoomName;
    private String Date;
    private int Last;

    public BookRecord(String customerName, String roomName, String date, int last) {
        CustomerName = customerName;
        RoomName = roomName;
        Date = date;
        Last = last;
    }

    public String getCustomerName() {
        return CustomerName;
    }

    public void setCustomerName(String customerName) {
        CustomerName = customerName;
    }

    public String getRoomName() {
        return RoomName;
    }

    public void setRoomName(String roomName) {
        RoomName = roomName;
    }

    public String getDate() {
        return Date;
    }

    public void setDate(String date) {
        Date = date;
    }

    public int getLast() {
        return Last;
    }

    public void setLast(int last) {
        Last = last;
    }
}
