package com.homework.hotel.service;

import com.homework.hotel.bean.RoomType;
import com.homework.hotel.mapper.RoomTypeMapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class RoomTypeService {
    @Resource
    RoomTypeMapper roomTypeMapper;

    public void Insert(RoomType roomtype) {
        roomTypeMapper.Insert(roomtype);
    }

    public List<RoomType> ListAllRoomTypes() {
        return roomTypeMapper.ListAllRoomTypes();
    }

}
