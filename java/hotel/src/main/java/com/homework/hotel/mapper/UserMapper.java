package com.homework.hotel.mapper;

import com.homework.hotel.pojo.User;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface UserMapper {
    void Insert(User user);

    List<User> SelectAll();

    Integer SelectByCount();
}
