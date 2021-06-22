package com.homework.hotel.mapper;

import com.homework.hotel.pojo.Commodity;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface CommodityMapper {
    void Insert(Commodity commodity);

    List<Commodity> ListAllRooms();

    Integer SelectByCount();
}