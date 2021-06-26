package com.homework.hotel.mapper;

import com.homework.hotel.bean.Commodity;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface CommodityMapper {
    void Insert(Commodity commodity);

    List<Commodity> ListAllCommodities();

    Integer SelectByCount();

    Commodity SelectByID(int ID);
}
