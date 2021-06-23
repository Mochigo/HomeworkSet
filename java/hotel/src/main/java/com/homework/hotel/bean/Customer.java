package com.homework.hotel.bean;

public class Customer {
    private int ID;
    private String Name;
    private String Telephone;

    public Customer() {
    }

    public Customer(int ID, String Name, String tel) {
        this.ID = ID;
        this.Name = Name;
        this.Telephone = tel;
    }

    public int getID() {
        return this.ID;
    }

    public String getName() {
        return this.Name;
    }

    public String getTelephone() {
        return this.Telephone;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public void setName(String name) {
        this.Name = name;
    }

    public void setTelephone(String telephone) {
        this.Telephone = telephone;
    }
}
