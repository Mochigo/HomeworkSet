package com.homework.hotel.service;

import com.homework.hotel.bean.Book;
import com.homework.hotel.mapper.BookMapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class BookService {

    @Resource
    BookMapper bookMapper;

    public void Insert(Book book) {
        bookMapper.Insert(book);
    }

    public List<Book> SelectAll() {
        return bookMapper.SelectAll();
    }

    public Integer SelectByCount() {
        return bookMapper.SelectByCount();
    }
}
