package com.homework.hotel.mapper;

import com.homework.hotel.pojo.Customer;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface CustomerMapper {
    List<Customer> SelectAll();

    Integer SelectByCount();

    Customer SelectById(int ID);

    void Delete(int ID);

    void Insert(Customer customer);
}
