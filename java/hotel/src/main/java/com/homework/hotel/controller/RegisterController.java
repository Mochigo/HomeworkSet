package com.homework.hotel.controller;

import com.homework.hotel.bean.Mail;
import com.homework.hotel.bean.User;
import com.homework.hotel.service.UserService;
import com.homework.hotel.util.MD5Util;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.mail.javamail.JavaMailSenderImpl;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.validation.Valid;
import java.util.Map;
import java.util.Random;

@Controller
public class RegisterController {

    @Resource
    UserService userService;

    @Autowired
    JavaMailSenderImpl javaMailSender;

    @RequestMapping("/user/register")
    public String userRegister(@Valid Mail mail, Map<String, Object> map) {
        Random random = new Random();
        int number = random.nextInt(10000) + 1000;
        map.put("jihuoma", number);
        SimpleMailMessage simpleMailMessage = new SimpleMailMessage();
        simpleMailMessage.setSubject("激活码通知");
        simpleMailMessage.setText("您的激活码为:" + number);
        simpleMailMessage.setTo(mail.getEmail());
        simpleMailMessage.setFrom("345504450@qq.com");
        javaMailSender.send(simpleMailMessage);
        return "register";
    }

    @RequestMapping("/register")
    public String register(HttpServletRequest request, HttpServletResponse response, Map<String, Object> map) throws Exception {
        String jihuoma = request.getParameter("jihuoma");
        String code = request.getParameter("code");
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        if (code.equals(jihuoma) && username != null && password != null) {
            userService.Insert(new User(username, MD5Util.getMD5Str(password)));
            return "login";
        } else if (code == null || username == null || password == null) {
            map.put("msg", "信息不能为空");
            map.put("jihuoma", jihuoma);
            return "register";
        } else {
            map.put("msg", "激活码错误");
            map.put("jihuoma", jihuoma);
            return "register";
        }
    }
}
