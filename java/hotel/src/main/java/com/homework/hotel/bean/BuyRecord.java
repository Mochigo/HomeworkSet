package com.homework.hotel.bean;

public class BuyRecord {
    private String CustomerName;
    private String CommodityName;
    private int Quantity;
    private String Date;

    public BuyRecord(String customerName, String commodityName, int quantity, String date) {
        CustomerName = customerName;
        CommodityName = commodityName;
        Quantity = quantity;
        Date = date;
    }

    public String getCustomerName() {
        return CustomerName;
    }

    public void setCustomerName(String customerName) {
        CustomerName = customerName;
    }

    public String getCommodityName() {
        return CommodityName;
    }

    public void setCommodityName(String commodityName) {
        CommodityName = commodityName;
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
