package com.homework.hotel.service;

import com.homework.hotel.bean.Commodity;
import com.homework.hotel.mapper.CommodityMapper;

import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class CommodityService {
    @Resource
    CommodityMapper commodityMapper;

    public void Insert(Commodity commodity) {
        commodityMapper.Insert(commodity);
    }

    public List<Commodity> ListAllCommodities() {
        return commodityMapper.ListAllCommodities();
    }

    public Integer SelectByCount() {
        return commodityMapper.SelectByCount();
    }
}
