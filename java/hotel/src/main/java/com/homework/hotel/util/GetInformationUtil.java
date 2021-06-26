package com.homework.hotel.util;

import com.homework.hotel.bean.Commodity;
import com.homework.hotel.bean.Customer;
import com.homework.hotel.bean.Room;

import java.util.List;

public class GetInformationUtil {
    public static String getCustomerName(List<Customer> customers, int ID) {
        for (Customer customer : customers) {
            if (customer.getID() == ID) {
                return customer.getName();
            }
        }
        return "";
    }

    public static String getRoomName(List<Room> rooms, int ID) {
        for (Room room : rooms) {
            if (room.getID() == ID) {
                return room.getRoomName();
            }
        }
        return "";
    }

    public static String getCommodityName(List<Commodity> commodities, int ID) {
        for (Commodity commodity : commodities) {
            if (commodity.getID() == ID) {
                return commodity.getName();
            }
        }
        return "";
    }
}
