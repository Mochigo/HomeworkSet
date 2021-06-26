package com.homework.hotel.controller;

import com.github.pagehelper.PageHelper;
import com.homework.hotel.bean.*;
import com.homework.hotel.service.BookService;
import com.homework.hotel.service.CustomerService;
import com.homework.hotel.service.RoomService;
import com.homework.hotel.util.GetInformationUtil;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.util.ArrayList;
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
        List<BookRecord> bookRecords = new ArrayList<BookRecord>();
        List<Customer> customers = customerService.SelectAll();
        List<Room> rooms = roomService.ListAllRooms();
        for (Book book : books) {
            String roomName = GetInformationUtil.getRoomName(rooms, book.getRoomID());
            String customerName = GetInformationUtil.getCustomerName(customers, book.getCustomerID());
            BookRecord bookRecord = new BookRecord(customerName, roomName, book.getDate(), book.getLast());
            bookRecords.add(bookRecord);
        }
        model.addAttribute("book_records", bookRecords);
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
        roomService.UpdateStatusBusy(room);
        bookService.Insert(book);
        return "redirect:/room/list";
    }

    @GetMapping("/book/add")
    public String getNeedInformation(Model model) {
        model.addAttribute("rooms", roomService.ListEmptyRooms());
        model.addAttribute("customers", customerService.SelectAll());
        return "addBookRecords";
    }

    @RequestMapping("/book/check/out")
    public String Checkout(@RequestParam String roomID, RedirectAttributes redirectAttributes) {
        if (roomID == "") {
            redirectAttributes.addAttribute("msg", "退房失败，没有设置退房用户");
            return "redirect:/book/list";
        }
        roomService.UpdateStatusEmpty(Integer.parseInt(roomID));
        return "redirect:/room/list";
    }

    @GetMapping("/book")
    public String Book(Model model) {
        model.addAttribute("rooms", roomService.ListEmptyRooms());
        model.addAttribute("customers", customerService.SelectAll());
        return "BookRoom";
    }

    @PostMapping("/book")
    public String Book(@RequestParam String customerID, @RequestParam String roomID, @RequestParam String date, @RequestParam String last, RedirectAttributes redirectAttributes) {
        if (customerID == "") {
            redirectAttributes.addAttribute("msg", "预约失败，没有设置住房用户");
            return "redirect:/book/list";
        }
        if (roomID == "") {
            redirectAttributes.addAttribute("msg", "预约失败，没有设置房间");
            return "redirect:/book/list";
        }
        if (last == "") {
            redirectAttributes.addAttribute("msg", "预约失败，没有输入持续时间");
            return "redirect:/book/list";
        }
        if (last == "") {
            redirectAttributes.addAttribute("msg", "预约失败，没有输入持续时间");
            return "redirect:/book/list";
        }
        int customer = Integer.parseInt(customerID);
        int room = Integer.parseInt(roomID);
        int lastTime = Integer.parseInt(last);

        Book book = new Book(customer, room, date, lastTime);
        roomService.UpdateStatusBooked(room);
        bookService.Insert(book);
        return "redirect:/room/list";
    }
}