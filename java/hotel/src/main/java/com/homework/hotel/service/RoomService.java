package com.homework.hotel.service;


import com.homework.hotel.mapper.RoomMapper;
import com.homework.hotel.bean.Room;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class RoomService {

    @Resource
    RoomMapper roomMapper;

    public List<Room> ListEmptyRooms() {
        return roomMapper.ListEmptyRooms();
    }

    public List<Room> ListUsedRooms() {
        return roomMapper.ListUsedRooms();
    }

    public void Insert(Room room) {
        roomMapper.Insert(room);
    }

    public Integer SelectByCount() {
        return roomMapper.SelectByCount();
    }

    public List<Room> ListAllRooms() {
        return roomMapper.ListAllRooms();
    }

    public void UpdateStatusEmpty(int ID) {
        roomMapper.UpdateStatusEmpty(ID);
    }

    public void UpdateStatusBusy(int ID) {
        roomMapper.UpdateStatusBusy(ID);
    }

    public Room SelectByID(int ID) {
        return roomMapper.SelectByID(ID);
    }
    public void UpdateStatusBooked(int ID) {
        roomMapper.UpdateStatusBooked(ID);
    }
}
