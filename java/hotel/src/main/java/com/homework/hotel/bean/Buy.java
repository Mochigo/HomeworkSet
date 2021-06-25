package com.homework.hotel.bean;

import java.util.Date;
import java.text.SimpleDateFormat;

public class Buy {
    private int ID;
    private int CustomerID;
    private int CommodityID;
    private int Quantity;
    private String Date;

    public Buy() {
    }

    public Buy(int customerID, int commodityID, int quantity) {
        CustomerID = customerID;
        CommodityID = commodityID;
        Quantity = quantity;
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

    public int getCommodityID() {
        return CommodityID;
    }

    public void setCommodityID(int commodityID) {
        CommodityID = commodityID;
    }

    public int getQuantity() {
        return Quantity;
    }

    public void setQuantity(int quantity) {
        Quantity = quantity;
    }

    public String getDate() {
        return Date;
    }

    public void setDate(String date) {
        Date = date;
    }
}
