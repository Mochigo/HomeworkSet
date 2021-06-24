package com.homework.hotel.mapper;

import com.homework.hotel.bean.User;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface UserMapper {
    void Insert(User user);

    List<User> SelectAll();

    Integer SelectByCount();

    User getUser(String userName, String password);
}
