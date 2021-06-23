package com.homework.hotel.service;

import com.homework.hotel.bean.Buy;
import com.homework.hotel.mapper.BuyMapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class BuyService {

    @Resource
    BuyMapper buyMapper;

    public void Insert(Buy buy) {
        buyMapper.Insert(buy);
    }

    public List<Buy> SelectAll() {
        return buyMapper.SelectAll();
    }

    public Integer SelectByCount() {
        return buyMapper.SelectByCount();
    }
}
