package com.homework.hotel.mapper;

import com.homework.hotel.pojo.Book;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface BookMapper {
    void Insert(Book book);

    List<Book> SelectAll();

    Integer SelectByCount();
}
