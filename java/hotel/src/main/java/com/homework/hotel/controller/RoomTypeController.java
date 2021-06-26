package com.homework.hotel.controller;

import com.homework.hotel.bean.RoomType;
import com.homework.hotel.service.RoomTypeService;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import javax.annotation.Resource;

@Controller
public class RoomTypeController {
    @Resource
    RoomTypeService roomTypeService;

    @PostMapping("/roomType/add")
    public String addRoomType(@RequestParam String typeName, RedirectAttributes redirectAttributes) {
        if (typeName == "") {
            redirectAttributes.addAttribute("msg", "新增失败，类型名为空");
            return "redirect:/room/list";
        }
        RoomType roomType = new RoomType(typeName);
        roomTypeService.Insert(roomType);
        return "redirect:/room/list";
    }

    @GetMapping("/roomType/add")
    public String addRoomType(Model model) {
        return "addRoomType";
    }
}
