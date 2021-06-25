package com.homework.hotel.controller;

import com.github.pagehelper.PageHelper;
import com.homework.hotel.bean.Customer;
import com.homework.hotel.bean.Room;
import com.homework.hotel.service.CustomerService;
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
public class CustomerController {

    @Resource
    CustomerService customerService;

    @GetMapping("/customer/list")
    public String listCustomers(Model model, HttpServletRequest request) {
        String pageNum = request.getParameter("page_num");
        String msg = request.getParameter("msg");
        if (msg != null) {
            model.addAttribute("msg", msg);
        }
        Integer totalPage = customerService.SelectByCount() % 3 == 0 ? (customerService.SelectByCount() / 3) : (customerService.SelectByCount() / 3) + 1;
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
        List<Customer> customers = customerService.SelectAll();
        model.addAttribute("customers", customers);
        return "listCustomers";
    }

    @GetMapping("/customer/add")
    public String addCustomer() {
        return "addCustomer";
    }

    @PostMapping("/customer/add")
    public String addCustomer(@RequestParam String name, @RequestParam String telephone, RedirectAttributes redirectAttributes) {
        if (name == "") {
            redirectAttributes.addAttribute("msg", "新增失败，姓名为空");
            return "redirect:/customer/list";
        }
        if (telephone == "") {
            redirectAttributes.addAttribute("msg", "新增失败，电话号码为空");
            return "redirect:/customer/list";
        }

        Customer customer = new Customer(name, telephone);
        customerService.Insert(customer);
        return "redirect:/customer/list";
    }
}
