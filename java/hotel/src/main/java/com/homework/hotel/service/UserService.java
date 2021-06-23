package com.homework.hotel.service;

import com.homework.hotel.bean.User;
import com.homework.hotel.mapper.UserMapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class UserService {

    @Resource
    UserMapper userMapper;

    public void Insert(User user) {
        userMapper.Insert(user);
    }

    public List<User> SelectAll() {
        return userMapper.SelectAll();
    }

    public Integer SelectByCount() {
        return userMapper.SelectByCount();
    }

}
