package com.homework.hotel.controller;

import com.homework.hotel.bean.Commodity;
import com.homework.hotel.bean.Room;
import com.homework.hotel.service.CommodityService;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import javax.annotation.Resource;

@Controller
public class CommodityController {
    @Resource
    CommodityService commodityService;

    @GetMapping("/commodity/add")
    public String addCommodity() {
        return "addCommodity";
    }

    @PostMapping("/commodity/add")
    public String addCommodity(@RequestParam String name, @RequestParam String price, RedirectAttributes redirectAttributes) {
        if (name == "") {
            redirectAttributes.addAttribute("msg", "新增失败，商品名为空");
            return "redirect:/buy/list";
        }
        if (price == "") {
            redirectAttributes.addAttribute("msg", "新增失败，商品价格为空");
            return "redirect:/buy/list";
        }
        double fee;
        try {
            fee = Double.parseDouble(price);
        } catch (Exception e) {
            redirectAttributes.addAttribute("msg", "新增失败，商品价格填写错误");
            return "redirect:/buy/list";
        }
        Commodity commodity = new Commodity(name, fee);
        commodityService.Insert(commodity);
        return "redirect:/buy/list";
    }
}
