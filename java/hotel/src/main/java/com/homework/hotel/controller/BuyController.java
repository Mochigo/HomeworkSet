package com.homework.hotel.controller;

import com.github.pagehelper.PageHelper;
import com.homework.hotel.bean.Buy;
import com.homework.hotel.service.BuyService;
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
public class BuyController {

    @Resource
    BuyService buyService;

    @GetMapping("/buy/list")
    public String ListBuyRecords(Model model, HttpServletRequest request) {
        String pageNum = request.getParameter("page_num");
        String msg = request.getParameter("msg");
        if (msg != null) {
            model.addAttribute("msg", msg);
        }
        Integer totalPage = buyService.SelectByCount() % 3 == 0 ? (buyService.SelectByCount() / 3) : (buyService.SelectByCount() / 3) + 1;
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
        List<Buy> buys = buyService.SelectAll();
        model.addAttribute("buy_informations", buys);
        return "listRooms";
    }

    @PostMapping("/buy/add")
    public String addBuy(@RequestParam String customerID, @RequestParam String commodityID, @RequestParam String quantity, RedirectAttributes redirectAttributes) {
        if (customerID == "") {
            redirectAttributes.addAttribute("msg", "购买失败，没有购买人");
            return "redirect:/buy/list";
        }
        if (commodityID == "") {
            redirectAttributes.addAttribute("msg", "购买失败，没有购买的物品");
            return "redirect:/buy/list";
        }
        if (quantity == "") {
            redirectAttributes.addAttribute("msg", "购买失败，没有购买数量");
            return "redirect:/buy/list";
        }
        int customer = Integer.parseInt(customerID);
        int commodity = Integer.parseInt(commodityID);
        int total = Integer.parseInt(quantity);

        Buy buy = new Buy(customer, commodity, total);
        buyService.Insert(buy);
        return "listRooms";
    }
}
