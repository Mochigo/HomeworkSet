package com.homework.hotel.service;

import com.homework.hotel.bean.Customer;
import com.homework.hotel.mapper.CustomerMapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class CustomerService {

    @Resource
    CustomerMapper customerMapper;

    public List<Customer> SelectAll() {
        return customerMapper.SelectAll();
    }

    public Integer SelectByCount() {
        return customerMapper.SelectByCount();
    }

    public Customer SelectById(int ID) {
        return customerMapper.SelectById(ID);
    }

    public void Delete(int ID) {
        customerMapper.Delete(ID);
    }

    public void Insert(Customer customer) {
       customerMapper.Insert(customer);
    }
}
