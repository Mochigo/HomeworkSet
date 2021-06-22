package com.homework.hotel.controller;

import com.github.pagehelper.PageHelper;

import com.homework.hotel.pojo.Room;
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
public class RoomController {

    @Resource
    RoomService roomService;

    @GetMapping("room/list")
    public String ListRooms(Model model, HttpServletRequest request) {
        String pageNum = request.getParameter("page_num");
        String msg = request.getParameter("msg");
        if (msg != null) {
            model.addAttribute("msg", msg);
        }
        Integer totalPage = roomService.SelectByCount() % 3 == 0 ? (roomService.SelectByCount() / 3) : (roomService.SelectByCount() / 3) + 1;
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
            model.addAttribute("pageNum", 1);
        }
        List<Room> rooms = roomService.ListAllRooms();
        model.addAttribute("rooms", rooms);
        return "list_room";
    }

    @GetMapping("empty_room/list")
    public String ListEmptyRooms(Model model, HttpServletRequest request) {
        String pageNum = request.getParameter("page_num");
        String msg = request.getParameter("msg");
        if (msg != null) {
            model.addAttribute("msg", msg);
        }
        Integer totalPage = roomService.SelectByCount() % 3 == 0 ? (roomService.SelectByCount() / 3) : (roomService.SelectByCount() / 3) + 1;
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
            model.addAttribute("pageNum", 1);
        }
        List<Room> rooms = roomService.ListEmptyRooms();
        model.addAttribute("empty_rooms", rooms);
        return "list_empty_room";
    }


    @PostMapping("/room/add")
    public String addRoom(@RequestParam String name, @RequestParam String type, @RequestParam String price, RedirectAttributes redirectAttributes) {
        if (name == "") {
            redirectAttributes.addAttribute("msg", "新增失败，房间号为空");
            return "redirect:/room/list";
        }
        if (type == "") {
            redirectAttributes.addAttribute("msg", "新增失败，房间类型为空");
            return "redirect:/room/list";
        }
        if (price == "") {
            redirectAttributes.addAttribute("msg", "新增失败，房间价格为空");
            return "redirect:/room/list";
        }
        double fee;
        try {
            fee = Double.parseDouble(price);
        } catch (Exception e) {
            redirectAttributes.addAttribute("msg", "新增失败，房间价格填写错误");
            return "redirect:/room/list";
        }
        Room room = new Room(name, type, fee);
        return "redirect:/room/list";
    }
}