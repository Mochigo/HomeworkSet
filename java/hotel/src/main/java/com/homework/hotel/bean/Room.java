package com.homework.hotel.bean;

import java.io.Serializable;

public class Room implements Serializable {
    private int ID;
    private String RoomName;
    private String Type;
    private double Price;
    private String Status;

    public Room() {
    }

    public Room(int id, String roomName, String type, double price) {
        this.ID = id;
        this.RoomName = roomName;
        this.Type = type;
        this.Price = price;
        this.Status = "空闲";
    }

    public Room(String roomName, String type, double price) {
        this.RoomName = roomName;
        this.Type = type;
        this.Price = price;
        this.Status = "空闲";
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public void setPrice(double price) {
        this.Price = price;
    }

    public void setRoomName(String roomName) {
        this.RoomName = roomName;
    }

    public void setType(String type) {
        this.Type = type;
    }

    public int getID() {
        return this.ID;
    }

    public String getRoomName() {
        return this.RoomName;
    }

    public double getPrice() {
        return this.Price;
    }

    public String getStatus() {
        return Status;
    }

    public void setStatus(String status) {
        Status = status;
    }

    public String getType() {
        return this.Type;
    }
}
