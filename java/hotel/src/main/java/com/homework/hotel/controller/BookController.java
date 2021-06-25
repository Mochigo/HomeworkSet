package com.homework.hotel.controller;

import com.github.pagehelper.PageHelper;
import com.homework.hotel.bean.Book;
import com.homework.hotel.service.BookService;
import com.homework.hotel.service.CustomerService;
import com.homework.hotel.service.RoomService;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.util.List;

@Controller
public class BookController {

    @Resource
    BookService bookService;

    @Resource
    RoomService roomService;

    @Resource
    CustomerService customerService;

    @GetMapping("/book/list")
    public String ListBuyRecords(Model model, HttpServletRequest request) {
        String pageNum = request.getParameter("page_num");
        String msg = request.getParameter("msg");
        if (msg != null) {
            model.addAttribute("msg", msg);
        }
        Integer totalPage = bookService.SelectByCount() % 3 == 0 ? (bookService.SelectByCount() / 3) : (bookService.SelectByCount() / 3) + 1;
        if (pageNum != null) {
            if (Integer.parseInt(pageNum) == 0) {
                PageHelper.startPage(totalPage, 3);
                model.addAttribute("page_num", totalPage);
            } else if (Integer.parseInt(pageNum) == totalPage + 1) {
                PageHelper.startPage(1, 3);
                model.addAttribute("page_num", 1);
            } else {
                PageHelper.startPage(Integer.parseInt(pageNum), 3);
                model.addAttribute("page_num", Integer.parseInt(pageNum));
            }
        } else {
            PageHelper.startPage(1, 3);
            model.addAttribute("page_num", 1);
        }
        List<Book> books = bookService.SelectAll();
        model.addAttribute("book_records", books);
        return "listBookRecords";
    }

    @PostMapping("/book/add")
    public String addBook(@RequestParam String customerID, @RequestParam String roomID, @RequestParam String last, RedirectAttributes redirectAttributes) {
        if (customerID == "") {
            redirectAttributes.addAttribute("msg", "开房失败，没有设置住房用户");
            return "redirect:/book/list";
        }
        if (roomID == "") {
            redirectAttributes.addAttribute("msg", "开房失败，没有设置房间");
            return "redirect:/book/list";
        }
        if (last == "") {
            redirectAttributes.addAttribute("msg", "开房失败，没有输入持续时间");
            return "redirect:/book/list";
        }
        int customer = Integer.parseInt(customerID);
        int room = Integer.parseInt(roomID);
        int lastTime = Integer.parseInt(last);

        Book book = new Book(customer, room, lastTime);
        bookService.Insert(book);
        return "listBookRecords";
    }

    @GetMapping("/book/add")
    public String getNeedInformation(Model model) {
        model.addAttribute("rooms", roomService.ListEmptyRooms());
        model.addAttribute("customers", customerService.SelectAll());
        return "addBookRecords";
    }
}