package com.homework.hotel.bean;

public class RoomType {
    private int ID;
    private String TypeName;

    public RoomType(String typeName) {
        TypeName = typeName;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public String getTypeName() {
        return TypeName;
    }

    public void setTypeName(String typeName) {
        TypeName = typeName;
    }
}

