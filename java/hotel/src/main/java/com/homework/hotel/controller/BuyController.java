package com.homework.hotel.controller;

import com.github.pagehelper.PageHelper;
import com.homework.hotel.bean.Buy;
import com.homework.hotel.bean.BuyRecord;
import com.homework.hotel.bean.Commodity;
import com.homework.hotel.bean.Customer;
import com.homework.hotel.service.BuyService;
import com.homework.hotel.service.CommodityService;
import com.homework.hotel.service.CustomerService;
import com.homework.hotel.util.GetInformationUtil;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.util.ArrayList;
import java.util.List;

@Controller
public class BuyController {

    @Resource
    BuyService buyService;

    @Resource
    CommodityService commodityService;


    @Resource
    CustomerService customerService;

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
        List<BuyRecord> buyRecords = new ArrayList<BuyRecord>();
        List<Customer> customers = customerService.SelectAll();
        List<Commodity> commodities = commodityService.ListAllCommodities();
        for (Buy buy : buys) {
            String commodityName = GetInformationUtil.getCommodityName(commodities, buy.getCommodityID());
            String customerName = GetInformationUtil.getCustomerName(customers, buy.getCustomerID());
            BuyRecord buyRecord = new BuyRecord(customerName, commodityName, buy.getQuantity(), buy.getDate());
            buyRecords.add(buyRecord);
        }
        model.addAttribute("buy_records", buyRecords);
        return "listBuyRecords";
    }

    @GetMapping("/buy/add")
    public String addBuy(Model model) {
        model.addAttribute("commodities", commodityService.ListAllCommodities());
        model.addAttribute("customers", customerService.SelectAll());
        return "addBuyRecords";
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
        return "redirect:/buy/list";
    }
}
