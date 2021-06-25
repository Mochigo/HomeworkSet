package com.homework.hotel.controller;


import com.homework.hotel.bean.User;
import com.homework.hotel.service.UserService;
import com.homework.hotel.util.MD5Util;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import javax.annotation.Resource;
import javax.servlet.http.HttpSession;
import java.util.Map;

@Controller
public class LoginController {

    @Resource
    UserService userService;


    @PostMapping("/user/login")
    public String login(@RequestParam("username") String username, @RequestParam("password") String password, Map<String, Object> map, HttpSession session, RedirectAttributes redirectAttributes) throws Exception {
        String password1 = MD5Util.getMD5Str(password);
        User user = userService.getUser(username, password1);
        if (user != null) {
            session.setAttribute("login_user", user);
            return "redirect:/room/list";
        } else {
            map.put("msg", "用户名或密码错误");
            return "login";
        }
    }

    @GetMapping("/user/login/out")
    public String login_out(HttpSession session) {
        session.removeAttribute("login_user");
        return "login";
    }
}
