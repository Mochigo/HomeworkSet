package com.homework.hotel.mapper;

import com.homework.hotel.bean.Room;

import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface RoomMapper {
    void Insert(Room room); // 添加房间

    List<Room> ListEmptyRooms(); // 获取空闲房子

    List<Room> ListAllRooms();

    List<Room> ListUsedRooms();

    Integer SelectByCount();

    Room SelectByID(int ID);

    void UpdateStatusEmpty(int ID);

    void UpdateStatusBusy(int ID);

    void UpdateStatusBooked(int ID);
}
