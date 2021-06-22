package com.homework.hotel.pojo;

public class User {
    private int ID;
    private String Name;
    private String Password;

    public User() {
    }

    public User(String name, String password) {
        this.Name = name;
        this.Password = password;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public void setPassword(String password) {
        this.Password = password;
    }

    public void setName(String name) {
        this.Name = name;
    }

    public int getID() {
        return this.ID;
    }

    public String getName() {
        return this.Name;
    }

    public String getPassword() {
        return this.Password;
    }
}
