package com.homework.hotel.mapper;

import com.homework.hotel.bean.Buy;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface BuyMapper {
    void Insert(Buy buy);

    List<Buy> SelectAll();

    Integer SelectByCount();
}
