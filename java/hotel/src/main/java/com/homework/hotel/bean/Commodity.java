package com.homework.hotel.bean;

public class Commodity {
    private int ID;
    private String Name;
    private double Price;

    public Commodity() {}

    public Commodity( String name, double price) {
        this.Name = name;
        this.Price = price;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public double getPrice() {
        return Price;
    }

    public void setPrice(double price) {
        Price = price;
    }
}
