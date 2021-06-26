package com.homework.hotel.mapper;

import com.homework.hotel.bean.RoomType;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface RoomTypeMapper {
    void Insert(RoomType roomtype); // 添加房间类型

    List<RoomType> ListAllRoomTypes();
}
